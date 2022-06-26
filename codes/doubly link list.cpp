#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
	node* prev;

	node(int data)
	{
		this->data=data;
		this->next=NULL;
		this->prev=NULL;
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

void print(node *head)
{
	node *temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int  len(node *head)
{
	node *temp=head;

	int len=0;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	return len;
}
void insertathead(node* &head,node* &tail,int data)
{
	if(head==NULL)
	{
		node *temp=new node(data);
		head=temp;
		tail=temp;
	}
	else{
	node *temp=new node(data);
	head->prev=temp;
	temp->next=head;
	head=temp;
	}

}
void insertattail(node* &head,node* &tail,int data)
{
	if(tail==NULL)
	{
		node *temp=new node(data);
		head=temp;
		tail=temp;
	}
	else{
		node *temp=new node(data);
	    tail->next=temp;
	    temp->prev=tail;
	    tail=temp;

	}
	
}
void insertatpos(node* &head,node* &tail,int pos,int data)
{
	if(pos==1)
	{
		insertathead(head,tail,data);
		return;
	}
	int p=1;
	node *temp=head;
	node *temp2=new node(data);

	while(p<pos-1)
	{
		//cout<<temp->data<<endl;
		temp=temp->next;
		p++;
	}
	if(temp->next==NULL)
	{
		insertattail(head,tail,data);
		return;
	}

	temp->next->prev=temp2;
	temp2->next=temp->next;
	temp2->prev=temp;
	temp->next=temp2;


}
void deletenode2(node* &head,node* &tail,int pos)
{
	if(pos==1)
	{
		node *temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;

		delete temp;
	}
	else{
		node* pre=NULL;
		node* curr=head;

		int p=1;
		while(p<pos)
		{
			pre=curr;
			curr=curr->next;
			p++;
		}
		if(curr->next==NULL)
		{
			node *temp=curr;
			pre->next=NULL;
			tail=pre;

			delete temp;
			return ;

		}

		node *temp=curr;
		pre->next=curr->next;
		curr->next->prev=pre;

		curr->next=NULL;
		curr->prev=NULL;
		delete curr;
	}
}


int main() {
	node* head=NULL;
	node *tail=NULL;
	
	insertathead(head,tail,3);
	insertattail(head,tail,5);
	insertathead(head,tail,2);

	insertatpos(head,tail,2,8);
	insertatpos(head,tail,5,10);

	deletenode2(head,tail,4);

	cout<<head->data<<" "<<tail->data<<endl;

	

	print(head);
	cout<<len(head);



	

}
