#include<stdio.h>
int ext_euc(int a,int b,int *x,int *y)
{
	if(a==0)
	{
		*x=0,*y=1;
		return b;
	}
	int x1,y1;
	int g=ext_euc(b%a,a,&x1,&y1);
	*x=y1-((b/a)*x1);
	*y=x1;
	return g;
}

int main()
{
	int a,b;
	int x,y;
	int g;
	printf("nos.\n");
	scanf("%d %d",&a,&b);
	g=ext_euc(a,b,&x,&y);
	printf("gcd=%d , x=%d ,y=%d\n",g,x,y);
	return 0;
}

