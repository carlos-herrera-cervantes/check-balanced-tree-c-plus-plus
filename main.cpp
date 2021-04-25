#include "binarySearchTree.cpp"

int main()
{
    BinarySearchTree binarySearchTree;

    binarySearchTree.insert(2);
    binarySearchTree.insert(1);
    binarySearchTree.insert(4);

    bool isBalanced = binarySearchTree.isBalanced();

    if (isBalanced)
    {
        cout << "The binary tree is balanced";
    }
    else
    {
        cout << "The binary tree is not balanced";
    }

    return 0;
}