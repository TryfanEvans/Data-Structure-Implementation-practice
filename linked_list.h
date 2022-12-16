#include <iostream>

template <typename T>
class Node
{
public:
    Node()
    {
        value = NULL;
        next = NULL;
    }
    Node(T value, Node *next)
    {
        value = value;
        next = next;
    }
    T value;
    Node *next;
};

template <typename T>
class List
{
public:
    Node<T> *head = new Node<T>;

    T search(T target)
    {
        Node<T> node = *head;
        while (node.next != NULL)
        {
            if (node.value == target)
            {
                return target;
            }
            node = *node.next;
        }
        return -1;
    };

    void insertNode(T new_value)
    {
        if (head->value == NULL)
        {
            head->value = new_value;
        }
        else
        {
            Node<T> *testnode = new Node<T>;
            testnode->value = new_value;
            testnode->next = head;
            head = testnode;
        }
    }

    void deleteNode(T value)
    {
        Node<T> node = *head;
        if (node.value == value)
        {
            delete head;
            head = node.next;
            return;
        }
        while (node.next != NULL)
        {
            if (node.next->value == value)
            {
                Node<T> *temp = node.next;
                node.next->next = node.next;
                delete temp;
            }
            node = *node.next;
        }
    }
};

void test_linked_list()
{
    List<int> test;
    test.insertNode(12);
    test.insertNode(3);
    test.insertNode(3);
    test.insertNode(5);
    test.insertNode(1);

    std::cout << test.search(5) << std::endl;
    std::cout << test.search(4) << std::endl;

    std::cout << test.search(1) << std::endl;
    test.deleteNode(1);
    std::cout << test.search(1) << std::endl;
}