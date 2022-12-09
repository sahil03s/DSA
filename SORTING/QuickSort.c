#include <stdio.h>

int partition(int *arr, int lb, int ub)
{
    int start = lb, end = ub;
    int pivot = arr[lb], temp;

    while(start < end)
    {
        while(arr[start] <= pivot && start <= ub)
            start++;

        while(arr[end] > pivot && end >= lb)
            end--;

        if(start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;        
        }
    }

    temp = arr[end];
    arr[end] = arr[lb];
    arr[lb] = temp; 

    return end;

}

void quick_sort(int *arr, int lb, int ub)
{
    int loc;
    if(lb < ub)
    {
        loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc-1);
        quick_sort(arr, loc+1, ub);
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
    quick_sort(arr,0, n-1);
    display(arr,n);
}