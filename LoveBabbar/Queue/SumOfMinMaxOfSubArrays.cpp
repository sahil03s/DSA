//Sum of minimum and maximum elements of all subarrays of size k.

#include <iostream>
#include <queue>

using namespace std;

// T.C. = O(n)  S.C.=O(k)
int SumOfKsubArray(int arr[], int n, int k)
{
    //maxi stores the potential maximum element in decreasing order and mini stores potential minimum element  in increasing order
    deque<int> maxi(k);
    deque<int> mini(k);

    // Process first window of size K
    for(int i=0; i<k; i++)
    {
        // Remove all previous smaller that are elements are useless
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        // Remove all previous greater element that are useless
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        // Add current element at rear of both deque
        maxi.push_back(i);
        mini.push_back(i);
    }

    // Element at the front of the deque 'maxi' & 'mini' is the largest and smallest element of previous window respectively
    int sum = arr[maxi.front()] + arr[mini.front()];

    //after each step we will first pop any element from maxi and mini which is now out of current window and then add the new element in sliding window in maxi and mini in sorted manner and then calculate the sum accordingly
    for(int i=k; i<n; i++)
    {
        // Remove all elements which are out of this window
        while(!maxi.empty() && i-maxi.front() >= k)
            maxi.pop_front();

        while(!mini.empty() && i-mini.front() >= k)
            mini.pop_front();

        // Remove all previous smaller that are elements are useless
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        // Remove all previous greater element that are useless
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        
        // Add current element at rear of both deque
        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
        
    }

    return sum;
}

void print(int arr[], int n)
{
    cout << "\n";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << endl << endl;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2}; //6+4+4+4
    int k = 4;
    print(arr, 7);

    int x = SumOfKsubArray(arr, 7, k);

    cout << "Sum = " << x << endl;
    return 0;
}