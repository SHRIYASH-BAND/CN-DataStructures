#include <iostream>
#include "QueueUsingArray.h"
#include "QueueUsingLL.h"
using namespace std;

int main()
{
    cout << "Queue using Array\n";

    QueueUsingArray<char> q(5);
    q.enqueue(100);
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

    cout << "Queue using LL\n";

    QueueUsingLL<char> q1;
    q1.enqueue(100);
    q1.enqueue(101);
    q1.enqueue(102);
    q1.enqueue(103);
    q1.enqueue(104);
    q1.enqueue(105);
    q1.enqueue(106);
    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;

    cout << q1.getSize() << endl;
    cout << q1.isEmpty() << endl;

    return 0;
}