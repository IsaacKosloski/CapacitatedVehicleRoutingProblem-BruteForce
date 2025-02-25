/*Created by Isaac on 03/02/2025.*/

#include "Solution.h"

class Solver
{
public:
    CVRP *instance;         // The problem instance.
    Solution *bestSolution; // Stores the best solution found.

    vector<vector<Node>> permutations;

    Solver(string filename);

    void generatePermutations(const vector<Node> &node); // Generate all permutations of nodes (except the depot).
    void solve(Solution &solution);                // Construct routes from each permutation while respecting vehicle capacity.
    double evaluateCost(Solution &solution);       // Evaluate cost and update the best solution if a better one is found.
    void constructRoutes(const vector<Node>& nodes, int fleetSize, int capacity);

};

