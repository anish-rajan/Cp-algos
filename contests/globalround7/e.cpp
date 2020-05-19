
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
#define N 300005
#define mod 998244353
// v<ll> arr(N);
v<ll> pos(N);
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

vector<S> a(N), b(N);

typedef struct data
{
    S val;
} data;

struct data tree[4 * N];
struct data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.val = min(l.val, r.val);
    return res;
}
struct data make_data(S val, S ind)
{
    struct data res;
    res.val = val;
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

void push(S node)
{
    tree[node * 2].val += lazy[node].val;
    lazy[node * 2].val += lazy[node].val;
    tree[node * 2 + 1].val += lazy[node].val;
    lazy[node * 2 + 1].val += lazy[node].val;
    lazy[node].val = 0;
}

struct data query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data(0, 0);
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    push(node);
    S tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}
void update(S v, S tl, S tr, S pos, S new_val)
{
    if (tl == tr)
    {
        tree[v] = make_data(new_val, tl);
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
void update1(S node, S tl, S tr, S l, S r, S addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[node].val += addend;
        lazy[node].val += addend;
    }
    else
    {
        push(node);
        S tm = (tl + tr) / 2;
        update1(node * 2, tl, tm, l, min(r, tm), addend);
        update1(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll ans = n;
    ll ind = 1;
    for (ll i = 1; i <= n; i++)
    {
        while (true)
        {
            update1(1, 1, n, 1, pos[ans], -1);
            if (tree[1].val >= 0)
                ans--;
            else
            {
                update1(1, 1, n, 1, pos[ans], 1);
                break;
            }
        }
        cout << ans << " ";
        update1(1, 1, n, 1, b[i], 1);
    }

    cout << "\n";
}