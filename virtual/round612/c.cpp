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

ll n;
v<ll> a(105), cnt(105);
ll o, e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;
    for (ll i = 1; i <= n; i++)
    {
        if (!cnt[i])
        {
            if (i % 2)
                o++;
            else
                e++;
        }
    }
    ll ans = 0, ok = 1;
    while (ok)
    {
        ll last = 0, spos = 0, epos = 0, len = INF;
        for (ll i = 1; i <= n; i++)
        {
            if (a[i])
            {
                if (last == 0 || a[i] % 2 != a[last] % 2)
                {
                    last = i;
                    continue;
                }
                ll s = i - last - 1;
                // cout << s << " " << o << " " << e << "\n";
                if (s < len && s > 0)
                    if (a[i] % 2 && o >= s)
                        len = s, spos = last, epos = i;
                    else if (a[i] % 2 == 0 && e >= s)
                        len = s, spos = last, epos = i;
                last = i;
            }
        }
        if (spos != 0 && epos != 0)
        {
            ll p = a[spos] % 2 ? 1 : 2;
            for (ll i = spos + 1; i < epos; i++)
                a[i] = p;
            if (a[spos] % 2)
                o -= epos - spos - 1;
            else
                e -= epos - spos - 1;
        }
        else
            ok = 0;
    }
    ll last = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i])
        {
            ll s = i - last - 1;
            if (s > 0)
            {
                if (last == 0)
                {
                    if (a[i] % 2 && o < s)
                        ans++;
                    else if (a[i] % 2 == 0 && e < s)
                        ans++;
                    else if (a[i] % 2)
                        o -= s;
                    else
                        e -= s;
                }
                else if (a[i] % 2 == a[last] % 2)
                    ans += 2;
                else
                    ans++;
            }
            last = i;
        }
    }
    ll s = n - last;
    if (s > 0)
    {
        if (last == 0)
        {
            if (n > 1)
                ans++;
        }
        else if (a[last] % 2 && o < s)
            ans++;
        else if (a[last] % 2 == 0 && e < s)
            ans++;
    }
    for (ll i = 1; i < n; i++)
        if (a[i] && a[i + 1])
            if (a[i] % 2 != a[i + 1] % 2)
                ans++;
    cout << ans << "\n";
}