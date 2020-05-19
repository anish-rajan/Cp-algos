#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main()
{
    ll n;
    cin >> n;
    ll x = 0, y = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            x = (x + y + 1) % mod;
        }
        else
        {
            y = (y + x + 1) % mod;
        }
    }
    cout << (x + y) % mod << "\n";
}