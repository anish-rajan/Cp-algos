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
#define N 3003
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
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
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
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

ll n, m, l1, l2;
v<v<ll>> adj(N), dist(N, v<ll>(N));
v<ll> vs1(2), vs2(2);

using S = ll;
void bfs(S s, vector<S> &d)
{
    fill(d.begin(), d.end(), INF);
    queue<S> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        S v = q.front();
        q.pop();
        for (S u : adj[v])
        {
            if (d[u] == INF)
            {
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
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
    cin >> n >> m;
    input_adj(m + 1);
    cin >> vs1[0] >> vs1[1] >> l1 >> vs2[0] >> vs2[1] >> l2;
    for (ll i = 1; i <= n; i++)
    {
        bfs(i, dist[i]);
    }
    ll ans = dist[vs1[0]][vs1[1]] + dist[vs2[0]][vs2[1]];
    if (dist[vs1[0]][vs1[1]] > l1 || dist[vs2[0]][vs2[1]] > l2)
    {
        cout << -1 << "\n";
        return 0;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                for (ll l = 0; l < 2; l++)
                {
                    if (dist[vs1[k]][i] + dist[i][j] + dist[j][vs1[1 ^ k]] <= l1 &&
                        dist[vs2[l]][i] + dist[i][j] + dist[j][vs2[1 ^ l]] <= l2)
                    {
                        ans = min(ans, dist[vs1[k]][i] + dist[i][j] + dist[j][vs1[1 ^ k]] + dist[vs2[l]][i] + dist[j][vs2[1 ^ l]]);
                    }
                }
            }
        }
    }
    cout << m - ans << "\n";
}