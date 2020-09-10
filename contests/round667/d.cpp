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
#define N 200005
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

ll diff(string s, ll no)
{
    ll no1 = 0;
    for (ll i = 0; i < s.size(); i++)
        no1 = no1 * 10 + s[i] - 48;
    // cout << no << " " << no1 << "\n";
    return no1 - no;
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
        ll n, s;
        cin >> n >> s;
        ll tempn = n;
        ll sum = 0;
        string f;
        while (n > 0)
        {
            f += (n % 10) + 48;
            sum += n % 10;
            n /= 10;
        }
        if (sum <= s)
        {
            cout << 0 << "\n";
            continue;
        }
        n = tempn;
        ll d = INF;
        for (ll i = 0; i < f.size(); i++)
        {
            if (i == f.size() - 1)
            {
                f += '1';
                sum -= (f[i] - 48);
                f[i] = '0';
                sum += 1;
                string f1 = f;
                reverse(ALL(f1));
                d = min(d, diff(f1, n));
                break;
            }
            ll j = i + 1;
            while (j < f.size() && f[j] == '9')
                sum -= f[j] - 48, f[j] = '0', j++;
            if (j == f.size())
                f += '1';
            else
                f[j]++;
            sum -= (f[i] - 48);
            f[i] = '0';
            sum++;
            string f1 = f;
            reverse(ALL(f1));
            if (sum <= s)
                d = min(d, diff(f1, n));
        }
        cout << d << "\n";
    }
}
