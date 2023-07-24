#include <iostream>
#include <climits>
using namespace std;
#include "StackUsingArray.cpp"
#include "StackUsingLinkedList.cpp"

int main()
{
    cout << "stack using array\n";
    StackUsingArray<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    cout << "stack using LL\n";
    StackUsingLinkedList<char> l1;
    l1.push(100);
    l1.push(101);
    l1.push(102);
    l1.push(103);
    l1.push(104);

    cout << l1.top() << endl;
    cout << l1.pop() << endl;
    cout << l1.pop() << endl;
    cout << l1.pop() << endl;
    cout << l1.size() << endl;
    cout << l1.isEmpty() << endl;

    return 0;
}