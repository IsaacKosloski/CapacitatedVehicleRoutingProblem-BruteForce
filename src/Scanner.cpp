/*Created by Isaac on 30/01/2025.*/

#include "Scanner.h"

Scanner::Scanner()
{

}

Scanner::Scanner(string fileName)
{
    this->fileName{fileName};
    dimensionOfNodes{-1};
    capacityOfVehicles{-1};
    col{-1};
    row{-1};

    readFile(fileName, components, nodesDistance);
}

void
Scanner::readFile(const int &fileName, vector<Component> &components, vector<double> &nodesDistance, vector<Node>nodes)
{
    int ID{1};
    int nextID{1};
    int demand;
    vector<double> positionComponents;
    string line{};

    ifstream inputFile(fileName, ios::in);

    if (inputFile.is_open())
    {

        while(getline(inputFile, line) && !specificationPart((line)));

        while (getline(inputFile, line) && line != "DEMAND_SECTION")
        {
            istringstream ssLine(line);
            ssLine >> ID >> positionComponents[0] >> positionComponents[1];
            components[ID - 1] = (Component(positionComponents));
        }

        for (row = 0; row < dimensionOfNodes; row++)
        {
            for (col = 0; col < dimensionOfNodes; col++)
            {
                nodesDistance[(row * dimensionOfNodes) + col]
                        = sqrt((pow((components[row].positionComponents[0] - components[col].positionComponents[0]), 2)
                                     + (pow((components[row].positionComponents[1] - components[col].positionComponents[1]), 2)))));
            }
        }
        while(getline(inputFile, line) && line != "DEPOT_SECTION")
        {
            istringstream ssLine(line);
            ssLine >> ID >> demand;
            nodes.push_back(Node(ID, true, demand));
        }
        getline(inputFile, line);
        istringstream ssLine(line);
        ssLine >> ID;
        nodes[ID].isDepot = true;
        nodes[ID].isAvailable = false;
    }
    else
        throw std::runtime_error("Unable to open file");

    inputFile.close();
}

bool
Scanner::specificationPart(string line)
{
    size_t found = 0;
    string stringData{};

    if (line.find("DIMENSION") != string::npos)
    {
        found = line.find(": ");
        if (found != string::npos)
        {
            stringData = line.substr(found + 2);
            dimensionOfNodes = stoi(stringData);

        }
    }
    else if (line.find("CAPACITY") != string::npos)
    {
        found = line.find(": ");
        if (found != string::npos)
        {
            stringData = line.substr(found + 2);
            capacityOfVehicles = stoi(stringData);
        }
    }
    else if (line.find("NODE_COORD_SECTION") !=string::npos)
        return true;

    return false;
}
