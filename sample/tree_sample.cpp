#include <iostream>
#include <tree_constructor.h>

int main(int argc, char **argv)
{
    BinarySearchTree * newTree = new BinarySearchTree();

    newTree->insert(47);
    newTree->insert(21);
    newTree->insert(76);
    newTree->insert(18);
    newTree->insert(52);
    newTree->insert(82);
    newTree->insert(27);

    std::cout << newTree->contains(47) << std::endl;
    std::cout << newTree->contains(21) << std::endl;
    std::cout << newTree->contains(76) << std::endl;
    std::cout << newTree->contains(18) << std::endl;
    std::cout << newTree->contains(52) << std::endl;
    std::cout << newTree->contains(82) << std::endl;
    std::cout << newTree->contains(27) << std::endl;
    std::cout << newTree->contains(17) << std::endl;

    return 0;
}