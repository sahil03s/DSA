#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int lb, int ub, int target)
{
    if(lb > ub)
        return -1;
    
    int mid = lb + (ub-lb)/2;

    if(arr[mid] == target)
        return mid;

    else if(arr[mid] > target)
        return binarySearch(arr, lb, mid-1, target);

    else if(arr[mid] < target)
        return binarySearch(arr, mid+1, ub, target);

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

    int i = binarySearch(v,0,v.size()-1,6);
    cout << "\n\nPosition = " << i << "\n\n\n";

    return 0;
}