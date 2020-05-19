#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 2003
#define mod 1000000007
vector<vector<ll>> graph(N);
vector<ll> visited(N), dp(N), visited1(N);
ll d, n;
vector<ll> a(N);
ll ans = 0;
void dfs(ll u, ll val)
{
    visited[u] = 1;
    dp[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (a[graph[u][i]] > val && a[graph[u][i]] <= val + d)
        {
            if (!visited[graph[u][i]])
            {
                dfs(graph[u][i], val);
                dp[u] = (dp[u] * (dp[graph[u][i]] + 1)) % mod;
            }
        }
        else if (a[graph[u][i]] == val && !visited1[graph[u][i]])
        {
            if (!visited[graph[u][i]])
            {
                dfs(graph[u][i], val);
                dp[u] = (dp[u] * (dp[graph[u][i]] + 1)) % mod;
            }
        }
    }
    // if (val == 2)
    // {
    //     cout << u << " " << dp[u] << "\n";
    // }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> d >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        visited1[i] = 1;
        fill(visited.begin(), visited.end(), 0);
        fill(dp.begin(), dp.end(), 0);
        dfs(i, a[i]);
        ans = (ans + dp[i]) % mod;
        // cout << dp[i] << " ";
    }
    cout << ans << "\n";
}