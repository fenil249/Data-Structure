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
			
				//cout<<temp->data<<" ";

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
int main() {

 
	 node *root=NULL;	 
	 root=buildtree(root);
	 levelordertraverse(root);


	return 0;	

}
