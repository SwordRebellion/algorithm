#include<stdio.h>
int V[1001][8193],b[1001][8193],n,M,m[1001],v[1001],x,y,output[1001],num=0;//V存价值，b存取与不取，n总游戏个数，M最大内存，m各游戏大小，v各游戏价值，V中xy取到最大价值的行列，output所下游戏暂存，num所下游戏数。
void MaxFun()
{
	int i,j;
	for(j=0;j<m[1];j++)
		V[1][j]=b[1][j]=0;
	for(j;j<=M;j++)
	{
		V[1][j]=v[1];
		b[1][j]=1;
	}
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=M;j++)
		{
			if(m[i]>j)
			{
				V[i][j]=V[i-1][j];
				b[i][j]=0;
			}
			else if(V[i-1][j]>V[i-1][j-m[i]]+v[i])
			{
				V[i][j]=V[i-1][j];
				b[i][j]=0;
			}
			else
			{
				V[i][j]=V[i-1][j-m[i]]+v[i];
				b[i][j]=1;
			}
		}
	}
}
void Search()
{
	int i,j,max=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=M;j++)
  			if(V[i][j]>max)
			{
				max=V[i][j];
				x=i;
				y=j;
			}
	}
}
int Print(int i,int j)
{
	if(i==0 || m==0 )
		return 0;
	if(b[i][j]==1)
	{
		Print(i-1,j-m[i]);
		output[num]=i;
		num++;
	}
	else
		Print(i-1,j);
}
int main()
{
	int i;
	scanf("%d%d",&n,&M);
	for(i=1;i<=n;i++)
		scanf("%d",&m[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	MaxFun();
	Search();
	Print(x,y);
	printf("%d\n",num);
	for(i=0;i<num-1;i++)
		printf("%d ",output[i]);
	printf("%d\n",output[i]);
	return 0;
}