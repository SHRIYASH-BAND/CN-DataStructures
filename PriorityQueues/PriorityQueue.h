#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    void print()
    {
        cout << "Array Representation of Min-Heap \n";
        for (int i = 0; i < this->getSize(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (!isEmpty())
            return pq.at(0);
        return INT_MAX;
    }

    void upHeapify()
    {
        int childIndex = this->getSize() - 1;
        int parentIndex = (childIndex - 1) / 2;
        while (childIndex > 0 && pq[parentIndex] > pq[childIndex])
        {
            swap(pq[parentIndex], pq[childIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    void insert_MinHeap(int ele)
    {
        pq.push_back(ele);
        // UP-Heapify
        this->upHeapify();
    }

    void downHeapify()
    {
        int rootIndex = 0;
        int child1Index = 2 * rootIndex + 1;
        int child2Index = child1Index + 1;

        while (child2Index < this->getSize() && pq[rootIndex] > pq[child1Index] && pq[rootIndex] > pq[child2Index])
        {
            if (pq[child1Index] < pq[child2Index])
            {
                swap(pq[child1Index], pq[rootIndex]);
                rootIndex = child1Index;
            }
            else
            {
                swap(pq[child2Index], pq[rootIndex]);
                rootIndex = child2Index;
            }
            child1Index = 2 * rootIndex + 1;
            child2Index = child1Index + 1;
        }

        if (child1Index < this->getSize() && pq[rootIndex] > pq[child1Index])
        {
            swap(pq[child1Index], pq[rootIndex]);
        }
    }

    void removeMin()
    {
        pq[0] = pq[this->getSize() - 1];
        pq.pop_back();
        // Down-Heapify
        this->downHeapify();
    }

    void insert_MaxHeap(int element)
    {
        pq.push_back(element);
        // up-heapify
        int childIndex = getSize() - 1;
        int parentIndex = (childIndex - 1) / 2;
        while (childIndex > 0 && pq[parentIndex] < pq[childIndex])
        {
            swap(pq[parentIndex], pq[childIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    int getMax()
    {
        if (isEmpty())
            return INT_MIN;
        return pq[0];
    }

    int removeMax()
    {
        if (isEmpty())
            return 0;
        int max = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (parentIndex < pq.size())
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int maxIndex;
            if (leftChildIndex < pq.size() && rightChildIndex < pq.size())
                maxIndex = (pq[leftChildIndex] >= pq[rightChildIndex])
                               ? leftChildIndex
                               : rightChildIndex;
            else if (leftChildIndex < pq.size())
                maxIndex = leftChildIndex;
            else
                break;
            if (pq[maxIndex] > pq[parentIndex])
            {
                int temp = pq[maxIndex];
                pq[maxIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            parentIndex = maxIndex;
        }
        return max;
    }
};
