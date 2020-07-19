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

ll n, m;
v<ll> w(N), a(N);
v<pair<ll, ll>> f(N);
v<set<ll>> foods(N);
v<ll> ans;
set<pair<ll, ll>, greater<pair<ll, ll>>> diff;

bool func(ll i)
{
    ll sz = ans.size();
    v<ll> ind;
    for (auto p : foods[i])
    {
        ll x = f[p].fi, y = f[p].se;
        (y != i ? foods[y].erase(p) : foods[x].erase(p));
        (y != i ? ind.pb(y) : ind.pb(x));
        ans.pb(p);
        sz++;
    }
    diff.erase(diff.begin());
    a[i] = 0;
    for (auto p : ind)
    {
        diff.erase({w[p] - a[p], p});
        a[p]--;
        diff.insert({w[p] - a[p], p});
    }
    if (sz == m)
        return false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> w[i];
    for (ll i = 1; i <= m; i++)
    {
        cin >> f[i].fi >> f[i].se, a[f[i].fi]++, a[f[i].se]++;
        foods[f[i].fi].insert(i);
        foods[f[i].se].insert(i);
    }

    for (ll i = 1; i <= n; i++)
    {
        diff.insert({w[i] - a[i], i});
    }
    ll g = 1;
    bool ok = true;
    while (ok)
    {
        auto itr = diff.begin();
        ll i = itr->se;
        if (w[i] < a[i])
        {
            g = 0;
            break;
        }
        ok = func(i);
    }
    if (g == 0)
        cout << "DEAD\n";
    else
    {
        cout << "ALIVE\n";
        reverse(ans.begin(), ans.end());
        for (ll i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}