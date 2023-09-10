#include "Singly_LinkedList/Single_LS.h"

using namespace std;


int main()
{
    LinkedList Ls;
    Ls.Insert_end(10);
    Ls.Insert_end(20);
    Ls.Insert_end(30);
    Ls.Insert_end(30);
    Ls.Insert_end(30);
    Ls.Insert_end(40);
    Ls.Insert_end(50);

    Ls.Insert_front(100);

    Ls.Insert_front(200);

    Ls.delete_with_key(30);
    //Ls.Delete_front();
    
    Ls.Print_LS();

    //cout << (Ls.get_nth(2))->data << endl;

    return 0;
} 