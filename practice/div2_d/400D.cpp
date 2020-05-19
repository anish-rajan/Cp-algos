#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
#define K 505
vector<vector<pair<long long int, long long int>>> graph(N);
vector<ll> d(N), c(K), compo(N);
vector<vector<ll>> dp(K, vector<ll>(K));
ll n, m, k;
const long long int INF = 10000000000000000;

void floydWarshall()
{

    for (ll i = 0; i < k; i++)
        dp[i][i] = 0;
    long long int i, j, p;
    for (p = 0; p < k; p++)
    {

        for (i = 0; i < k; i++)
        {

            for (j = 0; j < k; j++)
            {

                if (dp[i][p] + dp[p][j] < dp[i][j])
                    dp[i][j] = dp[i][p] + dp[p][j];
            }
        }
    }
}

void dijkstra(long long int s, vector<long long int> &d)
{
    long long int n = graph.size();
    d.assign(n, INF);

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
                q.push({d[to], to});
            }
        }
    }
}

void createEdges()
{
    for (ll i = 0; i < k; i++)
    {
        fill(dp[i].begin(), dp[i].end(), INF);
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < graph[i].size(); j++)
        {
            dp[compo[i]][compo[graph[i][j].first]] = min(dp[compo[i]][compo[graph[i][j].first]], graph[i][j].second);
        }
    }
}

ll check_dist(ll val1, ll val2)
{
    ll val = d[val1];
    for (ll i = val1 + 1; i <= val2; i++)
    {
        if (d[i] != val)
            return 0;
    }
    if (val == INF)
        return -1;
    else
        return 1;
}

void input_graph()
{
    for (ll i = 0; i < m; i++)
    {
        ll u, v, t;
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
    cin >> n >> m >> k;
    for (ll i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    input_graph();
    ll sum = 0, f;
    vector<ll> cum(K);
    cum[0] = c[0];
    for (ll i = 1; i < k; i++)
    {
        cum[i] = cum[i - 1] + c[i];
    }
    fill(d.begin(), d.end(), INF);
    for (ll i = 0; i < k; i++)
    {
        f = check_dist(sum + 1, sum + c[i]);
        // cout << d[1] << " " << d[2] << "\n";
        if (f == 0)
            break;
        else if (f == -1)
        {
            dijkstra(sum + 1, d);
            // cout << d[1] << " " << d[2] << "\n";
            f = check_dist(sum + 1, sum + c[i]);
            // cout << f << "\n";
            if (f == 0 || f == -1)
            {
                f = 0;
                break;
            }
        }
        sum += c[i];
    }
    if (f == 0)
    {
        cout << "No\n";
        return 0;
    }
    ll p = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (cum[p] >= i)
            compo[i] = p;
        else
        {
            compo[i] = ++p;
        }
    }
    createEdges();
    floydWarshall();
    cout << "Yes\n";
    for (ll i = 0; i < k; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            if (dp[i][j] == INF)
                dp[i][j] = -1;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}