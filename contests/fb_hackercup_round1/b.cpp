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
#define N 1000006
ll mod = 1000000007;
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

ll t, n, m, k, ap, bp, cp, dp, aq, bq, cq, dq, s;
ll mul(ll a, ll b, ll m)
{
    return (a * b) % m;
}
v<ll> p, q;

bool check(ll time)
{
    ll j = 0, i = 0;
    for (; i < p.size() && j < q.size();)
    {
        ll k = j, curt = 0;
        while (k < q.size())
        {
            curt = q[k] - q[j] + min(abs(p[i] - q[j]), abs(p[i] - q[k]));
            if (curt > time)
                break;

            k++;
        }
        i++;
        j = k;
    }
    if (j == q.size())
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    freopen("test.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> m >> k >> s;
        ll ans = INF;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            p.push_back(val);
        }
        cin >> ap >> bp >> cp >> dp;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            q.pb(val);
        }
        cin >> aq >> bq >> cq >> dq;
        for (ll i = k; i < n; i++)
        {
            ll p1 = (mul(ap, p[i - 2], dp) + mul(bp, p[i - 1], dp) + cp) % dp + 1;
            p.pb(p1);
        }
        for (ll i = k; i < m; i++)
        {
            ll q1 = (mul(aq, q[i - 2], dq) + mul(bq, q[i - 1], dq) + cq) % dq + 1;
            q.pb(q1);
        }
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        ll l = 1, r = INF;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (check(mid))
                r = mid - 1, ans = min(ans, mid);
            else
                l = mid + 1;
        }
        cout << "Case #" << i << ": " << ans << "\n";
        p.clear(), q.clear();
    }
}
