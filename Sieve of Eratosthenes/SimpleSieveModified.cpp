#include <iostream>
#include <vector>

using namespace std;

vector<int> simpleSieveModified(int n)
{

    vector<bool> prime(n/2,true);
    prime[0] = false;

    for(int i=3; i*i<n; i+=2)
    {
        if(prime[i/2])
        {
            for(int j=i*i; j<n; j+=2*i)
            {
                prime[j/2]=false;
            }
        }
    }
    
    vector<int> ans{2};
    for(int i=0; i<prime.size(); i++)
    {
        if(prime[i])
            ans.push_back(i*2+1);
    }


    return ans;
}

void print(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    
    cout << "\n\n";
}

int main()
{
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    vector<int> v = simpleSieveModified(n);


    cout << "Prime numbers strictly less than " << n << " are : " << endl;
    print(v);

    return 0;
}