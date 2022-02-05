#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
  char data;
  struct node * nextPtr;
}Node;
typedef Node *NodePtr;

struct stack
{
  NodePtr top;
  int size;
};
typedef struct stack STACK;

int push_s(STACK *s, int x)
{
  Node *new_node=(NodePtr)malloc(sizeof(Node));
  if(new_node)
  {
	  new_node->data=x;
 	  new_node-> nextPtr=s->top;
    s->top=new_node;
    s->size++;
  }
  return x;
}

void pop_s(STACK *s)
{
 	NodePtr t = s->top;
	int value;		
	t= s->top;
  if(t)
  {
		value=t->data;
	  s->top=t->nextPtr;
	  free(t);
    s->size--; 			
  }
}