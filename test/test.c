#include<stdio.h>
void main(void)
{
    struct A
    {
        int a;
        

    };
    
    // enum{
    //     a=0,
    //     b,
    //     c
    // };

    typedef struct A * Atype;
    Atype a;
    struct A b;
    b.a=10;
    a=&b;
    printf("%d",a->a);

}