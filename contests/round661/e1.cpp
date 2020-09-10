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

ll t, n, s;
vector<vector<pair<ll, ll>>> adj(N);
vector<ll> visited(N);
multiset<pair<ll, pair<ll, ll>>> nos;
ll sum;

ll dfs(ll u)
{
    visited[u] = 1;
    ll leaves=0;
    if (adj[u].size()==1)
        leaves++;
    for (auto x:adj[u])
    {
        if (!visited[x.fi])
        {
            ll temp=dfs(x.fi);
            ll diff = (x.se-(x.se/2))*temp;
            nos.insert(mp(diff, mp(temp*x.se, temp)));
            sum+=temp*x.se;
            leaves+=temp;
        }
    }
    return leaves;

}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v, w;
        cin >> u >> v>>w;
        adj[u].push_back(mp(v, w));
        adj[v].push_back(mp(u, w));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin>>t;
    while (t--)
    {
        cin>>n>>s;
        input_adj(n);
        sum=0;
        dfs(1);
        ll moves=0;
        while (sum>s)
        {
            auto itr = nos.end();
            itr--;
            auto temp = *itr;
            nos.erase(itr);
            auto temp1 = temp;
            sum-=temp1.fi;
            temp1.se.fi/=temp1.se.se;
            temp1.se.fi/=2;
            ll diff = temp1.se.fi-(temp1.se.fi/2);
            diff*=temp1.se.se;
            temp1.se.fi*=temp1.se.se;
            temp1.fi=diff;
            nos.insert(temp1);
            moves++;
        }
        cout<<moves<<"\n";
        nos.clear();
        for (ll i=0;i<=n;i++)
        {
            adj[i].clear(), visited[i]=0;
        }
    }
}