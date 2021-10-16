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

int topOf(struct stack*p){
    assert(p !=NULL);
    assert(p->top != NULL);
    struct node*top = p->top;
    return top->info;
}

int sizeOf(struct stack* p){
    assert(p != NULL);
    return p->size;
}


bool emptyStack(struct stack*p){
    assert(p !=NULL);
    return(p->top == NULL);
}

void liberateStack(struct stack*p){
    assert( p != NULL);
    while (emptyStack(p) == false)
    {
        unStack(p);
    }
    
}

int main(){
    struct stack * my_stack = create();

    printf("\n Is empty (1-yes ; 0-no)? %d\n",emptyStack(my_stack));
        printf("Stack uping 1...\n");
        stackUp(my_stack,1);
        printf("Stack uping 2...\n");
        stackUp(my_stack,2);
        printf("Stack uping 3..");
        stackUp(my_stack,3);

    printf("\n Is empty (1-yes ; 0-no)? %d\n",emptyStack(my_stack));
    
    printf("Top = %d\n",topOf(my_stack));
    printf("Size = %d\n",sizeOf(my_stack));

    printf("Unstack the elemets : ");
    printf("%d ",unStack(my_stack));
    printf("%d ",unStack(my_stack));
    printf("%d ",unStack(my_stack));

    liberateStack(my_stack);
    return 0 ;
}