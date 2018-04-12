#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <Node.h>



class BinarySearchTree
{
    public:
      BinarySearchTree();
      ~BinarySearchTree();
      void insert(int value);
      void print();
      void deleteNode(int value);
      void deleteHelper(Node* &current, int value);

    private:
      Node *root;
      void insertHelper(Node *current, int value);
      void printHelper(Node *current);
      void destructorHelper(Node* current);

};

#endif // BINARYSEARCHTREE_H
