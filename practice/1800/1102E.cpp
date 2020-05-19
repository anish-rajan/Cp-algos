#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
#define mod 998244353
vector<ll> arr(N), dp(N);
set<pair<ll, ll>> check, check1;
int main()
{
    ll n;
    cin >> n;
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> temp(arr[i], INT64_MIN);
        auto it = check.lower_bound(temp);
        if (it == check.end() || (*it).first > arr[i])
        {
            check.insert(make_pair(arr[i], 1));
        }
        else
        {
            pair<ll, ll> val = *it;
            val.second++;
            check.erase(it);
            check.insert(val);
        }
    }
    // for (auto it = check.begin(); it != check.end(); it++)
    //     cout << (*it).first << " " << (*it).second << "\n";
    dp[0] = 1;
    pair<ll, ll> temp(arr[0], INT64_MIN);
    auto it = check1.lower_bound(temp);
    if (it == check1.end() || (*it).first > arr[0])
    {
        auto it1 = check.lower_bound(temp);
        if ((*it1).second > 1)
            check1.insert(make_pair((*it1).first, (*it1).second - 1));
    }
    else
    {
        check1.erase(it);
        if ((*it).second >= 2)
            check1.insert(make_pair((*it).first, (*it).second - 1));
    }
    for (ll i = 1; i < n; i++)
    {
        if (check1.size() == 0)
            dp[i] = (2 * dp[i - 1]) % mod;
        else
            dp[i] = dp[i - 1];
        // cout << dp[i] << " " << check1.size() << "\n";
        pair<ll, ll> temp(arr[i], INT64_MIN);
        auto it = check1.lower_bound(temp);
        if (it == check1.end() || (*it).first > arr[i])
        {
            auto it1 = check.lower_bound(temp);
            if ((*it1).second > 1)
                check1.insert(make_pair((*it1).first, (*it1).second - 1));
        }
        else
        {
            check1.erase(it);
            if ((*it).second - 1 >= 1)
                check1.insert(make_pair((*it).first, (*it).second - 1));
        }
    }
    cout << dp[n - 1] << "\n";
}