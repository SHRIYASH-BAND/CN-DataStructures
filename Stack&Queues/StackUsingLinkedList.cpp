template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class StackUsingLinkedList
{
private:
    Node<T> *head;
    int capacity;

public:
    StackUsingLinkedList()
    {
        head = nullptr;
        capacity = 0;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    int size()
    {
        return capacity;
    }

    void push(T ele)
    {

        Node<T> *t = new Node<T>(ele);
        t->next = head;
        head = t;
        capacity++;
    }

    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        capacity--;
        delete temp;
        return ans;
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};
