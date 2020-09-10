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
#define INF 1e15

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

ll n;
v<ll> a(N), b(N), order;
ll ans;

using S = long long int;
// number of vertices
vector<vector<S>> gr(N); // gracency list of graph
vector<bool> visited(N);
vector<S> ts;

void dfs(S v)
{
    visited[v] = true;
    for (S u : gr[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ts.push_back(v);
}

void topological_sort()
{
    visited.assign(n + 1, false);
    ts.clear();
    for (S i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ts.begin(), ts.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i] > 0)
            gr[i].pb(b[i]);
    }
    topological_sort();
    fill(visited.begin(), visited.end(), false);
    v<ll> order;
    for (auto x : ts)
    {
        if (a[x] >= 0)
        {
            visited[x] = 1;
            order.pb(x);
            ans += a[x];
            if (b[x] > 0)
                a[b[x]] += a[x];
        }
    }
    for (ll i = ts.size() - 1; i >= 0; i--)
    {
        if (!visited[ts[i]])
        {
            ans += a[ts[i]];
            order.pb(ts[i]);
            visited[ts[i]] = 1;
            if (b[ts[i]] > 0)
                a[b[ts[i]]] += a[ts[i]];
        }
    }
    cout << ans << "\n";
    for (auto x : order)
        cout << x << " ";
    cout << "\n";
}
