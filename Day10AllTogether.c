#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
// for doubly linked list
struct NODE{
	int data;
	struct NODE *next;
	struct NODE *prev;
};
//for singly linked list
struct node{
	int data;
	struct node *next;
};

//function declaration for doubly linked list
struct NODE* insertL(struct NODE *,int);
struct NODE* insertF(struct NODE *,int);
struct NODE* insertA(struct NODE *,int,int);
struct NODE* insertB(struct NODE *,int,int);
struct NODE* deleteF(struct NODE *);
struct NODE* deleteL(struct NODE *);
struct NODE* view(struct NODE *);
struct NODE* createNODE(int);
int MeNu();

//function declaration
struct node* createNode(int);
void insertAtBeg(struct node **,struct node **,int);
void insertAtLast(struct node **,struct node **,int);
void insertBefore(struct node **,struct node **,int,int);
void insertBefore(struct node **,struct node **,int,int);
void display(struct node **,struct node **);
void deleteFirst(struct node **,struct node **);
void deleteLast(struct node **,struct node **);
void delete(struct node **,struct node **,int);
void deleteAll(struct node **,struct node **);
void search(struct node **,int);
void update(struct node **,int,int);
void sortInAscending(struct node **);
void sortInDescending(struct node **);
void createLoop(struct node **);
void detectLoop(struct node **);
void findLen(struct node **);
void binarySearch(struct node **,int);
void reverseTheLinkedList(struct node **);

int menu(); // for stack
int MEnu(); // for queue
int MENU(); // for choice
int Menu(); // for linked list

// function for doubly linked list
//........................................................
//........................................................
struct NODE* createNODE(int data){
	struct NODE *p;
	p=(struct NODE*)malloc(sizeof(struct NODE));
	p->next=NULL;
	p->prev=NULL;
	p->data=data;
	return(p);
}

struct NODE* insertB(struct NODE *HEAD,int data,int value){
	struct NODE *p=createNODE(data);
	if(HEAD==NULL){
		HEAD=p;
		printf("\nList Was Empty: Hence The Node inserted as First Node");
		return(HEAD);
	}
	else{
		struct NODE *pt=HEAD;
		while(pt!=NULL){
			if(pt->data==value){
				if(pt->prev==NULL){
					p->next=pt;
					pt->prev=p;
					HEAD=p;
					printf("\nNode Successfully Inserted:");
				}
				else{
			        p->next=pt;
		            p->prev=pt->prev->next;
		            pt->prev->next=p;
		            pt->prev=p;
		            printf("\nNode Successfully Inserted:");
		        }
				return(HEAD);
			}
			pt=pt->next;
		}
	}
	printf("\nElement Not Found Insertion Not Possible:");
	return(HEAD);
}


struct NODE* insertA(struct NODE *HEAD,int data,int value){
	struct NODE *p=createNODE(data);
	if(HEAD==NULL){
		HEAD=p;
		printf("\nList Was Empty: Hence The Node inserted as First Node");
		return(HEAD);
	}
	else{
		struct NODE *pt=HEAD;
		while(pt!=NULL){
			if(pt->data==value){
				if(pt->next==NULL){
					p->prev=pt;
					pt->next=p;
					printf("\nNode Successfully Inserted:");
				}
				else{
			        p->next=pt->next;
		            p->prev=pt;
		            pt->next->prev=p;
		            pt->next=p;
		            printf("\nNode Successfully Inserted:");
		        }
				return(HEAD);
			}
			pt=pt->next;
		}
	}
	printf("\nElement Not Found Insertion Not Possible:");
	return(HEAD);
}

struct NODE* insertL(struct NODE *HEAD,int data){
	struct NODE *p=createNODE(data);
	if(HEAD==NULL){
		HEAD=p;
		printf("\nNode Successfully Inserted:");
	}
	else{
		struct NODE *pt=HEAD;
		while(pt->next!=NULL)
			pt=pt->next;
		pt->next=p;
		p->prev=pt;
		printf("\nNode Successfully Inserted:");
	}
	return(HEAD);
}

