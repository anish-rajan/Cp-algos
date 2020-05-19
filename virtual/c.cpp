#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        vector<ll> lastind(n + 1);
        vector<ll> arr(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        ll ans = INT64_MAX;
        for (ll i = 1; i <= n; i++)
        {
            if (lastind[arr[i]] == 0)
            {
                lastind[arr[i]] = i;
            }
            else
            {
                ll temp = i - lastind[arr[i]] + 1;
                ans = min(ans, temp);
                lastind[arr[i]] = i;
            }
        }
        if (ans == INT64_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}