template <typename T>

class StackUsingArray
{
private:
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    int size()
    {
        return this->nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int ele)
    {
        // dynamic stack
        if (capacity == nextIndex)
        {
            T *newData = new T[capacity * 2];

            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];

            delete[] data;
            data = newData;
            capacity *= 2;
        }

        this->data[this->nextIndex] = ele;
        this->nextIndex++;
    }

    T pop()
    {

        if (isEmpty())
        {
            cout << "Stack Empty " << endl;
            return 0;
        }
        return data[--nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty " << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};