struct NODE* insertF(struct NODE *HEAD,int data){
	struct NODE *p=createNODE(data);
	if(HEAD==NULL){
		HEAD=p;
		printf("\nNode Successfully Inserted:");
	}
	else{
		p->next=HEAD;
		HEAD->prev=p;
		HEAD=p;
		printf("\nNode Successfully Inserted:");
	}
	return(HEAD);
}

struct NODE* view(struct NODE *HEAD){
	struct NODE *pt=HEAD;
	while(pt!=NULL){
		printf("%d ",pt->data);
		pt=pt->next;
	}
	return(HEAD);
}
struct NODE* deleteF(struct NODE *HEAD){
	int d;
	if(HEAD==NULL)
		printf("\nDeletion Is Not Possible:");
	else{
		struct NODE *p;
		p=HEAD;
		if(HEAD->next==NULL)
		 HEAD=NULL;
		else{
		 HEAD=HEAD->next;
		 HEAD->prev=NULL;			
		}
		printf("\nDeleted Node=%d",p->data);
		free(p);
	}
	return(HEAD);
}

struct NODE* deleteL(struct NODE *HEAD){
	int d;
	if(HEAD==NULL)
		printf("\nList Is Empty,Deletion Is Not Possible:");
	else{
		struct NODE *p;
		p=HEAD;
		if(HEAD->next==NULL){
		  HEAD=NULL;
		  printf("\nDeleted Node=%d",p->data);
		  free(p);	
		}
		else{
		 while(p->next!=NULL)
		  p=p->next;
		 p->prev->next=NULL;
		 printf("\nDeleted Node=%d",p->data);
		 free(p);	
		}
	}
	return(HEAD);
}

int MeNu(){
	int ch;
	printf("\n1. Insert At Last:");
	printf("\n2. Insert At Begining:");
	printf("\n3. insert After A Particular Node:");
	printf("\n4. insert Before A Particular Node:");
	printf("\n5. Delete First Node:");
	printf("\n6. Delete Last Node:");
	printf("\n7. View List:");
	printf("\n8. JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP:");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	return(ch);
}
//........................................................
//........................................................
void reverseTheLinkedList(struct node **head){
	struct node *prev=*head,*curr=(*head)->next;
	(*head)=(*head)->next;
	prev->next=NULL;
	while(curr!=NULL){
		*head=(*head)->next;
		curr->next=prev;
		prev=curr;
		curr=(*head);
	}
	(*head)=prev;
}

//function definition
void binarySearch(struct node **head,int nodeValue){
	int ar[100],f,l,m,i=0;
	struct node *temp;
	temp=(*head);
	while(temp!=0){
		i++;
		temp=temp->next;
	}
	f=0;
	l=i-1;
	m=(f+l)/2;
	while(f<=l){
		i=-1;
		temp=(*head);
		while(temp!=NULL){
			i++;
			temp=temp->next;
			if(i==m)
			 break;	
		} 
		if(temp->data==nodeValue){
			printf("\nElement Found In The List");
			break;
		}
		if(nodeValue>temp->data)
		 f=m+1;
		if(nodeValue<temp->data)
		 l=m-1;
		m=(f+l)/2;
	}
	if(f>l)
	 printf("\nNode Not Found In The List");
}

void findLen(struct node **head){
	int n=0;
	struct node *temp;
	temp=(*head);
	while(temp!=NULL){
		n++;
		temp=temp->next;
	}
	printf("\nlength of list = %d NODE",n);
}

void detectLoop(struct node **head){
	struct node *s,*f; int k=0;
	s=(*head);
	f=(*head)->next;
	while(s && f && f->next){
		if(s==f){
			printf("\nLoop Found In The List");
			k=1;
			break;
		}
		s=s->next;
		f=f->next->next;
	}
	if(k==0)
	 printf("\nLoop Not Found In The List");
} 

