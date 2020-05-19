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
#define N 200005
#define mod 998244353

ll n;
vector<vector<ll>> gr(N);
v<ll> a(N);
v<pair<ll, ll>> dp(N);
vector<ll> visited(N);

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

void dfs(ll u)
{
    visited[u] = 1;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs(gr[u][i]);
        }
    }
    ll mini = INT64_MAX;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (dp[gr[u][i]].se > dp[gr[u][i]].fi + a[gr[u][i]])
        {
            mini = min(dp[gr[u][i]].se - dp[gr[u][i]].fi, mini);
            dp[u].fi += dp[gr[u][i]].se;
            dp[u].se += dp[gr[u][i]].se;
        }
        else
        {
            mini = min(a[gr[u][i]], mini);
            dp[u].fi += dp[gr[u][i]].fi + a[gr[u][i]];
            dp[u].se += dp[gr[u][i]].fi + a[gr[u][i]];
        }
    }
    if (gr[u].size() % 2)
    {
        dp[u].fi -= mini;
    }
    else if (gr[u].size() > 0)
    {
        dp[u].se -= mini;
    }
    // cout << u << " " << dp[u].fi << " " << dp[u].se << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll p1;
        cin >> p1 >> a[i];
        if (p1 != -1)
            gr[p1].pb(i);
    }
    dfs(1);
    dp[0].fi = max(dp[1].fi + a[1], dp[1].se);
    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        ans = max(ans, dp[i].fi);
    }
    cout << ans << "\n";
}