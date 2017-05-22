#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void quick_sort(int[],int,int);
int position(int[],int,int);

int main()
{
	int n,i,r;
	double total_time;
	clock_t start,end;
	
	cout<<"\n enter the number of elements:";
	cin>>n;
	int a[n];

	for(i=0;i<n;i++)
	{
		r=rand()%n;
		a[i]=r;
	}
	/*
		cout<<"enter the array elements:";
		for(i=0;i<n;i++)
		cin>>a[i];
	*/
	start=clock();
	quick_sort(a,0,n-1);
	end=clock();
	total_time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\n array sorted\n";
	/*
		for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	*/
	cout<<"\n total time taken for sorting is:"<<total_time;
	cout<<"\n";
	return 0;
}

void quick_sort(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=position(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}

int position(int a[],int l,int u)
{
	int i,j,v,temp;
	v=a[l];
	i=l;
	j=u+1;
	do
	{
		do
		  i++;
		while
		     (a[i]<v && i<=u);
		do
		  j--;
		while
		     (v<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	while(i<j);
	a[l]=a[j];
	a[j]=v;
 	return j;
}
