/*Created by Isaac on 03/02/2025.*/

#include "Solution.h"

class Solver
{
public:
    CVRP *instance;         // The problem instance.
    Solution *bestSolution; // Stores the best solution found.

    vector<vector<Node>> permutations;

    Solver();

    void generatePermutations(const vector<Node> &node); // Generate all permutations of nodes (except the depot).
    void solve(CVRP *instance , Solution *solution);                      // Construct routes from each permutation while respecting vehicle capacity.

};

