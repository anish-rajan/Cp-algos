#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 998244353
ll t;
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
        v<ll> arr(n + 1);
        v<v<ll>> cnt(202);
        v<v<ll>> occ(n + 1, v<ll>(205, 0));
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            cnt[arr[i]].pb(i);
            for (ll j = 1; j <= 200; j++)
            {
                occ[i][j] += j == arr[i] ? occ[i - 1][j] + 1 : occ[i - 1][j];
            }
            // cout << occ[i][arr[i]] << " " << arr[i] << " " << cnt[arr[i]].back() << "\n";
        }
        ll ans = 1;
        for (ll i = 1; i <= 200; i++)
        {
            ll sz = cnt[i].size();
            for (ll j = 0; j < sz / 2; j++)
            {
                ll x = 2 * (j + 1);
                ll y = 0;
                for (ll k = 1; k <= 200; k++)
                {
                    y = max(y, occ[cnt[i][sz - j - 1] - 1][k] - occ[cnt[i][j]][k]);
                }
                ans = max(ans, x + y);
                // cout << ans << " " << j << " " << y << " " << i << "\n";
            }
            ans = max(ans, sz);
        }
        cout << ans << "\n";
    }
}