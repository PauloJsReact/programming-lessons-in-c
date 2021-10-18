#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

struct Node {
    int info;
    struct Node*next;
};

struct Queue{
    struct Node*initial;
    struct Node*end;
    int size;
};

struct Queue*Create(){
    struct  Queue*new_queue = (struct Qeue*)malloc(sizeof(struct Queue));

    if(new_queue != NULL){
        new_queue->initial=NULL;
        new_queue->end=NULL;
        new_queue->size=0;
    }
    return new_queue;
}

void queueCreate(struct Queue*f,int item){
    assert(f !=NULL);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct  Node));

    if(new_node != NULL){
        new_node->info=item;
        new_node->next=NULL;
    

    if(f->end != NULL){
        f->end->next=new_node;
    }else
    {
        f->initial=new_node;
    }
    f->end=new_node;
    f->size++;
  }
}

int unQueue(struct Queue*f){
    assert(f !=NULL);
    assert(f->initial !=NULL);
    struct Node*aux = f->initial;

    int element = aux->info;
    f->initial=aux->next;

    if(f->initial == NULL){
        f->end=NULL;
    }
    f->size--;
    free(aux);

    return element;
}

bool emptyQueue(struct Queue*f){
    assert(f !=NULL);
    return (f->initial == NULL);
}

int sizeOf(struct Queue*f){
    assert(f !=NULL);
    return f->size;
};

int Start(struct Queue*f){
    assert(f != NULL);
    assert(f->initial != NULL);
    return f->initial->info;
};

void liberate(struct Queue*f){
    assert(f != NULL);
    while (f->initial != NULL)
    {
        unQueue(f);
    }
    free(f);
};

int main(){
    struct Queue*my_queue = Create();
    queueCreate(my_queue, 1);
    queueCreate(my_queue, 2);
    queueCreate(my_queue, 3);
    printf("Size : %d ",sizeof(my_queue));

    printf("\nMy queue : [%d",unQueue(my_queue));
    printf("%d",unQueue(my_queue));
    printf("%d]",unQueue(my_queue));

    printf("\nThe queue is empty (1-yes,0-no)? %d ",emptyQueue(my_queue));

    liberate(my_queue);

    return 0;
}