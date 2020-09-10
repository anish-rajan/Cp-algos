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
vector<vector<pair<ll, pair<ll, ll>>>> adj(N);
vector<ll> visited(N);
multiset<pair<ll, pair<ll, ll>>> one, two;
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
            ll diff = (x.se.fi-(x.se.fi/2))*temp;
            if (x.se.se==1)
                one.insert(mp(diff, mp(temp*x.se.fi, temp)));
            else
                two.insert(mp(diff, mp(temp*x.se.fi, temp)));
            sum+=temp*x.se.fi;
            leaves+=temp;
        }
    }
    return leaves;

}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v, w, c;
        cin >> u >> v>>w>>c;
        adj[u].push_back(mp(v, mp(w, c)));
        adj[v].push_back(mp(u, mp(w, c)));
    }
}

multiset<pair<ll, pair<ll, ll>>>::iterator conv(multiset<pair<ll, pair<ll, ll>>> &nos)
{
    auto itr = nos.end();
    itr--;
    auto temp1 = *itr;
    nos.erase(itr);
    temp1.se.fi/=temp1.se.se;
    temp1.se.fi/=2;
    ll diff = temp1.se.fi-(temp1.se.fi/2);
    diff*=temp1.se.se;
    temp1.se.fi*=temp1.se.se;
    temp1.fi=diff;
    nos.insert(temp1);
    itr= nos.find(temp1);
    return itr;
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
        ll cost=INF;
        v<ll> onea, twoa;
        ll ok=1;
        if (one.empty())
            ok=0;
        while (ok)
        {
            auto itr = one.end();
            itr--;
            ll added=0;
            if (onea.size()>0)
                added=onea.back();
            onea.pb(added+itr->fi);
            itr = conv(one);
            itr=one.end(), itr--;
            if (itr->fi==0)
                ok=0;
        }
        ok=1;
        if (two.empty())
            ok=0;
        while (ok)
        {
            auto itr = two.end();
            itr--;
            ll added=0;
            if (twoa.size()>0)
                added=twoa.back();
            twoa.pb(added+itr->fi);
            itr = conv(two);
            itr = two.end(), itr--;
            if (itr->fi==0)
                ok=0;
        }
        ll itr = lower_bound(ALL(onea), sum-s)-onea.begin();
        if (sum-s<=0)
            cost=0;
        if (itr!=onea.size())
            cost=min(cost, itr+1);
        for (ll i=0;i<twoa.size();i++)
        {
            ll curcost = 2*i+2;
            ll itr = lower_bound(ALL(onea), sum-s-twoa[i])-onea.begin();
            if (sum-s-twoa[i]<=0)
                cost = min(cost, curcost);
            if (itr!=onea.size())
                cost = min(cost, curcost+itr+1);
        }
        cout<<cost<<"\n";
        one.clear(), two.clear();
        for (ll i=0;i<=n;i++)
        {
            adj[i].clear(), visited[i]=0;
        }
    }
}