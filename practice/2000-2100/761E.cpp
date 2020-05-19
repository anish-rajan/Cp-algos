#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define pii pair<ll, ll>
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353
ll n, bc;
vector<vector<ll>> gr(N);
v<v<ll>> dirs(N, v<ll>(4)), child(N, v<ll>(3));
vector<ll> visited(N);
v<pii> ans(N);

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

void dfs1(ll u)
{
    visited[u] = 1;
    ll cnt = 0, tc = 0, lc = 0, rc = 0;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs1(gr[u][i]);
            cnt++;
            if (cnt == 1)
                child[u][0] = tc = gr[u][i];
            else if (cnt == 2)
                child[u][1] = lc = gr[u][i];
            else if (cnt == 3)
                child[u][2] = rc = gr[u][i];
            if (u == 1 && cnt == 4)
                bc = gr[u][i];
        }
    }
    if (gr[u].size() == 1)
        return;
    dirs[u][0] = max(dirs[lc][3], dirs[rc][2]);
    if (tc != 0)
        dirs[u][0] = max(dirs[u][0], dirs[tc][0] + 1);
    dirs[u][1] = max(dirs[lc][2], dirs[rc][3]);
    if (tc != 0)
        dirs[u][1] = max(dirs[u][1], dirs[tc][1] - 1);
    dirs[u][2] = dirs[tc][2];
    dirs[u][3] = dirs[tc][3];
    if (lc != 0)
    {
        dirs[u][2] = max(dirs[u][2], dirs[lc][0] + 1);
        dirs[u][3] = max(dirs[u][3], dirs[lc][1] - 1);
    }
    if (lc != 0)
    {
        dirs[u][2] = max(dirs[u][2], dirs[rc][1] - 1);
        dirs[u][3] = max(dirs[u][3], dirs[rc][1] + 1);
    }
    if (u == 1 && bc != 0)
        dirs[u][1] = max(dirs[u][1], dirs[bc][0] + 1);
}

void dfs2(ll u, ll x, ll y, ll x1)
{
    visited[u] = 1;
    ll cnt = 0, tc = child[u][0], lc = child[u][1], rc = child[u][2];
    if (u == 1 && bc != 0)
    {
        ans[bc].fi = x;
        ans[bc].se = y - max(dirs[lc][2], dirs[rc][3]) - dirs[bc][1] - 2;
    }
    if (tc != 0)
    {
        if (abs(x1) == 2)
        {
            ans[tc].fi = x;
            if (x1 == 2)
                ans[tc].se = y + max(dirs[lc][3], dirs[rc][2]) + dirs[tc][1] + 2;
            else
                ans[tc].se = y - max(dirs[lc][3], dirs[rc][2]) - dirs[tc][1] - 2;
        }
        else
        {
            ans[tc].se = y;
            if (x1 == 1)
                ans[tc].fi = x + max(dirs[lc][3], dirs[rc][2]) + dirs[tc][1] + 2;
            else
                ans[tc].fi = x - max(dirs[lc][3], dirs[rc][2]) - dirs[tc][1] - 2;
        }
    }
    if (lc != 0)
    {
        if (abs(x1) == 2)
        {
            ans[lc].se = y;
            if (x1 == 2)
            {
                if (u != 1)
                    ans[lc].fi = x - dirs[lc][1] - dirs[tc][2] - 1;
                else
                    ans[lc].fi = x - dirs[lc][1] - max(dirs[tc][2], dirs[bc][3]) - 1;
            }
            else
            {
                if (u != 1)
                    ans[lc].fi = x + dirs[lc][1] + dirs[tc][2] + 1;
                else
                    ans[lc].fi = x + dirs[lc][1] + max(dirs[tc][2], dirs[bc][3]) + 1;
            }
        }
        else
        {
            ans[lc].fi = x;
            if (x1 == 1)
            {
                if (u != 1)
                    ans[lc].se = y + dirs[lc][1] + dirs[tc][2] + 1;
                else
                    ans[lc].se = y + dirs[lc][1] + max(dirs[tc][2], dirs[bc][3]) + 1;
            }
            else
            {
                if (u != 1)
                    ans[lc].se = y - dirs[lc][1] - dirs[tc][2] - 1;
                else
                    ans[lc].se = y - dirs[lc][1] - max(dirs[tc][2], dirs[bc][3]) - 1;
            }
        }
    }
    if (rc != 0)
    {
        if (abs(x1) == 2)
        {
            ans[rc].se = y;
            if (x1 == -2)
            {
                if (u != 1)
                    ans[rc].fi = x - dirs[rc][1] - dirs[tc][3] - 1;
                else
                    ans[rc].fi = x - dirs[rc][1] - max(dirs[tc][3], dirs[bc][2]) - 1;
            }
            else
            {
                if (u != 1)
                    ans[rc].fi = x + dirs[rc][1] + dirs[tc][3] + 1;
                else
                    ans[rc].fi = x + dirs[rc][1] + max(dirs[tc][3], dirs[bc][2]) + 1;
            }
        }
        else
        {
            ans[rc].fi = x;
            if (x1 == -1)
            {
                if (u != 1)
                    ans[rc].se = y + dirs[rc][1] + dirs[tc][3] + 1;
                else
                    ans[rc].se = y + dirs[rc][1] + max(dirs[tc][3], dirs[bc][2]) + 1;
            }
            else
            {
                if (u != 1)
                    ans[rc].se = y - dirs[rc][1] - dirs[tc][3] - 1;
                else
                    ans[rc].se = y - dirs[rc][1] - max(dirs[tc][3], dirs[bc][2]) - 1;
            }
        }
    }
    // cout << u << " " << tc << " " << lc << " " << rc << " " << x1 << " " << y << " " << ans[lc].se << "\n";
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            ll tempx1;
            if (gr[u][i] == tc)
                tempx1 = x1;
            else if (gr[u][i] == bc && u == 1)
                tempx1 = -x1;
            else if (gr[u][i] == lc)
            {
                if (abs(x1) == 1)
                    tempx1 = x1 == 1 ? 2 : -2;
                else
                    tempx1 = x1 == 2 ? -1 : 1;
            }
            else
            {
                if (abs(x1) == 1)
                    tempx1 = x1 == 1 ? -2 : 2;
                else
                    tempx1 = x1 == 2 ? 1 : -1;
            }
            dfs2(gr[u][i], ans[gr[u][i]].fi, ans[gr[u][i]].se, tempx1);
        }
    }
}

bool input_graph(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
        if (gr[i].size() > 4)
            return 0;
    return 1;
}

void output()
{
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    bool f = input_graph(n);
    if (f == 0)
    {
        cout << "NO\n";
        return 0;
    }
    dfs1(1);
    fill(visited.begin(), visited.begin() + n + 1, 0);
    ans[1] = mp(0, 0);
    // cout << ans[1].fi << " " << ans[1].se << "\n";
    dfs2(1, 0, 0, 2);
    cout << "YES\n";
    output();
}