cmake_minimum_required(VERSION 3.27)
project(CapacitatedVehicleRoutingProblem-BruteForce)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(CapacitatedVehicleRoutingProblem
        src/main.cpp
        src/Component.cpp
        src/Component.h
        src/Node.cpp
        src/Node.h
        src/Vehicle.cpp
        src/Vehicle.h
        src/Scanner.cpp
        src/Scanner.h
        src/CVRP.cpp
        src/CVRP.h
        src/Scanner.cpp
        src/Functions.cpp
        src/Solution.h
        src/Solution.cpp
        src/Solver.h
        src/Solver.h
        src/Solver.cpp
        src/CVRP.cpp
        src/CVRP.cpp
        src/CVRP.cpp
        src/Solver.h
        src/Solution.h
        src/Solution.h
        src/Solution.h
        src/Scanner.cpp
        src/Solver.cpp)
