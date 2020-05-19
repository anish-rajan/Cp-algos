#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<vector<ll>> arr(N, vector<ll>(N)), dp1(N, vector<ll>(N)), dp2(N, vector<ll>(N)), dp3(N, vector<ll>(N)), dp4(N, vector<ll>(N));
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = arr[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    for (int j = m; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            dp2[i][j] = arr[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = arr[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = arr[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (j > 1 && j < m && i > 1 && i < n)
            {
                ans = max(ans, dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1]);
                ans = max(ans, dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j]);
            }
        }
    }
    cout << ans << "\n";
}