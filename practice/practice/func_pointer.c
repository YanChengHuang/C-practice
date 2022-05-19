#include <stdio.h>
#include <string.h>
void hello_2();
int main(){

    void hello();
    void (*func)() = &hello;
    func();
    return 0;
}
void hello_2(){
    
    printf("Hello world");
}

void hello(){
    hello_2();
    printf("Hello world");
}