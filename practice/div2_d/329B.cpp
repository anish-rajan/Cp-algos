#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
ll r, c;
vector<vector<ll>> dp(N, vector<ll>(N)), visited(N, vector<ll>(N));
vector<string> arr(N);
void topush(pair<ll, ll> node, queue<pair<ll, ll>> &coord)
{
    ll i = node.first, j = node.second;
    if (i + 1 < r)
    {
        if (!visited[i + 1][j] && arr[i + 1][j] != 'T')
        {
            coord.push(make_pair(i + 1, j));
            visited[i + 1][j] = 1;
            dp[i + 1][j] = dp[i][j] + 1;
        }
    }
    if (i - 1 >= 0)
    {
        if (!visited[i - 1][j] && arr[i - 1][j] != 'T')
        {
            coord.push(make_pair(i - 1, j));
            visited[i - 1][j] = 1;
            dp[i - 1][j] = dp[i][j] + 1;
        }
    }
    if (j + 1 < c)
    {
        if (!visited[i][j + 1] && arr[i][j + 1] != 'T')
        {
            coord.push(make_pair(i, j + 1));
            visited[i][j + 1] = 1;
            dp[i][j + 1] = dp[i][j] + 1;
        }
    }
    if (j >= 0)
    {
        if (!visited[i][j - 1] && arr[i][j - 1] != 'T')
        {
            coord.push(make_pair(i, j - 1));
            visited[i][j - 1] = 1;
            dp[i][j - 1] = dp[i][j] + 1;
        }
    }
}
void bfs(ll ei, ll ej)
{
    queue<pair<ll, ll>> coord;
    coord.push(make_pair(ei, ej));
    visited[ei][ej] = 1;
    dp[ei][ej] = 0;
    while (!coord.empty())
    {
        pair<ll, ll> u = coord.front();
        coord.pop();
        topush(u, coord);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    ll e1, e2, s1, s2;
    for (ll i = 0; i < r; i++)
    {
        cin >> arr[i];
        for (ll j = 0; j < c; j++)
        {
            dp[i][j] = INT64_MAX;
            if (arr[i][j] == 'E')
            {
                e1 = i, e2 = j;
            }
            if (arr[i][j] == 'S')
            {
                s1 = i, s2 = j;
            }
        }
    }
    bfs(e1, e2);
    ll minvalue = dp[s1][s2];
    ll ans = 0;
    for (ll i = 0; i < r; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            // cout << dp[i][j] << " ";
            if (arr[i][j] != 'S' && arr[i][j] != 'E' && arr[i][j] != 'T')
            {
                ll temp = arr[i][j] - '0';
                if (dp[i][j] <= minvalue)
                {
                    ans += temp;
                }
            }
        }
        // cout << endl;
    }
    cout << ans << "\n";
}