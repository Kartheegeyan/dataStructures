#include "stack.h"

int main()
{
    Stack newStack(1);
    newStack.push(2);
    newStack.push(3);

    std::cout << "Popped Value: " << newStack.pop() << std::endl;
    std::cout << "Popped Value: " << newStack.pop() << std::endl;

    newStack.printStack();
    std::cout << "Top: " << newStack.getTop() << std::endl;
    std::cout << "Height: " << newStack.getHeight() << std::endl;
    // Stack stack1; Can be created using the other constructor definition
    return 0;
}