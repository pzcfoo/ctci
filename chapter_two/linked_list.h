#include <iostream>
#include <memory>


template <typename T>
class Node;


namespace linked_list
{
    template <typename T>
    std::shared_ptr<Node<T>> AppendToTail(std::shared_ptr<Node<T>> n, T d)
    {
        auto new_ = std::make_shared<Node<T>>(d);
        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->next = new_;
        return new_;
    }

    template <typename T>
    void PrintLinkedList(std::shared_ptr<Node<T>> n)
    {
        std::cout << n->data << "-";
        while(n->next)
        {
            n = n->next;
            std::cout << n->data << "-";
        }
        std::cout << std::endl;
    }

    template <typename T>
    std::shared_ptr<Node<T>> Delete(std::shared_ptr<Node<T>> head, T d)
    {
        if (head->data == d)
        {
            return head->next; // could be nullptr
        }
        auto n = head;
        while (n)
        {
            if (n->next)
            {
                if (n->next->data == d)
                {
                    n->next = n->next->next;
                    break;
                }
            }
            n = n->next;
        }
        return head;
    }

    std::shared_ptr<Node<int>> MakeLinkedList(int size)
    {
        auto head = std::make_shared<Node<int>>(0);
        for (int i = 1; i < size; i++)
        {
            auto a = linked_list::AppendToTail<int>(head, i);
        }
        return head;
    }
}


template <typename T>
struct Node
{
    Node(T d)
    {
        data = d;
    };
    ~Node()
    {
        // std::cout << "Deleting Node: " << data << std::endl;
    }

    T data;
    std::shared_ptr<Node<T>> next = nullptr;
};



