/*Created by Isaac on 03/02/2025.*/

#include "CVRP.h"

class Solution
{
public:

    double totalCost;
    vector<double> routesCosts;  // Total cost of the solution.
    vector<vector<Node>> routes; // Each route corresponds to a vehicle’s route.

    Solution();

    double computeCost(int dimensionOfNodes, vector<double> &matrixCost);
    bool validate();
    void printSolution(const char* fileName, double elapsedTime, int iterations, int dimensionOfNodes);

};
