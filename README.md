# 🚛 Capacitated Vehicle Routing Problem
# 💪 A Brute Force Approach

This repository contains an implementation of a brute-force algorithm to solve the **Capacitated Vehicle Routing Problem (CVRP)**.  
The CVRP is a classic optimization problem that focuses on determining the most efficient routes for a fleet of vehicles 🚐 with limited capacity to deliver goods 📦 to a set of customers.

## ✨ Features
- 🧠 **Exhaustive Search**: Explore all possible solutions to find the optimal routes.
  - 🛠️ **Customizable Inputs**: Configure vehicle capacities and customer demands.
  - 📊 **Visualization**: Analyze routes and performance metrics.
  - 🎓 **Educational Focus**: Ideal for small-scale problems and learning purposes.

## 🚀 Use Cases
This repository is perfect for:
- 📚 Gaining insights into the CVRP and brute-force techniques.
  - 🔍 Comparing brute-force solutions with heuristics or metaheuristics.
  - 🧪 Experimenting with optimization on small problem instances.

## 🏗 Project Structure
```
CapacitatedVehicleRoutingProblem-BruteForce/
│── Benchmarks/    # Contains benchmark problem instances and solutions
│── src/           # Source code of the project
│── Makefile       # Build automation file
│── README.md      # Project documentation
```

## 🛠️ Compilation and Execution
This project uses a `Makefile` for easy compilation. To build the project, navigate to the repository root and run:
```
make
```
This will generate an executable file. To run the program, use:
```
./cvrp_solver input_file.vrp
```
where `input_file.vrp` is a valid CVRP instance file from the `Benchmarks/` directory.

## 📌 Example Usage
```
./cvrp_solver Benchmarks/A/A-n32-k5.vrp
```
This will process the problem instance and output the optimal solution found by the brute-force algorithm.

## 📊 Class Diagram Overview

### 📋 Table

| Class         | Attributes                                                                                                                                                                   | Methods                                                                                                                                                              |
|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Node**      | `int id`, `int demand`, `bool isDepot`, `bool isAvailable`                                                                                                                   | `+ Node()`, `+ Node(int, int)`                                                                                                                                       |
| **Component** | `int numberOfComponents`, `vector<double> positionComponents`                                                                                                                | `+ Component()`, `+ Component(vector<double>)`                                                                                                                       |
| **Vehicle**   | `int capacity`, `int currentLoad`, `vector<int> route`                                                                                                                       | `+ addNode()`, `+ reset()`, `+ computeCost()`                                                                                                                        |
| **CVRP**      | `vector<Node> nodes`, `vector<double> distanceMatrix`, `int depotID`, `int nodesDimension`, `int capacityOfVehicle`, `Scanner *scanner`                                      | `+ CVRP(string)`, `+ loadInstance(string)`,                                                                                                            |
| **Solution**  | `double totalCost`, `vector<double> routesCosts`, `vector<vector<Node>> routes`                                                                                              | `+ computeCost(int, vector<double>)`, `+ validate()`, `+ printSolution(const char*, double, int, int)`                                                               |
| **Scanner**   | `int dimensionOfNodes`, `capacityOfVehicles`, `int col`, `int row`, `string fileName`, `vector<Component> components`, `vector<Node> nodes`, `vector<double> nodesDistance`  | `+ Scanner(string)`, `+ readFile(const string, vector<Component>, vector<doubles>, vector<Node>)`, `+ specificationPart(string)`                                     |
| **Solver**    | `CVRP *instance`, `Solution *bestSolution`, `vector<vector<Node>>`                                                                                                           | `+ Solver(string)`, `+ generatePermutations(const vector<Node>)`, `+ solve(Solution)`, `+ evaluateCost(Solution)`, `+ constructRoutes(const vector<Node>, int, int)` |



---
### 📂 Diagram

```mermaid
classDiagram
    class Node {
        +int id
        +int demand
        +bool isDepot
        +bool isAvailable
    }
    
    class Component{
        +int numberOfComponents
        +vector<double> positionComponents
    }

    class Vehicle {
        +int capacity
        +int currentLoad
        +vector<int> route
        +addNode()
        +reset()
        +computeCost()
    }

    class CVRP {
        +vector<Node> nodes 
        +vector<double> distanceMatrix 
        +int depotID
        +int nodesDimension 
        +int capacityOfVehicle 
        +Scanner *scanner 
        +loadInstance()
        
    }

    class Solution {
        +int totalCost
        +vector<double> routeCosts
        +vector<vector<int>> routes
        +computeCost()
        +printSolution()
    }

    class Solver {
        +CVRP *instance
        +Solution *bestSolution
        +vector<vector<Node>> permutations
        +generatePermutations()
        +solve()        
    }

    class Scanner {
        +int dimensionOfNodes
        +int capacityOfVehicles
        +int col
        +int row
        +string fileName
        +vector<Component> components
        +vector<Node> nodes
        +vector<double> nodesDistance
        +readFile()
        +specificationPart()
    }
    
    Component --* Scanner
    Node --* CVRPInstance
    Vehicle --* CVRPInstance
    CVRPInstance --* Solver
    Solution --* Solver
    Scanner --* CVRPInstance
```
---
## 🔀 Activity Diagram
```mermaid
graph TD;
    Start((Start)) -->|Read Input Data| Scanner["Scanner reads instance file"];
    Scanner -->|Initialize CVRP Instance| CVRP["Create CVRP instance"];
    CVRP -->|Load Nodes and Vehicles| Nodes["Initialize Nodes and Vehicles"];
    Nodes -->|Create Solver| Solver["Solver initialized"];
    Solver -->|Generate Permutations| Permutations["Generate node permutations"];
    Permutations -->|Construct Routes| Routes["Construct vehicle routes"];
    Routes -->|Evaluate Solution| Solution["Compute and validate solution"];
    Solution -->|Output Results| Output["Print solution and cost"];
    Output --> End((End));

```
---
## ➡️ Sequence Diagram

```mermaid
sequenceDiagram;
    participant Main
    participant CVRP
    participant Scanner
    participant Solver
    participant Solution
    Main->>CVRP: Create Instance
    CVRP->>Scanner: Load Instance
    Scanner->>Scanner: Read File
    Scanner-->>CVRP: Return Data
    CVRP-->>Main: Instance Loaded
    Main->>Solver: Create Solver
    Solver->>Solver: Generate Permutations
    Solver->>Solution: Solve Problem
    Solution->>Solution: Compute Cost
    Solution-->>Solver: Return Cost
    Solver->>Solution: Print Solution
    Solution->>Main: Done
```
---
## ↔️ Comunication Diagram

```mermaid
graph LR;
    Main -- Calls --> CVRP;
    CVRP -- Uses --> Scanner;
    Main -- Calls --> Solver;
    Solver -- Generates --> Permutations;
    Solver -- Calls --> Solution;
    Solution -- Computes --> Cost;
    Solution -- Outputs --> Result;

```
---
Feel free to explore, experiment, and optimize! 🧩 Let me know if you'd like to add more features or examples.  

