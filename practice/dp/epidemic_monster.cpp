#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 505
vector<vector<ll>> dp;
vector<ll> weights(N);
vector<ll> barr(N);
vector<pair<ll, char>> sol;
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> weights[i];
    }
    ll k;
    cin >> k;
    for (ll i = 1; i <= k; i++)
    {
        cin >> barr[i];
    }
    ll y = 0;
    ll p = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll j = i;
        vector<ll> temp;
        ll sum = 0;
        while (sum < barr[p] && j <= n)
        {
            sum += weights[j];
            temp.push_back(weights[j]);
            j++;
        }
        if (sum > barr[p] || sum < barr[p])
        {
            y = 1;
            break;
        }
        else
        {
            dp.push_back(temp);
            p++;
            i = j - 1;
        }
        if ((p <= k && i >= n) || (i < n && p > k))
            y = 1;
    }
    for (ll i = 0; i < dp.size(); i++)
    {
        ll maxelement = -1;
        ll ind = 0;
        ll counter = 0;
        ll s = dp[i].size();
        for (ll j = 0; j < s; j++)
        {
            if (dp[i][j] > maxelement)
            {
                maxelement = dp[i][j];
                ind = j;
                counter = 0;
            }
            if (dp[i][j] == maxelement)
            {
                if (j > 0)
                    if (dp[i][j - 1] < maxelement)
                        ind = j;
                if (j < s - 1)
                    if (dp[i][j + 1] < maxelement)
                        ind = j;
                counter++;
            }
        }
        if (s == counter)
        {
            if (s > 1)
            {
                y = 1;
                break;
            }
            else
                continue;
        }
        // cout << dp[i][ind] << " " << dp[i][ind + 1] << " " << maxelement << "\n";
        if (ind > 0)
        {
            if (dp[i][ind - 1] < maxelement)
            {
                dp[i][ind] += dp[i][ind - 1];
                dp[i].erase(dp[i].begin() + ind - 1);
                sol.push_back(make_pair(i + 1 + ind, 'L'));
                ind--;
            }
            else if (ind < s - 1)
            {
                if (dp[i][ind + 1] < maxelement)
                {
                    dp[i][ind] += dp[i][ind + 1];
                    dp[i].erase(dp[i].begin() + ind + 1);
                    sol.push_back(make_pair(i + 1 + ind, 'R'));
                }
            }
        }
        else
        {
            if (dp[i][ind + 1] < maxelement)
            {
                dp[i][ind] += dp[i][ind + 1];
                dp[i].erase(dp[i].begin() + ind + 1);
                sol.push_back(make_pair(i + 1 + ind, 'R'));
            }
        }
        s--;
        while (ind + 1 != s)
        {
            dp[i][ind] += dp[i][ind + 1];
            dp[i].erase(dp[i].begin() + ind + 1);
            sol.push_back(make_pair(i + 1 + ind, 'R'));
            s--;
        }
        while (s > 1)
        {
            // cout << i << " " << s << "\n";
            dp[i][s - 1] += dp[i][s - 2];
            dp[i].erase(dp[i].begin() + s - 1);
            sol.push_back(make_pair(i + s, 'L'));
            s--;
        }
    }
    if (y == 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (ll i = 0; i < sol.size(); i++)
        {
            cout << sol[i].first << " " << sol[i].second << "\n";
        }
    }
}