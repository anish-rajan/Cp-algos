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
#define N 407
ll mod = 998244353;
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
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

ll te;
string s, t;
v<v<ll>> nex(N, v<ll>(300));

ll check(ll i)
{
    string s1 = t.substr(0, i + 1), s2 = t.substr(i + 1, (ll)t.size() - i);
    v<v<ll>> dp((ll)s1.size() + 3, v<ll>((ll)s2.size() + 3, INF));
    dp[0][0] = 0;
    for (ll j = 0; j <= s1.size(); j++)
    {
        for (ll k = 0; k <= s2.size(); k++)
        {
            if (dp[j][k] >= INF)
            {
                dp[j + 1][k] = INF, dp[j][k + 1] = INF;
                continue;
            }
            if (j < s1.size() && dp[j][k] < s.size())
                dp[j + 1][k] = min(nex[dp[j][k]][s1[j]] + 1, dp[j + 1][k]);
            if (k < s2.size() && dp[j][k] < s.size())
                dp[j][k + 1] = min(nex[dp[j][k]][s2[k]] + 1, dp[j][k + 1]);
        }
    }
    if (dp[(ll)s1.size()][(ll)s2.size()] >= INF)
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> te;
    while (te--)
    {
        cin >> s >> t;
        for (ll i = 0; i < s.size(); i++)
        {
            fill(nex[i].begin(), nex[i].end(), INF);
            for (ll j = i; j < s.size(); j++)
            {
                nex[i][s[j]] = min(nex[i][s[j]], j);
            }
        }
        ll f = 0;
        for (ll i = 0; i < t.size(); i++)
            if (check(i))
                f = 1;
        if (f == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}