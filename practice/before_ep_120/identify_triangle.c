#include <stdio.h>

int main() {
    int input1,input2,input3;
    int old_number;
    printf("please enter the numbers: ");
    scanf("%d %d %d", &input1, &input2, &input3);
    //排序 Input 1,2,3
    if(input2 < input1){
        old_number = input2;
        input2 = input1;
        input1 = old_number;
    }
    if(input3 < input1){
        old_number = input3;
        input3 = input1;
        input1 = old_number;
    }
    if(input3 < input2){
        old_number = input3;
        input3 = input2;
        input2 = old_number;
    }
    printf("smallest = %d, middle = %d, biggest = %d\n",input1 ,input2 ,input3);
//    分辨三角形種類
        if((input1*input1 + input2*input2 == input3*input3))
            printf("It's a rectangular triangle!");

        else if((input1 == input2) && (input2 == input3))
            printf("It's a regular triangle!");

        else if((input1 == input2) || (input2 == input3))
            printf("It's a isoceles triangle!");

        else
            printf("It's nothing!");


    return 0;
}
