#include <stdio.h>

void foo()
{
    inside_foo:
        printf("PP");
    }
    
int main()
{
    int i = 0;
    while (i <= 4)
    {
       printf("%d", i);
       if (i > 3)
        goto inside_foo;
       i++;
    } 
    
    getchar();
    return 0;
}
 
