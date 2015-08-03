/*
 * Shows how to use a call-back.  
 *
 */
 
#include <stdio.h>

/* create a callback type (function pointer) that receives two integers and return an integer*/
typedef int (*func_cb)(int a, int b);

typedef struct
{
    int num1;
    int num2;
    func_cb func;
    
}myStruct;


int add(int num1, int num2);
int multiply(int num1, int num2);

void main()
{
    myStruct st;
    int a = 1;
    int b = 2;
    st.num1 = a;
    st.num2 = b;
    st.func = multiply;

    printf(" results: %d\n", st.func(a,b));

    st.func = add;

    printf(" results: %d\n", st.func(a,b));
}


int add(int num1, int num2)
{
    return num1+num2;

}

int multiply(int num1, int num2)
{
    return num1*num2;

}
