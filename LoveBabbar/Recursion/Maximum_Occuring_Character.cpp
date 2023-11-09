#include <iostream>
#include <vector>

using namespace std;

char maxOccuringCharacter(string s)
{
    vector<int> freq(26);
    int n = s.size();
    int max = 0;

    for(int i=0; i<n; i++)
    {
        int idx=-1;
        if(s[i]<='Z')
            idx = s[i]-'A';
        else
            idx = s[i]-'a';

        freq[idx]++;
        
        if(freq[max]<freq[idx])
            max = idx;
        else if(freq[max] == freq[idx] && max > idx)
            max = idx;
        

        
    }

    return 'a' + max;
}

void print(string& s)
{
    for(char i : s)
        cout << i;

    cout << endl << endl;
}

int main()
{
    string s;
    cout << "Enter a string : " ;
    cin >> s;
    print(s);

    cout << maxOccuringCharacter(s) << endl;
    return 0;
}