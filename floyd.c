#include<stdio.h>

int min(int,int);

void floyd(int a[10][10],int n)
{
	int d[10][10],i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	printf("\n the distance matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
}

int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

void main()
{
	int n,i,j,a[10][10];
	printf(" enter the number of nodes:\n");
	scanf("%d",&n);
	printf(" enter the weight of the matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	floyd(a,n);
}
