#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define N 5005
#define mod 1000000007
#define INF INT_MAX
ll n, m, n1, n2, n3, poss;
vector<vector<ll>> gr(N);
vector<ll> visited(N), visited1(N);
v<v<ll>> dp, vals;
v<ll> st;
void dfs(ll u, ll c, ll &nr, ll &nb)
{
    visited[u] = c;
    c == 1 ? nr++ : nb++;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            dfs(gr[u][i], c == 1 ? 2 : 1, nr, nb);
        }
        else if (visited[gr[u][i]] == c)
        {
            poss = 0;
        }
    }
}
void dfs1(ll u, ll no)
{
    visited[u] = visited[u] == no ? 2 : (n1 > 0 ? 1 : 3);
    if (visited[u] != 2)
        visited[u] == 1 ? n1-- : n3--;
    visited1[u] = 1;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited1[gr[u][i]])
        {
            dfs1(gr[u][i], no);
        }
    }
}
void input_gr(long long int n)
{
    for (long long int i = 0; i < n; i++)
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
    cin >> n >> m >> n1 >> n2 >> n3;
    input_gr(m);
    poss = 1;
    ll c = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            // cout << i << " " << c << " \n";
            st.pb(i);
            ll nr = 0, nb = 0;
            dfs(i, 1, nr, nb);
            vals.pb(v<ll>(3));
            vals.back()[1] = nr, vals.back()[2] = nb;
            dp.pb(v<ll>(n + 1, 0));
            // dp[c][0] = 1;
            if (c == 0)
            {
                dp[c][nr] = 1, dp[c][nb] = 2;
                c++;
                // cout << c << "\n";
                continue;
            }
            // cout << nr << " " << nb << "\n";
            for (ll j = 0; j <= n; j++)
            {
                if (j - nr >= 0)
                    if (dp[c - 1][j - nr])
                        dp[c][j] = 1;
                if (j - nb >= 0)
                    if (dp[c - 1][j - nb])
                        dp[c][j] = 2;
            }
            c++;
            // cout << c << "\n";
        }
    }
    c--;
    // cout << visited[3] << " " << n << " " << c << " " << n2 << "\n";
    // for (ll i = 0; i <= c; i++)
    // {
    //     for (ll j = 0; j <= n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    if (!dp[c][n2])
        poss = 0;
    if (poss == 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (ll j = c; j >= 0; j--)
    {
        dfs1(st[j], dp[j][n2]);
        // cout << dp[j][n2] << " " << st[j] << " " << vals[j][dp[j][n2]] << "\n";
        n2 -= vals[j][dp[j][n2]];
    }
    for (ll i = 1; i <= n; i++)
        cout << visited[i];
    cout << "\n";
    // cout << n1 << " " << n3 << "\n";
}