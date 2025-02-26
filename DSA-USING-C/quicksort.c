#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int part(int a[],int low,int high)
{
    int piv=a[high];
    int i=low-1;
    for (int j=low;j<high;j++)
    {
        if(a[j]<piv)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
int qs(int a[],int low,int high)
{
    if (low<high)
    {
        int piv=part(a,low,high);
        qs(a,low,piv-1);
        qs(a,piv+1,high);
    }
}
int main()
{
    int a[]={12,3,42,5,32,56,8,64,1,44};
    qs(a,0,9);
    for (int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}