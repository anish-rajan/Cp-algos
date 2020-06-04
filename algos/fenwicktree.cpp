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
#define N 31622779
#define mod 998244353

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