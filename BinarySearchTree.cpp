#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;


BinarySearchTree::BinarySearchTree() {
  root = NULL;
}


BinarySearchTree::~BinarySearchTree() {
  destructorHelper(root);
}

void BinarySearchTree::destructorHelper(Node *current) {
  if(current != NULL) {
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current;
  }
}

void BinarySearchTree::insert(string key, int value) {
  if(root == NULL)
    root = new Node(key,value);
  else
    insertHelper(root, key, value);
}


void BinarySearchTree::insertHelper(Node *current, string key, int value) {
  if(value < current->data) {
    //Insert Left
    if(current->left == NULL)
      current->left = new Node(value);
    else
      insertHelper(current->left, value);
  }
  else {
    //Insert Right
    if(current->right == NULL)
      current->right = new Node(value);
    else
      insertHelper(current->right, value);
  }

}


void BinarySearchTree::print() {
  printHelper(root);
  cout << endl;
}


void BinarySearchTree::printHelper(Node *current) {
  // In-order traversal.
  if(current != NULL) {
    printHelper(current->left);
    cout << current->data << " ";
    printHelper(current->right);
  }
}





void BinarySearchTree::deleteNode(string key, int value) {
  deleteHelper(root, key,  value);
}

//need to add the string as the criteria for search
void BinarySearchTree::deleteHelper(Node* &current, string key, int value) {
  //Node doesn't exist
  if(current == NULL)
    return;
  //Go left
  else if(value < current->data)
    deleteHelper(current->left, value);
  //Go right
  else if(current->data < value)
    deleteHelper(current->right, value);
  //Equal
  else {
    Node *temp;

    if(current->left == NULL) {
      temp = current->right;
      delete current;
      current = temp;
    }
    else if(current->right == NULL) {
      temp = current->left;
      delete current;
      current = temp;
    }
    //2 children
    else {
      temp = current->right;
      Node *parent = NULL;

      while(temp->left != NULL) {
	parent = temp;
	temp = temp->left;
      }

      current->data = temp->data;

      if(parent != NULL)
	deleteHelper(parent->left, parent->left->data);
      else
	deleteHelper(current->right, current->right->data);

    }//else
  }//else
}//deleteHelper
