#include <iostream>
#include <vector>

struct Edge
{
    int node_index;
    int weight;
};

template <typename T>
class Node
{
public:
    std::vector<Edge> edges;
    T value;
};

template <typename T>
class Graph
{
public:
    bool directed;
    std::vector<Node<T>> adjacency_list;

    Graph(bool directed) : directed(directed)
    {
    }

    void insertNode(std::vector<Edge> edges, T value)
    {
        Node<T> node;
        for (int i = 0; i < edges.size(); i++)
        {
            node.edges.push_back(edges[i]);
            // if (!directed)
            // {
            // adjacency_list[edges[i].node_index].edges.push_back({adjacency_list.size(), edges[i].weight})
            // }
        }
        node.value = value;
        adjacency_list.push_back(node);
    }

    void print()
    {
        for (int i = 0; i < adjacency_list.size(); i++)
        {
            std::cout << adjacency_list[i].value << std::endl;
        }
    }
};

void test_graph_using_adjacency_list()
{
    Graph<int> graph(false);
    graph.insertNode({{4, 3}, {2, 1}}, 6);
    graph.insertNode({{4, 3}, {3, 1}}, 4);
    graph.insertNode({{4, 3}, {1, 1}}, 2);
    graph.insertNode({{2, 3}, {2, 1}}, 3);
    graph.print();
}