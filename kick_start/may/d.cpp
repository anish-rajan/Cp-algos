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
#define INF INT64_MAX
ll t;
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

using S = long long int;

vector<S> a;

typedef struct data
{
    S sum, sum1;
} data;

vector<struct data> tree;
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.sum = l.sum + r.sum;
    res.sum1 = l.sum1 + r.sum1;
    return res;
}
struct data make_data(S val, S ind)
{
    struct data res;
    res.sum = val;
    res.sum1 = val * ind;
    return res;
}

void build(S v, S tl, S tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(a[tl], tl);
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
        return make_data(0, 0);
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
        tree[v] = make_data(new_val, pos);
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

bool check(ll no)
{
    ll temp = (ll)sqrt(no);
    if (temp * temp == no)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll ans = 0, n, q;
        cin >> n >> q;
        a.resize(n + 1);
        tree.resize(4 * n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
                a[i] = -a[i];
        }

        build(1, 1, n);
        for (ll i = 1; i <= q; i++)
        {
            char p;
            ll x, y;
            cin >> p >> x >> y;
            if (p == 'U')
            {
                if (x % 2 == 0)
                    update(1, 1, n, x, -y);
                else
                    update(1, 1, n, x, y);
            }
            else
            {
                auto temp = query(1, 1, n, x, y);
                ll sum = temp.sum, sum1 = temp.sum1;
                if (x % 2 == 0)
                {
                    sum = -sum;
                    sum1 = -sum1;
                }
                sum = sum1 - sum * (x - 1);
                ans += sum;
            }
        }
        cout << "Case #" << i << ": " << ans << "\n";
        a.clear();
        tree.clear();
    }
}