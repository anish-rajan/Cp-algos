#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
#define lli long long int
ll n, q, t;
vector<ll> a(N);

typedef struct data
{
    ll sum, pref, suff, ans;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
struct data make_data(ll val)
{
    struct data res;
    res.sum = val;
    res.pref = res.suff = val;
    res.ans = max((ll)0, val);
    return res;
}

void build(long long int v, long long int tl, long long int tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(a[tl]);
    }
    else
    {
        long long int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
struct data query(long long int node, long long int tl, long long int tr, long long int l, long long int r)
{
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    long long int tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    // cout << tl << " " << tr << " " << temp.pref << " " << temp.suff << "\n";
    return temp;
}
void update(long long int v, long long int tl, long long int tr, long long int pos, long long int new_val)
{
    if (tl == tr)
    {
        tree[v] = make_data(new_val);
    }
    else
    {
        long long int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // cin >> t;
    // while (t--)
    // {
    //     cin >> n >> q;
    //     for (ll i = 0; i < n; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     build(arr, 0, n - 1, 0);
    //     while (q--)
    //     {
    //         char q;
    //         ll x, y;
    //         cin >> q >> x >> y;
    //         if (q == 'U')
    //         {
    //             arr[x - 1] = y;
    //             update(arr, 0, 0, n - 1, x - 1, y);
    //         }
    //         else
    //         {
    //             ll temp = query(arr, 0, 0, n - 1, x - 1, y - 1).sum;
    //             ll temp1 = 0, temp2 = 0;
    //             if (y <= n - 1)
    //             {
    //                 temp1 = max(query(arr, 0, 0, n - 1, y, n - 1).prefixsum, (ll)0);
    //             }
    //             if (x - 2 >= 0)
    //             {
    //                 temp2 = max(query(arr, 0, 0, n - 1, 0, x - 2).suffixsum, (ll)0);
    //             }
    //             // cout << temp << " " << temp1 << " " << temp2 << "\n";
    //             cout << temp + temp1 + temp2 << "\n";
    //         }
    //     }
    // }
    lli t, n, i, k, l, r, ans, index, value;
    char ch;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        // lli a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // build the tree
        build(1, 0, n - 1);
        while (k--)
        {
            cin >> ch;
            if (ch == 'Q')
            {
                cin >> l >> r;
                ans = 0;
                ans = query(1, 0, n - 1, l - 1, r - 1).sum;
                if (r < n)
                {
                    ans += max(query(1, 0, n - 1, r, n - 1).pref, (lli)0);
                }
                if (l >= 2)
                {
                    ans += max(query(1, 0, n - 1, 0, l - 2).suff, (lli)0);
                }
                cout << ans << "\n";
            }

            else
            {
                cin >> index >> value;
                a[index - 1] = value;
                update(1, 0, n - 1, index - 1, value);
            }
        }
    }
}