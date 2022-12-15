template <typename T>
class Node
{
public:
    Node *left;
    Node *right;
    T value;
};

template <typename T>
class BinarySearchTree
{
public:
    Node<T> root;

    insert(T value)
    {
        Node<T> = root;
        while (true)
        {
            if (value > node.value)
            {
                if (node.right)
                {
                    node = node.right;
                }
                else
                {
                    node.right = new Node<T>;
                    node.value = value;
                }
            }
            else if (value < node.value)
            {
                if (node.left)
                {
                    node = node.left;
                }
                else
                {
                    node.left = new Node<T>;
                    node.value = value;
                }
            }
            else
            {
            }
        }
    }
};

void test_binary_tree()
{
    std::cout << "This is the binary tree test!" << std::endl;
};