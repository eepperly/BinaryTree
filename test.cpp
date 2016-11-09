#include "tree.h"
#include <iostream>

int main(){
  Tree<int>* my_tree = new Tree(10);
  std::cout << my_tree->getContent() << std::endl;
}
