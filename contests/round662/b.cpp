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
ll n;
set<pair<ll, ll>> t, f;
v<ll> a(N);
map<ll, ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++)
        cin>>a[i], cnt[a[i]]++;
    for (auto x:cnt)
    {
        if (x.se>=4)
            f.insert({ x.se, x.fi });
        else if (x.se>=2)
            t.insert({ x.se, x.fi });
    }
    ll q;
    cin>>q;
    while (q--)
    {
        char s;
        ll x;
        cin>>s>>x;
        if (cnt[x]>=4)
            f.erase({ cnt[x], x });
        else if (cnt[x]>=2)
            t.erase({ cnt[x], x });
        if (s=='+')
            cnt[x]++;
        else
            cnt[x]--;
        if (cnt[x]>=4)
            f.insert({ cnt[x], x });
        else if (cnt[x]>=2)
            t.insert({ cnt[x], x });
        ll pos=1;
        if (f.size()==0)
            pos=0;
        if (t.size()<2)
        {
            ll t1=0;
            if (t.size()>0)
                t1+=2;
            auto itr = f.end();
            if (f.size()>0)
            {
                itr--, t1+=itr->fi;
                if (itr!=f.begin())
                    itr--, t1+=itr->fi;
            }
            if (t1<8)
                pos=0;
        }
        if (pos==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
