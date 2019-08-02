#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    
    if (b >= c)
    {
        cout << "-1"; return 0;
    }
    else {
        double x = a / (c - b);
        printf("%.0lf", floor(x) + 1);
    }
    return 0;
}