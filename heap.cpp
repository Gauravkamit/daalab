#include<time.h>
#include<iostream>
#include<math.h>
using namespace std;
	
int h[10000];

void heapify(int h[],int n)
{
	int i,j,n1,k,heap,v;
	n1=n;
	for(i=n1/2;i>=1;i--)
	{
		k=i;
		v=h[k];
		heap=0;
		while(!(heap)&&(2*k)<=n1)
		{
			j=2*k;
			if(j<n1)
			if(h[j]<h[j+1])
			j=j+1;
			if(v>=h[j])
			heap=1;
			else
			{
				h[k]=h[j];
				k=j;
			}
			h[k]=v;
		}
	}
}

int main()
{
	int i,n,size,t;
	clock_t start,end;
 	double total_time;
	cout<<"enter the number of elements\n";
	cin>>n;
	/* cout<<" enter the array elements\n";
	for(i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	cout<<"elements are\n";
	for(i=1;i<=n;i++)
	cout<<h[i]<<"\t";
	cout<<"\n";
	*/
	start=clock();
	heapify(h,n);
	/*cout<<h[i]<<"\t";
	cout<<"\n";*/
	for(i=n;i>=1;i--)
	{
		t=h[1];
		h[1]=h[i];
		h[i]=t;
		size=i-1;
		heapify(h,size);
	}
	end=clock();
	cout<<"elements sorted\n";
	/*	
	for(i=1;i<=n;i++)
	cout<<h[i]<<"\t";
	*/	
	total_time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\ntotal time taken is "<<total_time;
}
