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
#define N 200005
#define mod 998244353
ll n, m, k, s;
v<ll> d(N), p(N);
v<pair<ll, ll>> di(N), pi(N), cumd(N), cump(N);
ll p1, p2;
pair<ll, ll> ans;
ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

pair<bool, ll> check(ll d)
{
    ll sum1 = 0, sum2 = 0, t1 = cumd[d].fi, t2 = cump[d].fi;
    for (ll i = 1; i <= min(k, p1); i++)
        sum1 += di[i].fi;
    for (ll i = 1; i <= k - min(k, p1); i++)
        sum2 += pi[i].fi;
    for (ll i = min(k, p1); i >= 0; i--)
    {
        if (k - i > p2)
            continue;
        // if (d == 5)
        //     cout << i << " " << sum1 << " " << sum2 << " " << t1 << " " << t2 << " " << sum1 * t1 + sum2 * t2 << "\n";
        if (sum1 * t1 + sum2 * t2 <= s)
            return mp(1, i);
        sum1 -= di[i].fi;
        sum2 += pi[k - i + 1].fi;
    }
    return mp(0, 0);
}

void solve()
{
    ll l = 1, r = n;
    ans.fi = -1;
    cumd[0].fi = cump[0].fi = INT64_MAX;
    for (ll i = 1; i <= n; i++)
    {
        cumd[i] = min(cumd[i - 1], mp(d[i], i));
        cump[i] = min(cump[i - 1], mp(p[i], i));
    }
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        auto pos = check(mid);
        if (pos.fi == 1)
        {
            ans.fi = mid, ans.se = pos.se;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k >> s;
    for (ll i = 1; i <= n; i++)
        cin >> d[i];
    for (ll i = 1; i <= n; i++)
        cin >> p[i];
    for (ll i = 1; i <= m; i++)
    {
        ll c1, c2;
        cin >> c1 >> c2;
        if (c1 == 1)
            di[++p1].fi = c2, di[p1].se = i;
        else
            pi[++p2].fi = c2, pi[p2].se = i;
    }
    if (p1 > 0)
        sort(di.begin() + 1, di.begin() + p1 + 1);
    if (p2 > 0)
        sort(pi.begin() + 1, pi.begin() + p2 + 1);
    solve();
    if (ans.fi == -1)
    {
        cout << ans.fi << "\n";
    }
    else
    {
        cout << ans.fi << "\n";
        ll t1 = cumd[ans.fi].se, t2 = cump[ans.fi].se;
        ll p = ans.se;
        for (ll i = 1; i <= p; i++)
        {
            cout << di[i].se << " " << t1 << "\n";
        }
        for (ll i = 1; i <= k - p; i++)
        {
            cout << pi[i].se << " " << t2 << "\n";
        }
    }
}