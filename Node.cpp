#include "Node.h"
#include <iostream>
using namespace std;
#include <string>


Node::Node(string key1, int value) {
      left=NULL;
      right=NULL;
      data=value;
      key = key1;
}
