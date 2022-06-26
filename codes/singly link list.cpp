#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
	~node()
	{
		if(this->next!=NULL)
		{
			delete next;
			this->next=NULL;
		}
	}
};
void inserathead(node* &head,int data)
{
	node* temp=new node(data);
	temp->next=head;
	head =temp;
}

void inserattail(node* &head,int data)
{
	node* temp=new node(data);
	node *head2=head;

		while(head2->next!=NULL)
		{
		head2=head2->next;
		//cout<<head2->data<<endl;	
		}
		
	head2->next=temp;
	return ;
}
void inserattail2(node* &tail,int data)
{
			node *temp=new node(data);
			tail->next=temp;
			tail=tail->next;
}

void print(node *head)
{
	node *temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
void deletenode(node* &head,int pos)
{
	if(pos==1)
	{
		node * temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}
	else
	{
		node* prev=NULL;
		node* curr=head;

		int p=1;
		while(p<pos)
		{
			prev=curr;
			curr=curr->next;
			p++;
		}

		node *temp=curr;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;

	}
}
void insertatpos(node* &head,node* &tail,int pos,int data)
{
	if(pos==1)
	{
		inserathead(head,data);
		return;
	}
	int n=1;
	node *temp=head;
	while(n!=pos-1)
	{
		n++;
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		inserattail2(tail,data);
		return ;
	}

	node *temp2=new node(data);
	temp2->next=temp->next;
	temp->next=temp2;

}


int main() {
	node* node1=new node(1);

	node* head=node1;
	node* tail =node1;
	inserattail2(tail,2);
	inserattail2(tail,3);
	inserattail2(tail,4);
	//print(head);
	insertatpos(head,tail,3,6);
	//cout<<head->data<<" "<<tail->data<<endl;
	deletenode(head,3);
	print(head);



	

}
