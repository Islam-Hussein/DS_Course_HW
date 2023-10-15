#include "Stack/stack.h"


int main()
{

    stack st(20);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.display();

    return 0;
}