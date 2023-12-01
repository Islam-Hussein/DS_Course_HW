#include "queuee.h"


void Queuee::enqueue(int value)
{
    list.Insert_end(value);
}

int Queuee::dequeue(void)
{
    return list.Delete_front();
}

void Queuee::display(void)
{
    list.Print_LS();
}

bool Queuee::is_empty(void)
{
    return list.size() == 0;
}
