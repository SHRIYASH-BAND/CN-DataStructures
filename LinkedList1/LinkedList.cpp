#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* createLinkedList()
{
    int data;
    cout << "Enter Node Data";
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        cout << "\n Enter Node Data";
        cin >> data;
    }

    return head;
}

int main()
{
    Node *head = createLinkedList();

    return 0;
}