/*Created by Isaac on 28/01/2025.*/

#include "Node.h"

// Default Constructor
Node::Node()
{

}

// Constructor for Clients
Node(int ID, bool isAvailable, int demand)
{
    this->ID{ID};
    this->isAvailable{isAvailabe};
    this->demand{demand};
}

// Constructor for Depot
Node::Node(bool isDepot)
{
    this->isDepos{true};
    this-ID{};
    this->isAvailable{false};
    this->demand{};
}