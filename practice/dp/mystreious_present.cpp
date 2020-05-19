#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 5005
vector<pair<pair<ll, ll>, ll>> arr(N);
vector<pair<ll, ll>> dp(N);
int main()
{
    ll n, w, h;
    cin >> n >> h >> w;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.begin() + n);
    dp[n - 1].first = 1;
    dp[n - 1].second = n;
    for (ll i = n - 2; i >= 0; i--)
    {
        dp[i].first = 1;
        dp[i].second = n;
        for (ll j = i + 1; j < n; j++)
        {
            if (arr[i].first.first < arr[j].first.first && arr[i].first.second < arr[j].first.second)
            {
                if (dp[i].first < dp[j].first + 1)
                {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                }
            }
        }
    }
    ll ans = 0, ans1 = n;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i].first.first > h && arr[i].first.second > w)
        {
            if (ans < dp[i].first)
            {
                // cout << arr[i].first.second << " " << w;
                ans = dp[i].first;
                ans1 = i;
            }
        }
    }
    cout << ans << "\n";
    if (ans != 0)
    {
        cout << arr[ans1].second + 1 << " ";
        while (dp[ans1].second != n)
        {
            cout << arr[dp[ans1].second].second + 1 << " ";
            ans1 = dp[ans1].second;
        }
        cout << "\n";
    }
}