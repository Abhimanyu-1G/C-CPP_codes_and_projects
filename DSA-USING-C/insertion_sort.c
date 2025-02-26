#include<stdio.h>
int insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j<0 && arr[j]<arr[j-1])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    insertion_sort(arr,n);
    display(arr,n);
    return 0;
}