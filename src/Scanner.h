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
    int distanceType;
    int explicitDistanceFormat;
    int displayDataType;
    int edgeWeightFormat;
    int edgeWeightType;
    int col;
    int row;
    string fileName;
    vector<Component> components;
    vector<Node> nodes;
    vector<Node> nodesDistance;

    Scanner();
    Scanner(string fileName);

    void readFile(const string &fileName, vector<Component> &components, vector<Node> &nodes, vector<Node> &nodesDistance);
    bool specificationPart(string line);
};
