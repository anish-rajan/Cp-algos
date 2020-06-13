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
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
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

bool check1(v<ll> st, v<ll> tar)
{
    ll p1;
    for (ll i = 0; i < st.size(); i++)
        if (st[i] != tar[i])
        {
            p1 = tar[i] - st[i];
        }
    ll f = 1;
    for (ll i = 0; i < st.size(); i++)
    {
        if (st[i] != tar[i] && !(tar[i] - st[i] == p1))
            f = 0;
    }
    if (f == 1)
        return true;
    f = 1;
    ll p = INF;
    for (ll i = 0; i < st.size(); i++)
        if (st[i] && st[i] != tar[i])
        {
            p = tar[i] / st[i];
        }
    if (p == INF)
        return false;
    for (ll i = 0; i < st.size(); i++)
    {
        if (st[i] == tar[i])
            continue;
        if (!st[i])
            f = 0;
        else if (!(tar[i] % st[i] == 0 && tar[i] / st[i] == p))
            f = 0;
    }
    if (f == 1)
        return true;
    return false;
}
bool check2(v<ll> st, v<ll> tar)
{
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            for (ll k = 0; k < 3; k++)
            {
                if (i != j && i != k && k != j)
                {
                    ll p;
                    if (st[i] && tar[i] % st[i] == 0)
                        p = tar[i] / st[i];
                    else
                        continue;
                    // cout << p << " " << tar[i] << " " << st[i] << " ";

                    if (check1({st[j], st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({st[j], p * st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({p * st[j], st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({p * st[j], p * st[k]}, {tar[j], tar[k]}))
                        return true;
                    // cout << p << "\n";
                }
            }
        }
    }
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            for (ll k = 0; k < 3; k++)
            {
                if (i != j && i != k && k != j)
                {
                    ll p = tar[i] - st[i];
                    // cout << p << " " << tar[i] << " " << st[i] << " ";
                    if (check1({st[j], st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({st[j], p + st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({p + st[j], st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({p + st[j], p + st[k]}, {tar[j], tar[k]}))
                        return true;
                    if (check1({st[j], st[k]}, {tar[j] - p, tar[k] - p}))
                        return true;
                    // cout << p << "\n";
                }
            }
        }
    }
    ll p = tar[0], q = tar[1], r = tar[2], a = st[0], b = st[1], c = st[2];
    if (a - b != 0 && b - c != 0)
    {
        if ((p - q) % (a - b) == 0 && (q - r) % (b - c) == 0)
        {
            ll s = (p - q) / (a - b), s1 = (q - r) / (b - c);
            if (s == s1)
            {
                ll p1 = p - a * s, p2 = q - b * s, p3 = r - c * s;
                if (p1 == p2 && p2 == p3 && p1 == p3)
                    return true;
                if (s != 0 && p % s == 0 && q % s == 0 && r % s == 0)
                {
                    p1 = p / s - a, p2 = q / s - b, p3 = r / s - c;
                    if (p1 == p2 && p2 == p3 && p1 == p3)
                        return true;
                }
            }
        }
    }
    return false;
}

ll t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> t;
    while (t--)
    {
        v<ll> st(3), tar(3);
        for (ll i = 0; i < 3; i++)
            cin >> st[i];
        for (ll i = 0; i < 3; i++)
            cin >> tar[i];
        if (st == tar)
        {
            cout << 0 << "\n";
        }
        else if (check1(st, tar))
        {
            cout << 1 << "\n";
        }
        else if (check2(st, tar))
        {
            cout << 2 << "\n";
        }
        else
            cout << 3 << "\n";
    }
}