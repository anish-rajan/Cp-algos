#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n;
vector<pair<ld, ld>> kb(N);
v<pair<ld, ll>> cods;
vector<ll> check(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> kb[i].fi >> kb[i].se;
        if (kb[i].fi == 0)
        {
            cods.pb(mp(INT_MIN, i));
            cods.pb(mp(INT_MAX, i));
        }
        else if (kb[i].fi < 0)
        {
            cods.pb(mp(-1 * kb[i].se / kb[i].fi, i));
            cods.pb(mp(INT_MIN, i));
        }
        else
        {
            cods.pb(mp(-1 * kb[i].se / kb[i].fi, i));
            cods.pb(mp(INT_MAX, i));
        }
    }
    sort(cods.begin(), cods.end());
    ld k1 = 0, b1 = 0, k2 = 0, b2 = 0;
    ll counter = 0;
    for (ll i = 0; i < 2 * n;)
    {
        ll j = i;
        // cout << cods[i].fi << " ";
        while (j < 2 * n)
        {
            if (cods[j].fi == cods[i].fi)
            {
                if (check[cods[j].se] == 0)
                {
                    k2 += kb[cods[j].se].fi, b2 += kb[cods[j].se].se;
                    check[cods[j].se] = 1;
                }
                else
                {
                    k2 -= kb[cods[j].se].fi, b2 -= kb[cods[j].se].se;
                }
                j++;
            }
            else
            {
                if (cods[i].fi != (ld)INT_MIN)
                {
                    if (k1 != k2)
                        counter++;
                }
                break;
            }
        }
        if (j == 2 * n)
        {
            if (cods[i].fi != (ld)INT_MAX)
                counter++;
        }
        k1 = k2, b1 = b2;
        i = j;
    }
    cout << counter << "\n";
}