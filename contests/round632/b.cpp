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
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll t;
v<ll> a(N), b(N), stat(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i - 1] == -1)
            {
                // cout << a[i - 1] << " " << stat[i - 1] << " " << stat[i] << endl;
                if (stat[i - 1] == 0)
                    stat[i] = -1;
                else if (stat[i - 1] == 1)
                    stat[i] = 2;
                else
                    stat[i] = stat[i - 1];
                // cout << a[i - 1] << " " << stat[i - 1] << " " << stat[i] << endl;
            }
            else if (a[i - 1] == 1)
            {
                if (stat[i - 1] == 0)
                    stat[i] = 1;
                else if (stat[i - 1] == -1)
                    stat[i] = 2;
                else
                    stat[i] = stat[i - 1];
            }
            else
                stat[i] = stat[i - 1];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        ll f = 1;
        for (ll i = 1; i <= n; i++)
        {
            // cout << stat[i] << endl;
            if (stat[i] == 0)
            {
                if (a[i] != b[i])
                    f = 0;
            }
            if (stat[i] == 1)
            {
                if (a[i] > b[i])
                    f = 0;
            }
            if (stat[i] == -1)
            {
                if (a[i] < b[i])
                    f = 0;
            }
        }
        if (f == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}