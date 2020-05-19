#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<ll> arr(N);
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    vector<ll> ansvec;
    for (ll i = 0; i < n; i++)
    {
        ll sum = 0;
        vector<ll> temp;
        ll minelem = arr[i];
        for (ll j = i - 1; j >= 0; j--)
        {
            sum += min(arr[j], minelem);
            temp.push_back(min(arr[j], minelem));
            minelem = min(arr[j], minelem);
        }
        reverse(temp.begin(), temp.end());
        sum += arr[i];
        temp.push_back(arr[i]);
        minelem = arr[i];
        for (ll j = i + 1; j < n; j++)
        {
            sum += min(arr[j], minelem);
            temp.push_back(min(arr[j], minelem));
            minelem = min(arr[j], minelem);
        }
        if (ans < sum)
        {
            ans = sum;
            ansvec = temp;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ansvec[i] << " ";
    }
    cout << endl;
    // cout << ans << "\n";
}