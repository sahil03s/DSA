#include <stdio.h>

void insertion_sort(int *arr, int n)
{
    int temp;
    int i,j;
    for(i=1; i < n; i++)
    {
        temp = arr[i];
        for(j=i-1; j >= 0 && arr[j] > temp; j--)
            arr[j+1] = arr[j];
        arr[++j] = temp;
    }
    
}

void display(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ",*(arr+i));

    printf("\n\n");
}

void main()
{
    int n;
    printf("Input no. of elements : ");
    scanf("%d",&n);
    int arr[n];
    int i = 0;
    for(; i < n; i++)
    {
        printf("Enter data %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    insertion_sort(arr,n);
    display(arr,n);
}