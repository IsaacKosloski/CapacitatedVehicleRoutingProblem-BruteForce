/*Created by Isaac on 30/01/2025.*/

#include "Scanner.h"



Scanner::Scanner(string fileName)
{
    this->fileName = fileName;
    dimensionOfNodes = -1;
    capacityOfVehicles = -1;
    col = -1;
    row = -1;

    readFile(fileName, components, nodesDistance, nodes);
}

void
Scanner::readFile(const string &fileName, vector<Component> &components, vector<double> &nodesDistance, vector<Node> &nodes)
{
    int ID = 1;
    int demand;
    vector<double> positionComponents(2);
    string line{};

    ifstream inputFile(fileName, ios::in);

    if (inputFile.is_open())
    {

        while(getline(inputFile, line) && !specificationPart((line)));

        if (dimensionOfNodes <= 0)
            throw std::runtime_error("Error: Invalid or missing DIMENSION in file.");

        // Resizing vectors
        components.resize(dimensionOfNodes);
        nodesDistance.resize(dimensionOfNodes * dimensionOfNodes);

        while (getline(inputFile, line) && line != "DEMAND_SECTION ")
        {
            istringstream ssLine(line);

            if (!(ssLine >> ID >> positionComponents[0] >> positionComponents[1]))
            {
                cerr << "Error: Malformed line: " << line << endl;
                throw std::runtime_error("Invalid data format.");
            }

            if (ID - 1 >= 0 && ID - 1 < (int)components.size())
            {
                components[ID - 1] = Component(positionComponents);
            }
            else
            {
                cerr << "Error: ID out of range (" << ID << ")" << endl;
                throw std::runtime_error("Invalid node ID in input file.");
            }
        }


        for (row = 0; row < dimensionOfNodes; row++)
        {
            for (col = 0; col < dimensionOfNodes; col++)
            {
                vector<double> posA = components[row].getPosition();
                vector<double> posB = components[col].getPosition();

                if ((row * dimensionOfNodes) + col < (int)nodesDistance.size())
                    nodesDistance[(row * dimensionOfNodes) + col] = sqrt(pow((posA[0] - posB[0]), 2) + pow((posA[1] - posB[1]), 2));
                else
                    cerr << "Warning: nodesDistance index out of range!" << endl;

                //nodesDistance[(row * dimensionOfNodes) + col] = sqrt((pow((components[row].positionComponents[0] - components[col].positionComponents[0]), 2) + (pow((components[row].positionComponents[1] - components[col].positionComponents[1]), 2))));
            }
        }
        while(getline(inputFile, line) && line != "DEPOT_SECTION ")
        {
            istringstream ssLine(line);
            if (ssLine >> ID >> demand)
            {
                nodes.push_back(Node(ID, demand));
            }
            else
            {
                cerr << "Warning: Invalid line format in DEMAND_SECTION: " << line << endl;
            }
        }

        getline(inputFile, line);
        istringstream ssLine(line);
        ssLine >> ID;
        if (ID - 1 >= 0 && ID - 1 < (int)nodes.size())
        {
            nodes[ID - 1].isDepot = true;
            nodes[ID - 1].isAvailable = false;
        }
        else
        {
            cerr << "Error: Depot index out of range: " << ID - 1 << endl;
        }/**/
    }
    else
    {
        cerr << "Error: Could not open file " << fileName << endl;
        throw std::runtime_error("Unable to open file");
    }

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
