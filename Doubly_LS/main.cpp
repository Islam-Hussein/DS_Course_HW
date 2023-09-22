#include "Doubly_LS/doubly_LS.h"

using namespace std;

int main()
{

    LinkedList Ls;

    Ls.insert_front(10);
    Ls.insert_front(20);
    Ls.insert_front(30);
    Ls.insert_front(20);
    Ls.insert_front(10);
    /*
    Ls.insert_front(40);
    Ls.insert_front(50);
    Ls.insert_front(60);
    */

    Ls.print();

    /*
    Ls.delete_even_nodes();
    std::cout << "After deletion of even nodes.\n";
    Ls.print();
    */
    
    /*
    Ls.delete_odd_nodes();
    std::cout << "After deletion of odd nodes.\n";
    Ls.print();
    */
    //Ls.delete_all_nodes_with_key(40);
    //std::cout << "After deletion of All values : 40.\n";
    //Ls.print();

    Ls.print_length();
    bool palindrome = Ls.is_palindrome();
    std::cout << "Is this Linked List Palindrome : " << palindrome << "\n";


}