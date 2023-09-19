#include "Singly_LinkedList/Single_LS.h"

using namespace std;


int main()
{
    LinkedList Ls;
    Ls.Insert_end(10);
    Ls.Insert_end(20);
    Ls.Insert_end(30);
    Ls.Insert_end(40);
    Ls.Insert_end(50);
    Ls.Insert_end(60);

    //Ls.Delete_front();
    
    Ls.Print_LS();

    //cout << "After deletion the last Node. \n";
    //Ls.delete_last_node();
    //Ls.Print_LS();

    Ls.swap_pairs();
    Ls.Print_LS();

    cout << "After Reverse. \n";
    Ls.reverse();
    Ls.Print_LS();

    cout << "After Deletion of Even Nodes. \n";
    Ls.delete_even_positions();
    

    Ls.Print_LS();


    //cout << (Ls.get_nth(2))->data << endl;

    return 0;
} 