#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define N 1000006
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll n, k;
v<ll> arr;
vector<ll> primes;
vector<ll> prime_check(N);
vector<ll> max_pows(N), gpd(N), max_pow1(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    ll maxval = k;
    for (ll i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        arr.pb(val);
        maxval = max(maxval, val);
    }
    for (ll i = 2; i <= maxval; i++)
    {
        if (!prime_check[i])
            for (ll j = 2 * i; j <= maxval; j += i)
            {
                prime_check[j] = 1;
                gpd[j] = i;
            }
    }
    for (ll i = 2; i <= maxval; i++)
    {
        if (!prime_check[i])
        {
            primes.push_back(i);
            gpd[i] = i;
        }
    }
    ll temp = k;
    while (temp > 1)
    {
        ll gp = gpd[temp];
        // cout << gp << endl;
        ll c = 0;
        while (gp == gpd[temp])
        {
            c++;
            temp /= gp;
            max_pow1[gp] = max(max_pow1[gp], c);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        ll temp = arr[i];
        while (temp > 1)
        {
            ll gp = gpd[temp];
            ll c = 0;
            while (gp == gpd[temp])
            {
                c++;
                temp /= gp;
                max_pows[gp] = max(max_pows[gp], c);
            }
        }
    }
    ll f = 1;
    for (ll i = 2; i <= maxval; i++)
    {
        if (max_pow1[i] > max_pows[i])
        {
            f = 0;
            break;
        }
    }
    if (f == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}