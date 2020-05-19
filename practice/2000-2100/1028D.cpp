#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 300005
#define mod 1000000007
ll n;
set<ll> nos;
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    ll ans = 1;
    ll buyt = 0;
    ll selt = INT64_MAX;
    for (ll i = 1; i <= n; i++)
    {
        string s;
        ll val;
        cin >> s >> val;
        if (s == "ADD")
            nos.insert(val);
        else
        {
            nos.erase(val);
            if (buyt < val && selt > val)
                ans = (ans * 2) % mod;
            else if (buyt == val || selt == val)
                ans = (ans * 1) % mod;
            else
                ans = 0;
            auto it = nos.upper_bound(val);
            auto it1 = nos.lower_bound(val);
            if (it != nos.end())
                selt = *it;
            else
                selt = INT64_MAX;
            if (it1 != nos.begin())
            {
                it1--;
                buyt = *it1;
            }
            else
            {
                buyt = 0;
            }
        }
    }
    ll m = 0;
    for (auto it = nos.begin(); it != nos.end(); it++)
    {
        ll temp = *it;
        if (temp > buyt && temp < selt)
            m++;
    }
    ans = (ans * (m + 1)) % mod;
    cout << ans << "\n";
}