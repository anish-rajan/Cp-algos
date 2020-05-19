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
#define N 100005
#define mod 1000000009
#define INF INT_MAX
ll n, m;
v<pair<pair<ll, ll>, ll>> intervals;
v<v<pair<ll, ll>>> l(N), r(N);
v<ll> ans_int;
using S = ll;

vector<S> a(N);

typedef struct data
{
    S minimum, maximum;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.minimum = min(l.minimum, r.minimum);
    res.maximum = max(l.maximum, r.maximum);
    return res;
}
struct data make_data(S val)
{
    struct data res;
    res.minimum = val;
    res.maximum = val;
    return res;
}

void build(S v, S tl, S tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(a[tl]);
    }
    else
    {
        S tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
// Lazy updates... currently queries for minimum in a range... lazy may have to be modified for other queries.
S lazy[4 * N];

void push(S node)
{
    tree[node * 2].minimum += lazy[node];
    tree[node * 2].maximum += lazy[node];
    lazy[node * 2] += lazy[node];
    tree[node * 2 + 1].minimum += lazy[node];
    tree[node * 2 + 1].maximum += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

void lazy_update(S node, S tl, S tr, S l, S r, S addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[node].minimum += addend;
        tree[node].maximum += addend;
        lazy[node] += addend;
    }
    else
    {
        push(node);
        S tm = (tl + tr) / 2;
        lazy_update(node * 2, tl, tm, l, min(r, tm), addend);
        lazy_update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }
}

struct data lazy_query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data(INF);
    if (l <= tl && tr <= r)
        return tree[node];
    push(node);
    S tm = (tl + tr) / 2;
    struct data temp = combine(lazy_query(node * 2, tl, tm, l, min(r, tm)), lazy_query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        ll l1, r1;
        cin >> l1 >> r1;
        intervals.pb(mp(mp(l1, r1), i));
        l[l1].pb(mp(l1, r1));
        r[r1].pb(mp(l1, r1));
    }
    auto temp = lazy_query(1, 1, n, 1, n);
    ll ans = temp.maximum - temp.minimum, ind = 0;

    for (ll i = 0; i < m; i++)
        lazy_update(1, 1, n, intervals[i].fi.fi, intervals[i].fi.se, -1);
    for (ll i = 1; i <= n; i++)
    {
        for (auto j : l[i])
        {
            lazy_update(1, 1, n, j.fi, j.se, 1);
        }
        auto temp = lazy_query(1, 1, n, 1, n);
        ll temp1 = temp.minimum;
        ll temp2 = temp.maximum;
        if (temp2 - temp1 >= ans)
        {
            ans = temp2 - temp1;
            ind = i;
        }
        for (auto j : r[i])
        {
            lazy_update(1, 1, n, j.fi, j.se, -1);
        }
    }
    cout << ans << "\n";
    if (ind == 0)
        cout << 0 << "\n";
    else
    {
        for (ll i = 0; i < m; i++)
        {
            ll x = intervals[i].fi.fi, y = intervals[i].fi.se;
            if (!(x <= ind && y >= ind))
            {
                ans_int.pb(intervals[i].se);
            }
        }
        cout << ans_int.size() << "\n";
        for (ll i = 0; i < ans_int.size(); i++)
        {
            cout << ans_int[i] << " ";
        }
        cout << "\n";
    }
}