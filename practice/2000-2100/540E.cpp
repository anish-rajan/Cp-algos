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
#define N 5005
#define mod 1000000007
#define INF INT_MAX
ll n;
map<ll, ll> m;
map<pair<ll, ll>, ll> intes;

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

using S = ll;

struct FenwickTree
{
    vector<S> bit; // binary indexed tree
    S n;
    S tot;

    FenwickTree(S n)
    {
        this->n = n;
        tot = 0;
        bit.assign(n + 1, 0);
    }

    // FenwickTree(vector<S> a) : FenwickTree(a.size())
    // {
    //     for (size_t i = 0; i < n; i++)
    //         add(i, a[i]);
    // }

    S search(S sum) // for finding sumth number if arranged in ascending order.
    {
        S x = 0;
        for (S i = 22; i >= 0; i--)
        {
            S newX = x + (1 << i);
            if (newX <= n && sum > bit[newX])
            {
                x = newX;
                sum -= bit[x];
            }
        }
        return x + 1;
    }

    S qry(S r)
    {
        S ret = 0;
        for (; r >= 1; r -= r & (-r))
            ret += bit[r];
        return tot - ret;
    }

    S sum(S l, S r)
    {
        return qry(r) - qry(l - 1);
    }

    void add(S idx, S delta)
    {
        tot += delta;
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += delta;
        // for (ll i = 0; i <= 8; i++)
        //     cout << bit[i] << " ";
        // cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (!m.count(x))
            m[x] = x;
        if (!m.count(y))
            m[y] = y;
        swap(m[x], m[y]);
    }
    ll j = 1, l = 0;
    for (auto x : m)
    {
        if (l + 1 <= x.fi - 1)
            intes[mp(l + 1, x.fi - 1)] = j++;
        intes[mp(x.fi, x.fi)] = j++;
        l = x.fi;
    }
    if (l + 1 <= 1e9)
        intes[mp(l + 1, 1e9)] = j++;
    FenwickTree ft(1e6);
    ll ans = 0;
    for (ll i = 1; i <= 1e9; i++)
    {
        ll curr, range;
        if (m.count(i))
        {
            auto itr = intes.upper_bound(mp(m[i], 1e9));
            itr--;
            curr = itr->se;
            range = 1;
        }
        else
        {
            auto itr = intes.upper_bound(mp(i, 1e9));
            itr--;
            curr = itr->se;
            range = itr->fi.se - itr->fi.fi + 1;
            // cout << curr << " " << (itr->fi.fi) << " " << (itr->fi.se) << " " << itr->se << "\n";
            i = itr->fi.se;
        }
        ans += range * ft.qry(curr);
        ft.add(curr, range);
    }
    cout << ans << "\n";
}