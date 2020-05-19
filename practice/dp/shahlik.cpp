#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;
    ll i, diff = 0;
    for (i = k + 1; i <= n; i += 2 * k + 1)
    {
        ans.pb(i);
    }
    if (i - n <= k)
    {
        ans.pb(n);
        diff = k + 1 - n + (2 * k + 1) * (n / (2 * k + 1));
    }
    cout << ans.size() << "\n";
    for (ll i = 0; i < ans.size(); i++)
    {
        if (ans[i] != n)
        {
            ans[i] -= diff;
        }
        cout << ans[i] << " ";
    }
}