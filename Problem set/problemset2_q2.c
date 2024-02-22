# include <stdio.h>
int main()
{
   int i=0;
   for(i=2; i<20; i++)
   {
     switch(i)
     {
       case 2:
         {i+=5;
         printf("%d  ", i);}
       case 12:
         {i+=2;
         printf("%d  ", i);}
       case 5:
         {i-=3;
         printf("%d  ", i);}
       default:              
         i+=5;
         printf("%d  ", i);
         break;
     }
     printf("%d  ", i);
   }
//    switch 後面沒有 break ， 會把 true case 後面的 case 全部執行過
   getchar();
   return 0;
}  