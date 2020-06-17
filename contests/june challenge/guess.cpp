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
#define N 3003
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
v<ll> primes;

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

void Sieve()
{
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n;
v<pair<ll, ll>> ranges, nxt;

ll size()
{
    ll l = 0;
    for (auto e : ranges)
        l += e.se - e.fi + 1;
    return l;
}

char query(ll x)
{
    char a;
    cout << x << endl;
    cin >> a;
    if (a == 'E')
        exit(0);
    return a;
}

ll kth(ll k)
{
    for (auto e : ranges)
    {
        ll len = e.se - e.fi + 1;
        if (k > len)
            k -= len;
        else
            return e.fi + k - 1;
    }
    return -1;
}

ll cnt_small(ll l)
{
    ll ans = 0;
    for (auto e : ranges)
    {
        if (e.se <= l)
            ans += e.se - e.fi + 1;
        else if (l >= e.fi)
            ans += l - e.fi + 1;
    }
    return ans;
}

void remove(ll l, ll r)
{
    nxt.clear();
    for (auto e : ranges)
    {
        if (e.fi > r)
            nxt.pb(e);
        else if (l > e.se)
            nxt.pb(e);
        else
        {
            if (e.fi < l)
                nxt.pb(mp(e.fi, l - 1));
            if (e.se > r)
                nxt.pb(mp(r + 1, e.se));
        }
    }
    ranges = nxt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    ranges.pb({1, n});
    while (true)
    {
        ll len = size();
        if (len <= 5)
        {
            for (ll i = 1; i <= len; i++)
                query(kth(i));
        }
        ll x = kth(len / 2);
        char last = query(x);
        ll l = len / 2 - 1, r = len - len / 2;
        v<ll> qry = {x, x};
        bool done = false;
        for (; l > 1 && r > 1 && !done;)
        {
            ld delta = 0.33;
            if (last == 'G')
            {
                ll nq = kth(l * (1 - delta));
                char next = query(nq);
                if (next == last)
                {
                    remove(1, nq);
                    remove(qry[0], qry[1]);
                    done = true;
                }
                else
                {
                    qry[0] = qry[1], qry[1] = nq;
                }
                last = next;
                l = cnt_small(nq - 1);
            }
            else
            {
                ll nq = kth(len - r * (1 - delta));
                char next = query(nq);
                if (next == last)
                {
                    remove(nq, n);
                    remove(qry[1], qry[0]);
                    done = true;
                }
                else
                {
                    qry[0] = qry[1], qry[1] = nq;
                }
                last = next;
                r = len - cnt_small(nq);
            }
            if (!done)
            {
                remove(min(qry[0], qry[1]), max(qry[0], qry[1]));
                len = size();
                l = cnt_small(min(qry[0], qry[1]));
                r = len - cnt_small(max(qry[0], qry[1]));
            }
        }
    }
    return 0;
}