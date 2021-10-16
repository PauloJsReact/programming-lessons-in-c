#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node
{
    int info;
    struct node * next;  
};


struct stack
{
    struct node * top;
    int size ;
};

struct stack*create(){
    struct stack * new_stack = (struct stack*) malloc(sizeof(struct stack));

    if (new_stack !=NULL)
    {
        new_stack ->top = NULL;
        new_stack->size = 0;
    }
    return new_stack;
}

void stackUp(struct stack* s,int item){
    assert(s != NULL);
    struct node * new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node != NULL)
    {
        new_node->info=item;
        new_node->next=s->top;
        s->top=new_node;
        s->size++;
    }
}

int unStack(struct stack* s){
    assert(s !=  NULL);
    assert(s->top != NULL);
    struct node * aux = s->top;
    int element =  aux->info;
    s->top = aux->next;
    s->size -- ;
    free(aux);
    return element;
}


int main(){
    struct stack * my_stack = create();
    stackUp(my_stack,1);
    stackUp(my_stack,2);
    stackUp(my_stack,3);

    printf("%d ",unStack(my_stack));
    printf("%d ",unStack(my_stack));
    printf("%d ",unStack(my_stack));

    return 0 ;
}