#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()

ll n, m, d;
vector<vector<ll>> graph(N);
vector<ll> visited(N), p(N), dp1(N);
v<pair<ll, ll>> dp(N);

void dfs1(ll u)
{
    visited[u] = 1;
    dp[u].se = INT64_MIN;
    if (p[u])
        dp[u].fi = 0;
    else
        dp[u].fi = INT64_MIN;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs1(graph[u][i]);
            ll temp = dp[graph[u][i]].fi;
            if (temp >= 0)
            {
                if (temp + 1 >= dp[u].fi)
                {
                    dp[u].se = dp[u].fi;
                    dp[u].fi = temp + 1;
                }
                else if (temp + 1 >= dp[u].se)
                    dp[u].se = temp + 1;
            }
        }
    }
    // cout << u << " " << dp[u].fi << " " << dp[u].se << "\n";
}
void dfs2(ll u, ll par)
{
    visited[u] = 1;
    dp1[u] = dp1[par] + 1;
    if (dp[u].fi + 1 == dp[par].fi)
    {
        dp1[u] = max(dp1[u], dp[par].se + 1);
    }
    else
        dp1[u] = max(dp1[u], dp[par].fi + 1);
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs2(graph[u][i], u);
        }
    }
    // cout << u << " " << dp1[u] << "\n";
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
    cin >> n >> m >> d;
    for (ll i = 0; i < m; i++)
    {
        ll val;
        cin >> val;
        p[val] = 1;
    }
    input_graph(n);
    dp1[0] = INT64_MIN;
    dp[0].fi = INT64_MIN, dp[0].se = INT64_MIN;
    dfs1(1);
    fill(ALL(visited), 0);
    dfs2(1, 0);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {

        if (dp[i].fi <= d && dp1[i] <= d)
            ans++;
    }
    cout << ans << "\n";
}