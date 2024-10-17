#include <iostream>
#include <math.h>
using namespace std;

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
            // obj.insertKey(val);
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
            // obj.deleteKey(val);
            break;

        case 4:
            cout << "Get min value: ";
            // cout<<obj.getMin()<<endl;
            cout << endl;
            break;

        case 5:
            cout << "Extract Min value: ";
            // cout<<obj.extractMin()<<endl;
            cout << endl;
            break;
        case 6:
            cout << "Heap tree height: ";
            // cout<<obj.height()<<endl;
            break;

        case 7:
            cout << "Print heap array: " << endl;
            // obj.printArray();
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