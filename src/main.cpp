/*Created by Isaac on 30/01/2025.*/

#include "Functions.h"

int main(int argc, char **argv)
{
    auto *cvrp = new CVRP(argv[1]);
    cout << "Success" << endl;

    printInstance(cvrp);

    delete cvrp;

    return 0;
}