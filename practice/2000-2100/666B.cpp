#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define N 3003
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll n, m;

v<v<ll>> d1(N, v<ll>(N));
v<v<pair<ll, ll>>> di1(N, v<pair<ll, ll>>(4)), di2(N, v<pair<ll, ll>>(4));

using S = ll;

vector<vector<S>> adj(N), adjT(N);

void update(ll u, ll val, ll v)
{
    if (di1[u][0].fi < val)
        di1[u][3] = di1[u][2], di1[u][2] = di1[u][1], di1[u][1] = di1[u][0], di1[u][0] = {val, v};
    else if (di1[u][1].fi <= val)
        di1[u][3] = di1[u][2], di1[u][2] = di1[u][1], di1[u][1] = {val, v};
    else if (di1[u][2].fi <= val)
        di1[u][3] = di1[u][2], di1[u][2] = {val, v};
    else if (di1[u][3].fi <= val)
        di1[u][3] = {val, v};
}
void update1(ll u, ll val, ll v)
{
    if (di2[u][0].fi < val)
        di2[u][3] = di2[u][2], di2[u][2] = di2[u][1], di2[u][1] = di2[u][0], di2[u][0] = {val, v};
    else if (di2[u][1].fi <= val)
        di2[u][3] = di2[u][2], di2[u][2] = di2[u][1], di2[u][1] = {val, v};
    else if (di2[u][2].fi <= val)
        di2[u][3] = di2[u][2], di2[u][2] = {val, v};
    else if (di2[u][3].fi <= val)
        di2[u][3] = {val, v};
}

void bfs(S s, vector<S> &d, vector<S> &used)
{
    queue<S> q;
    q.push(s);
    used[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        S v = q.front();
        q.pop();
        for (S u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                update(s, d[u], u);
            }
        }
    }
}

void bfs1(S s, vector<S> &d, vector<S> &used)
{
    queue<S> q;
    q.push(s);
    used[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        S v = q.front();
        q.pop();
        for (S u : adjT[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                update1(s, d[u], u);
            }
        }
    }
}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].pb(u);
    }
}

bool check(ll point, v<ll> points)
{
    for (ll i = 0; i < points.size(); i++)
        if (points[i] == point)
            return true;
    return false;
}

ll find_point(ll u, v<ll> &points, ll &dist)
{
    for (auto itr = di1[u].begin(); itr != di1[u].end(); itr++)
    {
        ll vert = itr->se;
        if (check(vert, points) || itr->fi == 0)
            continue;
        points.pb(vert);
        dist += itr->fi;
        return vert;
    }
    return 0;
}
ll find_point1(ll u, v<ll> &points, ll &dist)
{
    for (auto itr = di2[u].begin(); itr != di2[u].end(); itr++)
    {
        ll vert = itr->se;
        if (check(vert, points) || itr->fi == 0)
            continue;
        points.insert(points.begin(), vert);
        dist += itr->fi;
        return vert;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m;
    input_adj(m);
    for (ll i = 1; i <= n; i++)
    {
        v<ll> d(n + 1, INF), visited(n + 1, 0);
        bfs(i, d, visited);
        for (auto j = 1; j <= n; j++)
            d1[i][j] = d[j];
        fill(d.begin(), d.end(), INF), fill(visited.begin(), visited.end(), 0);
        bfs1(i, d, visited);
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= n; j++)
    //         cout << d1[i][j] << " ";
    //     cout << "\n";
    // }
    ll ans = 0;
    v<ll> ansp;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (d1[i][j] == INF || i == j)
                continue;
            v<ll> points;
            ll dist = d1[i][j];
            points.pb(i), points.pb(j);
            find_point(j, points, dist);
            find_point1(i, points, dist);
            if (points.size() == 4)
            {
                // if (dist == 13)
                //     cout << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << "\n";
                if (ans < dist)
                    ans = dist, ansp = points;
            }
        }
    }
    for (ll i = 0; i < ansp.size(); i++)
        cout << ansp[i] << " ";
    cout << "\n";
}