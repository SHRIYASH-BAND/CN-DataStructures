#include <iostream>
using namespace std;
template <typename T>
class QueueUsingArray
{
private:
    T *data;
    int firstIndex;
    int lastIndex;
    int size;
    int arraySize;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        firstIndex = -1;
        lastIndex = 0;
        size = 0;
        arraySize = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    // insert
    void enqueue(T ele)
    {
        if (size == arraySize)
        {
            T *newData = new T[arraySize * 2];
            int k = 0;
            newData[k++] = data[firstIndex];
            for (int i = firstIndex + 1; i != lastIndex; i = (i + 1) % arraySize)
            {
                newData[k] = data[i];
                k++;
            }

            delete[] data;
            data = newData;
            firstIndex = 0;
            lastIndex = arraySize;
            arraySize = arraySize * 2;
        }

        data[lastIndex] = ele;
        lastIndex = (lastIndex + 1) % arraySize;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }

        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue Empty !" << endl;
            return 0;
        }

        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty !" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        // lastIndex = arraySize - lastIndex
        firstIndex = (firstIndex + 1) % arraySize;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            lastIndex = 0;
        }

        return ans;
    }
};
