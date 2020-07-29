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
string p = "abacaba";
string p1;
ll check(string s, ll ind)
{
    p1 = s;
    if (p1.substr(ind, 7) == p)
        return true;
    for (ll i = ind; i < ind + 7; i++)
    {
        if (p1[i] != p[i - ind] && p1[i] != '?')
        {
            return false;
        }
        else
            p1[i] = p[i - ind];
    }
    return true;
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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll f1 = 0;
        for (ll i = 0; i < s.size() - 6; i++)
        {
            ll f = 1;
            if (!check(s, i))
            {
                f = 0;
                continue;
            }
            for (ll j = 0; j < s.size() - 6; j++)
            {
                if (j == i)
                    continue;
                if (p1.substr(j, 7) == p)
                    f = 0;
            }
            // cout << p1 << " ";
            if (f == 1)
            {
                cout << "YES\n";
                f1 = 1;
                for (ll j = i; j < i + 7; j++)
                    s[j] = p[j - i];
                for (ll j = 0; j < s.size(); j++)
                    if (s[j] == '?')
                        s[j] = 'z';
                cout << s << "\n";
                break;
            }
        }
        if (f1 == 0)
            cout << "NO\n";
    }
}