#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 200005
ll t;
vector<ll> arr(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> check(n + 1), cum(n + 1), cum1(n + 1), check1(n + 1);
        check = {0}, check1 = {0};
        v<pair<ll, ll>> ans;
        ll i1, i2 = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        cum[0] = 0, cum1[n] = arr[n];
        for (ll i = 1; i <= n; i++)
        {
            cum[i] = cum[i - 1] + arr[i];
        }
        for (ll i = n - 1; i >= 1; i--)
            cum1[i] = cum1[i + 1] + arr[i];
        for (ll i = n; i >= 0; i--)
        {
            check1[arr[i]]++;
            if (check1[arr[i]] == 2)
            {
                i2 = i;
                break;
            }
        }
        for (ll i = 1; i <= n - 1; i++)
        {
            check[arr[i]]++;
            if (check[arr[i]] == 2)
                break;
            ll temp = ((i) * (i + 1)) / 2;
            ll temp1 = n - i;
            temp1 = ((temp1) * (temp1 + 1)) / 2;
            // cout << i << " " << temp << " " << temp1 << " " << cum[i] << " " << cum1[i + 1] << "\n";
            if (temp == cum[i] && temp1 == cum1[i + 1] && i >= i2)
            {
                ans.pb(mp(i, n - i));
            }
        }
        cout << ans.size() << "\n";
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i].fi << " " << ans[i].se << "\n";
        }
    }
}