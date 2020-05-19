#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll func(ll p)
{
    ll digits = 0;
    ll temp1 = p % 10, temp2;
    ll temp3 = p;
    while (temp3 > 0)
    {
        temp2 = temp3 % 10;
        temp3 /= 10;
        digits++;
    }
    ll nos = temp2 * (ll)pow(10, digits - 1);
    ll p1 = p - nos;
    p1 /= 10;
    ll ans = 0;
    for (ll i = 1; i < digits; i++)
    {
        if (i == 1)
        {
            ans += 9;
        }
        else
            ans += 9 * (ll)pow(10, i - 2);
        // cout << ans << " " << 9 * (ll)pow(10, i - 2) << "\n";
    }
    if (digits == 1)
    {
        ans += p;
    }
    else
    {
        // cout << ans << "\n";
        ans += (temp2 - 1) * (ll)(pow(10, digits - 2));
        // cout << ans << "\n";
        if (temp2 <= temp1)
        {
            ans += p1 + 1;
        }
        else
        {
            ans += p1;
        }
        // cout << ans << "\n";
    }
    // cout << p1 << "\n";
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll l, r;
    cin >> l >> r;
    ll ans1 = 0, ans2 = 0;
    if (l != 1)
        ans1 = func(l - 1);
    ans2 = func(r);
    // cout << ans1 << " " << ans2 << "\n";
    cout << ans2 - ans1 << "\n";
}