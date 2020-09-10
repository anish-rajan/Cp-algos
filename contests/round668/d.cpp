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

ll t, n, a, b, da, db;
vector<vector<ll>> adj(N);
vector<ll> visited(N);

using S = ll;

pair<ll, ll> bfs(S s, S de)
{
    queue<S> q;
    vector<S> d(n + 1);
    q.push(s);
    visited[s] = true;
    d[s] = 0;
    ll ans = 0;
    while (!q.empty())
    {
        S v = q.front();
        q.pop();
        for (S u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                ans = max(ans, d[u]);
            }
        }
    }
    return mp(ans, d[de]);
}

vector<ll> dp(N);

//fill dp all elements with 0 and fill visited all elements with 0
ll diameter(ll u)
{
    visited[u] = 1;
    ll ans = 0;
    dp[u] = 0;
    ll firstmax = 0, secondmax = 0;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (!visited[adj[u][i]])
        {
            ans = max(ans, diameter(adj[u][i]));
            dp[u] = max(dp[u], dp[adj[u][i]] + 1);
            if (firstmax <= dp[adj[u][i]])
            {
                secondmax = firstmax;
                firstmax = dp[adj[u][i]];
            }
            else if (secondmax < dp[adj[u][i]])
            {
                secondmax = dp[adj[u][i]];
            }
        }
    }
    if (adj[u].size() >= 2)
        ans = max(ans, firstmax + secondmax + 2);
    ans = max(ans, dp[u]);

    return ans;
}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
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
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> da >> db;
        input_adj(n);
        ll f = 1;
        if (da >= db / 2 + db % 2)
            f = 0;
        ll dia = diameter(1);
        if (dia / 2 + dia % 2 <= da)
            f = 0;
        fill(visited.begin(), visited.begin() + n + 1, false);
        auto temp = bfs(b, a);
        if (temp.se <= da)
            f = 0;
        // cout << dia << " ";
        if (f == 1)
            cout << "Bob\n";
        else
            cout << "Alice\n";
        for (ll i = 0; i <= n; i++)
        {
            visited[i] = 0;
            adj[i].clear();
        }
    }
}
