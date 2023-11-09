#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int start = 0, end = arr.size()-1;
    
    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid] < target)
            start = mid + 1 ;

        else if(arr[mid] > target)
            end = mid - 1 ;

        else    
            return mid;
        
    }

    return -1;
}

int main()
{
    vector<int> v;
    for(int i=2; i<=8; i+=2)
        v.push_back(i);

    v.insert(v.begin()+2,4);
    v.insert(v.begin()+3,6);
    cout <<"Vector is : " << endl << endl; 
    for(int i: v)
    {
        cout << i << " " ;
    }
    cout << endl;

    int i = binarySearch(v,34);
    cout << "\n\nPosition = " << i << "\n\n\n";

    return 0;
}