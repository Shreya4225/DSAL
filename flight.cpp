#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
    string vertex;
    int time;
    Node* next;

    Node(string v, int t) : vertex(v), time(t), next(nullptr) {}
};

class Graph {
private:
    int numCities;
    vector<string> cities;
    vector<vector<int>> adjMatrix;
    vector<Node*> adjList;

public:
    Graph() : numCities(0) {}

    void getGraph() {
        cout << "Enter the number of cities (max. 20): ";
        cin >> numCities;

        cities.resize(numCities);
        adjMatrix.resize(numCities, vector<int>(numCities, 0));
        adjList.resize(numCities, nullptr);

        cout << "Enter the names of cities:\n";
        for (int i = 0; i < numCities; i++) {
            cout << "City " << (i + 1) << ": ";
            cin >> cities[i];
        }

        for (int i = 0; i < numCities; i++) {
            for (int j = 0; j < numCities; j++) {
                if (i != j) {
                    cout << "Is there a path between " << cities[i] << " and " << cities[j] << "? (y/n): ";
                    char ch;
                    cin >> ch;

                    if (ch == 'y') {
                        cout << "Enter the time required to reach " << cities[j] << " from " << cities[i] << " (in minutes): ";
                        int time;
                        cin >> time;
                        adjMatrix[i][j] = time;
                        addEdge(i, j, time);
                    }
                }
            }
        }
    }

    void addEdge(int src, int dest, int time) {
        Node* newNode = new Node(cities[dest], time);

        if (adjList[src] == nullptr) {
            adjList[src] = newNode;
        } else {
            Node* temp = adjList[src];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n\t";
        for (int i = 0; i < numCities; i++) {
            cout << cities[i] << "\t";
        }
        cout << "\n";
        for (int i = 0; i < numCities; i++) {
            cout << cities[i] << "\t";
            for (int j = 0; j < numCities; j++) {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < numCities; i++) {
            cout << cities[i];
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << " -> " << temp->vertex << " [time required: " << temp->time << " min]";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph graph;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter graph\n";
        cout << "2. Display adjacency matrix for cities\n";
        cout << "3. Display adjacency list for cities\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                graph.getGraph();
                break;
            case 2:
                graph.displayAdjMatrix();
                break;
            case 3:
                graph.displayAdjList();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
