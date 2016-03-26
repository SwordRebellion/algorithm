#include<stdio.h>
int begin[1000],over[1000],A[1000],n;
int GreedyTaskSelect()
{
	int i,j,k;
	A[1]=1;
	i=1;
	j=2;
	for(k=2;k<=n;k++)
	{
		if(begin[k]>=over[i])
		{
			A[j]=k;
			i=k;
			j++;
		}
	}
	return j-1;
}
void input()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&begin[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&over[i]);
}
void output(int j)
{
	int i;
	for(i=1;i<=j;i++)
		printf("%d ",A[i]);
	printf("\n");
}
int main()
{
	int j;
	input();
	j=GreedyTaskSelect();
	output(j);
	return 0;
}