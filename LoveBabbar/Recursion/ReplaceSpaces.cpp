//Replace spaces with '@40'

#include <iostream>
#include <vector>

using namespace std;

void update(string& s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            s.replace(i,1,"@40");
        }
    }
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
    cout << "Enter a string : " << endl;
    getline(cin,s);
    
    print(s);
    update(s);
    print(s);


    return 0;
}
