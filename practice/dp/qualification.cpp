#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll onesComplement(ll n)
{
    // Find number of bits in the given integer
    ll number_of_bits = floor(log2(n)) + 1;

    // XOR the given integer with poe(2,
    // number_of_bits-1 and print the result
    return ((1 << number_of_bits) - 1) ^ n;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<pair<ll, ll>, vector<ll>>> count(16);
    for (ll i = 0; i < n; i++)
    {
        ll temp = 1;
        ll sum = 0, sum1 = 0;
        vector<ll> temp1;
        for (ll j = 0; j < k; j++)
        {
            ll p;
            cin >> p;
            temp1.push_back(p);
            sum1 += p;
            sum += temp * p;
            temp *= 2;
        }
        count[sum].first.first++;
        count[sum].first.second = sum1;
        count[sum].second = temp1;
    }
    ll yes = 0;
    if (count[0].first.first > 0)
    {
        yes = 1;
    }
    else
    {
        for (ll i = 0; i < 16; i++)
        {
            if (count[i].first.first > 0)
                if (count[i].first.second == 1)
                {
                    ll ind;
                    for (ll j = 0; j < count[i].second.size(); j++)
                    {
                        if (count[i].second[j] == 1)
                        {
                            ind = j;
                            break;
                        }
                    }
                    for (ll j = 0; j < 16; j++)
                    {
                        if (count[j].first.first > 0)
                            if (count[j].second[ind] == 0)
                            {
                                yes = 1;
                            }
                    }
                }
        }
        for (ll i = 0; i < 16; i++)
        {
            if (count[i].first.first > 0)
                if (count[i].first.second == 2)
                {
                    if (count[onesComplement(i)].first.first > 0)
                    {
                        yes = 1;
                    }
                }
        }
    }
    if (yes == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}