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
#define mod 1000000007
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

ll n, m;
v<string> a(N), b(N);
v<v<ll>> dp(N, v<ll>(17, INF));
v<ll> no(N);

ll check(ll a, ll b)
{
    for (ll i=0;i<m-1;i++)
    {
        ll sum = (((1LL<<i)&a)>0) + (((1LL<<i)&b)>0) + (((1LL<<(i+1))&a)>0) + (((1LL<<(i+1))&b)>0);
        if (sum%2==0)
            return 0;
    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i].insert(a[i].begin(), '0');
    }
    if (n>=4 && m>=4)
    {
        cout<<-1<<"\n";
        return 0;
    }
    if (n<=3)
    {
        b=a;
        for (ll i=1;i<=m;i++)
        {
            a[i].clear();
            a[i]+='0';
            for (ll j=1;j<=n;j++)
            {
                a[i]+= b[j][i];
            }
        }
        swap(n, m);
    }
    for (ll i=0;i<(1LL<<m);i++)
        dp[0][i]=0;
    for (ll i=1;i<=n;i++)
    {
        for (ll j=1;j<=m;j++)
        {
            no[i]|=((a[i][j]-48)<<(j-1));
        }
    }
    for (ll i=1;i<=n;i++)
    {
        for (ll j=0;j<(1LL<<m);j++)
        {
            for (ll k=0;k<(1LL<<m);k++)
            {
                if (check(k, j))
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+__builtin_popcount(no[i]^j));
                }
            }
        }
    }
    ll ans=INF;
    for (ll i=0;i<(1LL<<m);i++)
        ans = min(ans, dp[n][i]);
    cout<<ans<<"\n";
}
