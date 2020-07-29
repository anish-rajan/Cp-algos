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
#define INF 1e16

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

ll t, n, m, a, b, no, offset;
map<ll, ll> dp;
multiset<ll> dp1;
using S = ll;

vector<vector<ll>> adj(N);
vector<ll> visited(N), p(N), c(N), seq;

void dfs(ll u, ll x, ll y, ll dist = 0)
{
    if (u == x || u == y)
        return;
    if (2 * dist > m)
        return;
    visited[u] = 1;
    if (dp.find(dist - offset) == dp.end())
        dp[dist - offset] = INF;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (!visited[adj[u][i]])
        {
            dfs(adj[u][i], x, y, dist + 1);
        }
    }
}

void input_adj(long long int n)
{
    for (long long int i = 1; i <= n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        c[i] = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(S s)
{
    queue<S> q;
    q.push(s);
    vector<S> used(n + 1);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
        S v = q.front();
        q.pop();
        for (S u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                p[u] = v;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    // init_fact();
    // Sieve();
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll ans = INF;
        cin >> n >> m >> a >> b;
        input_adj(n);
        bfs(a);
        ll temp = b;
        seq.pb(temp);
        while (p[temp] != 0)
            seq.pb(p[temp]), temp = p[temp];
        reverse(seq.begin(), seq.end());
        no = seq.size();
        seq.insert(seq.begin(), 0);
        offset = 0;
        for (ll i = 1; i <= m; i++)
            dp[i] = INF;
        for (ll i = 1; i <= min(m + 1, no); i++)
        {
            ll vert = seq[i];
            ll ans1 = 0;
            if (dp[0 - offset] == dp.end())
                dp[0 - offset] = INF;
            dp[0 - offset] = ans1;
            dfs(vert, seq[i - 1], seq[i + 1]);
            if (i == no)
                ans = ans1;
            offset++;
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
