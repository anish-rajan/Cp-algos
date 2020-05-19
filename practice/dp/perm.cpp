#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;
    for (ll i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            ans.pb(2 * i - 1);
            ans.pb(2 * i);
        }
        else
        {
            ans.pb(2 * i);
            ans.pb(2 * i - 1);
        }
    }
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}