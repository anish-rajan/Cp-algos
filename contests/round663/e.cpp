#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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

ll t, n, m;
vector<vector<ll>> adj(N), l(N);
vector<ll> visited(N), dep(N), par(N);
ll vert;

void dfs(ll u, ll d=1, ll p=0)
{
    visited[u] = 1;
    dep[u]=d;
    l[d].pb(u);
    par[u]=p;
    if (dep[u]>=(n/2+n%2))
        vert=u;
    for (auto x:adj[u])
    {
        if (!visited[x])
        {
            dfs(x, d+1, u);
        }
    }
}

void input_adj(ll n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
        cin>>n>>m;
        input_adj(m+1);
        dfs(1);
        if (vert)
        {
            cout<<"PATH\n";
            v<ll> ans;
            while (vert!=0)
                ans.pb(vert), vert = par[vert];
            cout<<ans.size()<<"\n";
            for (auto x:ans)
                cout<<x<<" ";
            cout<<"\n";
        }
        else
        {
            cout<<"PAIRING\n";
            v<pair<ll, ll>> ans;
            for (ll j=1;j<=n;j++)
            {
                for (ll i=0;i<l[j].size() && i+1<l[j].size();i+=2)
                    ans.pb(mp(l[j][i], l[j][i+1]));
            }
            cout<<ans.size()<<"\n";
            for (auto x:ans)
                cout<<x.fi<<" "<<x.se<<"\n";
        }
        for (ll i=0;i<=n;i++)
            adj[i].clear(), visited[i]=0, dep[i]=0, par[i]=0, l[i].clear();
        vert=0;
    }
}
