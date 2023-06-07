#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
	int data;
	struct node *next;
}node;
node *head, *tail;



void ekle(int gelen){
	node *temp = (node*)malloc(1*sizeof(node));
	temp->data=gelen;
	temp->next = NULL;
	if(!head){
		head = tail = temp;
		return;
	}

	tail->next=temp;
	tail=temp;
	return;
}


int ara(int gelen){
	int sayac = 0;
	node *temp = head;

	do{

		
		

		if(temp->data == gelen){
			
			return sayac;

		}

		temp = temp->next;
		sayac++;
		
		if(temp->next == NULL){
			if(temp->data == gelen){
			
			return sayac;

			}
		}

	}while(temp->next != NULL);

	return -1;
}



void sil(int silinecek){
	node *temp = head;

	if(silinecek == temp->data){
		head=head->next;
		free(temp);
		return;
	}


	struct node *prev = NULL;
	struct node *sonraki = NULL;


	while(temp->next->data != silinecek){
		temp = temp->next;

	}




	if(temp->next->next == NULL){

			tail = temp;
			tail->next = NULL;
			free(temp->next);

			return;
	}



	prev = temp;
	sonraki = temp->next->next;
	free(temp->next);
	prev->next = sonraki;





}

void listele(){
	node *temp = head;
	
	do{
		printf("%d\n", temp->data);
		temp = temp->next;
		if(!temp)
			return;
		if(head == tail){
			return;
		}
		if(temp == tail)
			printf("%d\n", temp->data);
		
	}while(temp->next != NULL);
}

int main(int argc, char *argv[]) {

	FILE *fp;
	int sayi;
	fp = fopen("oku.txt", "r");

	if(fp == NULL)
	printf("hata");

	while(! feof(fp)){

		fscanf(fp , "%d" , &sayi);
		ekle(sayi);
	}

	fclose(fp);


	listele();
	printf("\n");
	sil(55);
	listele();



	int gelen = ara(44);
	if(gelen == -1){
		printf("\nBulunamadi.");
	}
	else{
		printf("\n%d.inci indiste duruyor.", gelen);
	}

	return 0;
}
