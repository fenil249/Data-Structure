 #include <iostream>
#include <bits/stdc++.h>
using namespace std;


class trienode{
public:
	char data;
	trienode * children[26];
	bool isterminal;

	trienode(char ch)
	{
		data=ch;

		for(int i=0;i<26;i++)
			children[i]=NULL;
		isterminal=false;
	}
};
class trie{
   public:

	trienode * root;

		trie()
		{
			root=new trienode('\0');
		}

	void insertword(trienode * root,string word){

		if(word.length()==0)
		{     
			root->isterminal=true;
			return;
		}

		int index=word[0]-'a';
		trienode *child;

		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		 {
			child=new trienode(word[0]);
			root->children[index]=child;
			//cout<<child->data;
		}

		insertword(child,word.substr(1));

	}

	void insert(string word)
	{
		insertword(root,word);
	}


	bool searchword(trienode * root,string word){

		if(word.length()==0)
		{     
			return root->isterminal;
		}

		int index=word[0]-'a';
		trienode *child;

		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		 {
		 	return false;
		}

		searchword(child,word.substr(1));

	}

	bool search1(string word)
	{
		return searchword(root,word);
	}


	  void print()
	  {
	  	cout<<root->children[0]->data<<" ";
	  	cout<<root->children[0]->children[1]->data<<" ";
	  	cout<<root->children[0]->children[1]->children[2]->isterminal<<" ";
	  	cout<<root->children[0]->children[1]->children[2]->children[3]->isterminal<<" ";
	  }


};
bool search(trienode *root, string key)
{
    struct trienode *child = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!child->children[index])
            return false;
 
        child = child->children[index];
    }
 
    return (child->isterminal);
}

void remove1(trienode *&root, string key)
{
    struct trienode *child = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!child->children[index])
            return ;
 
        child = child->children[index];
    }
 
    child->isterminal=false;
}

int main() {
	//	cout<<123;

	trie *t=new trie();
	t->insert("abcd");

	trienode * root1=new trienode('\0');
	t->insertword(root1,"zbcdd");
	t->insertword(root1,"fenil");
	remove1(root1,"fenil");	
	cout<<search(root1,"fenil");
	

	return 0;
}
