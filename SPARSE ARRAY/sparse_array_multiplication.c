#include <stdio.h>

void main()
{
    int r=4,c=4;
    int i,j,k=0;
    int sparse1[4][4]=
    {
        {0,10,0,12},
        {0,0,0,0},
        {0,0,5,0},
        {15,12,0,0}
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
    for(i=0; i<size1; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    int sparse2[4][4]=
    {
        {0,0,8,0},
        {0,0,0,23},
        {0,0,9,0},
        {20,25,0,0}
    };
    int size2 = 0;
    for(i=0; i<c; i++)
    {
        for(j=0; j<r; j++)
        {
            if(sparse2[i][j] != 0)
            size2++;
        }
    }
    int arr2[size2][3];
    k=0;
    for(i=0; i<c; i++)
    for(j=0; j<r; j++)
    if(sparse2[i][j] != 0)
    {
        arr2[k][0] = i;
        arr2[k][1] = j;
        arr2[k][2] = sparse2[i][j];
        k++;
    }
    
    // printf("\n\n");
    // for(i=0; i<size2; i++)
    // {
    //     for(j=0; j<3; j++)
    //     {
    //         printf("%d ",arr2[i][j]);
    //     }
    //     printf("\n");
    // }
    int temp;
    for(i=0; i<size2; i++)
    {
        temp = arr2[i][0];
        arr2[i][0] = arr2[i][1];
        arr2[i][1] = temp;
    }
    for(i=0; i<size2; i++)
    {
        for(j=i+1; j<size2; j++)
        {
            if(arr2[i][0] > arr2[j][0] || arr2[i][0]==arr2[j][0] && arr2[i][1] > arr2[j][1])
            {
                temp = arr2[i][0];
                arr2[i][0] = arr2[j][0];
                arr2[j][0]=temp;
                temp = arr2[i][1];
                arr2[i][1] = arr2[j][1];
                arr2[j][1]=temp;
                temp = arr2[i][2];
                arr2[i][2]=arr2[j][2];
                arr2[j][2]=temp;
            }   
        }
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
    int size3 = size1+size2;
    int arr3[size3][3];
    k=0;
    for(i=0; i<size1; i++)
    {
        for(j=0;j<size2;j++)
        {
            if(arr1[i][1] == arr2[j][1])
            {
                arr3[k][0] = arr1[i][0];
                arr3[k][1] = arr2[j][0];
                arr3[k][2] = arr1[i][2]*arr2[j][2];
                k++;
            }
        }
    }
    size3 = k;
    for(i=0; i<size3; i++)
    {
        for(j=i+1; j<size3; j++)
        {
            if(arr3[i][0] > arr3[j][0] || arr3[i][0]==arr3[j][0] && arr3[i][1] > arr3[j][1])
            {
                temp = arr3[i][0];
                arr3[i][0] = arr3[j][0];
                arr3[j][0]=temp;
                temp = arr3[i][1];
                arr3[i][1] = arr3[j][1];
                arr3[j][1]=temp;
                temp = arr3[i][2];
                arr3[i][2]=arr3[j][2];
                arr3[j][2]=temp;
            }   
        }
    }
    for(i=0; i<size3; i++)
    {
        for(j=i+1; j<size3; j++)
        {
            if(arr3[i][0] == arr3[j][0] && arr3[i][1] == arr3[j][1])
            {
                arr3[i][2] += arr3[j][2];
                for(int z=j; z<size3-1; z++)
                {
                    arr3[z][0] = arr3[z+1][0];
                    arr3[z][1] = arr3[z+1][1];
                    arr3[z][2] = arr3[z+1][2];
                }
                size3--;
            }
        }
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