#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap
{
public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
        {
            smallest = l;
        }

        if (r < heap_size && harr[r] < harr[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
        {
            return INT_MAX;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    int getMin()
    {
        return harr[0];
    }

    void getUnsortedArray()
    {
        cout << "Enter " << capacity << " no of elements to sort using Heapsort:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cin >> harr[i];
        }
        heap_size = capacity;
    }

    void heapSort()
    {
        int temp[capacity];
        for (int j = 0; j < capacity; j++)
        {
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int s;
    cout << "Enter size of min heap" << endl;
    cin >> s;
    MinHeap obj(s);
    obj.getUnsortedArray();

    cout << "Unsorted Array: " << endl;
    obj.printArray();

    for (int i = s / 2 - 1; i >= 0; i--)
    {
        obj.MinHeapify(i);
    }

    cout << "Heap sorted array: " << endl;
    obj.heapSort();

    return 0;
}