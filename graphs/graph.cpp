#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

template <typename T> struct Vertex;
template <typename T> struct Edge;

template <typename T>
struct Vertex {
    T data;
    vector<Edge<T>> outEdges;

    Vertex(T val) : data(val) {}
};

template <typename T>
struct Edge {
    size_t sourceIndex;
    size_t destinationIndex;
    int weight;

    Edge(size_t srcIndex, size_t destIndex, int weight)
        : sourceIndex(srcIndex), destinationIndex(destIndex), weight(weight) {}
};

template <typename T>
class Graph {
private:
    vector<Vertex<T>> vertices;

    size_t makeOrGetVertexIndex(T val) {
        for (size_t i = 0; i < vertices.size(); ++i) {
            if (vertices[i].data == val)
                return i;
        }

        vertices.emplace_back(val);
        return vertices.size() - 1;
    }

public:
    void addEdge(T v1, T v2, int weight) {
        size_t vertex1Index = makeOrGetVertexIndex(v1);
        size_t vertex2Index = makeOrGetVertexIndex(v2);

        vertices[vertex1Index].outEdges.emplace_back(vertex1Index, vertex2Index, weight);
    }

    // Time complexity: |V| log |V| + |E|
    void dijkstra(T start) {
        priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, greater<pair<int, size_t>>> pq;
        vector<int> distance(vertices.size(), numeric_limits<int>::max());
        vector<size_t> predecessor(vertices.size(), SIZE_MAX);
        vector<bool> visited(vertices.size(), false);

        size_t startIndex = makeOrGetVertexIndex(start);    

        distance[startIndex] = 0;
        pq.push({0, startIndex});

        while(!pq.empty()) {
            size_t currentNodeIndex = pq.top().second;
            pq.pop();
            if (visited[currentNodeIndex])
                continue;
            visited[currentNodeIndex] = true;
            for (auto& edge : vertices[currentNodeIndex].outEdges) {
                size_t neighborIndex = edge.destinationIndex;
                int weight = edge.weight;

                if (distance[currentNodeIndex] + weight < distance[neighborIndex]) {
                    distance[neighborIndex] = distance[currentNodeIndex] + weight;
                    predecessor[neighborIndex] = currentNodeIndex;
                    pq.push({distance[neighborIndex], neighborIndex});
                }
            }
        }

        for (size_t i = 0; i < vertices.size(); ++i) {
            if (i != startIndex) {
                cout << "Shortest distance from " << start << " to " << vertices[i].data << " is: " << distance[i] << " | ";
            cout << "Shortest path: ";
            size_t current = i;
            while (current != SIZE_MAX) {
                cout << vertices[current].data;
                if (current != startIndex) {
                    cout << " <- ";
                }
                current = predecessor[current];
            }
            cout << endl;
            }
        }
    }

    // Time complexity: |V|·|E|
    void bellmanFord(T start) {
        size_t startIndex = makeOrGetVertexIndex(start);
        vector<int> distance(vertices.size(), numeric_limits<int>::max());
        vector<size_t> predecessor(vertices.size(), SIZE_MAX);

        distance[startIndex] = 0;

        for (size_t i = 0; i < vertices.size() - 1; ++i) {
            for (auto& vertex : vertices) {
                size_t currentNodeIndex = makeOrGetVertexIndex(vertex.data);
                for (auto& edge : vertex.outEdges) {
                    size_t neighborIndex = edge.destinationIndex;
                    int edgeWeight = edge.weight;

                    if (distance[currentNodeIndex] != numeric_limits<int>::max() &&
                        distance[currentNodeIndex] + edgeWeight < distance[neighborIndex]) {
                        distance[neighborIndex] = distance[currentNodeIndex] + edgeWeight;
                        predecessor[neighborIndex] = currentNodeIndex;
                    }
                }
            }
        }

        for (size_t i = 0; i < vertices.size(); ++i) {
            for (auto& edge : vertices[i].outEdges) {
                size_t neighborIndex = edge.destinationIndex;
                int edgeWeight = edge.weight;

                if (distance[i] != numeric_limits<int>::max() &&
                    distance[i] + edgeWeight < distance[neighborIndex]) {
                    cout << "Graph contains a negative cycle!" << endl;
                    return;
                }
            }
        }

        for (size_t i = 0; i < vertices.size(); ++i) {
            cout << "Shortest distance from " << start << " to " << vertices[i].data << " is: " << distance[i] << " | ";
            cout << "Shortest path: ";
            size_t current = i;
            while (current != SIZE_MAX) {
                cout << vertices[current].data;
                if (current != startIndex) {
                    cout << " <- ";
                }
                current = predecessor[current];
            }
            cout << endl;
        }
    }

    void showGraph() {
        for (size_t i = 0; i < vertices.size(); ++i) {
            cout << vertices[i].data << " has outgoing edges: ";
            for (auto& edge : vertices[i].outEdges) {
                cout << vertices[edge.sourceIndex].data << "->" << vertices[edge.destinationIndex].data << "(" << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<char> myGraph;
    Graph<char> myGraph1;
    Graph<char> myGraph2;
    Graph<char> myGraph3;

    myGraph.addEdge('A', 'B', 5);
    myGraph.addEdge('A', 'C', 10);
    myGraph.addEdge('B', 'C', 8);
    myGraph.addEdge('C', 'D', 3);
    myGraph.addEdge('D', 'E', 20);
    myGraph.addEdge('E', 'F', 15);
    myGraph.addEdge('F', 'G', 12);
    myGraph.addEdge('G', 'H', 7);
    myGraph.addEdge('H', 'A', 4);
    myGraph.addEdge('B', 'D', 2);
    myGraph.addEdge('F', 'H', 10);
    myGraph.addEdge('G', 'A', 6);

    myGraph.showGraph();
    char startNode = 'A';
    char endNode = 'H';
    myGraph.dijkstra('A');

    myGraph1.addEdge('X', 'Y', 5);
    myGraph1.addEdge('X', 'Z', 3);
    myGraph1.addEdge('Y', 'Z', -4);
    myGraph1.showGraph();
    myGraph1.bellmanFord('X');
    cout << endl;

    myGraph2.addEdge('J', 'K', 3);
    myGraph2.addEdge('K', 'L', -2);
    myGraph2.addEdge('L', 'J', -3);
    myGraph2.showGraph();
    myGraph2.bellmanFord('J');

    return 0;
}
