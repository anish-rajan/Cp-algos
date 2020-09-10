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
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
// v<ll> prime_check(N);
// v<ll> primes;

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

ll t;

ll mul(ll a, ll b)
{
    return (a * b) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init_fact();
    // Sieve();
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<ll> dp(n + 1), cnt(n + 1), cum(n + 1), mult(n + 2, 1);
        v<v<ll>> ways(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            ll val;
            cin >> val;
            cnt[val]++;
        }
        dp[0] = cum[0] = 1;
        for (ll i = 1; i <= n; i++)
        {
            ways[i].pb(0);
            ll m = 1;
            for (ll j = 1; j <= cnt[i]; j++)
            {
                m = mul(mult[j], m);
                mult[j] = 1;
                dp[j] = mul(dp[j], m);
                cum[j] = (cum[j - 1] + dp[j]) % mod;
            }
            mult[cnt[i] + 1] = mul(m, mult[cnt[i] + 1]);
            for (ll j = 1; j <= cnt[i]; j++)
            {
                ways[i].pb(mul(cum[j - 1], C(cnt[i], j)));
            }
            ll val = 0;
            for (ll j = 1; j <= cnt[i]; j++)
            {
                val = (val + C(cnt[i], j - 1)) % mod;
                dp[j] = (mul(val, dp[j]) + mul(cum[j], C(cnt[i], j))) % mod;
            }
            mult[cnt[i] + 1] = mul(powmod(2, cnt[i], mod), mult[cnt[i] + 1]);
            // cout << i << " " << ways[i][1] << " " << ways[i][2] << " " << ways[i][3] << "\n";
        }
        fill(dp.begin(), dp.end(), 0), fill(cum.begin(), cum.end(), 0), fill(mult.begin(), mult.end(), 1);
        dp[0] = cum[0] = 1;
        for (ll i = n; i >= 1; i--)
        {
            ll m = 1;
            for (ll j = 1; j <= cnt[i]; j++)
            {
                m = mul(mult[j], m);
                mult[j] = 1;
                dp[j] = mul(dp[j], m);
                cum[j] = (cum[j - 1] + dp[j]) % mod;
            }
            mult[cnt[i] + 1] = mul(m, mult[cnt[i] + 1]);
            for (ll j = 1; j <= cnt[i]; j++)
            {
                ways[i][j] = mul(ways[i][j], cum[j]);
            }
            ll val = 0;
            for (ll j = 1; j <= cnt[i]; j++)
            {
                val = (val + C(cnt[i], j - 1)) % mod;
                dp[j] = (mul(val, dp[j]) + mul(cum[j], C(cnt[i], j))) % mod;
            }
            mult[cnt[i] + 1] = mul(powmod(2, cnt[i], mod), mult[cnt[i] + 1]);
            // cout << i << " " << cum[1] << " " << cum[2] << " " << cum[3] << "\n";
        }
        ll sum = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll ans = 0;
            for (ll j = 1; j <= cnt[i]; j++)
                ans = (ans + ways[i][j]) % mod;
            cout << ans << " ";
            sum = (sum + ans) % mod;
        }
        cout << "\n";
        // cout << sum << "\n";
    }
}
