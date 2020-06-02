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
#define N 100005
#define mod 1000000007
#define INF INT_MAX
ll n;
v<ll> p(N);
v<v<ll>> cycles(N);
v<pair<ll, ll>> edges;
v<ll> visited(N);
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

void dfs(ll u, ll noc)
{
    if (visited[u])
        return;
    visited[u] = 1;
    cycles[noc].pb(u);
    dfs(p[u], noc);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> p[i];
    ll pos = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (p[i] == i)
            pos = i;
    }
    if (pos)
    {
        cout << "YES\n";
        for (ll i = 1; i <= n; i++)
        {
            if (pos != i)
                cout << i << " " << pos << "\n";
        }
        return 0;
    }
    ll noc = 0;
    ll sz2 = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            noc++;
            dfs(i, noc);
            if (cycles[noc].size() % 2)
            {
                cout << "NO\n";
                return 0;
            }
            if (cycles[noc].size() == 2)
                sz2 = noc;
        }
    }
    if (sz2 == 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    edges.pb(mp(cycles[sz2][0], cycles[sz2][1]));
    for (ll i = 1; i <= noc; i++)
    {
        if (i != sz2)
        {
            for (ll j = 0; j < cycles[i].size(); j++)
            {
                edges.pb(mp(cycles[sz2][j % 2], cycles[i][j]));
            }
        }
    }
    for (ll i = 0; i < edges.size(); i++)
        cout << edges[i].fi << " " << edges[i].se << "\n";
    return 0;
}