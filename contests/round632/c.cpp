#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
v<ll> arr(N), cum(N);
set<pair<ll, ll>> cums;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cum[i] = cum[i - 1] + arr[i];
    }
    ll ans = 0;
    ll ind = -1;
    cums.insert(mp(0, 0));
    for (ll i = 1; i <= n; i++)
    {
        // cout << ans << " " << ind << endl;

        if (arr[i] == 0)
        {
            ind = i;
            auto itr = cums.lower_bound(mp(arr[i], 0));
            if (itr == cums.end())
                continue;
            if ((*itr).fi != cum[i])
                continue;
            cums.erase(itr);
            cums.insert(mp(cum[i], i));
            continue;
        }
        auto itr = cums.lower_bound(mp(cum[i], 0));
        if (itr == cums.end())
        {
            // ans += i;
            ans += min(i, i - ind);
            cums.insert(mp(cum[i], i));
            continue;
        }
        // cout << cum[i] << " " << (*itr).fi << endl;

        auto temp = *itr;
        if (temp.fi != cum[i])
        {
            ans += min(i, i - ind);
            cums.insert(mp(cum[i], i));
            continue;
        }
        ans += min(i - temp.se - 1, i - ind);
        ind = max(ind, temp.se + 1);
        cums.erase(itr);
        temp.se = i;
        cums.insert(mp(cum[i], i));
    }
    cout << ans << endl;
}