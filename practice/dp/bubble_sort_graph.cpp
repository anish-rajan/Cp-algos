#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> arr(N);
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> ans;
    ans.push_back(arr[1]);
    for (ll i = 2; i <= n; i++)
    {
        ll ind = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
        if (ind >= ans.size())
        {
            ans.push_back(arr[i]);
        }
        else
            ans[ind] = arr[i];
    }
    cout << ans.size() << "\n";
}