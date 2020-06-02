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
#define N 200005
#define mod 1000000007
#define INF 1e16

ll n, p1, p2, ans;
v<ll> a(N), b(N), c(N);
v<v<ll>> gr(N);
v<ll> dist(N);
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

void dfs1(ll u, ll par)
{
    visited[u] = 1;
    if (par != 0)
        a[u] = min(a[u], a[par]);
    if (b[u] == 1 && c[u] == 0)
        p1++;
    else if (b[u] == 0 && c[u] == 1)
        p2++;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs1(gr[u][i], u);
        }
    }
}

pair<ll, ll> dfs2(ll u, ll par)
{
    visited[u] = 1;
    ll pt1 = 0, pt2 = 0;
    if (b[u] == 0 && c[u] == 1)
        pt1++;
    if (b[u] == 1 && c[u] == 0)
        pt2++;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            auto temp = dfs2(gr[u][i], u);
            pt1 += temp.fi, pt2 += temp.se;
        }
    }
    ll temp = min(pt1, pt2);
    ans += a[u] * 2 * temp;
    pt1 -= temp, pt2 -= temp;
    // cout << u << " " << ans << "\n";

    return mp(pt1, pt2);
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
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    input_gr(n);
    dfs1(1, 0);
    if (p1 != p2)
    {
        cout << "-1\n";
        return 0;
    }
    fill(visited.begin(), visited.end(), 0);
    dfs2(1, 0);
    cout << ans << "\n";
}