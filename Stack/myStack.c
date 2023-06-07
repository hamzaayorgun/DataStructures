//180101001
//Ayhan OLGAC

#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n *next,*prev;
}node;

node *first,*last;

void push(int gelen){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=gelen;
    temp->next=temp->prev=NULL;
    if(!first){
        first=last=temp;
        return;
    }
    last->next=temp;
    temp->prev=last;
    last=temp;
}

int pop(){
    int tutucu;
    node *temp;
    tutucu=last->data;
    temp=last;

    if(first==last){
        first=last=NULL;
        free(temp);
        return tutucu;
    }
    last=last->prev;
    last->next=NULL;
    free(temp);
    return tutucu;
}

void listele(){
    node * temp=last;

    while(temp!=NULL){
        if(!temp)
            return;
        printf("%d-->",temp->data);
        temp=temp->prev;
    }
    printf("NULL");
}

int main()
{
    push(11),push(22),push(33),push(44),push(55);
    printf("listemiz: ");
    listele();

    printf("\nSilinenler:\n");
    printf("%d\n",pop());
    printf("%d\n",pop());

    printf("guncel listemiz: ");
    listele();

    return 0;
}
