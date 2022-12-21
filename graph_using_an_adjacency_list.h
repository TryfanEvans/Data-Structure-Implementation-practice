#include <iostream>
#include <vector>

struct Edge
{
    int target_label;
    int weight;
};

template <typename T>
class Node
{
public:
    int label;
    std::vector<Edge> edges;
    T value;
};

template <typename T>
class Graph
{
public:
    bool directed;
    int nvertices = 0;
    std::vector<Node<T>> adjacency_list;

    Graph(bool directed, int nvertices) : directed(directed), nvertices(nvertices)
    {
        Node<T> node;
        for (int i = 0; i < nvertices; i++)
        {
            adjacency_list.push_back(node);
        }
        this->nvertices = 0;
    }

    void insertNode(std::vector<Edge> edges, T value)
    {
        Node<T> *node = &adjacency_list[nvertices];
        for (int i = 0; i < edges.size(); i++)
        {
            node->edges.push_back(edges[i]);
            if (!directed)
            {
                Node<T> *target_node = &adjacency_list[edges[i].target_label];
                Edge reverse_edge = {nvertices, edges[i].weight};
                target_node->edges.push_back(reverse_edge);
            }
        }
        node->value = value;
        node->label = nvertices;
        nvertices++;
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
    Graph<int> graph(false, 4);
    graph.insertNode({{3, 3}, {2, 1}}, 6);
    graph.insertNode({{3, 3}, {0, 1}}, 4);
    graph.insertNode({{3, 3}, {1, 1}}, 2);
    graph.insertNode({{2, 3}, {2, 1}}, 3);
    graph.print();
}