#include <stdio.h>

void merge(int *arr, int lb, int mid, int ub)
{
    int i = lb, j = mid+1, k = 0;
    int temp[ub-lb+1];
    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];           
        else
            temp[k++] = arr[j++];
    } 
    if(i > mid)
    {
        while(j <= ub)
            temp[k++] = arr[j++];
    }
    else if(j > ub)
    {
        while(i <= mid)
            temp[k++] = arr[i++];
    }

    k = 0;
    for(i = lb; i <= ub; i++)
        arr[i] = temp[k++];
}

void merge_sort(int *arr, int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb+ub)/2;
        merge_sort(arr, lb, mid);     
        merge_sort(arr, mid+1, ub);
        merge(arr,lb,mid,ub);     
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
    merge_sort(arr,0,n-1);
    display(arr,n);
}