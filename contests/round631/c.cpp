#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 100005
v<pair<ll, ll>> arr(N);
ll n, m;
v<pair<ll, ll>> ans(N);
v<ll> cum(N);
bool sortbysec(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.second < b.second);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    cum[m] = arr[m].fi;
    for (ll i = m - 1; i >= 1; i--)
    {
        cum[i] = cum[i + 1] + arr[i].fi;
    }
    cum.push_back(0);
    // cout << cum[1] << " " << arr[m].fi + m - 1 << endl;
    if (cum[1] < n)
    {
        cout << -1 << "\n";
        return 0;
    }
    ll i1 = m + 1;
    ll a1 = 0;
    ll f = 1;
    for (ll i = 1; i <= m; i++)
    {
        if (arr[i].fi > n - i + 1)
        {
            f = 0;
            break;
        }
        if (cum[i + 1] < n - i - arr[i].fi + 1)
        {
            ll temp = n - i - cum[i + 1] - arr[i].fi + 1;
            ans[i].fi = i + temp;
            ans[i].se = arr[i].se;
            i1 = i + 1;
            a1 = ans[i].fi + arr[i].fi;
            break;
        }
        else if (cum[i + 1] == n - i - arr[i].fi + 1)
        {
            ans[i].fi = i;
            ans[i].se = arr[i].se;
            i1 = i + 1;
            a1 = i + arr[i].fi;
            // cout << i << " " << a1 << "\n";
            break;
        }
        else
        {
            ans[i].fi = i;
            ans[i].se = arr[i].se;
        }
    }
    for (ll i = i1; i <= m; i++)
    {
        ans[i].fi = a1;
        ans[i].se = arr[i].se;
        a1 += arr[i].fi;
    }
    if (f == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    ans[m].fi = n - arr[m].fi + 1;
    ans[m].se = arr[m].se;
    sort(ans.begin() + 1, ans.begin() + m + 1, sortbysec);
    for (ll i = 1; i <= m; i++)
    {
        cout << ans[i].fi << " ";
    }
    cout << endl;
}