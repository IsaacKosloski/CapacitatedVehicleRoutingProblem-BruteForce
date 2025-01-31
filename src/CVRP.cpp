/*Created by Isaac on 30/01/2025.*/

#include "CVRP.h"

CVRP::CVRP(string fileName)
{
    loadInstance(fileName);
}

// Method to load instance data (from file or manually).
void
CVRP::loadInstance(string fileName)
{
    scanner = new Scanner(fileName);

    this->nodesDimension = scanner->dimensionOfNodes;
    this->capacityOfVehicle = scanner->capacityOfVehicles;

    for (auto n : scanner->nodesDistance)
        this->distanceMatrix.push_back(n);

    for (auto n : scanner->nodes)
        this->nodes.push_back(n);

    delete scanner;
}
