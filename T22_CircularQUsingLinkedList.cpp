#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class CircularQueue
{
public:
    Node *front;
    Node *rear;
    CircularQueue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool checkIfNodeExist(Node *n)
    {
        if (isEmpty())
        {
            return false;
        }
        
        Node *temp = front;
        do
        {
            if (temp->key == n->key)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != front);
        return false;
    }

    void enqueue(Node *n)
    {
        if (isEmpty())
        {
            front = n;
            rear = n;
            n->next=n;
            cout << "Enqueue operation successful." << endl
                 << endl;
        }
        else if (checkIfNodeExist(n))
        {
            cout << "Enqueue operation unseccessful. Enter another key of node." << endl;
        }

        else
        {
            rear->next = n;
            rear = n;
            n->next = front;
            cout << "Enqueue operation successful." << endl
                 << endl;
        }
    }

    Node dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty. Dequeue operation unsuccessful" << endl
                 << endl;
                 return Node();
        }

        else if (rear == front)
        {
            Node *temp = front;
            rear = NULL;
            front = NULL;
            cout << "Dequeue operation successful";
            return *temp;
        }

        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            return *temp;
        }
    }

   int count()
{
    Node *temp = front;
    int count = 0;

    // If the queue is not empty, traverse and count
    if (!isEmpty()) {
        do {
            count++;
            temp = temp->next;
        } while (temp != front);
    }

    return count;
}
    void display()
    {
        Node *temp = front;

        if (isEmpty())
        {
            cout << "No node exist." << endl
                 << endl;
        }

        else
        {
            cout << "All nodes in the queue:" << endl
                 << endl;
            do
            {
                cout << "(" << temp->key << ", " << temp->data << ") -> ";
                temp = temp->next;
            } while (temp != front);
            cout << "(" << temp->key << ", " << temp->data << ")";
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    CircularQueue q;
    int option, key1, value;
    do
    {
        cout << "Which operation you want to perform? Press 0 to exit." << endl;
        cout << "1. Enqueue." << endl;
        cout << "2. Dequeue." << endl;
        cout << "3. IsEmpty." << endl;
        cout << "4. Count." << endl;
        cout << "5. Display." << endl;
        cout << "6. Clear Screen." << endl;

        Node *new_node = new Node();
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue function called." << endl;
            cout << "Enter key and value:" << endl;
            cin >> key1 >> value;
            new_node->key = key1;
            new_node->data = value;
            q.enqueue(new_node);
            break;

        case 2:
            cout << "Deque function called.";
            q.dequeue();
            break;

        case 3:
            if (q.isEmpty())
            {
                cout << "Queue is empty." << endl
                     << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;

        case 4:
            cout << "Total number of nodes in the queue are: " << q.count() << endl
                 << endl;
            break;

        case 5:
            q.display();
            break;
        case 6:
            system("cls");
            break;

        default:
            cout << "Invalid option. Enter valid option." << endl
                 << endl;
            break;
        }
    } while (option != 0);

    return 0;
}