#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 4000006
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll t, h, g, t1, t2, counter;
v<ll> a(N);
v<ll> ans;
ll f(ll ind)
{
    ll l = 2 * ind, r = 2 * ind + 1;
    if (a[l] == 0 && a[r] == 0)
    {
        if (ind > t2)
        {
            a[ind] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    ll stat;
    if (a[l] > a[r])
    {
        ll temp = a[l];
        stat = f(l);
        if (stat == 1)
            a[ind] = temp;
    }
    else
    {
        ll temp = a[r];
        stat = f(r);
        if (stat == 1)
            a[ind] = temp;
    }
    return stat;
}

void dfs(ll ind)
{
    if (a[ind] == 0)
        return;
    while (counter < t1 - t2)
    {
        ll stat = f(ind);
        if (stat == 0)
        {
            dfs(2 * ind);
            dfs(2 * ind + 1);
            return;
        }
        else
        {
            ans.pb(ind);
            counter++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ans.clear();
        counter = 0;
        cin >> h >> g;
        t1 = (ll)pow(2, h) - 1;
        t2 = (ll)pow(2, g) - 1;
        // cout << t1 << " " << t2 << endl;
        for (ll i = 1; i <= t1; i++)
        {
            cin >> a[i];
        }
        ll sum = 0;
        ll ind = 1;
        dfs(1);
        for (ll i = 1; i <= t2; i++)
        {
            sum += a[i];
        }
        cout << sum << endl;
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        fill(a.begin(), a.begin() + t1 + 1, 0);
    }
}