#include "Stack/stack.h"


int main()
{


    //stack st(20);
    /*
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.display();
    */

    std::string operation = "1+2*3";

    std::string result = infixToPostfix(operation);

    std::cout << result << "\n";
    return 0;
}