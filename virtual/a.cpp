#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(ll n, ll x, ll a, ll b)
{
    if (x >= (a - 1 + n - b))
    {
        return n - 1;
    }
    else
    {
        return b - a + x;
    }
}
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, x, a, b;
        cin >> n >> x >> a >> b;
        ll ans;
        if (a < b)
            ans = solve(n, x, a, b);
        else
            ans = solve(n, x, b, a);
        cout << ans << "\n";
    }
}