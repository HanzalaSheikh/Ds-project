#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct number{
	char cid;
	int sid;
	//int semester;
	char sname[25];
	struct number*nonext;
	struct number*cstart;
};

struct alpha{
	
	char aname;
	struct number*nostart;
	struct alpha*anext;
};
struct alpha*start=NULL;

void insertalphabet(){
	
	struct alpha*temp=(struct alpha*)malloc(sizeof(struct alpha));
	printf("enter alphabet name :");
	scanf("%s",&temp->aname);

	temp->anext=NULL;
	temp->nostart=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		struct alpha*curr=start;
		while(curr->anext!=NULL){
			curr=curr->anext;
		}
		curr->anext=temp;
		
	}
}
void printalphabet(){
    struct alpha*z=start;
    while(z!=NULL){
        
        printf("%s ->",&z->aname);
	z=z->anext;
	}
}
void searchalphabet(){
	char i;
	printf("enter alphabet name you want to search:");
	scanf("%s",&i);
	struct alpha*z=start;
	while(z!=NULL){
		if(i==z->aname){
			printf("its found and the alphabet is " );
			printf("%s",&z->aname);
			break;
		}
		z=z->anext;
		
	}

	
}


void addnumberinalphabet(){
    struct alpha *Ccurr=start;
    struct number *peoplenewnode;
    peoplenewnode = (struct number*)malloc(sizeof(struct number));
	 int v,z;
	 //char [i];
    printf("enter alphabet in which you add number:");
    scanf("%s",&peoplenewnode->cid);
     printf("enter whose name which number you add:");
    scanf("%s",&peoplenewnode->sname);
    printf("enter Number:");
    scanf("%d",&peoplenewnode->sid);
    //Studentnewnode->sid=z;
	//Studentnewnode->cid=i;
    //printf("enter semester no:");
    //scanf("%d",&v);
   
   

   // Studentnewnode->semester=v;
    peoplenewnode->nonext=NULL;
    peoplenewnode->cstart=NULL;

    while(Ccurr!=NULL)
        {
        	//printf("%s",&Studentnewnode->cid);
        	//printf("%s",&Ccurr->aname);
        if (peoplenewnode->cid==Ccurr->aname)
        {
                if(Ccurr->nostart==NULL)
                {

                    Ccurr->nostart=peoplenewnode;
                    printf("Contact has been linked with Directory\n ");
                }
                else{
                    struct number *temp=Ccurr;
                    while(temp->nonext!=NULL)
                    {
                        temp=temp->nonext;
                    }
                    temp->nonext=peoplenewnode;
                    printf("hello");
                }
        }
        Ccurr=Ccurr->anext;
        
}
}

void printnumberwithalphabet(struct alpha*z){
    z=start;
    
    
    while(z!=NULL){
       
        printf("\n%s \n",&z->aname);
    if(z->nostart!=NULL){
        	while(z->nostart!=NULL){
			
        	printf("it's number and %d",z->nostart->sid);
        	printf(" it's name %s",&z->nostart->sname);
			//printf("%d ->",z->nostart->semester);
	z->nostart=z->nostart->nonext;
	}
	
		}
	z=z->anext;
	
	}
}
void searchnumber(){
	char i;
	int j;
	printf("enter alphabet name you want to search:");
	scanf("%s",&i);
	printf("Enter the number you want to search :");
	scanf("%d",&j);
	//printf("%s",&j);

	struct alpha*z=start;
	struct number*p=z;
//	printf("%d ->",p->cstart->sid);
	while(z!=NULL){
		if(i==z->aname){
		//	printf("its found and the number is " );
			while(p!=NULL){
		
				if(j==p->sid){
				printf("the number is found\n");
				printf("the number is %d ->",p->sid);
        	    printf(" and the owner name is %s ->",&p->sname);
				}
				p=p->nonext;
			}
		}
		z=z->anext;	
	}	
}

struct node{
	int number;
	char name;
	struct node*next;
};
struct node*top=NULL;

