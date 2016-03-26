#include<stdio.h>
int m,n,c[1000][1000],b[1000][1000];
char X[1000],Y[1000];
void DPLCSLength()
{
	int i,j;
		c[0][0]=0;
	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i]==Y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;//XY均移动到下一元素
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;  //X移动到下一元素
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;    //Y移动到下一元素
			}

		}
	}
}
void input()
{
	int i;
	scanf("%d%d",&m,&n);
	getchar();
	for(i=1;i<=m;i++)
		scanf("%c",&X[i]);
	getchar();
	for(i=1;i<=n;i++)
		scanf("%c",&Y[i]);
}
int PrintLCS(int b[1000][1000],char X[1000],int i,int j)
{
	if(i==0 || j==0)
		return 0;
	if(b[i][j]==1)
	{
		PrintLCS(b,X,i-1,j-1);
		printf("%c ",X[i]);
	}
	else if(b[i][j]==2)
		PrintLCS(b,X,i-1,j);
	else
		PrintLCS(b,X,i,j-1);

}
int main()
{
	input();
	DPLCSLength();
	PrintLCS(b,X,m,n);
	return 0;
}