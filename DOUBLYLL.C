//operation on doubly linked list
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node
{
	struct node *prev;
	int data;
	struct node *add;
}*ptr,*head,*temp,*ptr1;//stucture to create node
void create(int num)//node creation function
{
	ptr=(struct node*)malloc(sizeof(struct node)); //allocates memory
	if(ptr==NULL)
	{
		printf("\n overflow");
		exit(1);
	}
	else
	{
		ptr->prev=NULL;
		ptr->data=num;
		ptr->add=NULL;
	}
}//end of function
void insert_beg()//function to insert node at begining
{
	if(head==NULL)
		head=ptr;
	else
	{
		head->prev=ptr;
		ptr->add=head;
		head=ptr;
	}
}//end of function
void insert_loc(int loc)//function to insert node at any location
{
	int i=1;
	temp=head;
	if(loc==1)
	      insert_beg();
	else
	{
		while(i<loc&&temp!=NULL)
		{
			temp=temp->add;
			ptr1=temp->prev;
			i++;
		}
	ptr1->add=ptr;
	ptr->prev=ptr1;
	ptr->add=temp;
	temp->prev=ptr;
	}
}//end of function
void insert_end()//function to insert node at end
{
	if(head==NULL)
		head=ptr;
	else
	{
		temp=head;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		temp->add=ptr;
		ptr->prev=temp;
	}
}//end of function
void delete_loc(int loc)//function to delete node at any location
{
	int i=1;
	temp=head;
	while(i<loc&&temp!=NULL)
	{
		temp=temp->add;
		i++;
	}
	ptr1=temp->prev;
	ptr1->add=temp->add;
	ptr=temp->add;
	ptr->prev=ptr1;
	free(temp);
}//end of function
void delete_beg()//function to delete node at begining
{
	if(head==NULL)
	{
		printf("\n underflow");
		exit(1);
	}
	else
	{
		temp=head;
		head=head->add;
		head->prev=NULL;
		free(temp);
	}
}//end of function
void delete_end()//function to delete node at end
{
	if(head==NULL)
	{
		printf("\n underflow");
		exit(1);
	}
	else
	{
		temp=head;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		ptr1=temp->prev;
		ptr1->add=NULL;
		free(temp);
	}
}//end of function
void display()//function to display linked list
{
	temp=head;
	printf("\n values:");
	while(temp!=NULL)
	{
		printf("\t %d",temp->data);
		temp=temp->add;
	}
}//end of funtion
void main()
{
	int num,ch,loc,choice;
	clrscr();
	do
	{
		printf("\n press \n1: to create node\n2: to delete node");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				do
				{
					printf("\n enter num");
					scanf("%d",&num);
					create(num);
					printf("\n press \n1:to add at begining\n2:to add at end\n3:to add at any location");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:
							insert_beg();
							break;
						case 2:
							insert_end();
							break;
						case 3:
							printf("\n enter loc");
							scanf("%d",&num);
							insert_loc(loc);
							break;
						default:
							printf("\n invalid number");
					}
				printf("\n press \n1: to add more node\n0: to exit");
				scanf("%d",&ch);
				}while(ch==1);
				display();
				break;
			case 2:
				do
				{
					printf("\n press  \n1: to delete node at begining \n2:to delete node at end\n3:to delete node at any location");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:
							delete_beg();
							break;
						case 2:
							delete_end();
							break;
						case 3:
							printf("\n enter loc");
							scanf("%d",&loc);
							delete_loc(loc);
							break;
						default:
							printf("\n invalid choice");
					}
				printf("\n press \n1: to delete more node\n0: to exit");
				scanf("%d",&ch);
				}while(ch==1);
				display();
				break;
			default:
				printf("\n invalid choice");
		}
		printf("\n press\n1:to continue\n0:to exit");
		scanf("%d",&ch);
	}while(ch==1);
	getch();
}

