/*
 * Name: Drew Presson
 * Date: 04/10/18
 * File: main.cpp
 * Description:  main driver
 */
#include <iostream>
#include <BinarySearchTree.h>
#include <string>


using namespace std;

int main()
{

    BinarySearchTree tree;

    bool done = false;
    int choice;
    while (done != true){
//populates tree
    tree.insert("The",6);
    tree.insert("times",7);
    tree.insert("best",2);
    tree.insert("of",4);

    cout << "1. Set to the BST" << endl << "2. Find" << endl << "3. Print " << endl << "4. Min" << endl << "5. Max" << endl << "6. Save "  << "7. Delete" << endl;
    cin >> choice;
    cout << endl;
//menu driven by choice
    if (choice == 1){
            string key;
            int value;
                cout << "Enter key";
                cin >> key;
                cout << "Enter value";
                cin >> value;
                tree.insert(key, value);
    }

    if(choice == 2){
        string word;
        cout << "Enter word to find" << endl;
        cin >> word;
        tree.find(word);
    }
    if(choice == 3){
        tree.print();
    }
    if(choice == 4){
        string max = tree.max();
        cout <<"Max: " <<  max << endl;
    }
    if(choice == 5){
        string min = tree.min();
        cout << "Min: " << min << endl;

    }
    if(choice == 6){
            string filesavename;
            cout << "Enter file save name" << endl;
        cin >> filesavename;
        tree.save(filesavename);
    }
    if(choice == 7){
        string key;
        cout << "Enter the key of node you want to delete!" << endl;
        cin >> key;
        tree.deleteNode(key);
    }
    //sets program to done
    else
        done == true;

    }

    return 0;
}
