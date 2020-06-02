#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 1003
#define mod 1000000007
#define INF INT_MAX

ll t;
v<v<ll>> gr(N);
v<ll> dist(N);
v<ll> visited(N), marked(N);

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

void dfs(ll u, ll dis)
{
    visited[u] = 1;
    dist[u] = dis;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs(gr[u][i], dis + 1);
        }
    }
}

void input_gr(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        input_gr(n);
        dfs(x, 0);
        v<ll> leaves;
        for (ll i = 1; i <= n; i++)
            if (gr[i].size() == 1 || gr[i].size() == 0)
                leaves.pb(i), marked[i] = 1;
        string win = "Ashish";
        ll f = 0;
        // cout << leaves.size() << " ";
        for (ll i = 1; i <= n; i++)
        {
            ll f1 = 0;
            for (ll j = 0; j < leaves.size(); j++)
            {
                if (leaves[j] == x)
                {
                    win = win == "Ashish" ? "Ayush" : "Ashish";
                    f = 1;
                }
            }
            if (f == 1)
                break;
            for (ll j = 0; j < leaves.size(); j++)
            {
                if (dist[leaves[j]] % 2 == 0)
                {
                    f1 = 1;
                    win = win == "Ashish" ? "Ayush" : "Ashish";
                    ll p = leaves[j];
                    leaves.erase(leaves.begin() + j);
                    ll p1 = gr[p][0];
                    gr[p].clear();
                    for (ll i = 0; i < gr[p1].size(); i++)
                    {
                        if (gr[p1][i] == p)
                        {
                            gr[p1].erase(gr[p1].begin() + i);
                            break;
                        }
                    }
                    break;
                }
            }
            if (!f1)
            {
                for (ll j = 0; j < leaves.size(); j++)
                {
                    if (gr[leaves[j]][0] != x)
                    {
                        f1 = 1;
                        win = win == "Ashish" ? "Ayush" : "Ashish";
                        ll p = leaves[j];
                        leaves.erase(leaves.begin() + j);
                        ll p1 = gr[p][0];
                        gr[p].clear();
                        for (ll i = 0; i < gr[p1].size(); i++)
                        {
                            if (gr[p1][i] == p)
                            {
                                gr[p1].erase(gr[p1].begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            if (!f1)
            {
                win = win == "Ashish" ? "Ayush" : "Ashish";
                ll p = leaves[0];
                leaves.erase(leaves.begin());
                ll p1 = gr[p][0];
                gr[p].clear();
                for (ll i = 0; i < gr[p1].size(); i++)
                {
                    if (gr[p1][i] == p)
                    {
                        gr[p1].erase(gr[p1].begin() + i);
                        break;
                    }
                }
            }
            for (ll j = 1; j <= n; j++)
                if ((gr[j].size() == 1 || gr[j].size() == 0) && !marked[j])
                    leaves.pb(j), marked[j] = 1;
            // cout << win << " " << leaves.size() << " ";
        }
        cout << win << "\n";
        for (ll i = 0; i <= n; i++)
            gr[i].clear();
        fill(dist.begin(), dist.begin() + n + 1, 0);
        fill(visited.begin(), visited.begin() + n + 1, 0);
        fill(marked.begin(), marked.begin() + n + 1, 0);
    }
}