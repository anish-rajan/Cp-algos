#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> arr(N);
ll solve(vector<ll> c, ll bit)
{
    if (bit < 0)
        return 0;
    vector<ll> on, off;
    for (ll i = 0; i < c.size(); i++)
    {
        if ((c[i] >> bit) & 1)
            on.push_back(c[i]);
        else
            off.push_back(c[i]);
    }
    if (on.size() == 0)
        return solve(off, bit - 1);
    else if (off.size() == 0)
        return solve(on, bit - 1);
    else
        return min(solve(on, bit - 1), solve(off, bit - 1)) + (1 << bit);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        ll temp = arr[i];
    }
    arr.resize(n);
    cout << solve(arr, 31) << "\n";
}