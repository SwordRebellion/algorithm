#include<stdio.h>
int MatrixChain(int p[],int n)
{
	int m[200][200];
	int i,c,j,k,q;
	for(i=1;i<=n;i++)
		m[i][i]=0;  //定义只有一个矩阵时‘乘积’为0
	for(c=2;c<=n;c++) //c:矩阵链长度，c=2时为最小子问题两两相乘
	{
		for(i=1;i<=n-c+1;i++) //子矩阵链(i,i+c)
		{
			j=i+c-1;
			m[i][j]=1000000000;//初始m[i][j]的值
			for(k=i;k<=j-1;k++)//(i,j)/间，最优算法是在k处划分得到
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
					m[i][j]=q;
			}
		}

	}
	return m[1][n];

}
int main()
{
	int i,n,p[200],min;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
	min=MatrixChain(p,n);
	printf("%d\n",min);
	return 0;
}