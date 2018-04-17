#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <Node.h>



class BinarySearchTree
{
    public:
      BinarySearchTree();
      ~BinarySearchTree();
      void insert(string key, int value);
      void print();
      void deleteNode(string key);
      void deleteHelper(Node* &current, string key);
      void find(string Word);
      void findHelper (Node* &current,string Word);
      string min();
      string max();

    private:
      Node *root;
      void insertHelper(Node *current, string key, int value);
      void printHelper(Node *current);
      void destructorHelper(Node* current);

};

#endif // BINARYSEARCHTREE_H
