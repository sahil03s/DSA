#include <stdio.h>

void selection_sort(int *arr, int n)
{
    int i,j,min,temp;
    for(i=0; i < n-1; i++)
    {
        min = i;
        for(j=i+1; j < n; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    selection_sort(arr,n);
    display(arr,n);
}