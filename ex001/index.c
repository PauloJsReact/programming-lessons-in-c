#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct node
{
    int info;
    struct node*next;
};

struct list{
    struct node *beginning;
    int size;
};
struct list* create(){
    struct list * new_list = (struct list*)malloc(sizeof(struct list));

    if (new_list != NULL)
    {
        new_list->beginning=NULL;
        new_list->size=0;
    }
    return new_list;
};

bool empty(struct list*li){
    assert(li != NULL);
    if (li->beginning == NULL)
    {
       return true;
    }else{
        return false;
    }
};

int main(){
  struct list*my_list = create();
    if (empty(my_list)==true)
    {
        printf("\n Ok , list empty!!");
    }else{
        printf("\n Ops... One error occurred!!");
    }
    return 0;
}