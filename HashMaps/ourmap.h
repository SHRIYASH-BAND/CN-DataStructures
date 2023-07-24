#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{

    getBucketsIndex(string key)
    {
        int hashCode = 0;

        int currCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currCoeff;
            hashCode %= numBuckets;
            currCoeff *= 37;
            currCoeff %= numBuckets;
        }

        return hashCode % numBuckets;
    }

public:
    MapNode<V> **buckets;
    int count = 0;
    int numBuckets;

    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }

        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketsIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    double getLoadFactor()
    {
        return (1.000 * count) / numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];

        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }

        int oldBucketsCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for (int i = 0; i < oldBucketsCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketsCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    void insert(string key, V value)
    {

        int bucketIndex = getBucketsIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.000 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketsIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {

            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                head->next = NULL;
                V ans = head->value;
                delete head;
                count--;
                return ans;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }
};