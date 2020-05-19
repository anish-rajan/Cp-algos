#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define mp make_pair
#define pii pair<ll, ll>
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 998244353
using S = long long int;

ll n, m;
v<ll> a(N);
v<ll> isr(N), tans(N), seq;
vector<vector<S>> gr(N); // gracency list of gr
vector<bool> visited;
vector<S> ts;

void dfs(S v)
{
    visited[v] = true;
    for (S u : gr[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ts.push_back(v);
}

void topological_sort()
{
    visited.assign(n + 1, false);
    ts.clear();
    for (S i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ts.begin(), ts.end());
}

void dfs2(ll u, ll x)
{
    if (tans[u] != 0)
        return;
    tans[u] = x;
    for (auto i : gr[u])
    {
        dfs2(i, x);
    }
}

void input_graph(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
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
        cin >> a[i];
        isr[a[i]] = 1;
    }
    topological_sort();
    reverse(ts.begin(), ts.end());
    for (ll i = 0; i < ts.size(); i++)
    {
        // cout << ts[i] << " ";
        if (isr[ts[i]])
        {
            dfs2(ts[i], ts[i]);
            seq.pb(ts[i]);
            // cout << seq.back() << " ";
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        // cout << tans[i] << " " << a[i] << "\n";
        if (tans[i] != a[i])
        {
            cout << "-1\n";
            return 0;
        }
    }
    cout << seq.size() << "\n";
    for (ll i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << "\n";
    }
    return 0;
}