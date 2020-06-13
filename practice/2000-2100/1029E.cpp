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
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll n;
v<v<ll>> adj(N);
v<ll> visited(N);
v<v<ll>> dp(N, v<ll>(4));

void dfs(ll u, ll par, ll dist)
{
    visited[u] = 1;
    ll S = 0, S1 = 0, S2 = 0;
    dp[u][1] = (par != 1), dp[u][3] = INT64_MAX;
    for (auto x : adj[u])
    {
        if (!visited[x] && x != par)
        {
            dfs(x, u, dist + 1);
            dp[u][1] += min(dp[x][1], dp[x][2]);
            dp[u][2] += min(dp[x][1], dp[x][3]);
        }
    }
    if (adj[u].size() > 1)
        for (auto x : adj[u])
            if (x != par)
                dp[u][3] = min(dp[u][3], dp[u][2] - min(dp[x][1], dp[x][3]) + dp[x][1]);
    // cout << u << " " << dp[u][1] << " " << dp[u][2] << " " << dp[u][3] << "\n";
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
    cin >> n;
    input_adj(n);
    ll ans = 0;
    for (auto x : adj[1])
        dfs(x, 1, 1), ans += dp[x][1];
    cout << ans << "\n";
}