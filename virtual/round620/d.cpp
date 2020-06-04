#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////
ll t;

using S = long long int;

vector<S> a(N);
v<ll> ans1(N), ans2(N);

struct ST
{

    struct data
    {
        S sum;
    };

    v<data> tree;
    v<S> lazy;

    ST(ll n)
    {
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    data combine(struct data l, struct data r)
    {
        struct data res;
        res.sum = l.sum + r.sum;
        return res;
    }
    data make_data(S val)
    {
        struct data res;
        res.sum = val;
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

    void push(S node, S tl, S tr)
    {
        ll tm = (tl + tr) / 2;
        tree[node * 2].sum += lazy[node] * (tm - tl + 1);
        lazy[node * 2] += lazy[node];
        tree[node * 2 + 1].sum += lazy[node] * (tr - tm);
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }

    void lazy_update(S node, S tl, S tr, S l, S r, S addend)
    {
        if (l > r)
            return;
        if (l == tl && tr == r)
        {
            tree[node].sum += (tr - tl + 1) * addend;
            lazy[node] += addend;
        }
        else
        {
            push(node, tl, tr);
            S tm = (tl + tr) / 2;
            lazy_update(node * 2, tl, tm, l, min(r, tm), addend);
            lazy_update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    data lazy_query(S node, S tl, S tr, S l, S r)
    {
        if (l > r)
            return make_data(0);
        if (l <= tl && tr <= r)
            return tree[node];
        push(node, tl, tr);
        S tm = (tl + tr) / 2;
        struct data temp = combine(lazy_query(node * 2, tl, tm, l, min(r, tm)), lazy_query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        return temp;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> t;
    while (t--)
    {
        string s;
        ll n;
        cin >> n >> s;
        ST st1(n + 1), st2(n + 1);
        st1.build(1, 1, n), st2.build(1, 1, n);
        st1.lazy_update(1, 1, n, 1, 1, 1), st2.lazy_update(1, 1, n, 1, 1, 1);
        // for (ll i = 1; i <= 9; i++)
        //     cout << st1.tree[i].sum << " ";
        // cout << "\n";
        for (ll i = 0; i < s.size(); i++)
        {
            ll pos = i + 2;
            if (s[i] == '>')
            {
                st1.lazy_update(1, 1, n, 1, pos - 1, 1);
                st1.lazy_update(1, 1, n, pos, pos, 1);
            }
            else
            {
                st1.lazy_update(1, 1, n, pos, pos, pos);
            }
            // for (ll i = 1; i <= 9; i++)
            //     cout << st1.tree[i].sum << " ";
            // cout << "\n";
        }
        for (ll i = 1; i <= n; i++)
        {
            ans1[i] = st1.lazy_query(1, 1, n, i, i).sum;
            // cout << ans1[i] << " ";
        }
        for (ll i = 0; i < s.size();)
        {
            ll j = i, addend, x;
            while (j < s.size())
            {
                if (s[j] == s[i])
                    j++;
                else
                    break;
            }
            if (s[i] == '>')
                addend = -1, x = j - i, st2.lazy_update(1, 1, n, 1, i + 1, x);
            else
                addend = 1, x = 2, st2.lazy_update(1, 1, n, 1, i, j - i);
            for (ll k = i; k < j; k++)
                st2.lazy_update(1, 1, n, k + 2, k + 2, x), x += addend;
            i = j;
            // for (ll i = 1; i <= 10; i++)
            //     cout << st2.tree[i].sum << " ";
            // cout << "\n";
        }
        for (ll i = 1; i <= n; i++)
        {
            ans2[i] = st2.lazy_query(1, 1, n, i, i).sum;
        }
        for (ll i = 1; i <= n; i++)
            cout << ans2[i] << " ";
        cout << "\n";
        for (ll i = 1; i <= n; i++)
            cout << ans1[i] << " ";
        cout << "\n";
    }
}