/*Created by Isaac on 30/01/2025.*/

#include "Component.h"
Component::Component()
{

}

Component::Component(vector<double>& positionComponents)
{
    for (auto n : positionComponents)
        this->positionComponents.push_back(n);
}
