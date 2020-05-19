#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, s, k;
        cin >> n >> s >> k;
        vector<ll> arr(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        ll ans = INT64_MAX;
        sort(arr.begin(), arr.end());
        ll ind = lower_bound(arr.begin(), arr.end(), s) - arr.begin();
        for (ll i = ind; i < k; i++)
        {
            if (i < k - 1)
            {
                if (arr[i + 1] != arr[i] + 1)
                {
                    ans = min(ans, abs(s - arr[i] - 1));
                }
            }
            else if (arr[k - 1] != n)
            {
                ans = min(ans, abs(s - arr[k - 1] - 1));
            }
            // cout << ans << "\n";
        }
        for (ll i = ind; i >= 0; i--)
        {
            if (i > 0)
            {
                if (arr[i - 1] != arr[i] - 1)
                {
                    ans = min(ans, abs(s - arr[i] + 1));
                }
            }
            else if (arr[0] != 1)
            {
                ans = min(ans, abs(s - arr[0] + 1));
            }
        }
        // cout << s;
        if (k > 0 && arr[ind] == s)
            cout << ans << "\n";
        else
            cout << 0 << '\n';
    }
}