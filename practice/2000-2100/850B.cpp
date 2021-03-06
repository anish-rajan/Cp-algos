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
#define N 2000006
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

ll n, x, y;
v<ll> a(N), b(N), cnt(N), sum(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> x >> y;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], b[a[i]]++;
    for (ll i = 1; i < N; i++)
        cnt[i] = cnt[i - 1] + b[i], sum[i] = sum[i - 1] + b[i] * i;
    ll c = x / y;
    ll ans = INF;
    for (ll i = 2; i <= 1e6; i++)
    {
        ll cost = 0, f = i - min(i, c);
        for (ll j = 0; j <= 1e6; j += i)
        {
            ll st = j + 1, en = j + i, st2 = max(st, st + f - 1);
            ll c1 = cnt[st2 - 1] - cnt[st - 1];
            ll c2 = cnt[en] - cnt[st2 - 1];
            ll c3 = sum[en] - sum[st2 - 1];
            cost += c1 * x + y * (c2 * en - c3);
        }
        // if (i <= 30)
        //     cout << i << " " << cost << "\n";
        ans = min(ans, cost);
    }
    cout << ans << '\n';
}