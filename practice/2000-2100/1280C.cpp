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
#define N 300005
#define mod 1000000007
ll t, n;
v<v<ll>> gr(N);
v<ll> visited(N), dp(N), parent(N);
v<pair<pair<ll, ll>, ll>> edges(N);
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
void dfs(ll u, ll par)
{
    visited[u] = 1;
    dp[u] = 1;
    parent[u] = par;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs(gr[u][i], u);
            dp[u] += dp[gr[u][i]];
        }
    }
}

void input_gr(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v, val;
        cin >> u >> v >> val;
        gr[u].push_back(v);
        gr[v].push_back(u);
        edges.pb(mp(mp(u, v), val));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        input_gr(2 * n);
        dfs(1, 0);
        ll minans = 0, maxans = 0;
        // for (ll i = 1; i <= 2 * n; i++)
        //     cout << dp[i] << " ";
        for (ll i = 0; i < edges.size(); i++)
        {
            ll a = edges[i].fi.fi, b = edges[i].fi.se, temp;
            if (parent[a] == b)
                temp = dp[a];
            else
                temp = dp[b];
            maxans += min(temp, 2 * n - temp) * edges[i].se;
            minans += temp % 2 ? edges[i].se : 0;
        }
        cout << minans << " " << maxans << "\n";
        for (ll i = 1; i <= 2 * n; i++)
            gr[i].clear();
        edges.clear();
        fill(dp.begin(), dp.begin() + 2 * n + 1, 0);
        fill(parent.begin(), parent.begin() + 2 * n + 1, 0);
        fill(visited.begin(), visited.begin() + 2 * n + 1, 0);
    }
}