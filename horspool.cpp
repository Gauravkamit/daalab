#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define max 500

int t[max];

void shifttable(char p[])
{
	int i,j,m;
	m=strlen(p);
	for(i=0;i<max;i++)
	t[i]=m;
	for(j=0;j<m-1;j++)
	t[p[j]]=m-1-j;
}

int horspool(char src[],char p[])
{
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	i=m-1;
	while(i<n)
	{
		k=0;
		while((k<m)&&(p[m-1-k])==src[i-k])
		k++;
		if(k==m)
		return i-m+1;
		else
		i+=t[src[i]];
	}
	return -1;
}

int main()
{
	char src[100],p[100];
	int pos;
	cout<<"enter the text in which pattern is to be searched\n";
	cin.getline(src,100,'\n');
	cout<<"pattern to be searched\n";
	cin.getline(p,100,'\n');
	shifttable(p);
	pos=horspool(src,p);
	if(pos>=0)
	cout<<"pattern is found at positon"<<pos+1;
	else
	cout<<"pattern not found";
}
