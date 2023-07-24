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
class QueueUsingLL
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << " Queue Empty !" << endl;
            return 0;
        }
        return head->data;
    }

    void enqueue(T ele)
    {
        if (head == nullptr)
        {
            head = new Node<T>(ele);
            tail = head;
            size++;
            return;
        }
        tail->next = new Node<T>(ele);
        tail = tail->next;
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << " Queue Empty !" << endl;
            return 0;
        }
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }
};
