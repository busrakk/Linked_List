#include <stdio.h>
#include <stdlib.h>

struct node { //liste yapisini olusturma
    int data; //data tutma
    struct node *next; // node gosteren pointer
};

struct node* addlast(struct node* head, int key){ //sona ekleme fonksiyonu
		
	if(head == NULL){ //liste bossa
		head = (struct node *)malloc(sizeof(struct node));
        head -> data = key;
        head -> next =NULL;
	}
	else{ //listede eleman varsa
		struct node *temp = (struct node *)malloc(sizeof(struct node)); //hafizadan yer alma
        temp -> data = key;
        temp -> next = NULL;
        struct node *last = head; //gecici gezici pointer olusturma 

        while(last -> next != NULL){ //liste sonunu bulma
		    last = last -> next;
		last -> next = temp;
	    }
	}
			
	return head;
}

struct node *addhead(struct node *head, int key){ //basa ekleme fonksiyonu
	
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = key;
	temp -> next = head;
	head = temp;
	return head;

}

void listeinfo(struct node* head){ //tum eleman bilgilerini yazdirma
    int i = 1;

    while(head != NULL){ //listenin basindan sonuna kadar dolasma
        printf("Listenin %d. dugumunun adresi = %p \n", i, head);
        printf("Listenin %d. dugumunun verisi = %d \n", i, head -> data);
        printf("Listenin %d. dugumunun bagli oldugu dugumunun adresi = %p \n\n",i, head -> next);
        head = head -> next;
        i++;
    }
}

struct node *deletelist(struct node *head, int key){ //listeden eleman silme
    if(head == NULL){
        printf("Listede veri bulunmamaktadir. \n");
        return head;
    }

    struct node *temp = head;
    if(head -> data == key){ //ilk dugum silinmesi
        head = head -> next; //head sonraki eleman olur
        free(temp); //silme
    }
    else if(head -> next == NULL){ //liste tek dugumse
        printf("Silmek istediginiz veri bulunmamaktadir.\n");
        return head;
    }
    else{
        while(temp -> next -> data != key){
            if(temp -> next -> next == NULL){
                printf("Silmek istediginiz veri bulunmamaktadir.\n");
                return head;
            }
            temp = temp -> next;
        }
        struct node *last = temp -> next;
        temp -> next = temp -> next -> next;
        free(last);
    }
    return head;
}

/*void print(struct node *head){ //yazdirma
	if(head == NULL){
		printf("list is empty");
        return;
	}
	else{
		while(head != NULL){ //tek tek dolasilacak
			printf("%d\t", head -> data);
			head = head -> next;
		}
        printf("\n");
	}
}*/
	
void print(struct node *head){ //yazdirma
	if(head == NULL){ //liste bossa
		printf("List is empty");
        return;
	}
	else{
        struct node *last = head; //gecici gezici pointer olusturma

		while(last -> next != NULL){ //tek tek dolasilacak
			printf("%d\t", last -> data);
			last = last -> next;
		}

        printf("%d ", last -> data);
        printf("\n");
	}
}

/*void printlist(struct node *head){ 
    
    if(head -> next != NULL){
        printlist(head -> next);
        printf("%d\t", head -> data);
        printlist(head -> next);
    }
}*/

struct node *destroy(struct node *head){ //tamamen silme
    if(head == NULL){
        printf("Listede eleman bulunmamaktadir.");
        return head;
    }

    struct node *last; //gecici pointer

    while(head != NULL){
        last = head;
        head = head -> next;
        free(last);
    }
    return head;
}
	
int count(struct node *head){ //kaç eleman oldugunu bulma
	int counter = 0;
		
	while(head != NULL){
		counter ++;
		head = head -> next;
	}
	return counter;
}
	
void reverseprint(struct node *head){ //listeyi tersten yazdirma
	if(head == NULL){ // liste bossa
		return;
	}
    
    if(head != NULL){
       // reverseprint(head -> next); //listeyi basa dondur
	    printf("%d\t ",head -> data);
        reverseprint(head -> next); //listeyi basa dondur
    }    
}
	
struct node *cutlastAddFront(struct node *head){ //en son listeyi en basa ekleme
	struct node *p, *q;
	p = head;
	q = p;

	while(p -> next != NULL){
		q = p;
		p = p -> next;
	}
		
	p -> next = head;
	q -> next = NULL;
	head = p;
		
	return head;
}

int main(int argc, char const *argv[])
{
    
    int select, data;
    struct node *head = NULL;

    printf("******** LISTELER ********\n\n");

    while(1){
        printf("1- Liste basina eleman ekleme\n");
        printf("2- Liste sonuna eleman ekleme\n");
        printf("3- Listeyi yazdirma\n");
        printf("4- Listeden verilen degere gore dugum silme\n");
        printf("5- Listeyi silme\n");
        printf("6- Listedeki toplam eleman sayisini yazdirma\n");
        printf("7- Listenin tum eleman bilgileri yazdirma\n");
        printf("8- Listeyi tersten yazdirma\n");
        printf("9- Listedeki son dugumu en basa ekleme\n");
        printf("10- programdan cikma\n\n");

        printf("Yapmak istediginiz islem nedir :  ");
        scanf("%d",&select);
        printf("\n");

        switch(select){
            case 1:
            printf("Eklemek istediginiz degeri giriniz : ");
            scanf("%d", &data);
            printf("\n");
            head = addhead(head, data);
            break;

            case 2:
            printf("Eklemek istediginiz degeri giriniz : ");
            scanf("%d",&data);
            head = addlast(head, data);
            break;

            case 3:
            print(head);
            printf("\n");
            break;

            case 4:
            printf("Silmek istediginiz degeri giriniz : ");
            scanf("%d",&data);
            head = deletelist(head, data);
            printf("\n");
            print(head);
            printf("\n");
            break;

            case 5:
            head = destroy(head);
            printf("\n");
            print(head);
            printf("\n");
            break;

			case 6:
            printf("Listede %d eleman var.\n", count(head));
            printf("\n");
            break;

            case 7:
            listeinfo(head);
            printf("\n");
            break;
            
            /*case 8:
            printlist(head);
            break;*/

            case 8:
            reverseprint(head);
            printf("\n");
            break;

            case 9:
            head = cutlastAddFront(head);
            printf("\n");
            print(head);
            printf("\n");
            break;

            case 10:
            exit(1);
            break;


            default :
            printf("Yanlis secim yaptiniz\n");
        }
    }
    
    return 0;
}


	
    
