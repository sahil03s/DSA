#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r=5,c=6;
    int i,j,k=0;
    int sparse1[5][6]=
    {
        {0,0,0,6},
        {0,7},
        {0,2,0,5},
        {0},
        {4}
    };
    int size1 = 0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(sparse1[i][j] != 0)
            size1++;
        }
    }
    int arr1[size1][3];
    for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    if(sparse1[i][j] != 0)
    {
        arr1[k][0] = i;
        arr1[k][1] = j;
        arr1[k][2] = sparse1[i][j];
        k++;
    }
    printf("\n\n");
    k =0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(*(*(arr1+k)) == i && *(*(arr1+k)+1) == j)
            {
                printf("%d ",*(*(arr1+k)+2));
                k++;
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<size1; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    int sparse2[5][6]=
    {
        {0},
        {0,3,0,0,5},
        {0,0,2,0,0,7},
        {0,0,0,9},
        {8}
    };
    int size2 = 0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(sparse2[i][j] != 0)
            size2++;
        }
    }
    int arr2[size2][3];
    k=0;
    for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    if(sparse2[i][j] != 0)
    {
        arr2[k][0] = i;
        arr2[k][1] = j;
        arr2[k][2] = sparse2[i][j];
        k++;
    }
    printf("\n\n");
    k =0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(*(*(arr2+k)) == i && *(*(arr2+k)+1) == j)
            {
                printf("%d ",*(*(arr2+k)+2));
                k++;
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<size2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    i=0,j=0,k=0;
    int size3 = 0;
    int arr3[size1+size2][3];
    while(i < size1 && j < size2)
    {
        if(arr1[i][0] == arr2[j][0] && arr1[i][1] == arr2[j][1])
        {
            size3++;
            arr3[k][0] = arr1[i][0];
            arr3[k][1] = arr1[i][1];
            arr3[k++][2] = arr1[i][2]+arr2[j][2];
            i++;
            j++;
        }
        else if(arr1[i][0] < arr2[j][0] || arr1[i][0] == arr2[j][0] && arr1[i][1] < arr2[j][1])
        {
            size3++;
            arr3[k][0] = arr1[i][0];
            arr3[k][1] = arr1[i][1];
            arr3[k++][2] = arr1[i][2];
            i++;
        }
        else
        {
            size3++;
            arr3[k][0] = arr2[j][0];
            arr3[k][1] = arr2[j][1];
            arr3[k++][2] = arr2[j][2];
            j++;
        }
    }
    if(i < size1)
    while(i < size1)
    {
        size3++;
        arr3[k][0] = arr1[i][0];
        arr3[k][1] = arr1[i][1];
        arr3[k++][2] = arr1[i][2];
        i++;
    }
    if(j < size2)
    while(j < size2)
    {
        size3++;
        arr3[k][0] = arr2[j][0];
        arr3[k][1] = arr2[j][1];
        arr3[k++][2] = arr2[j][2];
        j++;
    }
    printf("\n\n");
    k =0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(*(*(arr3+k)) == i && *(*(arr3+k)+1) == j)
            {
                printf("%d ",*(*(arr3+k)+2));
                k++;
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<size3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
}