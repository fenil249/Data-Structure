#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class queue2{
public:
	int *a;
	int front;
	int rear;
	int size;

		queue2()
		{
			this->size=100000;
			a=new int[size];
			front=0;
			rear=0;
		}


	void push2(int x)
	{
		if(rear==size)
		{
			cout<<"queue is full";
		}
		else
		{
			a[rear]=x;
			rear++;

		}
	}
	void pop2()
	{
		if(front==rear)
		cout<<"queue is empty";

		a[front]=-1;
		front++;

		if(front==rear)
		{
			front=0;
			rear=0;
		}

	}
	int front2()
	{
		if(rear==front)
		return -1;

		return a[front];
	}
	bool empty2()
	{
		if(rear==front)
			return true;
		else return false;
	}
};



int main() {

   queue2 q;
   q.push2(2);
   q.push2(5);
   q.push2(7);
   q.push2(9);
   q.pop2();
   q.pop2();
   cout<<q.front2();




	return 0;	

}
