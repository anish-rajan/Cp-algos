#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1005
vector<ll> arr(N), ans;
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll g = arr[0];
    for (ll i = 0; i < n; i++)
    {
        g = __gcd(arr[i], g);
    }
    for (ll i = 0; i < n; i++)
    {
        ans.push_back(arr[i]);
        ans.push_back(arr[0]);
    }
    if (g != arr[0])
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans.size() << "\n";
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}