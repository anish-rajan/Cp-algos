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

ll t, n, s;
v<pair<ll, ll>> a(N);

bool check(ll x)
{
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = x, j = 0;
    v<ll> mid;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i].se < x)
            cnt1++, sum += a[i].fi;
        else if (a[i].fi > x)
            cnt2++, sum += a[i].fi;
        else
            cnt3++, mid.pb(a[i].fi);
    }
    sort(ALL(mid));
    cnt3--;
    if (cnt3 < 0)
        return 0;
    mid.pop_back();
    if (cnt1 < n / 2)
    {
        cnt3 -= n / 2 - cnt1;
        if (cnt3 < 0)
            return 0;
        ll cnt = 0;
        for (; cnt < n / 2 - cnt1; j++)
            sum += mid[j], cnt++;
    }
    if (cnt2 < n / 2)
    {
        cnt3 -= n / 2 - cnt2;
        if (cnt3 < 0)
            return 0;
    }
    while (j < mid.size())
        sum += x, j++;
    if (cnt3 < 0 || sum > s)
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
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (ll i = 1; i <= n; i++)
            cin >> a[i].fi >> a[i].se;
        sort(a.begin() + 1, a.begin() + n + 1);
        ll l = a[n / 2 + 1].fi, r = 1e9 + 1, ans = l;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (check(mid))
                l = mid + 1, ans = max(ans, mid);
            else
                r = mid - 1;
        }
        cout << ans << "\n";
    }
}
