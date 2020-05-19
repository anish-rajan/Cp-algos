#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<vector<pair<ll, ll>>> graph(N);
vector<vector<ll>> kvalue(N);
vector<ll> visited(N), dp(N);
ll n, m;
const long long int INF = 10000000000000000;

ll real_val(ll val, ll u)
{
    ll si = kvalue[u].size();
    ll ind = lower_bound(kvalue[u].begin(), kvalue[u].end(), val) - kvalue[u].begin();
    if (ind < si)
    {
        if (val == kvalue[u][ind])
        {
            while (ind < si)
            {
                if (kvalue[u][ind] == val)
                    ind++, val++;
                else
                    break;
            }
        }
    }
    return val;
}

void dijkstra(long long int s, vector<long long int> &d)
{
    long long int n = graph.size();
    d.assign(n, INF);
    ll offset = real_val(0, s);
    d[s] = offset;
    using pii = pair<long long int, long long int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({offset, s});
    while (!q.empty())
    {
        long long int v = q.top().second;
        long long int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        offset = real_val(d[v], v);
        for (auto edge : graph[v])
        {
            long long int to = edge.first;
            long long int len = edge.second;

            if (offset + len < d[to])
            {
                d[to] = offset + len;
                q.push({d[to], to});
            }
        }
    }
}
void input_graph(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        long long int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back(make_pair(v, t));
        graph[v].push_back(make_pair(u, t));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    input_graph(m);
    for (ll i = 1; i <= n; i++)
    {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++)
        {
            ll temp;
            cin >> temp;
            kvalue[i].push_back(temp);
        }
    }
    fill(dp.begin(), dp.end(), -2);
    dijkstra(1, dp);
    ll ans = dp[n];
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
}