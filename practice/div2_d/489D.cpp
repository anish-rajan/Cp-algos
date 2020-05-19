#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 3003
#define N1 30003
// typedef long long int int;
vector<vector<int>> graph(N);
vector<vector<int>> dp(N, vector<int>(N));
vector<int> visited(N);
int ans = 0, n, m;
void dfs(int u)
{
    visited[u] = 1;
    vector<int> temp(N);
    for (int i = 0; i < graph[u].size(); i++)
    {
        dp[u][graph[u][i]] = 1;
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(N);
        for (int k = 0; k < graph[i].size(); k++)
            for (int j = 1; j <= n; j++)
            {
                if (j != i)
                    temp[j] += dp[graph[i][k]][j];
            }
        for (int j = 1; j <= n; j++)
        {
            int t = temp[j];
            if (t)
            {
                ans += (t * (t - 1)) / 2;
            }
        }
    }
    cout << ans << "\n";
}
