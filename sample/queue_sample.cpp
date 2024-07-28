#include "queue.h"


int main()
{
    Queue * newQueue = new Queue(1);
    newQueue->enqueue(2);
    newQueue->enqueue(3);
    newQueue->printQueue();

    std::cout << "--------- After Dequeue ---------" << std::endl;
    newQueue->dequeue();
    // newQueue->dequeue();
    
    newQueue->printQueue();
    std::cout <<"first: " << newQueue->getFirst()->getValue() << std::endl;    
    std::cout <<"last: " << newQueue->getLast()->getValue() << std::endl;
    std::cout <<"Length: " << newQueue->getLength() << std::endl;

    return 0;
}