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
#define N 800005
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(1e6 + 2);
// v<ll> primes;

// long long powmod(long long x, long long y, long long m)
// {
//     long long res = 1LL;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % m;
//         x = (x * x) % m;
//         y /= 2;
//     }
//     return res;
// }

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
//     for (ll i = 2; i <= 1e6 + 1; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j <= 1e6 + 2; j += i)
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
v<pair<ll, ll>> ph(N);
map<ll, ll> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.txt", "r", stdin);
    freopen("ouput1.txt", "w", stdout);
    // init_fact();
    // Sieve();
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {

        ll ans = 0;
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++)
            cin >> ph[i].fi >> ph[i].se;
        sort(ph.begin() + 1, ph.begin() + n + 1);
        dp[ph[1].fi] = ph[1].se;
        dp[ph[1].fi + ph[1].se] = ph[1].se;
        ans = ph[1].se;
        for (ll i = 2; i <= n; i++)
        {
            ll len = ph[i].se, pos = ph[i].fi;
            if (dp.find(pos) == dp.end())
                dp[pos] = 0;
            if (dp.find(pos - len) == dp.end())
                dp[pos - len] = 0;
            dp[pos + len] = max(dp[pos + len], dp[pos] + len);
            dp[pos] = max(dp[pos], dp[pos - len] + len);
            ans = max(ans, max(dp[pos], dp[pos + len]));
        }
        cout << "Case #" << i << ": " << ans << "\n";
        dp.clear();
    }
}
