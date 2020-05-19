#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll r = __gcd(x, y);
    x /= r, y /= r;
    ll r1 = a / x, r2 = b / y;
    if (r1 == 0 || r2 == 0)
        a = 0, b = 0;
    else if (r1 == r2)
    {
        a = x * r1;
        b = y * r2;
    }
    else if (r1 < r2)
    {
        a = x * r1;
        b = y * r1;
    }
    else
    {
        a = x * r2;
        b = y * r2;
    }
    cout << a << " " << b << "\n";
}