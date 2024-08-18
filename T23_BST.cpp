#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int option;
    BST obj;
    do
    {
        cout << "What operation do you want to perform? Enter 0 to exit." << endl
             << endl;
        cout << "1. Insert Node " << endl;
        cout << "2. Search Node " << endl;
        cout << "3. Delete Node " << endl;
        cout << "4. Print BST value " << endl;
        cout << "5. Clear Screen " << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Insert" << endl;
            break;
        case 2:
            cout << "Search" << endl;
            break;
        case 3:
            cout << "Delete" << endl;
            break;
        case 4:
            cout << "Print" << endl;
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Enter valid option number" << endl;
            break;
        }
    } while (option != 0);
}