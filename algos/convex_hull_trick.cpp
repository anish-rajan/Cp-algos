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
#define N 500005
#define mod 1000000009
#define INF INT_MAX

//currently upper convex hull..
struct CHT
{
    //**CHT for decreasing slope and min query**//
    vector<ll> m, c;
    bool bad(ll f1, ll f2, ll f3) //change this for other query..
    {
        return 1.0 * (c[f3] - c[f1]) * (m[f1] - m[f2]) <= 1.0 * (c[f2] - c[f1]) * (m[f1] - m[f3]);
    }
    void add(ll _m, ll _c)
    {
        m.pb(_m), c.pb(_c);
        ll len = m.size();
        while (len >= 3 and bad(len - 3, len - 2, len - 1))
        {
            m.erase(m.end() - 2);
            c.erase(c.end() - 2);
            --len;
        }
    }
    ll f(ll i, ll x) { return m[i] * x + c[i]; }
    ll query(ll x)
    {
        ll l = 0, r = m.size() - 1;
        ll id = 0;
        while (l <= r)
        {
            ll del = (r - l) / 3;
            ll mid1 = l + del, mid2 = r - del;
            if (f(mid1, x) > f(mid2, x)) ///change this for another query.
                id = mid2, l = mid1 + 1;
            else
                id = mid1, r = mid2 - 1;
        }
        return f(id, x);
    }
} C;