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
#define N 300005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e6 + 2);
v<ll> primes;

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
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

void Sieve()
{
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e6 + 2; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n, m, u;

using S = long long int;

vector<vector<pair<S, pair<S, S>>>> adj(N);
v<ll> visited(N);
v<ll> ans;
ll ans1;

void dijkstra(S s)
{
    S n = adj.size();
    vector<ll> d;
    d.assign(n + 1, INF);

    d[s] = 0;
    using pii = pair<pair<S, S>, pair<S, S>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({{0, 0}, {-1, s}});
    while (!q.empty())
    {
        S v = q.top().second.se;
        S d_v = q.top().first.fi;
        S wt = q.top().fi.se;
        S ind = q.top().se.fi;
        // cout << v << " ";
        q.pop();
        if (!visited[v])
        {
            if (ind != -1)
                ans1 += wt, ans.pb(ind);
            visited[v] = 1;
            if (d_v != d[v])
                continue;

            for (auto edge : adj[v])
            {
                S to = edge.first;
                S len = edge.second.fi;

                if (d[v] + len <= d[to])
                {
                    d[to] = d[v] + len;
                    q.push({{d[to], len}, {edge.se.se, to}});
                }
            }
        }
    }
}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(mp(v, mp(w, i)));
        adj[v].push_back(mp(u, mp(w, i)));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    input_adj(m + 1);
    cin >> u;
    dijkstra(u);
    cout << ans1 << "\n";
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
}