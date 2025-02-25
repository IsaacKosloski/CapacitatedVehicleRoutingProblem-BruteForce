/* Created by Isaac on 03/02/2025. */

#include "Solver.h"
#include <limits>

Solver::Solver(string filename)
{
    this->instance = new CVRP(filename);
    generatePermutations(this->instance->nodes);
}

// Generate all permutations of nodes (except the depot).
void
Solver::generatePermutations(const vector<Node>& nodes)
{
    auto permutatedNodes = nodes;

    do
    {
        this->permutations.push_back(permutatedNodes);
    } while (next_permutation(permutatedNodes.begin() + 1, permutatedNodes.end(),
                              [](const Node& a, const Node& b) { return a.ID < b.ID; }));
}

// Construct routes from each permutation while respecting vehicle capacity.
void
Solver::solve(Solution& solution)
{
    double bestCost = numeric_limits<double>::max();

    for (auto& perm : this->permutations)
    {
        Solution tempSolution();
        tempSolution.constructRoutes(perm, this->instance->fleetSize, this->instance->capacity);

        double cost = evaluateCost(tempSolution);
        if (cost < bestCost)
        {
            bestCost = cost;
            *this->bestSolution = tempSolution;  // Update best solution
        }
    }

    solution = *this->bestSolution;
}

// Evaluate cost and update the best solution if a better one is found.
double
Solver::evaluateCost(Solution& solution)
{
    return solution.computeCost(this->instance->nodesDimension, this->instance->distanceMatrix);
}

void
Solver::constructRoutes(const vector<Node>& nodes, int fleetSize, int capacity)
{
    this->routes.clear();
    this->totalCost = 0;

    int depotID = 0; // Assuming depot is node 0
    vector<int> currentRoute;
    int currentLoad = 0;
    int vehicleCount = 0;

    currentRoute.push_back(depotID); // Start at depot

    for (const Node& customer : nodes)
    {
        if (customer.isDepot) continue; // Skip depot in permutations

        if (currentLoad + customer.demand > capacity)
        {
            currentRoute.push_back(depotID); // Return to depot
            this->routes.push_back(currentRoute);

            vehicleCount++;
            if (vehicleCount >= fleetSize) return; // Stop if no more vehicles are available

            currentRoute.clear();
            currentRoute.push_back(depotID);
            currentLoad = 0;
        }

        currentRoute.push_back(customer.id);
        currentLoad += customer.demand;
    }

    currentRoute.push_back(depotID); // Close last route
    this->routes.push_back(currentRoute);
}
