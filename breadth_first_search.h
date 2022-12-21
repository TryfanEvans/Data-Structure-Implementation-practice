#include "graph_using_an_adjacency_list.h"
#include <algorithm>

enum State
{
    undiscovered,
    discovered,
    processed
};

struct Vertex
{
    State state = undiscovered;
    int parent_label;
};

std::vector<Vertex> bfs(Graph<int> graph, int start_label)
{
    std::vector<Vertex> tree;

    for (int i = 0; i < graph.adjacency_list.size(); i++)
    {
        tree.push_back({undiscovered, -1});
    }
    for (int i = 0; i < tree.size(); i++)
    {
        Node<int> currentNode = graph.adjacency_list[i];
        if (currentNode.label == start_label)
        {
            tree[i].state = discovered;
            break;
        }
    }
    bool complete = false;
    while (!complete)
    {
        for (int i = 0; i < tree.size(); i++)
        {
            Node<int> currentNode = graph.adjacency_list[i];
            Vertex currentVertex = tree[i];
            if (currentVertex.state == discovered)
            {
                std::vector<Edge> edges = currentNode.edges;
                for (int j = 0; j < edges.size(); j++)
                {
                    Vertex *targetNode = &tree[edges[j].target_label];
                    if (targetNode->state == undiscovered)
                    {
                        targetNode->parent_label = i;
                        targetNode->state = discovered;
                        complete = true;
                    }
                }
                tree[i].state = processed;
            }
        }
    }
    return tree;
}

void traverse_tree(std::vector<Vertex> tree, int end_label)
{
    std::string traversal = std::to_string(end_label);
    int current_label = end_label;
    if (tree[current_label].state == undiscovered)
    {
        std::cout << "This target is not in the same connected component as the source" << std::endl;
        return;
    }
    while (tree[current_label].parent_label != -1)
    {
        current_label = tree[current_label].parent_label;
        traversal.append(" ");
        traversal.append(std::to_string(current_label));
    }
    std::reverse(traversal.begin(), traversal.end());
    std::cout << traversal << std::endl;
}

void test_breadth_first_search()
{
    Graph<int> graph(false, 6);

    graph.insertNode({{3, 3}, {2, 1}}, 6);
    graph.insertNode({{1, 3}, {4, 1}}, 4);
    graph.insertNode({{5, 3}, {1, 1}}, 2);
    graph.insertNode({{2, 4}, {3, 1}}, 3);
    graph.insertNode({{5, 5}, {2, 1}}, 3);
    graph.insertNode({{4, 4}, {2, 1}}, 3);
    std::vector<Vertex> tree = bfs(graph, 1);
    traverse_tree(tree, 3);
    std::cout << "This is the breadth first search test!" << std::endl;
}
