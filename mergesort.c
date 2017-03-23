#include<stdio.h>
#include<stdlib.h>

void merge1(int A[],int i,int mid,int j)
{
    int p,m,k;
    int n1=(mid-i)+1;
    int n2=j-mid;
    int l[n1],r[n2];
    for(p=0;p<n1;p++)
        l[p]=A[i+p];
    for(m=0;m<n2;m++)
        r[m]=A[mid+1+m];
    p=0;
    m=0;
    k=i;
    while(p<n1&&m<n2)
    {
        if(l[p]<=r[m])
        {
            A[k]=l[p];
            p++;
            k++;
        }
        else
        {
            A[k]=r[m];
            m++;
            k++;
        }
    }
    while(p<n1)
    {
        A[k]=l[p];
        p++;
        k++;
    }
    while(m<n2)
    {
        A[k]=r[m];
        m++;
        k++;
    }
}
void mergesort1(int A[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort1(A,i,mid);
        mergesort1(A,mid+1,j);
        merge1(A,i,mid,j);
    }
}
int main()
{
    int i;
    int A[]={5,4,7,1,8,3,2,6};
    int n=sizeof(A)/sizeof(int);
    mergesort1(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    return 0;
}
