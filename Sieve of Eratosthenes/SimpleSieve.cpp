#include <iostream>
#include <vector>

using namespace std;

vector<int> simpleSieve(int n)
{

    vector<bool> prime(n,true);
    prime[0] = prime[1] = false;


    for(int i=2; i*i<n; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<n; j+=i)
            {
                prime[j] = false;
            }

        }
    }
    
    vector<int> ans;
    for(int i=2; i<n; i++)
    {
        if(prime[i])
            ans.push_back(i);
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

    vector<int> v = simpleSieve(n);


    cout << "Prime numbers strictly less than " << n << " are : " << endl;
    print(v);

    return 0;
}