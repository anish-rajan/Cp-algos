#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 998244353
using S = long long int;
ll t;
ll r, b, g;
v<ll> ar, ab, ag;
S ans;
S calc(S x, S y, S z)
{
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ans = INT64_MAX;
        cin >> r >> b >> g;
        for (ll i = 1; i <= r; i++)
        {
            ll val;
            cin >> val;
            ar.pb(val);
        }
        for (ll i = 1; i <= b; i++)
        {
            ll val;
            cin >> val;
            ab.pb(val);
        }
        for (ll i = 1; i <= g; i++)
        {
            ll val;
            cin >> val;
            ag.pb(val);
        }
        sort(ar.begin(), ar.end());
        sort(ab.begin(), ab.end());
        sort(ag.begin(), ag.end());
        for (auto x : ar)
        {
            ll itr = lower_bound(ab.begin(), ab.end(), x) - ab.begin();
            if (itr == b)
                itr--;
            if (itr != 0)
            {
                if (abs(x - ab[itr]) > abs(x - ab[itr - 1]))
                    itr--;
            }
            ll y = ab[itr];
            ll temp = (x + y) / 2;
            ll itr1 = lower_bound(ag.begin(), ag.end(), temp) - ag.begin();
            if (itr1 == g)
                itr1--;
            if (itr1 != 0)
            {
                if (abs(temp - ag[itr1]) > abs(temp - ag[itr1 - 1]))
                    itr1--;
            }
            ll z = ag[itr1];
            ans = min(ans, calc(x, y, z));
        }
        for (auto x : ab)
        {
            ll itr = lower_bound(ag.begin(), ag.end(), x) - ag.begin();
            if (itr == g)
                itr--;
            if (itr != 0)
            {
                if (abs(x - ag[itr]) > abs(x - ag[itr - 1]))
                    itr--;
            }
            ll y = ag[itr];
            ll temp = (x + y) / 2;
            ll itr1 = lower_bound(ar.begin(), ar.end(), temp) - ar.begin();
            if (itr1 == r)
                itr1--;
            if (itr1 != 0)
            {
                if (abs(temp - ar[itr1]) > abs(temp - ar[itr1 - 1]))
                    itr1--;
            }
            ll z = ar[itr1];
            ans = min(ans, calc(x, y, z));
        }
        for (auto x : ag)
        {
            ll itr = lower_bound(ar.begin(), ar.end(), x) - ar.begin();
            if (itr == r)
                itr--;
            if (itr != 0)
            {
                if (abs(x - ar[itr]) > abs(x - ar[itr - 1]))
                    itr--;
            }
            ll y = ar[itr];
            ll temp = (x + y) / 2;
            ll itr1 = lower_bound(ab.begin(), ab.end(), temp) - ab.begin();
            if (itr1 == b)
                itr1--;
            if (itr1 != 0)
            {
                if (abs(temp - ab[itr1]) > abs(temp - ab[itr1 - 1]))
                    itr1--;
            }
            ll z = ab[itr1];
            ans = min(ans, calc(x, y, z));
        }
        cout << ans << "\n";
        ar.clear(), ab.clear(), ag.clear();
    }
}