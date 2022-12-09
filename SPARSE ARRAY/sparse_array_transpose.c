#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r=5,c=6;
    int i,j,k=0;
    int sparse[5][6]=
    {
        {0,0,0,6},
        {0,10,0,0,5},
        {0,2,2,5,0,7},
        {0,0,0,9},
        {12}
    };
    int size = 0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(sparse[i][j] != 0)
            size++;
        }
    }
    int arr[size][3];
    for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    if(sparse[i][j] != 0)
    {
        arr[k][0] = i;
        arr[k][1] = j;
        arr[k][2] = sparse[i][j];
        k++;
    }
    printf("\n\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int trans[size][3];
    k = 0 ;
    for(i = 0; i < c; i++)
    {
        for(j=0; j<size; j++)
        {
            if(arr[j][1] == i)
            {
                trans[k][0] = arr[j][1];
                trans[k][1] = arr[j][0];
                trans[k][2] = arr[j][2];
                k++;
            }
        }
    }
    printf("\n\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }
    int temp;
    for(i=0; i<size; i++)
    {
        temp = arr[i][0];
        arr[i][0] = arr[i][1];
        arr[i][1] = temp;
    }
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i][0] > arr[j][0] || arr[i][0]==arr[j][0] && arr[i][1] > arr[j][1])
            {
                temp = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0]=temp;
                temp = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1]=temp;
                temp = arr[i][2];
                arr[i][2]=arr[j][2];
                arr[j][2]=temp;
            }   
        }
    }

    printf("\n\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}