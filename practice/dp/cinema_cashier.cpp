#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll xc = (k + 1) / 2, yc = xc;
    vector<vector<vector<ll>>> dp(k + 1, vector<vector<ll>>(k + 1, vector<ll>(k + 1)));
    while (n--)
    {
        ll m;
        cin >> m;
        ll x = INT64_MAX, yl = INT64_MAX, yr = INT64_MAX;
        ll ans = INT64_MAX;
        for (ll i = 1; i <= k; i++)
        {
            for (ll j = 1; j <= k && j + m - 1 <= k; j++)
            {
                if (!dp[i][j][j + m - 1])
                {
                    ll temp1 = (abs(i - xc)) * m;
                    ll temp2 = abs(j - yc);
                    temp2 = (temp2 * (temp2 + 1)) / 2;
                    ll temp3 = abs(j + m - yc - 1);
                    temp3 = (temp3 * (temp3 + 1)) / 2;
                    ll temp4 = temp1;
                    if (j >= yc && m != 1)
                    {
                        temp4 += temp3 - temp2 + abs(j - yc);
                    }
                    else if (j + m - 1 <= yc && m != 1)
                    {
                        temp4 += temp2 - temp3 + abs(j + m - 1 - yc);
                    }
                    else if (m != 1)
                    {
                        temp4 += temp3 + temp2;
                    }
                    else
                    {
                        temp4 += abs(j - yc);
                    }
                    // cout << temp4 << " " << i << " " << j << " " << j + m - 1 << "\n";
                    if (temp4 < ans)
                    {
                        ans = temp4;
                        x = i;
                        yl = j;
                        yr = j + m - 1;
                    }
                }
            }
        }
        if (ans == INT64_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (ll i = yl; i <= yr; i++)
            {
                for (ll j = 1; j <= k; j++)
                {
                    if (i < j)
                    {
                        dp[x][i][j] = 1;
                    }
                    else
                    {
                        dp[x][j][i] = 1;
                    }
                }
            }
            for (ll i = 1; i < yl; i++)
            {
                for (ll j = yr + 1; j <= k; j++)
                {
                    dp[x][i][j] = 1;
                }
            }
            cout << x << " " << yl << " " << yr << "\n";
        }
    }
}