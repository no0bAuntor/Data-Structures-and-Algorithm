#include <iostream>
#define SPACE 10
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
    BST()
    {
        root = NULL;
    }
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

    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value Inserted as root node!" << endl;
        }

        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value already exist" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "value inserted to the left" << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "value inserted to the right" << endl;
                    break;
                }

                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += SPACE;
        print2D(r->right, space);

        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << " ";
        }
        cout << r->value << endl;

        print2D(r->left, space);
    }

    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
        {
            return r;
        }

        else if (val < r->value)
        {
            return recursiveSearch(r->left, val);
        }

        else
        {
            return recursiveSearch(r->right, val);
        }
    }

    int height(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }

            else
            {
                return (rheight + 1);
            }
        }
    }

    // print nodes at a given level
    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << r->value << " ";
        }
        else
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    TreeNode *iterativeSearch(int val)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (val == temp->value)
                {
                    return temp;
                }

                else if (val < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }

            return NULL; // when find nothing
        }
    }
    void printLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(r, i);
        }
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        // loop down to find the leftmost leaf
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, int v)
    {
        if (r == NULL)
        {
            return r;
        }
        // if the key to be deleted is smaller than the root's key, then it lies in left subtree
        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }
        // if the key to be deleted is greater than the root's key, then it lies in right subtree
        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }
        // if the key is same as root's key, then this is the node to be deleted
        else
        {
            // node with only one child or no child
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }

            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }

            else
            {
                // node with two children
                TreeNode *temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }
};

int main()
{
    int option, val;
    BST obj;

    do
    {
        cout << "What operation do you want to perform? Enter 0 to exit." << endl
             << endl;
        cout << "1. Insert Node " << endl;
        cout << "2. Search Node " << endl;
        cout << "3. Delete Node " << endl;
        cout << "4. Print BST value " << endl;
        cout << "5. Height of Tree " << endl;
        cout << "6. Clear Screen " << endl;
        cin >> option;
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Insert" << endl;
            cout << "Enter value of tree node to insert in BST: ";
            cin >> val;
            new_node->value = val;
            obj.insertNode(new_node);
            cout << endl;
            break;
        case 2:
            cout << "Search" << endl;
            cout << "Enter value of tree node to search: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;
        case 3:
            cout << "Delete" << endl;
            cout << "Enter value of tree node to delete: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node!=NULL)
            {
                obj.deleteNode(obj.root, val);
                cout<<"Value deleted"<<endl;
            }

            else
            {
                cout<<"Value not found"<<endl;
            }
            break;
        case 4:
            cout << "Print" << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print level order BFS:" << endl;
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
            break;
        case 5:
            cout << "Tree height: " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter valid option number" << endl;
            break;
        }
    } while (option != 0);
}
