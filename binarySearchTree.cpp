#include <iostream>
#include "treeNode.cpp"

using namespace std;

class BinarySearchTree
{

    Node *root;
    int length;

    /**
     * Prints the elements
     * @param node Node object class
     * @returns Void
    */
    void inorder(Node *node)
    {
        if (!node)
            return;

        cout << node->data << ": ";

        if (node->left)
            cout << "L" << node->left->data << " ";
        if (node->rigth)
            cout << "R" << node->rigth->data << " ";

        cout << endl;

        inorder(node->left);
        inorder(node->rigth);
    }

    /** Inserts a new node
     * @param node Node object class
     * @param value Number value
     * @returns Node object class
    */
    Node* insert(Node* node, int value)
    {
        if (!node)
        {
            node = new Node();
            node->data = value;
            node->left = node->rigth = NULL;
        }
        else if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->rigth = insert(node->rigth, value);
        }

        return node;
    }

    /**
     * Counts the number of levels in the binary search tree
     * @param node Node object class
     * @returns Integer
    */
    int checkLevels(Node* node)
    {
        if (node == NULL) return -1;

        int leftHeight = checkLevels(node->left);
        if (leftHeight == INT_MIN) return INT_MIN;

        int rightHeight = checkLevels(node->rigth);
        if (rightHeight == INT_MIN) return INT_MIN;

        int heightDiff = leftHeight - rightHeight;

        if (abs(heightDiff) > 1)
        {
            return INT_MIN;
        }
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    public:

        BinarySearchTree()
        {
            root = NULL;
            length = 0;
        }

        /**
         * Prints the elements to the console
         * @returns Void
         */
        void print()
        {
            inorder(root);
            cout << endl;
        }

        /**
         * Inserts a new value
         * @param data Number value
         * @returns Void
         */
        void insert(int data)
        {
            root = insert(root, data);
            length++;
        }

        /**
         * Checks if the binary search tree is balanced
         * @returns If it is balanced returns true otherwise false
         */
        bool isBalanced()
        {
            return checkLevels(root) != INT_MIN;
        }
};