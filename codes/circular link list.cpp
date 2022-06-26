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

void print(node *tail)
{
	node *temp=tail;
	//cout<<temp->data<<endl;

	
	do{
		cout<<temp->data<<endl;
		temp=temp->next;
	}while(temp!=tail);
}
void insertelement(node* &tail,int ele,int d)
{
	if(tail==NULL)
	{
		node *temp=new node(d);
		tail=temp;
		temp->next=temp;

	}
	else{
		node *temp=tail;
		while(temp->data!=ele)
		{
			temp=temp->next;
		}
		node* temp2=new node(d);
		temp2->next=temp->next;
		temp->next=temp2;
	}
}
void deletenode(node* &tail,int data){
	if(tail==NULL)
	{
		cout<<"LL is emepty"<<endl;
		return;
	}
	else{
		node *prev=tail;
		node *curr=tail->next;

		while(curr->data!=data)
		{
			prev=curr;
			curr=curr->next;
		}
		if(curr==tail)
		{
			tail=prev;
		}
		prev->next=curr->next;
		curr->next=NULL;
		 delete curr;
	}
}

int main() {
	node *tail=NULL;
	insertelement(tail,3,5);
	insertelement(tail,5,3);
	insertelement(tail,3,7);
	insertelement(tail,5,4);
	deletenode(tail,4);

	print(tail);
	



	

}
