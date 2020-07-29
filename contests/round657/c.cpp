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
        ll n, m;
        cin >> n >> m;
        v<pair<ll, ll>> a(m + 1);
        v<ll> a1(m + 1), c(m + 2, 0);
        ll ans = 0;
        for (ll i = 1; i <= m; i++)
        {
            cin >> a[i].se >> a[i].fi;
            a1[i] = a[i].se;
        }
        sort(a1.begin() + 1, a1.begin() + m + 1);
        for (ll i = m; i >= 1; i--)
            c[i] = c[i + 1] + a1[i];
        for (ll i = 1; i <= m; i++)
        {
            ll t1 = a[i].fi, t2 = a[i].se;
            ll ind = lower_bound(a1.begin() + 1, a1.begin() + m + 1, t1) - a1.begin();
            ll nos = m - ind + 1;
            ll ans1 = c[max(ind, m - n + 1)];
            if (nos >= n)
            {
                ans = max(ans, ans1);
                continue;
            }
            ans1 += (n - nos - 1) * t1 + t2;
            if (t2 >= t1)
                ans1 -= t2, ans1 += t1;
            ans = max(ans, ans1);
            // cout << i << " " << ans1 << "\n";
        }
        cout << ans << "\n";
    }
}