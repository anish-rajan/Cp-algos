#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> factors;
    ll temp = n;
    for (ll i = 3; i <= temp / 2; i++)
    {
        if (temp % i == 0)
        {
            factors.push_back(i);
            while (temp % i == 0)
            {
                temp /= i;
            }
        }
    }
    if (temp > 1)
        factors.push_back(temp);
    temp = n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll f = 1;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            f = 0;
            break;
        }
    }
    if (f == 1)
    {
        cout << "YES\n";
        return 0;
    }
    ll j = 0;
    while (j < factors.size())
    {
        // cout << temp << "\n";
        temp = factors[j];
        if (temp >= 3)
        {
            ll inc = n / temp;
            for (ll i = 0; i + (inc) * (temp - 1) < n; i++)
            {
                ll f = 1;
                for (ll j = i; j < n; j += inc)
                    if (arr[j] == 0)
                    {
                        f = 0;
                        break;
                    }
                if (f == 1)
                {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
        j++;
    }
    cout << "NO\n";
    return 0;
}