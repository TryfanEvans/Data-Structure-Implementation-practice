template <typename T>
class Node
{
public:
    Node *left = NULL;
    Node *right = NULL;
    T value;
};

template <typename T>
class BinarySearchTree
{
public:
    Node<T> root;

    BinarySearchTree(T value)
    {
        root.value = value;
    }

    void insert_node(T value)
    {
        Node<T> *node = &root;
        while (true)
        {
            if (value > node->value)
            {
                if (node->right != NULL)
                {
                    node = node->right;
                }
                else
                {
                    node->right = new Node<T>;
                    node = node->right;
                    node->value = value;
                    node->left = NULL;
                    node->right = NULL;
                    break;
                }
            }
            else if (value < node->value)
            {
                if (node->left != NULL)
                {
                    node = node->left;
                }
                else
                {
                    node->left = new Node<T>;
                    node = node->left;
                    node->value = value;
                    node->left = NULL;
                    node->right = NULL;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    void delete_node(T value)
    {
        Node<T> *node = &root;
        while (true)
        {
            if (value > node->value)
            {
                if (node->right != NULL)
                {
                    if (node->right->value == value)
                    {
                        delete node->right;
                        node->right = NULL;
                        return;
                    }
                    node = node->right;
                }
                else
                {
                    return;
                }
            }
            else if (value < node->value)
            {
                if (node->left != NULL)
                {
                    if (node->left->value == value)
                    {
                        delete node->left;
                        node->left = NULL;
                        return;
                    }
                    node = node->left;
                }
                else
                {
                    return;
                }
            }
        }
    }
    T search(T value)
    {
        Node<T> *node = root;
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
                    return -1;
                }
            }
            else if (value < node.value)
            {
                if (node.left)
                {
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return value;
            }
        }
    }

    T find_minimum()
    {
        Node<T> *node = &root;
        while (node->left)
        {
            node = node->left;
        }
        return node->value;
    }
    T find_maximum()
    {
        Node<T> *node = &root;
        while (node->right)
        {
            node = node->right;
        }
        return node->value;
    }
    void process_item(T value)
    {
        std::cout << value << std::endl;
    }
    void traverse_tree(Node<T> *node) // goes through nodes in sorted order
    {
        if (node != NULL)
        {
            traverse_tree(node->left);
            process_item(node->value);
            traverse_tree(node->right);
        }
    }
};

void test_binary_tree()
{
    std::cout << "This is the binary tree test!" << std::endl;
    BinarySearchTree<int> tree(100);
    tree.insert_node(5);
    tree.insert_node(5);
    tree.insert_node(4);
    tree.insert_node(2);
    tree.insert_node(6);
    tree.delete_node(6);
    tree.insert_node(11);
    tree.insert_node(9);
    tree.traverse_tree(&tree.root);
    std::cout << tree.find_minimum() << std::endl;
    std::cout << tree.find_maximum() << std::endl;
};