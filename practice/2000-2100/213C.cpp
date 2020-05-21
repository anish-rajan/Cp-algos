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
#define N 303
#define mod 1000000007
#define INF INT_MAX
ll n;
v<v<ll>> a(N, v<ll>(N));
v<v<v<ll>>> dp(2 * N, v<v<ll>>(N, v<ll>(N, -INF)));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            cin >> a[i][j];
    dp[1][1][1] = a[1][1];
    for (ll i = 2; i <= 2 * n - 1; i++)
    {
        for (ll j = 1; j <= min(n, i); j++)
        {
            for (ll k = 1; k <= min(n, i); k++)
            {
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
                dp[i][j][k] += a[j][i - j + 1];
                if (j != k)
                    dp[i][j][k] += a[k][i - k + 1];
            }
        }
    }
    cout << dp[2 * n - 1][n][n] << "\n";
}