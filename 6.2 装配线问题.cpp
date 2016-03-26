#include<stdio.h>
int n,e1,e2,x1,x2,a[2][1000],t[2][1000],f[2][1000];
void input()
{
	int i;
	scanf("%d",&n);
	scanf("%d%d%d%d",&e1,&e2,&x1,&x2);
	for(i=0;i<n;i++)
		scanf("%d",&a[0][i]);
	for(i=0;i<n;i++)
		scanf("%d",&a[1][i]);
	for(i=0;i<n-1;i++)
		scanf("%d",&t[0][i]);
	for(i=0;i<n-1;i++)
		scanf("%d",&t[1][i]);
}
int FastWay()
{
	int i;
	f[0][0]=e1+a[0][0],f[1][0]=e2+a[1][0];
	for(i=1;i<n;i++)
	{
		if(f[0][i-1]<f[1][i-1]+t[1][i-1])
			f[0][i]=f[0][i-1]+a[0][i];
		else
			f[0][i]=f[1][i-1]+t[1][i-1]+a[0][i];
		if(f[1][i-1]<f[0][i-1]+t[0][i-1])
			f[1][i]=f[1][i-1]+a[1][i];
		else
			f[1][i]=f[0][i-1]+t[0][i-1]+a[1][i];
	}
	i--;
	if(f[0][i]+x1 < f[1][i]+x2)
		return f[0][i]+x1;
	else
		return f[1][i]+x2;
}
int main()
{
	int FastTime;
	input();
	FastTime=FastWay();
	printf("%d\n",FastTime);
	return 0;

}