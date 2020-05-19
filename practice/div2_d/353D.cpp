#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000006
string s;
vector<ll> dp(N), no(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    ll n = s.size();
    no[0] = s[0] == 'M';
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'M')
            no[i] = no[i - 1] + 1;
        else
            no[i] = no[i - 1];
    }
    ll counter = 0;
    ll last = 0, st = 0, lastans = 0;
    ll ans = -1;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'F')
        {
            counter++;
            if (counter == 1 || (i - counter + 1) > lastans || i == counter - 1)
            {
                dp[i] = i - counter + 1;
            }
            else
            {
                dp[i] = lastans + 1;
            }
            lastans = dp[i];
            // cout << lastans << " ";
            ans = max(ans, dp[i]);
        }
    }
    if (ans == -1)
        ans = 0;
    cout << ans << "\n";
}