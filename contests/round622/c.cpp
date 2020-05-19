#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void func(ll n, ll x, ll y, ll &mi, ll &ma)
{
    if (n - x - 1 >= y - 1)
    {
        mi = 1;
    }
    else
    {
        mi = min(y - n + x + 1, n);
    }
    ma = min(x + y - 1, n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y, mi, ma;
        cin >> n >> x >> y;
        if (x > y)
        {
            func(n, x, y, mi, ma);
        }
        else
        {
            func(n, y, x, mi, ma);
        }
        cout << mi << " " << ma << "\n";
    }
}