#include<stdio.h>
int _assert(int result)
{
   if(result)
   { 
      printf("PASS\n");
      return 0;
   }
   else 
   {
      printf("FAIL\n");
      return 1;
   }
}
