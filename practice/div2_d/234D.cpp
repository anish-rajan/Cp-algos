#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 104
ll m, k, n;
vector<ll> favs(N), check1(N), minfavs(N), maxfavs(N);
vector<vector<ll>> cast(N);
vector<pair<ll, ll>> minfav, maxfav;
ll calc_maxfav(ll ind)
{
    vector<ll> check(m + 1);
    check = {0};
    ll counter1 = 0;
    for (ll i = 0; i < cast[ind].size(); i++)
    {
        check[cast[ind][i]]++;
        if (check1[cast[ind][i]])
            counter1++;
    }
    ll counter = 0;
    for (ll i = 0; i < favs.size() && counter < check[0]; i++)
    {
        if (!check[favs[i]])
        {
            counter++;
        }
    }
    return counter + counter1;
}
ll calc_minfav(ll ind)
{
    vector<ll> check(m + 1);
    check = {0};
    ll counter1 = 0;
    for (ll i = 0; i < cast[ind].size(); i++)
    {
        check[cast[ind][i]]++;
        if (check1[cast[ind][i]])
            counter1++;
    }
    ll counter = 0;
    for (ll i = 1; i <= m; i++)
    {
        if (!check[i] && !check1[i])
        {
            counter++;
        }
    }
    return max((ll)0, check[0] - counter) + counter1;
}
ll calc_val(ll ind)
{
    ll t = minfavs[ind], t1 = maxfav[n - 1].first, i1 = maxfav[n - 1].second;
    ll p = maxfavs[ind], p1 = minfav[n - 1].first, i2 = minfav[n - 1].second;
    if (t >= t1)
    {
        return 0;
    }
    else if (ind == i1)
    {
        if (n >= 2)
        {
            if (t >= maxfav[n - 2].first)
                return 0;
            else if (p >= p1)
            {
                return 2;
            }
            else if (ind == i2)
            {
                if (p >= minfav[n - 2].first)
                    return 2;
                else
                    return 1;
            }
            else
            {
                return 1;
            }
        }
        else
            return 0;
    }
    else if (p >= p1)
    {
        return 2;
    }
    else if (ind == i2)
    {
        if (n >= 2)
            if (p >= minfav[n - 2].first)
                return 2;
            else
                return 1;
        else
            return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> m >> k;
    for (ll i = 0; i < k; i++)
    {
        cin >> favs[i];
        check1[favs[i]]++;
    }
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        string movie;
        ll d;
        cin >> movie >> d;
        for (ll j = 0; j < d; j++)
        {
            ll actor;
            cin >> actor;
            cast[i].push_back(actor);
        }
        minfavs[i] = calc_minfav(i);
        maxfavs[i] = calc_maxfav(i);
        minfav.push_back(make_pair(minfavs[i], i));
        maxfav.push_back(make_pair(maxfavs[i], i));
    }
    sort(minfav.begin(), minfav.end());
    sort(maxfav.begin(), maxfav.end());
    // for (ll i = 0; i < k; i++)
    // {
    //     cout << favs[i] << " ";
    // }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << minfavs[i] << " " << maxfavs[i] << "\n";
    // }
    for (ll i = 0; i < n; i++)
    {
        ll val = calc_val(i);
        cout << val << "\n";
    }
}