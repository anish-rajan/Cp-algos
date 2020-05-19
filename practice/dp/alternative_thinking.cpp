#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> ind;
    ll t = 0;
    ind.push_back(0);
    for (ll i = 1; i < n; i++)
    {
        if (s[i] != s[ind[t]])
        {
            t++;
            ind.push_back(i);
        }
        // cout << ind[t] << " ";
    }
    ll f = 0;
    ll last = 0;
    for (ll i = 1; i <= t; i++)
    {
        if (ind[i] - ind[i - 1] - 1 >= 2)
        {
            f = 1;
            break;
        }
        if (ind[i] - ind[i - 1] - 1 >= 1)
        {
            last++;
        }
    }
    if (n - ind[t] - 1 >= 2)
        f = 1;
    if (n - ind[t] - 1 >= 1)
        last++;
    if (last >= 2)
        f = 1;
    if (f == 1)
    {
        cout << ind.size() + 2 << "\n";
    }
    else if (last >= 1)
    {
        cout << ind.size() + 1 << "\n";
    }
    else
    {
        cout << ind.size() << "\n";
    }
}