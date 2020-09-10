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
#define N 500005
#define mod 1000000007
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
        ll n, c, k;
        cin >> n >> c >> k;
        v<map<ll, ll>> cnt(c + 1);
        v<ll> dp(k + 1, 0), cost(c + 1), dp1(k + 1, 0);
        v<v<ll>> rem(c + 1);
        ll ans = 0, ans1 = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            cnt[z][x]++;
        }
        for (ll i = 1; i <= c; i++)
            cin >> cost[i];
        for (ll i = 1; i <= c; i++)
        {
            set<pair<ll, ll>> sel;
            ll s1 = 0, s2 = 0, ways = 0;
            for (auto x : cnt[i])
                sel.insert({x.se, x.fi}), s1 += x.se;
            for (auto x : cnt[i])
                s2 += x.se * (s1 - x.se);
            s2 /= 2;
            for (auto x : cnt[i])
                ways += x.se * (s2 - x.se * (s1 - x.se));
            ways /= 3;
            ans += ways;
            while (s1 > 0)
            {
                auto itr = sel.begin();
                auto temp = *itr;
                sel.erase(itr);
                ll ways1 = ways;
                ways1 -= temp.fi * (s2 - temp.fi * (s1 - temp.fi));
                s2 -= temp.fi * (s1 - temp.fi);
                s1--, temp.fi--;
                s2 += temp.fi * (s1 - temp.fi);
                ways1 += temp.fi * (s2 - temp.fi * (s1 - temp.fi));
                if (temp.fi > 0)
                    sel.insert(temp);
                rem[i].pb(ways - ways1);
                ways = ways1;
            }
        }
        for (ll i = 1; i <= c; i++)
        {
            for (ll j = 1; j < rem[i].size(); j++)
                rem[i][j] += rem[i][j - 1];
        }
        for (ll i = 1; i <= c; i++)
        {
            dp1 = dp;
            for (ll j = 0; j < rem[i].size(); j++)
            {
                for (ll l = 0; l <= k; l++)
                {
                    if (l + cost[i] * (j + 1) <= k)
                        dp1[l] = max(dp1[l], dp[l + cost[i] * (j + 1)] + rem[i][j]);
                }
            }
            dp = dp1;
        }
        for (ll i = 0; i <= k; i++)
            ans1 = max(ans1, dp[i]);
        ans -= ans1;
        cout << ans << "\n";
    }
}
