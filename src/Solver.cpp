/* Created by Isaac on 03/02/2025. */

#include "Solver.h"
#include <limits>

Solver::Solver()
{

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
Solver::solve(CVRP *instance , Solution *solution)
{

    solution->routes.clear();
    solution->totalCost = 0;

    int depotID = 0; // Assuming depot is node 0
    vector<int> currentRoute;
    int currentLoad = 0;
    int vehicleCount = 0;

    currentRoute.push_back(depotID); // Start at depot

    for (const Node& customer : instance->nodes)
    {
        if (customer.isDepot) continue; // Skip depot in permutations

        if (currentLoad + customer.demand > instance->capacityOfVehicle)
        {
            currentRoute.push_back(depotID); // Return to depot
            solution->routes.push_back(currentRoute);

            vehicleCount++;
            if (vehicleCount >= solution->fleetSize) return; // Stop if no more vehicles are available

            currentRoute.clear();
            currentRoute.push_back(depotID);
            currentLoad = 0;
        }

        currentRoute.push_back(customer.ID);
        currentLoad += customer.demand;
    }

    currentRoute.push_back(depotID); // Close last route
    solution->routes.push_back(currentRoute);
}
