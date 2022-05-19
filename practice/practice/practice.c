#include <stdio.h>
int main(){
	int guess;
	int answer=87;
	printf("Please enter your guess : ");
	while(1){
		scanf("%d",&guess);
		if(guess > answer){
			printf("answer is smaller than ur guess.\n");
		}
		else if(guess < answer){
			printf("answer is bigger than ur guess.\n");
		}	
		else{
			printf("You are right.");
			break;
		}
	}
	return 0;
} 