void createLoop(struct node **head){
	struct node *temp,*t; int i=0;
	temp=(*head);
	while(temp->next!=NULL){
		i++;
		if(i==3)
		 t=temp;
		temp=temp->next;
    }
    temp->next=t;
    printf("\nLoop Successfully Created:");
}

void sortInDescending(struct node **head){
	int n=0,round,i,var;
	struct node *temp;
	temp=(*head);
	while(temp!=NULL){
		n++;
		temp=temp->next;
	}
	for(round=1;round<n;round++){
		temp=(*head);
		for(i=1;i<=n-round;i++){
			if(temp->data<temp->next->data){
				var=temp->data;
				temp->data=temp->next->data;
				temp->next->data=var;
	    	}
	    	temp=temp->next;
		}
	}
	printf("\nList sorted:");
}

void sortInAscending(struct node **head){
	int n=0,round,i,var;
	struct node *temp;
	temp=(*head);
	while(temp!=NULL){
		n++;
		temp=temp->next;
	}
	for(round=1;round<n;round++){
		temp=(*head);
		for(i=1;i<=n-round;i++){
			if(temp->data>temp->next->data){
				var=temp->data;
				temp->data=temp->next->data;
				temp->next->data=var;
	    	}
	    	temp=temp->next;
		}
	}
	printf("\nList sorted:");
}

void update(struct node **head,int newData,int nodeValue){
    struct node *temp; int a=0;
	temp=(*head);
	while(temp!=NULL){
		if(temp->data==nodeValue){
			temp->data=newData;
			a=1;
			printf("\nNew Data Updated Successfully:");
			break;
		}
		temp=temp->next; 
	}
	if(a==0)   
	 printf("\nNode ( node value=%d) ) to be updated not found:",nodeValue);	
}

void search(struct node **head,int nodeValue){
	struct node *temp; int a=0;
	temp=(*head);
	while(temp!=NULL){
		if(temp->data==nodeValue){
			printf("\nNode with value %d found:",nodeValue);
			a=1;
			break;
		}
		temp=temp->next;
	}
	if(a==0) 
	 printf("\nNode not found:");
}

void deleteAll(struct node **head,struct node **tail){
	struct node *temp,*t;
	temp=(*head);
	do{
		t=temp;
		temp=temp->next;
		free(t);
	}while(temp!=NULL);
	printf("\nAll node from the list got deleted: List is empty now");
	(*head)=NULL;
	(*tail)=NULL;
}

void delete(struct node **head,struct node **tail,int nodeValue){
	struct node *temp=NULL,*t=NULL;
	int a=0;
	temp=(*head);
	while(temp!=NULL){
		if(temp->data==nodeValue){
		  a=1;
		  break;	
		}
		t=temp;
		temp=temp->next;
	}
	if(a==1){
	 if(temp->next==NULL && t==NULL){
		printf("\nThis was only the node (node value=%d) in the list,Deleted noe the list is empty",nodeValue);
		free(temp);
		(*head)=NULL;
		(*tail)=NULL;
	 }
	 else if(temp->next!=NULL && t==NULL){
	 	(*head)=(*head)->next;
	 	int b=temp->data;
	 	free(temp);
	 	printf("\nThis was the First node (node value=%d) in th list,Deleted",b);
	 }
     else if(temp->next==NULL){
		t->next=NULL;
		(*tail)=t;
		free(temp);
		printf("\nThis was the last node ( node value=%d)),Deleted",nodeValue);
	 }
	 else{
		t->next=temp->next;
		free(temp);
		printf("\nThis was the Middle node (node value=%d)),Deleted",nodeValue);
	 }
    }
    else
     printf("\nNode not found,Deletion is not possible:");
}

