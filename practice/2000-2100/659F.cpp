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
ll n, m, k, no;
v<pair<ll, pair<ll, ll>>> nos;
v<v<ll>> a(N, v<ll>(N)), visited(N, v<ll>(N)), ans(N, v<ll>(N));
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

struct DSU
{
    using S = ll;
    S n, m;
    v<v<pair<S, S>>> parent;
    v<v<ll>> size;

    DSU(S no, S mo)
    {
        n = no, m = mo;
        parent.resize(n + 1, v<pair<S, S>>(m + 1));
        size.resize(n + 1, v<ll>(m + 1));
        for (S i = 1; i <= n; i++)
        {
            for (S j = 1; j <= m; j++)
            {
                parent[i][j] = mp(i, j);
                size[i][j] = 1;
            }
        }
    }

    pair<S, S> find_set(pair<S, S> v)
    {
        if (v == parent[v.fi][v.se])
            return v;
        return parent[v.fi][v.se] = find_set(parent[v.fi][v.se]);
    }

    void union_sets(pair<S, S> a, pair<S, S> b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a.fi][a.se] < size[b.fi][b.se])
                swap(a, b);
            parent[b.fi][b.se] = a;
            size[a.fi][a.se] += size[b.fi][b.se];
        }
    }
};

void dfs(ll i, ll j, ll val)
{
    // cout << no << " " << i << " " << j << "\n";
    if (no <= 0 || a[i][j] == 0)
        return;
    visited[i][j] = 1;
    ans[i][j] = val;
    no--;
    if (!visited[i - 1][j] && i - 1 >= 1 && a[i - 1][j] != 0)
        dfs(i - 1, j, val);
    if (!visited[i][j - 1] && j - 1 >= 1 && a[i][j - 1] != 0)
        dfs(i, j - 1, val);
    if (!visited[i + 1][j] && i + 1 <= n && a[i + 1][j] != 0)
        dfs(i + 1, j, val);
    if (!visited[i][j + 1] && j + 1 <= m && a[i][j + 1] != 0)
        dfs(i, j + 1, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            ll val;
            cin >> val;
            nos.pb(mp(val, mp(i, j)));
        }
    }
    DSU dsu(n, m);
    sort(nos.begin(), nos.end(), greater<pair<ll, pair<ll, ll>>>());
    ll f = 0;
    pair<ll, ll> ind;
    ll val;
    for (auto x : nos)
    {
        ll i = x.se.fi, j = x.se.se;
        val = x.fi;
        a[i][j] = val;
        // cout << i << " " << j << " " << a[i][j] << "\n";
        if (a[i][j - 1] != 0)
        {
            dsu.union_sets(mp(i, j), mp(i, j - 1));
            // cout << i << " " << j << " " << a[i][j - 1] << "\n";
        }
        if (a[i - 1][j] != 0)
        {
            dsu.union_sets(mp(i, j), mp(i - 1, j));
            // cout << i << " " << j << " " << a[i - 1][j] << "\n";
        }
        if (a[i][j + 1] != 0)
        {
            dsu.union_sets(mp(i, j), mp(i, j + 1));
            // cout << i << " " << j << " " << a[i][j + 1] << "\n";
        }
        if (a[i + 1][j] != 0)
        {
            dsu.union_sets(mp(i, j), mp(i + 1, j));
            // cout << i << " " << j << " " << a[i + 1][j] << "\n";
        }
        if (k % val == 0)
        {
            ll temp = k / val;
            // cout << temp << " " << dsu.size[mp(i, j)];
            auto par = dsu.find_set(mp(i, j));
            if (dsu.size[par.fi][par.se] >= temp)
            {
                no = temp;
                f = 1;
                ind = mp(i, j);
                break;
            }
        }
    }
    if (f == 1)
        dfs(ind.fi, ind.se, val);
    if (f == 0)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        cout << "YES\n";
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}