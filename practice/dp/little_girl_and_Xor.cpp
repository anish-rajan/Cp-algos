#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll l, r;
    cin >> l >> r;
    vector<ll> la, ra;
    ll ans = 0;
    while (l > 0)
    {
        la.push_back(l % 2);
        l /= 2;
    }
    while (r > 0)
    {
        ra.push_back(r % 2);
        r /= 2;
    }
    if (la.size() != ra.size())
    {
        ans = (ll)pow(2, ra.size()) - 1;
    }
    else
    {
        ll temp = la.size() - 1;
        while (la[temp] == ra[temp] && temp >= 0)
        {
            temp--;
        }
        ans = (ll)pow(2, temp + 1) - 1;
    }
    cout << ans << "\n";
}