#include<stdio.h>
#include<math.h>

int max(int,int);

void warshall(int r[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	r[i][j]=max(r[i][j],r[i][k] && r[k][j]);
}

int max(int a,int b)
{
	if(a>b)
	return(a);
	else
	return(b);
}

void main()
{
	int r[10][10],a[10][10],i,j,n;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("\n enter adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&r[i][j]);
		}
	}
	warshall(r,n);
	printf("transitive closure:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",r[i][j]);
		}
		printf("\n");
	}
}
