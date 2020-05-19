#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector<vector<int>> graph(N);
vector<int> visited(N);
vector<int> leaves(N);
void dfs(int u)
{
    visited[u] = 1;
    leaves[u - 1] = 0;
    if (graph[u].size() == 1 && u != 1)
    {
        leaves[u - 1] = 1;
        return;
    }
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i]);
            leaves[u - 1] += leaves[graph[u][i] - 1];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        graph[i].push_back(u);
        graph[u].push_back(i);
    }
    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        leaves[i] = 0;
    }
    dfs(1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << visited[i] << " ";
    // }
    sort(leaves.begin(), leaves.begin() + n);
    for (int i = 0; i < n; i++)
    {
        cout << leaves[i] << " ";
    }
    cout << "\n";
}