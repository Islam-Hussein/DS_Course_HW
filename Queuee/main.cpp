#include "queuee/queuee.h"

using namespace std;

int main()
{

    Queuee q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.display();


    q.dequeue();
    q.dequeue();

    q.display();




    return 0;
}