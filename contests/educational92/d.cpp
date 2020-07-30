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
ll n, l1, r1, l2, r2, k, s, m1;

pair<ll, ll> over(ll l1, ll r1, ll l2, ll r2)
{
    pair<ll, ll> ans;
    if (l2 < l1)
        ans = over(l2, r2, l1, r1);
    else if (l2 > r1)
    {
        ans.fi = r2 - r1 + l2 - l1;
        ans.se = 0;
    }
    else if (l1 <= l2 && r1 >= r2)
    {
        ans.fi = l2 - l1 + r1 - r2;
        ans.se = r2 - l2;
    }
    else
    {
        ans.fi = l2 - l1 + r2 - r1;
        ans.se = r1 - l2;
    }
    return ans;
}

ll check(ll m)
{
    ll s1 = max(r1, r2) - min(l1, l2);
    s1 -= s;
    ll k1 = k;
    if (k <= 0)
        return 1;
    if (k1 - s1 <= 0 && m1 - (s1 - k1) <= m)
    {
        return 1;
    }
    if (m - m1 < 0)
        return 0;
    m -= m1;
    k1 -= s1;
    if (k1 <= 0)
        return 1;
    for (ll i = 2; i <= n; i++)
    {
        if (k1 * 2 <= m)
            return 1;
        if (k1 - s1 <= 0 && m1 - (s1 - k1) <= m)
        {
            return 1;
        }
        else if (2 * s1 <= m1)
        {
            break;
        }
        else if (m - m1 < 0)
        {
            return 0;
        }
        m -= m1;
        k1 -= s1;
        if (k1 <= 0)
            return 1;
    }
    if (k1 * 2 <= m)
        return 1;
    else
        return 0;
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
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        auto temp = over(l1, r1, l2, r2);
        s = temp.se, m1 = temp.fi;
        k -= n * s;
        ll l = 0, r = 1e18;
        ll ans = 1e18;
        // cout << check(7) << "\n";
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            auto temp = check(mid);
            if (temp == 1)
                r = mid - 1, ans = min(ans, mid);
            else
                l = mid + 1;
        }
        cout << ans << "\n";
    }
}
