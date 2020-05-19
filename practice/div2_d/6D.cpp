#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 20
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
const ll INF = 1000000000000;
ll n, a, b;
v<ll> h(N), ans;
v<v<v<ll>>> dp(N, v<v<ll>>(N, v<ll>(N, -1))), hh(N, v<v<ll>>(N, v<ll>(N, -1))), sh(N, v<v<ll>>(N, v<ll>(N, -1)));
ll dfs(ll i, ll j, ll k)
{
    if (i == n - 1)
    {
        if (j > 0)
            return INF;
        else
            return 0;
    }
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    dp[i][j][k] = INF;
    ll health = max((ll)0, h[i] - k * b);

    for (ll s = 0; s <= 17; s++)
    {
        if (s * b < j)
        {
            continue;
        }
        ll temp = max(health - s * a, (ll)0);
        ll p = dfs(i + 1, temp, s) + s;
        // if (i == n - 2)
        //     cout << j << " " << s << " " << p << "\n";
        if (dp[i][j][k] > p)
        {
            dp[i][j][k] = p;
            hh[i][j][k] = temp;
            sh[i][j][k] = s;
        }
    }
    return dp[i][j][k];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // fill(ALL(dp), -1);
    cin >> n >> a >> b;
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
        h[i]++;
    }
    while (h[0] > 0)
    {
        h[0] -= b, h[1] -= a, h[2] -= b;
        ans.pb(2);
    }
    h[0] = max(h[0], (ll)0);
    h[1] = max(h[1], (ll)0);
    h[2] = max(h[2], (ll)0);
    while (h[n - 1] > 0)
    {
        h[n - 1] -= b, h[n - 2] -= a, h[n - 3] -= b;
        ans.pb(n - 2 + 1);
    }
    h[n - 1] = max((ll)0, h[n - 1]);
    h[n - 2] = max((ll)0, h[n - 2]);
    h[n - 3] = max((ll)0, h[n - 3]);
    dfs(1, h[0], 0);
    ll health = 0, shots = 0, i = 1;
    while (i != n - 1)
    {
        ll p = sh[i][health][shots];
        ll temp = health;
        while (p--)
            ans.pb(i + 1);
        health = hh[i][health][shots];
        shots = sh[i][temp][shots];
        i++;
    }
    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}