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
#define N 100005
#define mod 998244353

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
vector<vector<ll>> graph(N);
vector<ll> visited(N);
v<pair<ll, ll>> dp(N);
ll d, d1;
ll o, e;

pair<ll, ll> dfs1(ll u)
{
    ll o1 = 0, e1 = 0;
    visited[u] = 1;
    if (graph[u].size() == 1)
        return mp(1, 0);
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            auto temp = dfs1(graph[u][i]);
            if (temp.fi == 1)
                o1 = 1;
            if (temp.se == 1)
                e1 = 1;
        }
    }
    dp[u].fi = o1, dp[u].se = e1;
    // cout << u << " " << dp[u].fi << " " << dp[u].se << "\n";
    if (o1 == 1 && e1 == 1)
    {
        o = 1, e = 1;
        return mp(1, 1);
    }
    else if (o1 == 1)
        return mp(0, 1);
    else
        return mp(1, 0);
}

ll dfs(ll u)
{
    visited[u] = 1;
    ll l = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            ll temp = dfs(graph[u][i]);
            if (temp == 1)
                l++;
        }
    }
    if (l > 1)
        d1++, d += l;
    if (graph[u].size() == 1)
        return 1;
    return 0;
}

void input_graph(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    input_graph(n);
    for (ll i = 1; i <= n; i++)
    {
        if (graph[i].size() >= 2)
        {
            dfs(i);
            fill(visited.begin(), visited.end(), 0);
            dfs1(i);
            // cout << o << " " << e << "\n";
            break;
        }
    }
    ll maxf, minf;
    // cout << d << " " << d1 << "\n";
    maxf = n - 1 - d + d1;
    if (o == 1)
        minf = 3;
    else
        minf = 1;
    cout << minf << " " << maxf << "\n";
    // cout << maxf << "\n";
}