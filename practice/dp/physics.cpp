#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll j = 0;
    ll maximum = -1;
    for (ll i = 0; i < n; i++)
    {
        while (j < n)
        {
            if (arr[j] <= 2 * arr[i])
            {
                j++;
            }
            else
                break;
        }
        maximum = max(maximum, j - i);
        if (j >= n)
            break;
    }
    cout << n - maximum << "\n";
}