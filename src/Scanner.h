/*Created by Isaac on 30/01/2025.*/

#include "Component.h"
#include "Node.h"
#include "Vehicle.h"
#include <string>
#include <sstream>

class Scanner
{
public:
    int dimensionOfNodes;
    int capacityOfVehicles;
    int col;
    int row;
    string fileName;
    vector<Component> components;
    vector<Node> nodes;
    vector<double> nodesDistance;

    Scanner();
    Scanner(string fileName);

    void readFile(const string &fileName, vector<Component> &components, vector<double> &nodesDistance, vector<Node>nodes);
    bool specificationPart(string line);
};
