#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define N 100005
#define mod 998244353
ll n, m;
v<v<ll>> words(N);
v<ll> mark(N);
vector<vector<ll>> gr(N);
vector<ll> visited(N);

ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void dfs(ll u)
{
    visited[u] = 1;
    mark[u] = 1;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs(gr[u][i]);
        }
    }
}

void input_gr(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        ll len, no;
        cin >> len;
        for (ll j = 0; j < len; j++)
        {
            inp_push(no, words[i]);
        }
    }
    ll f = 1;
    for (ll i = 1; i < n; i++)
    {
        ll eq = 1;
        for (ll j = 0; j < min(words[i].size(), words[i + 1].size()); j++)
        {
            if (words[i][j] != words[i + 1][j])
            {
                if (words[i][j] > words[i + 1][j])
                    mark[words[i][j]] = 1;
                else
                    gr[words[i + 1][j]].pb(words[i][j]);
                eq = 0;
                break;
            }
        }
        if (eq == 1 && words[i].size() > words[i + 1].size())
            f = 0;
    }
    v<ll> marked;
    for (ll i = 1; i <= m; i++)
        if (mark[i])
            marked.pb(i);
    for (ll i = 0; i < marked.size(); i++)
    {
        if (!visited[marked[i]])
            dfs(marked[i]);
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < min(words[i].size(), words[i + 1].size()); j++)
        {
            if (words[i][j] != words[i + 1][j])
            {
                if (!mark[words[i][j]] && mark[words[i + 1][j]])
                    f = 0;
                else if (words[i][j] > words[i + 1][j] && !mark[words[i][j]])
                    f = 0;
                else if (words[i][j] > words[i + 1][j] && mark[words[i + 1][j]])
                    f = 0;
                break;
            }
        }
    }
    marked.clear();
    for (ll i = 1; i <= m; i++)
        if (mark[i])
            marked.pb(i);
    if (f == 1)
    {
        cout << "Yes\n";
        cout << marked.size() << "\n";
        for (ll i = 0; i < marked.size(); i++)
            cout << marked[i] << " ";
        if (marked.size() > 0)
            cout << "\n";
    }
    else
        cout << "No\n";
}