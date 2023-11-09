#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> simpleSieve(int n)
{

    vector<bool> prime(n,true);

    for(int i=2; i*i<=n; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=n; j+=i)
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

vector<int> segmentedSieve(int n)
{
    int limit = floor(sqrt(n))+1;
    vector<int> prime = simpleSieve(limit);

    int low = limit;
    int high = 2*limit;


    while(low<n)
    {
        if(high > n)
            high = n;

        vector<bool> isprime(limit+1,true);

        for(int i=0; i<prime.size(); i++)
        {
            int lowlimit = floor(low/prime[i]) * prime[i];
            
            if(lowlimit < low)
                lowlimit += prime[i];

            for(int j = lowlimit; j<high; j+=prime[i])
            {
                isprime[j-low] = false;
            }
        }

        for(int i=low; i<high; i++)
        {
            if(isprime[i-low])
                prime.push_back(i);
        }

        low += limit;
        high += limit;
    }

    return prime;
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
    
    
    v = segmentedSieve(n);
    cout << "\nPrime numbers strictly less than " << n << " are : " << endl;
    print(v);

    return 0;
}