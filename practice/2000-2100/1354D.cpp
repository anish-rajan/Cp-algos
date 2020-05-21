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
#define N 1000006
#define mod 1000000007
#define INF INT_MAX
ll n, q;
v<ll> a(N);

using S = ll;

struct FenwickTree
{
    vector<S> bit; // binary indexed tree
    S n;

    FenwickTree(S n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // FenwickTree(vector<S> a) : FenwickTree(a.size())
    // {
    //     for (size_t i = 0; i < n; i++)
    //         add(i, a[i]);
    // }

    S search(S sum)
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
        return ret;
    }

    S sum(S l, S r)
    {
        return qry(r) - qry(l - 1);
    }

    void add(S idx, S delta)
    {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += delta;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    FenwickTree tree(n);
    for (ll i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        tree.add(val, 1);
    }
    for (ll i = 0; i < q; i++)
    {
        ll val;
        cin >> val;
        if (val < 0)
        {
            tree.add(tree.search(-val), -1);
        }
        else
        {
            tree.add(val, 1);
        }
    }
    if (tree.qry(n) == 0)
        cout << 0 << "\n";
    else
        cout << tree.search(1) << "\n";
}