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
ll n, z, ind;
v<ll> arr(N);
v<pair<ll, ll>> neg, zers, others;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            zers.pb(mp(arr[i], i));
            continue;
        }
        else if (arr[i] < 0)
            neg.pb(mp(arr[i], i));
        others.pb(mp(arr[i], i));
    }
    ll ind, c = 0;
    if (zers.size() > 0)
        ind = zers[0].se;
    for (ll i = 1; i < zers.size(); i++)
    {
        cout << 1 << " " << zers[i].se + 1 << " " << ind + 1 << endl;
        c++;
    }
    ll n1 = neg.size();
    if (n1 % 2 == 0 && c < n - 1)
    {
        if (zers.size() > 0)
            cout << 2 << " " << ind + 1 << endl;
        ll ind1 = others[0].se;
        for (ll i = 1; i < others.size(); i++)
        {
            cout << 1 << " " << others[i].se + 1 << " " << ind1 + 1 << endl;
        }
    }
    else if (c < n - 1)
    {
        sort(neg.begin(), neg.end(), greater<pair<ll, ll>>());
        if (zers.size() > 0 && c < n - 1)
        {
            cout << 1 << " " << ind + 1 << " " << neg[0].se + 1 << endl;
            c++;
        }
        if (c < n - 1)
        {
            cout << 2 << " " << neg[0].se + 1 << endl;
            c++;
            ll ind1 = others[0].se;
            for (ll i = 0; i < others.size(); i++)
            {
                if (others[i].se != neg[0].se)
                {
                    ind1 = others[i].se;
                    break;
                }
            }
            for (ll i = 0; i < others.size(); i++)
            {
                if (others[i].se == ind1 || others[i].se == neg[0].se)
                    continue;
                cout << 1 << " " << others[i].se + 1 << " " << ind1 + 1 << endl;
            }
        }
    }
    return 0;
}