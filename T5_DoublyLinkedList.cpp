#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    // 1. Check if node exists using key value
    Node *NodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. Append a node to the list
    void appendNode(Node *n)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as head node\n\n";
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node appended\n\n";
            }
        }
    }

    // 3. prepend node- attach a node at the start
    void prependNode(Node *n)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Append another node with different key value\n\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node prepended as head node\n\n";
            }
            else
            {

                head->previous = n;
                n->next = head;
                head = n;
                cout << "Node prepended\n\n";
            }
        }
    }

    // 4.  Insert a node after a particular node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl
                 << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "node already exist with key value : " << n->key << ". Append another node with different key value\n\n";
            }
            else
            {

                Node *nextNode = ptr->next;
                // appending at the end
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node Inserted at the END\n\n";
                }
                // insering in between
                else
                {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between\n\n";
                }
            }
        }
    }

    // 5. Delete node by unique key. Basically De-Link not delete
    void deleteNodeByKey(int k)
    {
        Node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value\n\n";
        }
        else
        {
            if (head == NULL)
            {
                cout << "Doubly Linked List Already Empty. Can't Delete\n\n";
            }
            else if (head != NULL)
            {
                if (head->key == k)
                {
                    head = head->next;
                    cout << "Node unlinked with keys value : " << k << endl
                         << endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode = ptr->previous;
                    // deleting at the end
                    if (nextNode == NULL)
                    {
                        prevNode->next = NULL;
                        cout << "Node deleted at the END";
                    }

                    // deleting in between
                    else
                    {
                        prevNode->next = nextNode;
                        nextNode->previous = prevNode;
                        cout << "Node deleted in between\n\n";
                    }
                }
            }
        }
    }

    // 6. update node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = NodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data update successfully" << endl;
        }
        else
        {
            cout << "Node doesn't exist key value : " << k << endl;
        }
    }

    // 7. printing

    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in the doubly linked list.";
        }
        else
        {
            cout << endl
                 << "Doubly Linked List values : ";
            Node *temp = head;

            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ")<--> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. enter 0 to exit.\n";
        cout << "1. appendNide()\n";
        cout << "2. prependNode()\n";
        cout << "3. insertNodeAfter()\n";
        cout << "4. deleteNodeByKey()\n";
        cout << "5. updateNodeByKey()\n";
        cout << "6. print()\n";
        cout << "7. Clear Screen\n\n\n";

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Append node operation\nEnter key & data of the node to be appended\n";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendNode(n1);
            break;

        case 2:
            cout << "Prepend node operation\nEnter key & data of the node to be prepended\n";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Inser node after operation \nEnter key of existing node after which you want to insert this new node:  " << endl;
            cin >> k1;
            cout << "Enter key & data of the new node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout << "Delete node by key operation - \nEnter key of the node to be deleted: " << endl;
            cin >> k1;
            obj.deleteNodeByKey(k1);
            break;

        case 5:
            cout << "Update node by key operation - \nEnter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNodeByKey(key1, data1);
            break;

        case 6:
            obj.printList();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter proper option number" << endl;
        }
    } while (option != 0);

    return 0;
}
