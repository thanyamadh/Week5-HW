#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv)
{
  int i,j,check=0,check2=0;
   STACK s;
   s.top=NULL;
   s.size=0;
   
   printf("Checking the parenteses in argv arguments\n");
   for(i=1;i<argc;i++)
   {
     for(j=0; j<strlen(argv[i]); j++)
     {
       switch(argv[i][j])
       {
         case '{' : 
          if(check2==0)
            push_s(&s,argv[i][j]);
          break;
         case '[' :
          if(check2==0)
            push_s(&s,argv[i][j]);
          break;
         case ']' :
          if(s.size!=0 && s.top->data=='[')
            pop_s(&s);
          else if(s.size!=0)
          {
            pop_s(&s);
            check++;
          }
          else if (s.size==0)
            check2++;
          else
          check++;
          break;
         case '}' :
          if(s.size!=0 && s.top->data=='{')
            pop_s(&s);
          else if(s.size!=0)
          {
            pop_s(&s);
            check++;
          }
          else if (s.size==0)
            check2++;
          else
          check++;
          break;
       }
     }
     
     if (s.size == 0 && check == 0 && check2==0) 
     {
      printf("The parantheses match successfully for %s\n", argv[i]);
     } 
     else 
     {
      printf("The parantheses do not match for %s\n", argv[i]);
     }
     while(s.size>0)
     {
       printf("Popping %c \n",s.top->data);
       pop_s(&s);
     }
     check=0;
     check2=0;
   }
}