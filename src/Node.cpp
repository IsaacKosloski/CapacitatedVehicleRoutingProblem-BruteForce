/*Created by Isaac on 28/01/2025.*/

#include "Node.h"

// Default Constructor
Node::Node()
{

}

// Constructor for Clients
Node::Node(int ID, bool isAvailable, int demand)
{
    this->ID = ID;
    this->isAvailable = isAvailable;
    this->demand = demand;
    this->isDepot = false;
}
