#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef long long int int;
#define N 5005
vector<vector<pair<int, int>>> graph(N);
vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N));
int ans = 2, n, m, t;
int calc(int u, int j)
{
    // cout << u << " " << j << "\n";
    if (j < 0)
        return INT32_MAX;
    if (dp[u][j].first != -1)
        return dp[u][j].first;
    dp[u][j].first = INT32_MAX;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int temp = calc(graph[u][i].first, j - 1) + graph[u][i].second;
        if (temp < dp[u][j].first && temp > 0)
        {
            dp[u][j].first = temp;
            dp[u][j].second = graph[u][i].first;
        }
    }
    return dp[u][j].first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j].first = -1;
        }
    }
    dp[1][1].first = 0;
    dp[1][1].second = 0;
    int ind;
    for (int i = n; i >= 1; i--)
    {
        if (calc(n, i) <= t)
        {
            ind = i;
            break;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << dp[i][j].first << " ";
    //     cout << endl;
    // }
    cout << ind << "\n";
    int p = dp[n][ind].second;
    vector<int> places;
    places.push_back(n);
    while (ind > 1)
    {
        places.push_back(p);
        p = dp[p][--ind].second;
    }
    for (int i = places.size() - 1; i >= 0; i--)
    {
        cout << places[i] << " ";
    }
    cout << endl;
}