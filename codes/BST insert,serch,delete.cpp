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
node *buildtree(node *root, int d)
{
	if(root==NULL)
	{
		root=new node(d);
		return root;
	}

	if(d> root->data)
	root->right=buildtree(root->right,d);
    else root->left= buildtree(root->left,d);

    return root;  


}
void makebst(node * &root)
{
	int data;
	cin>>data;

	while(data!=-1)
	{
		root = buildtree(root,data);
		cin>>data;
	}
}
void search(node *root,int k,node *&ans)
{
	if(root==NULL)
		return;

	if(root->data==k)
	{
		ans=root;
		return ;
	}
	  

	if(root->data>k)
		search(root->left,k,ans);
	else search(root->right,k,ans);

	//return root;

}
node *minans(node * root)
{
	node *temp=root;

	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
node *maxans(node * root)
{
	node *temp=root;

	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp;
}
node *successor(node * root)
{
	node *temp=root->right;

	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
node *predecessor(node * root)
{
	node *temp=root->left;

	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp;
}
node *deletenode(node *root,int data)
{
	if(root==NULL)
		return root;

	if(root->data==data)
	{
		//0 child
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		//1 child
		//left child
		if(root->left!=NULL && root->right==NULL)
		{
			node *temp=root->left;
			delete root;
			return temp;
		}

		//right child
		if(root->left==NULL && root->right!=NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		//2 child
		if(root->left!=NULL && root->right!=NULL)
		{
			node *temp=predecessor(root);
			int mini=temp->data;
			root->data=mini;
			root->left=deletenode(root->left,mini);
			return root;
		}
	}
	else if(root->data>data)
	{
		root->left=deletenode(root->left,data);
		return root;
	}
	else 
	{
		root->right=deletenode(root->right,data);
		return root;
	}

}

int main() {

 
	node *root=NULL;
	makebst(root);
	 
	 //cout<<root->data;
	 
	 int k;
	 cin>>k;
	 deletenode(root,k);
	 levelordertraverse(root);
	 cout<<endl;
	 // node * ans=NULL;
	 // //search(root,k,ans);

	 // if(ans==NULL)
	 // 	cout<<-1;
	 // else cout<<ans->data;

	 cout<<maxans(root)->data<<endl;
	 cout<<minans(root)->data<<endl;
	 cout<<predecessor(root)->data<<endl;
	 cout<<successor(root)->data<<endl;



	

	return 0;	

}
