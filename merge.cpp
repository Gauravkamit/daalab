#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void merge_sort(int,int,int[],int);
void merge(int,int,int,int[],int);

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
	
		cout<<"\n enter the array elements: ";
		for(i=0;i<n;i++)
		cin>>a[i];
	
	start=clock();
	merge_sort(0,n-1,a,n);
	end=clock();
	total_time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\n array sorted";
	
		for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	
	cout<<"\n total time taken for sorting :"<<total_time;
	cout<<"\n";
	return 0;
}

void merge_sort(int low,int high,int a[],int n)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid,a,n);
		merge_sort(mid+1,high,a,n);
		merge(low,mid,high,a,n);
	}
}

void merge(int low,int mid,int high,int a[],int n)
{
	int h,i,j,k,b[n];
	h=low;
	i=low;
	j=mid+1;
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	a[k]=b[k];
}