void push(struct number*p){
	//printf("%d ->",p->sid);
    //printf("%s ->",&p->sname);
    struct node*temp=(struct node*)malloc(sizeof(struct node));
	
	temp->number =p->sid;
//	temp->name=p->sname;
	//printf("%d ->",temp->number);
    //printf("%s ->",&temp->name);
		temp->next=top;
	    top=temp;
	printf("%d",top->number);
}
void print(){
	struct node *p=top;
	while(p!=NULL){
		printf("%d\n",p->number);
		p=p->next;
	}
}
void peek(){
	struct node*p=top;
	printf("%d",p->number);
}
void pop(){

	if(top==NULL){
		printf("histroy is empty");
	}
	else{
	printf("deleted number is %d",top->number);
	free(top);
	top=top->next;
}
	
}

	
	


void make_a_call(){
    char i;
	int j;
	printf("enter alphabet of directory in which number is saved:");
	scanf("%s",&i);
	printf("Enter the number you want to call :");
	scanf("%d",&j);
	

	struct alpha*z=start;
	struct number*p=z;

	while(z!=NULL){
		if(i==z->aname){
        //printf("you successfully make a call");
			while(p!=NULL){
		//	printf("you successfully make a call");
				if(j==p->sid){
				printf("you successfully make a call");
			    push(p);
				}
				p=p->nonext;
			}
		}
		z=z->anext;	
	}	
	
}



/**void deletestudentfromcourse(){
	int a,b;
	printf("enter course from which you delete: ");



	scanf("%d",&a);
	printf("what student you want to delete enter student id: ");
	scanf("%d",&b);
	printf("%d ->",a);
	printf("%d ->",b);
	struct course*p=start;
	struct student*curr=p;
	struct student*prev=p->stustart;
	
	
	
while(p!=NULL){
		if(p->cno==a){
			printf("yes course found");
			while(curr!=NULL){
				
			
			
				if(curr->sid==b){
					printf("found");
					
				}
				
			
		curr=curr->stunext;	
		}
	}
		
		p=p->cnext;
	}
}
void addstudenttocourse(){

    struct course*p=start;

    
    
    
    struct student*newnode=(struct student*)malloc(sizeof(struct student));
    
    int i,v;
    printf("enter course id:");
    scanf("%d",&i);
    newnode->sid=i;
    printf("enter semester no:");
    scanf("%d",&v);
    printf("enter student name:");
    scanf("%s",&newnode->sname);
    newnode->semester=v;
    newnode->stunext=NULL;
    newnode->cstart=NULL;
    struct student*stu;
    while(p!=NULL){
        if(i==p->cno){
            printf("yes you add student in this course");
            if(p->stustart==NULL){
            	printf("your list is linked");
            	p->stustart=newnode;
			}
			else{
				struct student*cuur=p->stustart;
				while(cuur->stunext!=NULL){
					cuur=cuur->stunext;
				}
				cuur->stunext=newnode;
			}
	
            
        }
        p=p->cnext;

    }
    

}**/
	
void deletealphabetfromdirectory(){
	char i;
    printf("enter the alphabet of which you delete directory:");
    scanf("%s",&i);
    struct alpha*curr,*prev=start;
    if(start->aname==i){
    	start=start->anext;
    	free(prev);
    	printf("yes the alphabet is deleted");
	}
	else{
		curr=start->anext;
		prev=start;
		while(curr!=NULL){
			if(curr->aname==i){
				prev->anext=curr->anext;
				free(curr);
				printf("yes the alphabet is deleted");
			}
			curr=curr->anext;
			prev=prev->anext;
			
		}
	}
	
}	
	


int main(){

	int d;
	
	for(;;){
	
	printf("\n1 for add alphabet in directory: \n2 for print alphabet of directory: \n3 for search alphabet in directory : \n4 delete number from directory : \n5 for add number in directory :\n6 for print number with directory :\n7 for search number:\n8 for make a call :\n9 for print history of call logs : \n");
	scanf("%d",&d);
	if(d==1){
	insertalphabet();
    }
    else if(d==2){
		printalphabet();
    }
    else if(d==3){
    	searchalphabet();
	}
	else if(d==4){
    	deletealphabetfromdirectory();
	}
    else if(d==5){
    	addnumberinalphabet();
    }
        else if(d==6){
    	printnumberwithalphabet(start);
    }
    else if(d==7){
    	searchnumber();
	}
	else if (d==8){
		make_a_call();
	}
	else if (d==9){
		print();
	}
	else if (d==10){
		pop();
	}
	
}
}


