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
#define INF INT_MAX

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

bool lesser(S a, S b)
{
    return a <= b;
}
bool great(S a, S b)
{
    return a >= b;
}

vector<pair<S, S>> pge(vector<S> a, S n, function<bool(S, S)> func)
{
    vector<pair<S, S>> L(n + 1, {0, 0});
    stack<S> s;
    for (int i = 1; i <= n; i++)
    {
        while (s.size() && func(a[s.top()], a[i]))
            s.pop();
        if (s.size())
            L[i].fi = s.top();
        s.push(i);
        L[i].se = i;
    }
    return L;
}
vector<pair<S, S>> pge1(vector<S> a, S n, function<bool(S, S)> func)
{
    vector<pair<S, S>> L(n + 1, {n + 1, n + 1});
    stack<S> s;
    for (int i = n; i >= 1; i--)
    {
        while (s.size() && func(a[s.top()], a[i]))
            s.pop();
        if (s.size())
            L[i].fi = s.top();
        s.push(i);
        L[i].se = i;
    }
    return L;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        v<pair<ll, ll>> prev = pge(a, n, lesser);
        v<pair<ll, ll>> next = pge1(a, n, great);
        sort(prev.begin() + 1, prev.begin() + n + 1);
        ll j = 1;
        FenwickTree ft1(n);
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            while (j <= n)
            {
                if (prev[j].fi < i)
                {
                    ft1.add(prev[j].se, 1);
                    j++;
                }
                else
                    break;
            }
            ans += ft1.sum(i, next[i].fi - 1);
            // cout << next[i].fi << " " << next[i].se << " " << ans << "\n";
        }
        prev = pge(a, n, great);
        next = pge1(a, n, lesser);
        sort(prev.begin() + 1, prev.begin() + n + 1);
        FenwickTree ft2(n);
        j = 1;
        for (ll i = 1; i <= n; i++)
        {
            while (j <= n)
            {
                if (prev[j].fi < i)
                {
                    ft2.add(prev[j].se, 1);
                    j++;
                }
                else
                    break;
            }
            ans += ft2.sum(i, next[i].fi - 1);
        }
        j = 1;
        ll a3 = 0;
        for (ll i = 1; i <= n;)
        {
            while (j <= n)
            {
                if (a[j] == a[i])
                    a3 += j - i + 1, j++;
                else
                    break;
            }
            i = j;
        }
        ans -= a3;
        cout << ans << "\n";
    }
}