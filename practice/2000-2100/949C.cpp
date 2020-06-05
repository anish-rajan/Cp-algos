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
#define INF INT_MAX

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

ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a * b) / __gcd(a, b);
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll n, m, h;
v<ll> a(N);

using S = ll;
vector<vector<S>> adj(N), adjT(N);
struct SCC
{
    vector<bool> visited;
    vector<S> order, component;
    vector<S> belong;
    vector<S> condsz;
    vector<vector<S>> cond;
    S noc, n;

    SCC(S no)
    {
        n = no;
        visited.resize(n + 1, false);
        belong.resize(n + 1);
        cond.resize(n + 1);
        condsz.resize(n + 1);
        noc = 0;
        for (S i = 1; i <= n; ++i)
            if (!visited[i])
                dfs1(i);
        fill(visited.begin(), visited.begin() + n + 1, false);
        for (S i = 0; i < n; ++i)
        {
            S v = order[n - 1 - i];
            if (!visited[v])
            {
                dfs2(v);
                noc++;
                for (auto x : component)
                    belong[x] = noc;
                condsz[noc] = component.size();
                component.clear();
            }
        }
        make_cond();
    }

    void make_cond()
    {
        for (ll i = 1; i <= n; i++)
        {
            for (auto x : adj[i])
            {
                if (belong[x] != belong[i])
                    cond[belong[i]].pb(belong[x]);
            }
        }
    }

    void dfs1(S v)
    {
        visited[v] = true;
        for (S i = 0; i < adj[v].size(); ++i)
            if (!visited[adj[v][i]])
                dfs1(adj[v][i]);
        order.push_back(v);
    }

    void dfs2(S v)
    {
        visited[v] = true;
        component.push_back(v);
        for (S i = 0; i < adjT[v].size(); ++i)
            if (!visited[adjT[v][i]])
                dfs2(adjT[v][i]);
    }
};

void input_adj(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        if ((a[u] + 1) % h == a[v])
        {
            adj[u].push_back(v);
            adjT[v].pb(u);
        }
        if ((a[v] + 1) % h == a[u])
        {
            adj[v].push_back(u);
            adjT[u].pb(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m >> h;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    input_adj(m);
    for (ll i = 1; i <= n; i++)
        UN(adj[i]), UN(adjT[i]);
    SCC scc(n);
    ll ans = n, ans1 = 1;
    for (ll i = 1; i <= scc.noc; i++)
    {
        if (scc.cond[i].size() == 0)
        {
            if (ans > scc.condsz[i])
                ans = scc.condsz[i], ans1 = i;
        }
    }
    // cout << scc.noc << "\n";
    // cout << scc.cond[1].size() << " " << scc.cond[2].size() << " " << scc.cond[3].size() << "\n";
    cout << ans << "\n";
    for (ll i = 1; i <= n; i++)
    {
        if (scc.belong[i] == ans1)
            cout << i << " ";
    }
    cout << "\n";
}