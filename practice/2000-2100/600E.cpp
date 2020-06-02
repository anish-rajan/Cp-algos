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

using S = long long int;

v<ll> ans(N);
S cnt[N];
bool big[N];
S sz[N];
vector<S> col(N);
vector<vector<S>> adj(N);
map<ll, ll> count1;
void getsz(S v, S p)
{
    sz[v] = 1; // every vertex has itself in its subtree
    for (auto u : adj[v])
        if (u != p)
        {
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
}

void add(S v, S p, S x)
{
    count1[cnt[col[v]]] -= col[v];
    if (count1[cnt[col[v]]] <= 0)
        count1.erase(cnt[col[v]]);
    cnt[col[v]] += x;
    count1[cnt[col[v]]] += col[v];
    for (auto u : adj[v])
        if (u != p && !big[u])
            add(u, v, x);
}
void dfs(S v, S p, bool keep)
{
    S mx = -1, bigChild = -1;
    for (auto u : adj[v])
        if (u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for (auto u : adj[v])
        if (u != p && u != bigChild)
            dfs(u, v, 0); // run a dfs on small childs and clear them from cnt
    if (bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1; // bigChild marked as big and not cleared from cnt
    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

    auto f = count1.end();
    f--;
    ans[v] = f->se;

    if (bigChild != -1)
        big[bigChild] = 0;
    if (keep == 0)
        add(v, p, -1);
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
    for (ll i = 1; i <= n; i++)
        cin >> col[i];
    input_adj(n);
    getsz(1, 0);
    dfs(1, 0, 1);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}