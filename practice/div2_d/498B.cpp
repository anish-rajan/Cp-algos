#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double ld;
#define N 5001
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, t;
v<pair<ld, ll>> prob(N);
v<v<ld>> dp(N, v<ld>(N));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    for (ll i = 1; i <= n; i++)
    {
        cin >> prob[i].first >> prob[i].second;
        prob[i].fi /= 100;
    }
    dp[0][0] = 1;
    ld sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        ld p = prob[i].fi, sum1 = dp[i - 1][i - 1] * p;
        ll counter = 1;
        ld p1 = (ld)pow(1 - p, prob[i].se - 1);
        for (ll j = i; j <= t; j++)
        {
            if (counter < prob[i].se)
            {
                dp[i][j] = sum1;
                counter++;
                sum1 *= (1 - p);
                sum1 += dp[i - 1][j] * p;
            }
            else
            {
                sum1 -= dp[i - 1][j - prob[i].se] * p1 * p;
                dp[i][j] = sum1 + dp[i - 1][j - prob[i].se] * p1;
                sum1 *= 1 - p;
                sum1 += dp[i - 1][j] * p;
                counter++;
            }
            sum += dp[i][j];
        }
    }
    printf("%0.10lf\n", sum);
    return 0;
}