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
#define N 300005
#define mod 998244353
ll n;
vector<vector<ll>> graph(N);
vector<ll> visited(N);
v<pair<ll, ll>> dp(N);
v<ll> f(N);
void dfs(ll u)
{
    visited[u] = 1;
    dp[u].fi = dp[u].se = f[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i]);
            dp[u].fi = ((dp[u].fi) * (2 * dp[graph[u][i]].fi + 2 * dp[graph[u][i]].se - f[graph[u][i]] + mod) % mod) % mod;
            dp[u].se = ((dp[u].se) * (dp[graph[u][i]].se + 2 * dp[graph[u][i]].fi - f[graph[u][i]] + mod) % mod) % mod;
            f[u] = ((f[u]) * (dp[graph[u][i]].fi + dp[graph[u][i]].se - f[graph[u][i]] + mod) % mod) % mod;
        }
    }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    input_graph(n);
    dfs(1);
    ll ans = (dp[1].fi + dp[1].se - f[1] - 1 + 2 * mod) % mod;
    cout << ans << "\n";
}