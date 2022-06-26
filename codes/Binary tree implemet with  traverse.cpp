 #include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	 node(int data)
	 {
	 	this->data=data;
	 	this->left=NULL;
	 	this->right=NULL;
	 }


};
node *buildtree(node * root)
{
	int data;
	cin>>data;
	root=new node(data);

	if(data==-1)
		return NULL;

	root->left=buildtree(root->left);
	root->right=buildtree(root->right);

	return root;


}
void	levelordertraverse(node* root){
	queue<node *> q;

	q.push(root);
	q.push(NULL);

			while(!q.empty())
			{
				node *temp=q.front();
			

				q.pop();

				if(temp==NULL)
				{
					cout<<endl;
					if(!q.empty())
						q.push(NULL);
				}
				else{
				cout<<temp->data<<" ";

				if(temp->left)
				q.push(temp->left);

				if(temp->right)
				q.push(temp->right);
		    }
			}
}
void inorder(node *root)
{
	if(root==NULL)
		return ;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(node *root)
{
	if(root==NULL)
		return ;

	cout<<root->data<<" ";

	preorder(root->left);
	
	preorder(root->right);
}
void postorder(node *root)
{
	if(root==NULL)
		return ;

	

	postorder(root->left);
	
	postorder(root->right);
	cout<<root->data<<" ";
}
void makatreefromlevelorder(node *&root)
{
	int n;
	cin>>n;
	root=new node(n);
	queue<node *> q;
	q.push(root);


			while(!q.empty())
			{
				node *temp=q.front();
				q.pop();

				int left;
				cin>>left;

				if(left!=-1)
				{
					temp->left=new node(left);
					q.push(temp->left);
				}

				int right;
				cin>>right;

				if(right!=-1)
					{ temp->right=new node(right);
					q.push(temp->right);
				}

			} 

}

int main() {

 
	 node *root=NULL;	 
	 //root=buildtree(root);
	 makatreefromlevelorder(root);
	 levelordertraverse(root);
	 //inorder(root);
	 //cout<<endl;
	 //preorder(root);
	 //cout<<endl;
	// postorder(root);


	return 0;	

}
