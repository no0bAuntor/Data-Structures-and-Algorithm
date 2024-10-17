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

    void linearSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == val)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value not found";
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }

    int parent(int i)
    {
        return ceil(i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "\nOverflow" << endl;
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
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

    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i=parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main()
{
    int s;
    cout << "Enter size of Min Heap" << endl;
    cin >> s;
    MinHeap obj(s);
    cout << "Min Heap Created" << endl;

    int option, val;
    do
    {
        cout << "What operation do you want to perform?" << endl
             << "Select operation number. Enter 0 to exit" << endl;
        cout << "1. Insert key/node/vale" << endl;
        cout << "2. Search key/node" << endl;
        cout << "3. Delete key/node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap value" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit program" << endl;

        cin >> option;
        switch (option)
        {
        case 0:

            break;
        case 1:
            cout << "Insert operation" << endl;
            cout << "Enter value to insert:" << endl;
            cin >> val;
            obj.insertKey(val);
            cout << endl;
            break;
        case 2:
            cout << "Search operation" << endl;
            cout << "Enter value to search in heap:" << endl;
            cin >> val;
            // obj.linearSearch(val);
            break;
        case 3:
            cout << "Delete operation" << endl;
            cout << "Enter index of heap array to delete:" << endl;
            cin >> val;
            obj.deleteKey(val);
            break;

        case 4:
            cout << "Get min value: ";
            cout << obj.getMin() << endl;
            cout << endl;
            break;

        case 5:
            cout << "Extract Min value: ";
            cout << obj.extractMin() << endl;
            cout << endl;
            break;
        case 6:
            cout << "Heap tree height: ";
            // cout<<obj.height()<<endl;
            break;

        case 7:
            cout << "Print heap array: " << endl;
            obj.printArray();
            break;
        case 8:
            system("cls");
            break;
        default:
            cout << "Enter valid option number" << endl;
            break;
        }
    } while (option != 0);
}