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
#define N 32
ll t;
v<ll> pow2(32);
v<ll> pow21(32);
void comp(ll m)
{
    pow2[0] = 1;
    pow21[0] = 1;
    for (ll i = 1; i <= 31; i++)
    {
        pow2[i] = (pow2[i - 1] * (2)) % m;
        pow21[i] = pow21[i - 1] * 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll d, m;
        cin >> d >> m;
        ll bits = log2(d) + 1, sum = 0;
        comp(m);
        v<v<ll>> dp(32, v<ll>(32));
        dp[0] = {0};
        dp[0][0] = 1;
        for (ll i = 1; i <= bits; i++)
        {
            fill(dp[i].begin(), dp[i].end(), 0);
            ll sum1 = 0;
            if (i == 1)
                sum1 = 1;
            for (ll j = 1; j <= bits; j++)
            {
                if (j < bits)
                {
                    dp[i][j] = (sum1 * pow2[j - 1]) % m;
                }
                else
                {
                    // cout << (d - pow21[j - 1]) << " " << pow21[j - 1] - 1 << endl;
                    dp[i][j] = sum1 * ((d - pow21[j - 1] + 1));
                }
                sum = (sum + dp[i][j]) % m;
                sum1 += dp[i - 1][j];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        cout << sum << endl;
    }
}