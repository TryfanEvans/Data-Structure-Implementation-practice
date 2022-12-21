// This is going to use recursion
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
    int time;
};

int time = 0;
void dfs(Graph<int> graph, std::vector<Vertex> &tree, int current_label)
{
    // bool complete = true;
    // for (int i = 0; i < tree.size(); i++)
    // {
    // if (tree[i].state == undiscovered)
    // {
    // complete = false;
    // }
    // }
    // if (complete)
    // {
    // return;
    // }
    tree[current_label].state = discovered;
    tree[current_label].time = time;
    time++;
    Node<int> currentNode = graph.adjacency_list[current_label];
    for (int i = 0; i < currentNode.edges.size(); i++)
    {
        int target_label = currentNode.edges[i].target_label;
        if (tree[current_label].time < tree[target_label].time)
        {
            tree[target_label].parent_label = current_label;
        }

        if (tree[target_label].state == undiscovered)
        {

            dfs(graph, tree, target_label);
        }
    }
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
void test_depth_first_search()
{
    Graph<int> graph(true, 6);

    graph.insertNode({{3, 3}, {2, 1}}, 6);
    graph.insertNode({{1, 3}, {4, 1}}, 4);
    graph.insertNode({{5, 3}, {1, 1}}, 2);
    graph.insertNode({{2, 4}, {3, 1}}, 3);
    graph.insertNode({{5, 5}, {2, 1}}, 3);
    graph.insertNode({{4, 4}, {2, 1}, {0, 1}}, 3);

    std::vector<Vertex> tree;
    for (int i = 0; i < graph.nvertices; i++)
    {
        tree.push_back({undiscovered, -1, std::numeric_limits<int>::max()});
    }
    dfs(graph, tree, 2);
    traverse_tree(tree, 3);
    std::cout << "This is the depth first search test!" << std::endl;
}