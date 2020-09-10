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
#define N 1e8
#define mod 1000000007
#define INF 1e15

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(N);
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

// void init_fact()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
// }

// ll C(ll n, ll r)
// {
//     if (n < r)
//         return 0;
//     ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
//     temp *= powmod(fact[n - r], mod - 2, mod);
//     temp %= mod;
//     return temp;
// }

// void Sieve()
// {
//     for (ll i = 2; i < 1e8; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j < 1e8; j += i)
//             prime_check[j] = i;
//     }
// }
// ll phi(ll n)
// {
//     ll i, res = n;
//     for (i = 2; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n /= i;
//             res -= res / i;
//         }
//     if (n > 1)
//         res -= res / n;
//     return res;
// }

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

void simpleSieve(ll limit, vector<ll> &prime)
{
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));

    for (ll p = 2; p * p < limit; p++)
    {
        if (mark[p] == true)
        {
            for (ll i = p * 2; i < limit; i += p)
                mark[i] = false;
        }
    }
    for (ll p = 2; p < limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
}

vector<ll> segmentedSieve(ll n)
{

    ll limit = floor(sqrt(n)) + 1;
    vector<ll> prime;
    vector<ll> primes;
    simpleSieve(limit, prime);
    primes = prime;
    ll low = limit;
    ll high = 2 * limit;

    while (low < n)
    {
        if (high >= n)
            high = n;
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));
        for (ll i = 0; i < prime.size(); i++)
        {
            ll loLim = floor(low / prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            for (ll j = loLim; j < high; j += prime[i])
                mark[j - low] = false;
        }

        for (ll i = low; i < high; i++)
            if (mark[i - low] == true)
                primes.push_back(i);

        low = low + limit;
        high = high + limit;
    }
    return primes;
}
ll mul(ll a, ll b, ll m)
{
    return (a * b) % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    ll t;
    primes = segmentedSieve(1e8);
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (n == 0 || n == 1 || n == 3)
        {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2)
        {
            cout << 0 << "\n";
            continue;
        }
        ll ans = 1;
        ll i;
        for (i = 1; i < primes.size() && primes[i] <= sqrt(n); i++)
        {
            // cout << primes[i] << "\n";
            ll cnt = 0, x = primes[i];
            while (x <= n)
            {
                cnt += n / x;
                x = x * primes[i];
                // cout << cnt << " ";
            }
            // cout << cnt << " ";
            cnt = (cnt + 1) % m;
            ans = mul(ans, cnt, m);
        }
        for (; i < primes.size() && primes[i] <= n;)
        {
            ll l = i, r = primes.size() - 1, ind = i, cnt = n / primes[i];
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                ll c = n / primes[mid];
                if (c == cnt)
                    l = mid + 1, ind = mid;
                else
                    r = mid - 1;
            }
            // cout << cnt << " " << primes[i] << " " << primes[ind] << "\n";
            cnt = (cnt + 1) % m;
            ans = mul(ans, powmod(cnt, ind - i + 1, m), m);
            i = ind + 1;
        }
        ans = (ans - 1 + m) % m;
        cout << ans << "\n";
    }
}
