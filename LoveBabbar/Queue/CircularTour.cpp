#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
    public:
  
    //Function to find starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int start = 0;
        int balance = 0;
        int deficit = 0;
        
        for(int i=0; i<n; i++)
        {
            balance += p[i].petrol - p[i].distance;
            
            if(balance < 0)
            {
                deficit += balance;
                start = i+1;
                balance = 0;
            }
        }
        
        if(balance + deficit >= 0)
            return start;
        
        return -1;
    }

// int tour(petrolPump p[],int n)
// {
//     int front = 0, rear = 0;
//     int balance = 0;
//     int flag = 0;
        
//     while(front < n)
//     {
//         if(p[rear].petrol + balance >= p[rear].distance)
//         {
//             balance = p[rear].petrol + balance - p[rear].distance;
//             flag = 1;
//         }
//         else
//         {
//             balance = 0;
//             flag = 0;
//             front = rear+1;
//         }
                  
//         rear++;
        
            
//         if(rear == n )
//             rear = 0;
            
//         if(rear == front && flag)
//             return front;
//     } 
        
//     return -1;
// }

};

int main()
{
    int n = 4;
    petrolPump p[n];
    p[0].petrol = 4;
    p[1].petrol = 6;
    p[2].petrol = 7;
    p[3].petrol = 4;
    p[0].distance = 5;
    p[1].distance = 7;
    p[2].distance = 8;
    p[3].distance = 1;
    
    Solution obj;
    cout<<obj.tour(p,n)<<endl;
}
