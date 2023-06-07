#include <stdio.h>
#include <stdlib.h>
//5.de sıkıntı var onu düzelt
int counter = 0 ;

typedef struct node
{
    int ID ;
    int card ;
    struct node *next ;
    struct node *prev ;


} node;
node *head;


int generator(){
    FILE *fp=fopen("input.txt","a");
    int c, n;
    for (c = 1; c <= 100; c++) {
    n = 1 + rand() % 100;
    fprintf(fp,"%d\n",n);
  	}
  	fclose(fp);
  	return 0;
}

void ekleme(int x){
    counter++;

    node *temp = (node *)malloc(1*sizeof(node)) ;
    node *a = (node *)malloc(1*sizeof(node)) ;


    temp -> card = x ;
    temp -> ID = counter ;
    temp -> next = temp -> prev = NULL ;

    if(!head)
    {

        head = temp ;
        temp -> next = temp -> prev = head ;
        return;
    }

    if  (head -> next == head)
    {

        head -> next = temp ;
        head -> prev = temp ;

        temp -> prev = head ;
        temp -> next = head ;

        return;


    }
    
    a = head -> prev;
    a -> next = temp;
    temp -> prev = a;
    temp -> next = head;
    head -> prev = temp;


    return;
}

void ekle(){
    int x = 0;

    FILE *dosya;
	dosya = fopen("input.txt" , "r");
    if(dosya!=NULL){}
    else{
        printf("dosya yok.");
    }
    while(!feof(dosya)){
            fscanf(dosya,"%d\n",&x);
            ekleme(x);
    }
    return;
}

void startGame(){
    FILE *fp=fopen("output.txt","a");

    node *temp = (node *)malloc(1*sizeof(node)) ;
    node *a = (node *)malloc(1*sizeof(node)) ;
    node *b = (node *)malloc(1*sizeof(node)) ;
    node *chead = (node *)malloc(1*sizeof(node)) ;
    chead = head ;

    if(head -> next == chead)
    {

        printf("\nSonuncu\n");

    }

    printf("%d. insanin karti : %d\n",head->ID,head->card);
    fprintf(fp,"%d. insanin karti : %d\n", head->ID, head->card);
    fclose(fp);




    if (head -> card > 0){
        for(int i = 1 ; i <= head -> card ; i++){
            head = head -> next ;



        }
    }
    else{

        for(int i = head -> card ; i < 0 ; i++){
            head = head -> prev ;

        }

    }


    a = chead -> prev ;
    b = chead -> next ;
    a -> next = b;
    b -> prev = a ;
    free(chead) ;
}
int main()
{
    int i;
    generator();
    ekle();


    for(i = 1 ; i <= counter ; i++){

        startGame();
    }

    return 0;
}
