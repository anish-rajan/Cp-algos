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
    ll maximum = 1;
    for (ll i = 0; i < n; i++)
    {
        ll j = i + 1;
        while (j < n)
        {
            if (arr[j] <= arr[j - 1] * 2)
                j++;
            else
                break;
        }
        j--;
        maximum = max(maximum, j - i + 1);
        i = j;
    }
    cout << maximum << "\n";
}