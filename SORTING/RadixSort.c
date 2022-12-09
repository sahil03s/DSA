#include <stdio.h>
#include <stdlib.h>

int getmax(int *arr, int n)
{
    int x = arr[0];
    for(int i = 1; i < n; i++)
        if(x < arr[i])
            x = arr[i];

    return x;
}

void count_sort(int *arr, int n, int exp)
{
    int res[n];
    int *count = (int *)calloc(10,sizeof(int));
    int i;

    for(i=0; i < n; i++)
        count[ (arr[i] / exp) % 10]++;

    for(i=1; i<10; i++)
        count[i] += count[i-1];

    for(i = n-1; i >= 0; i--)
    {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[ (arr[i] / exp) % 10]--;
    }

    for(i=0; i<n; i++)
        arr[i] = res[i];
}

void radix_sort(int *arr, int n)
{
    int max = getmax(arr,n);

    for(int exp = 1; max/exp > 0; exp*=10)
        count_sort(arr,n,exp);
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
    radix_sort(arr,n);
    display(arr,n);
}