#include<stdio.h>
int MatrixChain(int p[],int n)
{
	int m[200][200];
	int i,c,j,k,q;
	for(i=1;i<=n;i++)
		m[i][i]=0;  //����ֻ��һ������ʱ���˻���Ϊ0
	for(c=2;c<=n;c++) //c:���������ȣ�c=2ʱΪ��С�������������
	{
		for(i=1;i<=n-c+1;i++) //�Ӿ�����(i,i+c)
		{
			j=i+c-1;
			m[i][j]=1000000000;//��ʼm[i][j]��ֵ
			for(k=i;k<=j-1;k++)//(i,j)/�䣬�����㷨����k�����ֵõ�
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