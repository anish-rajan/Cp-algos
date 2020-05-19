#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 1000000007
ll n, m, r, k;
set<pair<ll, pair<pair<ll, ll>, ll>>, greater<pair<ll, pair<pair<ll, ll>, ll>>>> cods;
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}
ll f(ll x, ll y)
{
    return (min(n + 1, x + r) - max(x, r)) * (min(m + 1, y + r) - max(y, r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r >> k;
    for (ll i = 1; i <= n; i++)
    {
        ll y = (m + 1) / 2;
        cods.insert(mp(f(i, y), mp(mp(i, y), 1)));
        cods.insert(mp(f(i, y + 1), mp(mp(i, y + 1), 0)));
        // cout << i << " " << y << " " << f(i, y) << "\n";
    }
    ld ans = 0;
    while (k--)
    {
        auto temp = *(cods.begin());
        // cout << temp.fi << " ";
        ans += temp.fi;
        cods.erase(temp);
        if (temp.se.se == 1)
        {
            ll y = temp.se.fi.se - 1, x = temp.se.fi.fi;
            if (y >= 0)
                cods.insert(mp(f(x, y), mp(mp(x, y), 1)));
        }
        else
        {
            ll y = temp.se.fi.se + 1, x = temp.se.fi.fi;
            if (y <= m)
                cods.insert(mp(f(x, y), mp(mp(x, y), 0)));
        }
    }
    ans /= (n - r + 1) * (m - r + 1);
    printf("%0.11Lf\n", ans);
}