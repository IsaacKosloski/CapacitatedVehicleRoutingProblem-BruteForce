/*Created by Isaac on 30/01/2025.*/

#include "Scanner.h"

Scanner::Scanner()
{

}

Scanner::Scanner(string fileName)
{
    this->fileName = fileName;
    dimensionOfNodes = -1;
    distanceType = -1;
    explicitDistanceFormat = -1;
    displayDataType = -1;
    edgeWeightFormat = -1;
    edgeWeightType = -1;
    col = -1;
    row = -1;

    readFile(fileName, components, nodes, nodesDistance);
}

void
Scanner::readFile(const int &fileName, vector <Component> &components, vector <Node> &nodes, vector <Node> &nodesDistance)
{
    int ID{1};
    int nextID{1};
    vector<double> positionComponents;
    string line{};

    ifstream inputFile(fileName, ios::in);

    if (inputFile.is_open())
    {
        while(getline(inputFile, line) && !specificationPart((line)));
        // Reading the file
        while (getline(inputFile, line) && line != "EOF")
        {
            istringstream ssLine(line);
            ssLine >> ID >> positionComponents.
        }
    }
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
            stringData = line.substr(found + 2)
        }
    }
}
