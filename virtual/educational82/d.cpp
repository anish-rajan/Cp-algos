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
#define N 1e5 + 5
ll mod = 998244353;
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
        ll n, m;
        cin >> n >> m;
        v<ll> cnt(70, 0), bit(70, 0);
        v<ll> a(m + 1);
        ll ind = 0, sum = 0;
        ll ans = 0;
        ll temp = n;
        while (temp > 0)
        {
            if (temp % 2)
                bit[ind]++;
            ind++;
            temp /= 2;
        }
        for (ll i = 1; i <= m; i++)
        {
            cin >> a[i];
            sum += a[i];
            ll temp = (ll)log2(a[i]);
            cnt[temp]++;
        }
        if (sum < n)
        {
            cout << -1 << "\n";
            continue;
        }
        ind = INF;
        for (ll i = 0; i < cnt.size(); i++)
        {
            if (bit[i] && cnt[i])
                bit[i]--, cnt[i]--;
            if (cnt[i] > 0)
            {
                if (ind != INF)
                {
                    ans += i - ind;
                    cnt[i]--;
                    ind = INF;
                }
                cnt[i + 1] += cnt[i] / 2;
                cnt[i] = cnt[i] % 2;
            }
            if (bit[i])
                ind = min(ind, i);
        }
        cout << ans << "\n";
    }
}