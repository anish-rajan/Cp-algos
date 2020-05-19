#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> arr(100);
int main()
{
    ll w, m;
    cin >> w >> m;
    ll p = 0;
    while (m > 0)
    {
        arr[p++] = m % w;
        // cout << arr[p - 1];
        m /= w;
    }
    ll f = 0;
    for (ll i = 0; i <= p; i++)
    {
        if (arr[i] != 1 && arr[i] != 0)
        {
            arr[i] -= w;
            arr[i + 1]++;
            // cout << arr[i] << " " << i << "\n";
        }
    }
    for (ll i = 0; i < 100; i++)
    {
        if (arr[i] != 1 && arr[i] != -1 && arr[i] != 0)
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}