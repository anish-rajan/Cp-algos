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
#define N 1003
ll t, n;
v<pair<pair<ll, ll>, ll>> times(N);
v<pair<ll, char>> ans(N);
ll i1, i2;
bool sortbysec(const pair<pair<ll, ll>, ll> &a,
               const pair<pair<ll, ll>, ll> &b)
{
    return (a.fi.se < b.fi.se);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        cin >> n;
        i1 = -1, i2 = -1;
        for (ll i = 1; i <= n; i++)
        {
            cin >> times[i].fi.fi >> times[i].fi.se;
            times[i].se = i;
        }
        sort(times.begin() + 1, times.begin() + n + 1);
        ll f = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (times[i].fi.fi < i1 && times[i].fi.fi < i2)
            {
                f = 0;
                break;
            }
            if (times[i].fi.fi >= i1)
                ans[i].se = 'C', ans[i].fi = times[i].se, i1 = times[i].fi.se;
            else
                ans[i].se = 'J', ans[i].fi = times[i].se, i2 = times[i].fi.se;
        }
        if (f == 0)
        {
            cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
            continue;
        }
        sort(ans.begin() + 1, ans.begin() + n + 1);
        cout << "Case #" << i + 1 << ": ";
        for (ll i = 1; i <= n; i++)
            cout << ans[i].se;
        cout << endl;
    }
}