#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 100005
vector<vector<pair<long long int, long long int>>> graph(N);
const long long int INF = 10000000000000000;
long long int m;

void dijkstra(long long int s, vector<long long int> &d, vector<long long int> &p)
{
    long long int n = graph.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<long long int, long long int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        long long int v = q.top().second;
        long long int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : graph[v])
        {
            long long int to = edge.first;
            long long int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

// code for getting graph input
void input_graph()
{
    for (long long int i = 0; i < m; i++)
    {
        long long int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back(make_pair(v, t));
        graph[v].push_back(make_pair(u, t));
    }
}