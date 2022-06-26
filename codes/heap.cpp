 #include <iostream>
#include <bits/stdc++.h>
using namespace std;

class heap{
public:


	int arr[100];
	int size;

	heap()
	{
		arr[0]=-1;
		size=0;
	}


	void insert(int data)
	{
		size=size+1;
		int index=size;

		arr[index]=data;


		while(index>1)
		{
			int parent=index/2;

			if(arr[parent]<arr[index])
			{
				swap(arr[parent],arr[index]);
				index=parent;
			}
			else return ;
		}
	}
	void print()
	{
		for(int i=1;i<=size;i++)
			cout<<arr[i]<<" ";
	}

	void delete2()
	{
		if(size==0)
		{
			cout<<"Nothig here to be delete";
			return;
		}

		swap(arr[1],arr[size]);
		size=size-1;
		int index=1;

		while(index<=size)
		{
		int left=2*index;
		int right=2*right+1;

		if(arr[left]>arr[right] && arr[left]>arr[index] && left<=size)
		{
			swap(arr[left],arr[index]);
			index=left;
		}
		else if(arr[right]>arr[left] && arr[right]>arr[index] &&right <=size)
		{
			swap(arr[right],arr[index]);
			index=right;
		}
		else return;

		}
	}
};
void makeheap(vector<int> &a,int n,int i)
{
     int left=2*i;
     int largest=i;
     int right=2*i+1;

     	if(left<=n && a[left]>a[largest])
     	{
     		largest=left;
     	}
     	
     	if(right<=n && a[right]>a[largest])
     	{
     		largest=right;
     	}


     	if(largest!=i)
     	{
     		swap(a[largest],a[i]);
     		makeheap(a,n,largest);
     	}
     	else return;
    

}

void heapify(vector<int> &a)
{
	int n=a.size()-1;


	for(int i=n/2;i>0;i--)
		makeheap(a,n,i);
}
void heapsort(vector<int> &a)
{
	int n=a.size()-1;


	for(int i=n;i>0;i--)
	{
		swap(a[1],a[i]);
		makeheap(a,i-1,1);
	}

}

int main() {
	heap h;
	h.insert(55);
	h.insert(70);
	h.insert(2);
	h.insert(100);

	h.delete2();


	//h.print();
	vector<int> a={-1,1,2,3,4,5,6,7};
	heapify(a);

	
	heapsort(a);
	for(int i=1;i<a.size();i++)
		cout<<a[i]<<" ";
 
	return 0;	

}
