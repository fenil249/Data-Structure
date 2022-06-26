#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class stack2{
public:
	int *arr;
	int size;
	int top;

	stack2(int size)
	{
		this->size=size;
		top=-1;
		arr=new int[size];
	}
	void push(int element)
	{
		if(top+1<size)
			arr[++top]=element;
		else cout<<"full";
	}
	void pop()
	{
		if(top==-1)
			cout<<"empty";
		else top--;
	}

	int peek()
	{
		if(top!=1 and top<size)
			return arr[top];
		else {cout<<"empty";
			return -1;}
	}

	bool isempty()
	{
		if(top==-1)
			return true;
		else return false;
	}



};

int main() {
	stack2 st(5);
	st.push(2);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
	//st.push(2);
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	
	cout<<st.isempty();



	return 0;	

}
