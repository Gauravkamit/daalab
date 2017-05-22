#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
	long int i,j,n,r;
	double  total_time;
	clock_t start,end;
	long int temp;
	cout<<"\n enter the number of elements:";
	cin>>n;
	long int a[n];
	for(i=0;i<n;i++)
	{
		r=rand()%n;	
		a[i]=r;
	}
	/*
		cout<<"\n enter the array elements:";
		for(i=0;i<n;i++)
		cin>>a[i];
	*/
	start=clock();
	for(i=0;i<n-2;i++)
	for(j=0;j<=n-2-i;j++)
	if(a[j+1]<a[j])
	{
		temp=a[j+1];
		a[j+1]=a[j];
		a[j]=temp;
	}
	end=clock();
	total_time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\n array sorted";
	/*
		for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	*/
	cout<<"\n total time taken for sorting is:"<<total_time;
	cout<<"\n";
	return 0;
}
