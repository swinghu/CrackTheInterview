
#include<stdio.h>
#include<malloc.h>



typedef struct node
{
	int data;
	struct node* next;
}mynode;

void add(int value);
void iterative_reverse();
void print_list();

mynode *head, *tail, *temp;

int main()
{
	head = (mynode*)0;
	add(3);
	add(56);
	add(43);
	add(87);
	print_list();
	iterative_reverse();
	print_list();
}

void add(int value)
{
	temp = (mynode*)malloc(sizeof(mynode*));
	temp->data = value;
	temp->next = NULL;
	
	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void print_list()
{
	printf("the LinkList is: ");
	
	for (temp=head; temp!=NULL;temp=temp->next)
	{
		printf("%d  ",temp->data);
	}
	printf("\n");
}

void iterative_reverse()
{
	mynode *p, *q, *r;
	if (head == (mynode*)0){
		return;
	}

	p = head;
	q = p->next;
	p->next = (mynode*)0;

	while (q != (mynode*)0)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
}