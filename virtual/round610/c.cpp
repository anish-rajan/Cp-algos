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
#define N 300005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e6 + 2);
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
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e6 + 2; j += i)
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
        ll n, T, a, b;
        cin >> n >> T >> a >> b;
        v<pair<ll, ll>> p(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> p[i].se;
        for (ll i = 1; i <= n; i++)
            cin >> p[i].fi;
        sort(p.begin(), p.begin() + n + 1);
        v<ll> p1(n + 1);
        ll te = 0, th = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll t1 = p1[i - 1] + b, t2 = p1[i - 1] + a;
            p1[i] = p[i].se == 1 ? t1 : t2;
            if (p[i].se == 1)
                th++;
            else
                te++;
        }
        ll ans = 0, e = 0, h = 0;
        for (ll i = 1; i < n; i++)
        {
            if (p[i].se == 1)
                h++;
            else
                e++;
            if (p1[i] < p[i + 1].fi)
            {
                ll s1 = p[i + 1].fi - p1[i] - 1;
                ll s2 = 0, s3 = s1;
                if (te - e > 0)
                    s2 = min(te - e, s1 / a), s3 = s1 - s2 * a;
                if (th - h > 0)
                    s2 += min(th - h, s3 / b);
                ans = max(ans, i + s2);
            }
        }
        if (p1[n] <= T)
            ans = n;
        ll s1 = p[1].fi - 1;
        ll s2 = 0, s3 = s1;
        if (te > 0)
            s2 = min(te, s1 / a), s3 = s1 - s2 * a;
        if (th > 0)
            s2 += min(th, s3 / b);
        ans = max(ans, s2);
        cout << ans << "\n";
    }
}