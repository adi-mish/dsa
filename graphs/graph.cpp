#include <iostream>
#include <vector>

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

    void showGraph() {
        for (size_t i = 0; i < vertices.size(); ++i) {
            cout << vertices[i].data << " has outgoing edges - ";
            for (const auto& edge : vertices[i].outEdges) {
                cout << vertices[edge.sourceIndex].data << "->" << vertices[edge.destinationIndex].data
                     << " (" << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<char> myGraph;

    myGraph.addEdge('A', 'B', 5);
    myGraph.addEdge('A', 'C', 10);
    myGraph.addEdge('B', 'C', 8);
    myGraph.addEdge('C', 'D', 3);
    myGraph.addEdge('D','E', 20);

    myGraph.showGraph();

    return 0;
}
