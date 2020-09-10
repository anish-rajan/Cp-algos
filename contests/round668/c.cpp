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
#define N 5005
ll mod = 1000000007;
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(N);
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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll z = 0, o = 0, q = 0, f = 1;
        for (ll i = 0; i < k; i++)
        {
            if (s[i] == '0')
                z++;
            else if (s[i] == '1')
                o++;
            else
                q++;
        }
        if (o + q < z || z + q < o)
            f = 0;
        if (s[0] == '0')
            z--;
        else if (s[0] == '1')
            o--;
        else
            q--;
        for (ll i = k; i < n; i++)
        {
            if (s[i - k] == '?')
            {
                if (s[i] == '1' && (z + q <= o || o + q < z - 1))
                    f = 0;
                else if (s[i] == '0' && (o + q <= z || z + q < o - 1))
                    f = 0;
                else if (s[i] == '1')
                    s[i - k] = '1';
                else if (s[i] == '0')
                    s[i - k] = '0';
            }
            else if (s[i] == '?')
            {
                if (s[i - k] == '1' && (z + q <= o || o + q < z - 1))
                    f = 0;
                else if (s[i - k] == '0' && (o + q <= z || z + q < o - 1))
                    f = 0;
                else if (s[i - k] == '1')
                    s[i] = '1';
                else if (s[i - k] == '0')
                    s[i] = '0';
            }
            else if (s[i] != s[i - k])
                f = 0;
            if (s[i - k + 1] == '0')
                z--;
            else if (s[i - k + 1] == '1')
                o--;
            else
                q--;
            if (s[i] == '0')
                z++;
            else if (s[i] == '1')
                o++;
            else
                q++;
        }
        if (f == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
