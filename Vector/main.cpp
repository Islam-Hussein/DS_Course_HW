#include "vector/vector.h"

using namespace std;


int main()
{
    Vector vec(10);

    for(int i = 0 ; i < 10 ; ++i)
    {
        vec.set(i , i);
    }


    //vec.insert(5 , 50);



    cout << "Before rotation \n";
    vec.print();

    cout << "Rotate right 3 times\n";
    vec.right_rotation_with_steps(3);
    vec.print();

    cout << "Rotate left 3 times\n";
    vec.left_rotation_with_steps(3);
    vec.print();


    cout << "after popping index 3\n";
    cout << "third element = " << vec.pop(3) << "\n";
    vec.print();

    cout << "find_transposition value 7\n";
    cout << "Index of value 7 after transposition : " << vec.find_transposition(7) << "\n";
    vec.print();

    //cout << "after right rotation \n";
    //vec.right_rotation();
    //vec.print();

    //cout << "after left rotation \n";
    //vec.left_rotation();
    //vec.print();    
    //cout << vec.find(5) << " " << vec.find(55);
 
    return 0;
} 