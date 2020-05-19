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
#define N 100005
#define mod 998244353

ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll n, m;
using S = ll;

v<pair<S, S>> ans;
vector<vector<S>> adj(N);
vector<bool> visited;
vector<S> tin, low;
S timer;
S is_there;

void dfs(S u, S p = -1)
{
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (S to : adj[u])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            if (tin[to] < tin[u])
            {
                ans.pb(mp(u, to));
            }
            low[u] = min(low[u], tin[to]);
        }
        else
        {
            dfs(to, u);
            ans.pb(mp(u, to));
            low[u] = min(low[u], low[to]);
            if (low[to] > tin[u])
            {
                //it is bridge
                is_there = 1;
            }
        }
    }
}

void find_bridges(S n1)
{
    timer = 1;
    S n = n1; // number of nodes
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (S i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

void input_graph(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    input_graph(m);
    find_bridges(n);
    if (is_there == 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
}