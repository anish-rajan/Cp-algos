#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 500005
#define mod 1000000007
#define INF INT_MAX

ll t;

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, pos = 1;
        cin >> n;
        string a, b;
        cin >> a >> b;
        set<ll> ac;
        v<ll> po(256, -1);
        for (ll i = 0; i < n; i++)
            ac.insert(a[i]);
        for (ll i = 0; i < n; i++)
            if (ac.find(b[i]) == ac.end() || a[i] < b[i])
                pos = 0;
        if (pos == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (po[a[i]] == -1)
                    po[a[i]] = i;
            }
            else
                po[a[i]] = i;
        }
        ll ans = 0;
        v<v<ll>> steps;
        for (ll i = 'z'; i >= 'a'; i--)
        {
            ans++;
            ll count = 0;
            steps.pb(v<ll>());
            steps.back().pb(po[i]);
            for (ll j = 0; j < n; j++)
            {
                if (a[j] != b[j] && b[j] == i)
                {
                    steps.back().pb(j);
                    count++;
                }
            }
            if (count == 0)
                steps.pop_back(), ans--;
        }
        cout << ans << "\n";
        for (ll i = 0; i < steps.size(); i++)
        {
            cout << steps[i].size() << " ";
            for (ll j = 0; j < steps[i].size(); j++)
                cout << steps[i][j] << " ";
            cout << "\n";
        }
    }
}