/*Created by Isaac on 30/01/2025.*/

#include "Node.h"
#include "Vehicle.h"

// Represents the problem instance, containing all data related to nodes, vehicles, and distances.
class CVRP
{
public:
    vector<Node>    nodes;          // All nodes, including depot and customers.
    vector<Vehicle> fleet;          // The fleet of vehicles.
    vector<int>     distanceMatrix; // Matrix of distances between nodes.
    int             depotID;        // ID of the depot node.

    void loadInstance();            // Method to load instance data (from file or manually).
    bool validate();                // Method to validate an instance (e.g., check if total demand is feasible with available vehicles).
};