void deleteLast(struct node **head,struct node **tail){
	int a;
	if(*head==NULL)
		printf("\nList is Empty Deletion Not Possible:");
	else{
		if((*head)->next==NULL){
			a=(*head)->data;
			free(*head);
			(*head)=NULL;
			(*tail)=NULL;
			printf("\nThis was only the node ( Node Value=%d ) in the list,Deleted: List is now empty",a);
		}
		else{
			struct node *temp;
			temp=(*head);
			while(temp->next->next!=NULL)
				temp=temp->next;
			a=temp->next->data;
			free(temp->next);
			temp->next=NULL;
			(*tail)=temp;
			printf("\nLast Node Deleted:( Node Value=%d ) But List is not empty",a);
	    }
	}
}

void deleteFirst(struct node **head,struct node **tail){
	int a;
	if(*head==NULL)
		printf("\nList is Empty Deletion Not Possible:");
	else{
		if((*head)->next==NULL){
			a=(*head)->data;
			free(*head);
			(*head)=NULL;
			(*tail)=NULL;
			printf("\nFirst Node Deleted:( Node Value=%d ) List is now empty",a);
		}
		else{
			struct node *temp;
			temp=(*head);
			a=temp->data;
			(*head)=(*head)->next;
			printf("\nFirst Node Deleted:( Node Value=%d ) But list is not empty",a);
			free(temp);
		}
	}
}

void insertAfter(struct node **head,struct node **tail,int data,int nodeValue){
	struct node *p;
	p=createNode(data);	
	if(*head==NULL){
		(*head)=p;
		(*tail)=p;
		printf("\nSince the List is Empty the node with data %d Inserted As First Node:",data);
	}
	else{
	  struct node *pt;
	  pt=(*head);
	  while(pt!=NULL){
	  	if(pt->data==nodeValue){
	  		p->next=pt->next;
	  		pt->next=p;
	  		printf("\nNode Successfully Inserted:");
	  		if(pt->next==NULL)
	          (*tail)=p;
	  		break;
		}
		pt=pt->next;
	  }	
	  if(pt==NULL)
	   	printf("\nNode with value %d not found in the list: Insertion not possible",nodeValue);
	}
}

void insertBefore(struct node **head,struct node **tail,int data,int nodeValue){
	struct node *p;
	p=createNode(data);
	if(*head==NULL){
		*head=p;
		*tail=p;
		printf("\nSince the List is Empty the node with data %d Inserted As First Node:",data);
	}
	else{
	  struct node *pt;
	  pt=*head;
	  if(pt->data==nodeValue){
	  	p->next=*head;
	  	*head=p;
	  	printf("\nNode Successfully Inserted:");
	  }
	  else{
	  	while(pt->next!=NULL){
	  	  if(pt->next->data==nodeValue){
	  	  	p->next=pt->next;
	  	  	pt->next=p;
	  	  	printf("\nNode Successfully Inserted:");
	  	  	break;
		  }
		  pt=pt->next;
        }
        if(pt->next==NULL)
         printf("\nNode with value %d not found in the list: Insertion not possible",nodeValue);
	  }
    }
}

void insertAtLast(struct node **head,struct node **tail,int data){
	struct node *p;
	p=createNode(data);
	if(*head==NULL){
	  *head=p;
	  *tail=p;
	  printf("\nNode successfullty inserted:");	
	}
	else{
		(*tail)->next=p;
		(*tail)=p;
		printf("\nNode successfullty inserted:");	
	}
}

struct node* createNode(int dat){
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=dat;
	ptr->next=NULL;
	return(ptr);
}

void insertAtBeg(struct node **head,struct node **tail,int data){
	struct node *p;
	p=createNode(data);
	if(*head==NULL){
	 *head=p;
	 *tail=p;
	 printf("\nNode successfullty inserted:");	
	}
	else{
		p->next=*head;
		*head=p;
		printf("\nNode successfullty inserted:");
	}
}

