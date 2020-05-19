#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> visited(N + 1);
vector<vector<ll>> graph(N + 1);
vector<vector<ll>> dp(N + 1, vector<ll>(6));
void dfs(ll u, vector<ll> &arr)
{
    arr.push_back(u);
    visited[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i], arr);
        }
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll u;
    for (ll i = 1; i <= n; i++)
    {
        if (graph[i].size() >= 3)
        {
            cout << -1 << "\n";
            return 0;
        }
        else if (graph[i].size() == 1)
        {
            u = i;
        }
    }
    vector<ll> arr;
    dfs(u, arr);
    dp[2][0] = a[arr[0]] + b[arr[1]] + c[arr[2]];
    dp[2][1] = a[arr[0]] + c[arr[1]] + b[arr[2]];
    dp[2][2] = b[arr[0]] + c[arr[1]] + a[arr[2]];
    dp[2][3] = b[arr[0]] + a[arr[1]] + c[arr[2]];
    dp[2][4] = c[arr[0]] + b[arr[1]] + a[arr[2]];
    dp[2][5] = c[arr[0]] + a[arr[1]] + b[arr[2]];
    // cout << dp[2][0] << " " << dp[2][1] << " " << dp[2][2] << " " << dp[2][3] << " " << dp[2][4] << " " << dp[2][5] << "\n";

    for (ll i = 3; i < arr.size(); i++)
    {
        // cout << arr[i] << " ";
        for (ll j = 0; j < 6; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][5] + c[arr[i]];
            else if (j == 1)
                dp[i][j] = dp[i - 1][3] + b[arr[i]];
            else if (j == 2)
                dp[i][j] = dp[i - 1][0] + a[arr[i]];
            else if (j == 3)
                dp[i][j] = dp[i - 1][4] + c[arr[i]];
            else if (j == 4)
                dp[i][j] = dp[i - 1][1] + a[arr[i]];
            else if (j == 5)
                dp[i][j] = dp[i - 1][2] + b[arr[i]];
        }
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << " " << dp[i][4] << " " << dp[i][5] << "\n";
    }
    ll ans = INT64_MAX;
    ll ind = -1;
    for (ll j = 0; j < 6; j++)
    {
        if (ans > dp[n - 1][j])
        {
            ans = dp[n - 1][j];
            ind = j;
        }
    }
    cout << ans << "\n";
    vector<ll> colors(n + 1);
    if (ind == 4)
    {
        ll p = 0;
        for (ll j = n - 1; j >= 0; j--)
        {
            colors[arr[j]] = p;
            if (p == 0)
                p = 1;
            else if (p == 1)
                p = 2;
            else
                p = 0;
        }
    }
    if (ind == 2)
    {
        ll p = 0;
        for (ll j = n - 1; j >= 0; j--)
        {
            colors[arr[j]] = p;
            if (p == 0)
                p = 2;
            else if (p == 1)
                p = 0;
            else
                p = 1;
        }
    }
    if (ind == 1)
    {
        ll p = 1;
        for (ll j = n - 1; j >= 0; j--)
        {
            colors[arr[j]] = p;
            if (p == 0)
                p = 1;
            else if (p == 1)
                p = 2;
            else
                p = 0;
        }
    }
    if (ind == 5)
    {
        ll p = 1;
        for (ll j = n - 1; j >= 0; j--)
        {
            colors[arr[j]] = p;
            if (p == 0)
                p = 2;
            else if (p == 1)
                p = 0;
            else
                p = 1;
        }
    }
    if (ind == 0)
    {
        ll p = 2;
        for (ll j = n - 1; j >= 0; j--)
        {
            colors[arr[j]] = p;
            if (p == 0)
                p = 2;
            else if (p == 1)
                p = 0;
            else
                p = 1;
        }
    }
    if (ind == 3)
    {
        ll p = 2;
        for (ll j = n - 1; j >= 0; j--)
        {
            colors[arr[j]] = p;
            if (p == 0)
                p = 1;
            else if (p == 1)
                p = 2;
            else
                p = 0;
        }
    }
    for (ll j = 1; j <= n; j++)
    {
        cout << colors[j] + 1 << " ";
    }
    cout << "\n";
}