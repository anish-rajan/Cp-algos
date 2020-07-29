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
#define N 100005
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

ll n, m, k;
v<v<ll>> a(N, v<ll>(7));
v<ll> ans(7);
stack<pair<ll, ll>> in[7], out[7];
ll ST, EN;

void empty_in()
{
    pair<ll, ll> temp;
    while (!in[1].empty())
    {
        for (int i = 1; i <= m; i++)
        {
            temp = in[i].top();
            in[i].pop();

            if (out[i].empty())
                out[i].push(make_pair(temp.second, temp.second));
            else
                out[i].push(make_pair(max(out[i].top().first, temp.second), temp.second));
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    ST = 1, EN = 1;
    ll mx = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 1; j <= m; j++)
        {
            in[j].push(make_pair(max((!in[j].empty()) ? in[j].top().first : 0, a[i][j]), a[i][j]));
        }
        EN++;
        for (ll j = 1; j <= m; j++)
        {
            sum += max(in[j].top().first, (!out[j].empty()) ? out[j].top().first : 0);
        }
        if (sum <= k)
        {
            if (EN - ST + 1 > mx)
            {
                mx = EN - ST + 1;
                for (ll j = 1; j <= m; j++)
                {
                    ans[j] = max(in[j].top().first, (!out[j].empty()) ? out[j].top().first : 0);
                    ;
                }
            }
        }
        else
        {
            while (sum > k and ST <= EN)
            {
                if (out[1].empty())
                    empty_in();

                sum = 0;
                ST++;

                for (int j = 1; j <= m; j++)
                {
                    if (!out[j].empty())
                    {
                        out[j].pop();
                        sum += max((out[j].empty()) ? 0 : out[j].top().first, (in[j].empty()) ? 0 : in[j].top().first);
                    }
                }
            }
        }
    }
    for (ll j = 1; j <= m; j++)
        cout << ans[j] << " ";
    cout << "\n";
}