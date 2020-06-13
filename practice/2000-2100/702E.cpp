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

ll n, k;
v<ll> child(N);
v<ll> weights(N), visited(N), visited1(N);

struct Query
{
    ll to, val, sum;
};

v<v<Query>> down(N, v<Query>(40, {0, INT64_MAX, 0}));
v<Query> ans(N);

void dfs(ll u, ll j)
{
    visited[u] = 1;
    visited1[u] = 1;
    down[u][j].to = down[down[u][j - 1].to][j - 1].to;
    down[u][j].val = min(down[u][j - 1].val, down[down[u][j - 1].to][j - 1].val);
    down[u][j].sum = down[u][j - 1].sum + down[down[u][j - 1].to][j - 1].sum;
    if (down[child[u]][j].to == 0)
        dfs(child[u], j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> child[i], child[i]++, down[i][0].to = child[i];
    for (ll i = 1; i <= n; i++)
        cin >> weights[i], down[i][0].val = down[i][0].sum = weights[i];
    ll L = ceil(log2(k)) + 2;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            for (ll j = 1; j <= L; j++)
            {
                dfs(i, j);
            }
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 0; j <= L; j++)
    //         cout << down[i][j].val << " ";
    //     cout << "\n";
    // }
    for (ll i = 1; i <= n; i++)
    {
        ll temp = k, cnt = 0, sum = 0, minval = INT_MAX, to = i;
        while (temp > 0)
        {
            if (temp % 2)
            {
                minval = min(minval, down[to][cnt].val);
                sum += down[to][cnt].sum;
                to = down[to][cnt].to;
            }
            temp /= 2;
            cnt++;
        }
        ans[i] = Query({to, minval, sum});
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i].sum << " " << ans[i].val << "\n";
    }
}