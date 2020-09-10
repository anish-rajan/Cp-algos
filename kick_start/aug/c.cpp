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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll n;
        cin >> n;
        v<pair<ll, ll>> a(n);
        ll suf = 0, pref = 0, maxans = 0, eraseans = 0, erase = 0, subt = 0;
        multiset<pair<ll, ll>> nos;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i].fi >> a[i].se;
            suf += a[i].fi;
        }
        for (ll i = 0; i < n; i++)
        {
            if (maxans < 2 * pref + suf)
                maxans = 2 * pref + suf, eraseans = erase;
            suf -= a[i].fi;
            if (pref + suf < a[i].se)
            {
                ll sub = a[i].fi + subt;
                erase++;
                for (auto itr = nos.begin(); itr != nos.end();)
                {
                    auto itr1 = itr;
                    if (itr1->fi < sub)
                    {
                        sub += itr1->se;
                        erase++;
                        itr++;
                        nos.erase(itr1);
                    }
                    else
                        break;
                }
                pref -= sub - a[i].fi - subt;
                subt = sub;
            }
            else
                nos.insert(mp(-a[i].se + pref + suf + subt, a[i].fi)), pref += a[i].fi;
        }
        if (maxans < 2 * pref + suf)
            maxans = 2 * pref + suf, eraseans = erase;
        if (nos.size() > 0)
            cout << "Case #" << i << ": "
                 << n - nos.size() << " "
                 << "INDEFINITELY"
                 << "\n";
        else
        {
            cout << "Case #" << i << ": " << eraseans << " " << maxans << "\n";
        }
    }
}