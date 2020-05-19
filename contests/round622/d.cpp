#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 500005
vector<ll> arr(N), dp(N), dp1(N);
set<pair<ll, ll>> elem;
ll n;
set<pair<ll, ll>>::iterator inorder_pred(ll element)
{
    pair<ll, ll> temp(element, INT64_MIN);
    set<pair<ll, ll>>::iterator itr = elem.lower_bound(temp);
    if (itr == elem.end())
        itr--;
    else if ((*itr).first != element)
    {
        if (itr == elem.begin())
            itr = elem.end();
        else
            itr--;
    }
    return itr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    elem.insert(make_pair(arr[1], 1));
    for (ll i = 2; i <= n; i++)
    {
        // cout << elem.size();
        if (arr[i] >= arr[i - 1])
        {
            dp[i] = dp[i - 1] + arr[i];
            set<pair<ll, ll>>::iterator itr = inorder_pred(arr[i]);
            // for (auto itr1 = elem.begin(); itr1 != elem.end(); itr1++)
            // {
            //     cout << i << " " << (*itr1).first << " ";
            // }
            // cout << (itr == elem.end()) << "\n";
            if (itr == elem.end())
            {
                elem.clear();
            }
            else if ((*itr).first != arr[i])
            {
                elem.erase(++itr, elem.end());
            }
            else
                elem.erase(itr, elem.end());
        }
        else
        {
            auto itr = inorder_pred(arr[i]);
            // for (auto itr1 = elem.begin(); itr1 != elem.end(); itr1++)
            // {
            //     cout << i << " " << (*itr1).first << " ";
            // }
            if (itr == elem.end())
            {
                dp[i] = arr[i] * i;
            }
            else
            {
                dp[i] = dp[(*itr).second] + arr[i] * abs((*itr).second - i);
            }
            if (itr == elem.end())
            {
                elem.clear();
            }
            else if ((*itr).first != arr[i])
            {
                elem.erase(++itr, elem.end());
            }
            else
                elem.erase(itr, elem.end());
        }
        elem.insert(make_pair(arr[i], i));
    }
    elem.clear();
    dp1[n] = arr[n];
    elem.insert(make_pair(arr[n], n));
    for (ll i = n - 1; i >= 1; i--)
    {
        if (arr[i] >= arr[i + 1])
        {
            dp1[i] = dp1[i + 1] + arr[i];
            auto itr = inorder_pred(arr[i]);
            if (itr == elem.end())
            {
                elem.clear();
            }
            else if ((*itr).first != arr[i])
            {
                elem.erase(++itr, elem.end());
            }
            else
                elem.erase(itr, elem.end());
        }
        else
        {
            auto itr = inorder_pred(arr[i]);
            if (itr == elem.end())
            {
                dp1[i] = arr[i] * (n - i + 1);
            }
            else
            {
                dp1[i] = dp1[(*itr).second] + arr[i] * abs((*itr).second - i);
            }
            if (itr == elem.end())
            {
                elem.clear();
            }
            else if ((*itr).first != arr[i])
            {
                elem.erase(++itr, elem.end());
            }
            else
                elem.erase(itr, elem.end());
        }
        elem.insert(make_pair(arr[i], i));
    }
    ll pos = 0;
    ll maxsum = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (maxsum < dp[i] + dp1[i] - arr[i])
        {
            maxsum = dp[i] + dp1[i] - arr[i];
            pos = i;
        }
        // cout << dp[i] << " " << dp1[i] << "\n";
    }
    vector<ll> ansvec;
    ll minelem = arr[pos];
    for (ll j = pos - 1; j >= 1; j--)
    {
        ansvec.push_back(min(arr[j], minelem));
        minelem = min(arr[j], minelem);
    }
    reverse(ansvec.begin(), ansvec.end());
    ansvec.push_back(arr[pos]);
    minelem = arr[pos];
    for (ll j = pos + 1; j <= n; j++)
    {
        ansvec.push_back(min(arr[j], minelem));
        minelem = min(arr[j], minelem);
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ansvec[i] << " ";
    }
    cout << endl;
}