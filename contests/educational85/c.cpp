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
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 505
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
        v<pair<ll, ll>> a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i].fi >> a[i].se;
        }
        ll minmoves = 0;
        if (a[1].fi > a[n].se)
            minmoves += a[1].fi - a[n].se;
        for (ll i = 2; i <= n; i++)
        {
            if (a[i].fi > a[i - 1].se)
            {
                minmoves += a[i].fi - a[i - 1].se;
            }
        }
        ll ans = INT64_MAX;
        if (a[1].fi > a[n].se)
            ans = min(ans, minmoves + a[n].se);
        else
            ans = min(ans, minmoves + a[1].fi);
        for (ll i = 2; i <= n; i++)
        {
            if (a[i].fi > a[i - 1].se)
            {
                ans = min(ans, minmoves + a[i - 1].se);
            }
            else
            {
                ans = min(ans, minmoves + a[i].fi);
            }
        }
        cout << ans << '\n';
    }
}