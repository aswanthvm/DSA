#include <stdio.h>
void BubbleSort(int n,int arr[]){
    int temp;
    for(int i=1;i<n;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    for (int j=0;j<n;j++)
    {
        printf("%d ",arr[j]);
    }

}
int main()
{
    int n;
    printf("Enter the size of the array ");
    scanf("%d",&n);
    int arr[n];
    for (int j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
        
    }
    BubbleSort(n,arr);
    
    return 0;
}