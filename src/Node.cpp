/*Created by Isaac on 28/01/2025.*/

#include "Node.h"

// Default Constructor
Node()
{

}

// Constructor for Clients
Node(int ID, int demand)
{
    this->ID{ID};
    this->demand{demand};
}

// Constructor for Depot
Node(bool isDepot)
{
    this->isDepos{true};
    this-ID{};
    this->demand{};
}