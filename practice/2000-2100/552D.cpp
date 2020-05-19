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
#define N 500005
#define mod 998244353
ll n, m;
v<ll> a(N), nex(N, INT_MAX), pre(N, INT_MAX);
map<ll, ll> ind;
v<ll> ans(N);
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

using S = long long int;

typedef struct data
{
    S val;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.val = min(l.val, r.val);
    return res;
}
struct data make_data(S val)
{
    struct data res;
    res.val = val;
    if (val == 0)
        res.val = INT_MAX;
    return res;
}

void build(S v, S tl, S tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(abs(tl - pre[tl]));
    }
    else
    {
        S tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
struct data query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    S tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}
void update(S v, S tl, S tr, S pos, S new_val)
{
    if (tl == tr)
    {
        tree[v] = make_data(new_val);
    }
    else
    {
        S tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        if (ind.find(a[i]) != ind.end())
            pre[i] = ind[a[i]];
        ind[a[i]] = i;
    }
    ind.clear();
    for (ll i = n; i >= 1; i--)
    {
        if (ind.find(a[i]) != ind.end())
            nex[i] = ind[a[i]];
        ind[a[i]] = i;
    }
    build(1, 1, n);
    // for (ll i = 1; i <= 4 * n; i++)
    //     cout << tree[i].val << " ";
    v<pair<pair<ll, ll>, ll>> q(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> q[i].fi.fi >> q[i].fi.se;
        q[i].se = i;
    }
    sort(q.begin(), q.end());
    ll curl = 0;
    for (ll i = 0; i < m; i++)
    {
        ll l = q[i].fi.fi, r = q[i].fi.se;
        while (curl < l)
        {
            if (nex[curl] <= n)
                update(1, 1, n, nex[curl], INT_MAX);
            curl++;
        }
        ans[q[i].se] = query(1, 1, n, 1, r).val;
    }
    // cout << INT_MAX << "\n";
    for (ll i = 0; i < m; i++)
    {
        if (ans[i] > n)
            ans[i] = -1;
        cout << ans[i] << "\n";
    }
}