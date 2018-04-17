/*
 * Name: Drew Presson
 * Date: 04/10/18
 * File: BinarySearchTree.cpp
 * Description:  binary search tree class implementations
 */
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <fstream>
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
  if(key < current->key) {
    //Insert Left
    if(current->left == NULL)
      current->left = new Node(key,value);
    else
      insertHelper(current->left, key, value);
  }
  else {
    //Insert Right
    if(current->right == NULL)
      current->right = new Node(key, value);
    else
      insertHelper(current->right, key, value);
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
    cout << current->key << " ";
    printHelper(current->right);
  }
}

void BinarySearchTree::save(string inFile){

    ofstream myOutFile;
    myOutFile.open(inFile.c_str());

    saveHelper(root, myOutFile);
    myOutFile.close();
}

void BinarySearchTree::saveHelper(Node *current, std::ofstream& myOutFile){

    if(current != NULL){
        saveHelper(current->left,myOutFile);
        myOutFile << current->key << " " << current ->data << endl;
        saveHelper(current->right, myOutFile);
    }
}

string BinarySearchTree::min(){

    if(root == NULL){
        return "NO MIN";
    }
    Node *current = root;
    if ((current->left == NULL)&&(current->right==NULL)){
        return current->key;
    }
    while(current->left != NULL){
        current = current->left;
    }
    return current->key;
}

string BinarySearchTree::max(){

    if(root == NULL){
        return "NO MAX";
    }
    Node *current = root;
    if ((current->left == NULL)&&(current->right==NULL)){
        return current->key;
    }
    while(current->right != NULL){
        current = current->right;
    }
    return current->key;
}

//searches the bst using a Word to search for.
void BinarySearchTree::find(string Word){
    findHelper(root,Word);
}

void BinarySearchTree::findHelper(Node* &current,string Word){
    if(current == NULL)
        return;
    else if( Word < current->key)
        findHelper(current->left,Word);
    else if(current->key < Word)
        findHelper(current->right,Word);
    cout << "The string " << Word << " has the value of " << current->data << endl;
        return;

}

void BinarySearchTree::deleteNode(string key) {
  deleteHelper(root, key);
}

//need to add the string as the criteria for search
void BinarySearchTree::deleteHelper(Node* &current, string key) {
  //Node doesn't exist
  if(current == NULL)
    return;
  //Go left
  else if(key < current->key)
    deleteHelper(current->left, key);
  //Go right
  else if(current->key < key)
    deleteHelper(current->right, key);
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

      current->key = temp->key;

      if(parent != NULL)
	deleteHelper(parent->left,parent->left->key);
      else
	deleteHelper(current->right, current->right->key);

    }//else
  }//else
}//deleteHelper