void display(struct node **head,struct node **tail){
	if(*head==NULL)
	 printf("\nLinked List Is Empty:");
	else{
		struct node *temp;
		temp=*head;
		printf("\nList is:\n");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

int MEnu(){
	int ch;
    printf("\n1.  InsertAtBeg");
	printf("\n2.  insertAtLast");
	printf("\n3.  insertBefore");
	printf("\n4.  insertAfter");
	printf("\n5.  deleteFirst");
	printf("\n6.  deleteLast");
	printf("\n7.  Delete Specific Node");
	printf("\n8.  deleteAll");
	printf("\n9.  search any node");
	printf("\n10. update any node value");
	printf("\n11. sort The List In Ascending Order");
	printf("\n12. sort The List In Descending Order");
	printf("\n13. Create Loop In The List");
	printf("\n14. Detect Loop In List");
	printf("\n15. Find The Length Of List");
	printf("\n16. binarySearch");
	printf("\n17. Reverse The Linked List");
	printf("\n18. View List");
	printf("\n19. JUMP JUMP JUMP JUMP ");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	return(ch);	
}

int menu(){
	int ch;
	printf("\n1. Push:");
	printf("\n2. Pop:");
	printf("\n3. View:");
	printf("\n4. JUMP:");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	return(ch);
}

int Menu(){
	int ch;
	printf("\n1. Enqueue:");
	printf("\n2. Dequeue:");
	printf("\n3. View:");
	printf("\n4. JUMP:");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	return(ch);
}

int MENU(){
	int ch;
	printf("\n1. Perform Queue Operation:");
	printf("\n2. Perform Stack Operation::");
	printf("\n3. Perform Singly Linked List Operation::");
	printf("\n4. Perform Doubly Linked List Operation::");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	return(ch);
}

int main(){
	struct node *head=NULL,*head1=NULL,*tail=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
	int data,value,k=0,l=0,m=0,n=0;
	struct NODE *HEAD=NULL;
	while(1){
		system("cls");
		switch(MENU()){
			case 1:
				while(1){
					system("cls");
				switch(Menu()){
					case 1:
						printf("\nEnter the data: ");
				        scanf("%d",&data);
				        insertAtLast(&head1,&tail1,data);
				        break;
					case 2:
						deleteFirst(&head1,&tail1);
				        break;
					case 3:
						display(&head1,&tail1);
				        break;
				    case 4:
						l=1;
						break;
					default:
				        printf("\nInvalid Choice:");
				}
				 if(l){
				 	l=0;
				 	break;
				 } 
				 getch();
			    }
				break;
			case 2:
				while(1){
				system("cls");
				switch(menu()){
					case 1:
				        printf("\nEnter the data: ");
				        scanf("%d",&data);
				        insertAtLast(&head2,&tail2,data);
				        break;
			        case 2:
				        deleteLast(&head2,&tail2);
				        break;
			        case 3:
				        display(&head2,&tail2);
				        break;
				    case 4:
				          k=1;
				          break;
			        default:
				        printf("\nInvalid Choice:");
				}
				 if(k){
				 	k=0;
				 	break;
				 } 
				 getch();
			    }
				break;
			case 3:
				while(1){
				system("cls");
				switch(MEnu()){
			    case 1:
				    printf("\nEnter the data: ");
				    scanf("%d",&data);
				    insertAtBeg(&head,&tail,data);
			  	    break;
			    case 2:
				    printf("\nEnter the data: ");
				    scanf("%d",&data);
				    insertAtLast(&head,&tail,data);
				    break;
			    case 3:
				    printf("\nEnter the data: ");
				    scanf("%d",&data);
				    printf("\nEnter the nodeValue: ");
				    scanf("%d",&value);
				    insertBefore(&head,&tail,data,value);
				    break;
		        case 4:
		    	    printf("\nEnter the data: ");
				    scanf("%d",&data);
				    printf("\nEnter the nodeValue: ");
				    scanf("%d",&value);
				    insertAfter(&head,&tail,data,value);
				    break;
			    case 5:
				    deleteFirst(&head,&tail);
				    break;
			    case 6:
				    deleteLast(&head,&tail);
				    break;	
			    case 7:
				    if(head==NULL)
				        printf("\nList is Empty First Insert some node:");
				    else{
				        printf("\nEnter the Node Value to be deleted: ");
				        scanf("%d",&value);  
			            delete(&head,&tail,value);
			        }
				    break;
			    case 8:
				    if(head==NULL)
				        printf("\nThe List is already empty:");
				    else
			            deleteAll(&head,&tail);
				    break;
			    case 9:
			        if(head==NULL)
				        printf("\nThe List is empty: Insert some node");
				    else{
				        printf("\nEnter the Node Value to be searched: ");
				        scanf("%d",&value);
				        search(&head,value);
				    } 
				    break;
			    case 10:
			        if(head==NULL)
				        printf("\nThe List is empty: Insert some node");
				    else{
				        printf("\nEnter the node data to be updated: ");
				        scanf("%d",&value);					
				        printf("\nEnter the new Node data to be updated: ");
				        scanf("%d",&data);
				        update(&head,data,value);
				    }	 
				    break;
			    case 11:
			        if(head==NULL)
			            printf("\nThe List is empty: Insert some node");
				    else
				        sortInAscending(&head);
			        break;
			    case 12:
			        if(head==NULL)
				        printf("\nThe List is empty: Insert some node");
				    else
				        sortInDescending(&head);
			        break;		
			    case 13:
			        if(head==NULL)
				        printf("\nThe List is empty: Insert some node");
				    else
					    createLoop(&head);
				    break;
			    case 14:
			        if(head==NULL)
				        printf("\nThe List is empty: Insert some node");
				    else
				        detectLoop(&head);
				    break;
			    case 15:
				    if(head==NULL)
				        printf("\nThe List is empty length=0 :First Insert some node");
				    else
			            findLen(&head);
				    break;
			    case 16:
				    if(head==NULL)
				        printf("\nThe List is empty length=0 :First Insert some node");
				    else{
				        printf("\nEnter the node data to be searched: ");
				        scanf("%d",&value);
				        binarySearch(&head,value);	
				    }
				    break;
			    case 17:
				    if(head==NULL)
				        printf("\nThe List is empty");
				    else{
				        display(&head,&tail);
				        reverseTheLinkedList(&head);
				        display(&head,&tail);
			        }
				    break;
			    case 18:
				    display(&head,&tail);
				    break;
				case 19:
					 m=1;
					 break;
				default:
					printf("\nInvalid Choice:");
		       }
		       if(m){
		       	m=0;
		       	break;
			   }
		        getch();
		       }
		       break;
		    case 4:
		    	while(1){
				system("cls");
				switch(MeNu()){
				    case 1:
				        printf("\nEnter the Data: ");
				        scanf("%d",&data);
				        HEAD=insertL(HEAD,data);
				        break;
			        case 2:
				        printf("\nEnter the Data: ");
				        scanf("%d",&data);
				        HEAD=insertF(HEAD,data);
				        break;
			        case 3:
				        printf("\nEnter the Node Data: ");
				        scanf("%d",&data);
			            printf("\nEnter the Node Value: ");
				        scanf("%d",&value);
				        HEAD=insertA(HEAD,data,value);
				        break;
			        case 4:
				        printf("\nEnter the Node Data: ");
				        scanf("%d",&data);
			            printf("\nEnter the Node Value: ");
				        scanf("%d",&value);
				        HEAD=insertB(HEAD,data,value);
				        break;
			        case 5:
				        HEAD=deleteF(HEAD);
				        break;
				    case 6: 
				        HEAD=deleteL(HEAD);
				        break;
			        case 7:
				        if(HEAD==NULL)
				            printf("\nList Is Empty:");
				        else
				            HEAD=view(HEAD);
				        break;
				    case 8:
				        n=1;
				        break;
			        default:
				        printf("\nInvalid Choice:");
				    }
				    if(n){
				    	n=0;
				    	break;
					}
				    getch();
			    }
		    	break;
			default:
			    printf("\nInvalid Choice:");
		}
		//getch();
	}
	return 0;
}

