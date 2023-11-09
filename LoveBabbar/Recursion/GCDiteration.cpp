#include <iostream>

using namespace std;

int findGCD(int x, int y)
{
    if(!x)
        return y;

    if(!y)
        return x;

    while(x!=y)
    {
        x>y?x-=y:y-=x;
    }
    return x;

}

int main()
{
    int x,y;
    cout << "Enter two numbers : " << endl;
    cin >> x >> y;

    cout << "GCD = " << findGCD(x,y) << endl;


    return 0;
}