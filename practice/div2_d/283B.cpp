#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
ll n;
vector<ll> dp(N), arr(N), visited(N);
ll dfs(ll x)
{
    // cout << x << " ";
    if (x == 1)
    {
        return -1;
    }
    else
    {
        visited[x] = 1;
        ll temp = x;
        dp[temp] = arr[x];
        x -= arr[x];
        if (x <= 0)
        {
            visited[temp] = 2;
            return dp[temp];
        }
        else if (x == 1)
        {
            dp[temp] = -1;
            visited[temp] = 2;
            return dp[temp];
        }
        dp[temp] += arr[x];
        x += arr[x];
        if (x > n)
        {
            visited[temp] = 2;
            return dp[temp];
        }
        if (visited[x] == 2)
        {
            if (dp[x] == -1)
                dp[temp] = -1;
            else
                dp[temp] += dp[x];
            visited[temp] = 2;
            return dp[temp];
        }
        else if (!visited[x])
        {
            ll temp1 = dfs(x);
            if (temp1 == -1)
                dp[temp] = -1;
            else
                dp[temp] += temp1;
            visited[temp] = 2;
            return dp[temp];
        }
        else
        {
            dp[temp] = -1;
            visited[temp] = 2;
            return -1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 2; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 2; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    for (ll i = 2; i <= n; i++)
    {
        if (dp[i] == -1)
            cout << dp[i] << "\n";
        else
            cout << i - 1 + dp[i] << "\n";
    }
}