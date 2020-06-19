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
#define N 504
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

ll t;

ll btoint(string s)
{
    ll n = s.size(), ans = 0;
    for (ll i = 0; i < n; i++)
        ans += (1LL << (n - 1 - i)) * (s[i] - 48);
    return ans;
}
string intob(ll x, ll m)
{
    string s;
    while (m--)
    {
        ll temp = x % 2;
        s += (temp + 48);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        v<string> b(n + 1);
        v<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> b[i], a[i] = btoint(b[i]);
        sort(a.begin() + 1, a.end());
        v<pair<ll, ll>> ranges;
        ll j = 1, i = 0;
        for (i = 0; j <= n;)
        {
            if (a[j] > i)
                ranges.pb({i, a[j] - 1}), i = a[j] + 1, j++;
            else
                i++, j++;
        }
        if (a[n] < (1LL << m) - 1)
            ranges.pb({a[n] + 1, (1LL << m) - 1});
        ll k = ((1LL << m) - 1 - n) / 2;
        k++;
        for (auto e : ranges)
        {
            ll len = e.se - e.fi + 1;
            if (k > len)
                k -= len;
            else
            {
                cout << intob(e.fi + k - 1, m) << "\n";
                break;
            }
        }
    }
}