#include <iostream>
#include <BinarySearchTree.h>
#include <string>


using namespace std;

int main()
{

    BinarySearchTree tree;

    tree.insert("The",6);
    tree.insert("times",7);
    tree.insert("best",2);
    tree.insert("of",4);

    string max = tree.max();
    string min = tree.min();
    cout <<"Max: " <<  max << endl;
    cout << "Min: " << min << endl;

    tree.print();
    tree.deleteNode("best");
    cout << endl << endl;

    tree.find("best");



    tree.print();


    return 0;
}
