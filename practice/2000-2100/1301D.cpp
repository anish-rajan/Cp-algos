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
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

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

ll n, m, k;
v<pair<ll, string>> ans;
ll moves;

void add(pair<ll, string> m)
{
    if (moves >= k)
        return;
    else if (moves + m.fi * m.se.size() <= k)
    {
        moves += m.fi * m.se.size();
        ans.pb(m);
    }
    else
    {
        ll t = k - moves;
        ll t1 = m.se.size();
        if (t / t1)
            ans.pb(mp(t / t1, m.se));
        if (t % t1)
        {
            string s;
            for (ll i = 0; i < t % t1; i++)
                s += m.se[i];
            ans.pb(mp(1, s));
        }
        moves = k;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> k;
    ll pos = 4 * n * m - 2 * n - 2 * m;
    if (k > pos)
    {
        cout << "NO\n";
        return 0;
    }
    if (m >= 2)
    {
        add(mp(m - 1, "R"));
        add(mp(m - 1, "L"));
    }
    if (2 <= n)
        add(mp(1, "D"));
    for (ll i = 2; i <= n; i++)
    {
        if (m >= 2)
        {
            add(mp(m - 1, "R"));
            add(mp(m - 1, "UDL"));
        }
        if (i + 1 <= n)
            add(mp(1, "D"));
    }
    if (n >= 2)
        add(mp(n - 1, "U"));
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
}