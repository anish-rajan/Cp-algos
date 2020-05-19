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
string a, c;
ll b, d, p;
vector<ll> ind(102);
bool possible(string a, string c)
{
    ll f = 0;
    for (ll i = 0; i < c.size(); i++)
    {
        f = 0;
        for (ll j = 0; j < a.size(); j++)
        {
            if (c[i] == a[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> b >> d;
    cin >> a >> c;
    bool pos = possible(a, c);
    if (pos)
    {
        for (ll i = 0; i < c.size(); i++)
        {
            for (ll j = 0; j < a.size(); j++)
            {
                if (a[j] == c[(i + ind[i]) % (c.size())])
                    ind[i]++;
            }
        }
        ll ans = 0;
        for (ll i = 0; i < b; i++)
        {
            ans += ind[ans % c.size()];
        }
        // cout << ans << " ";
        ans /= c.size();
        ans /= d;
        cout << ans << "\n";
    }
    else
        cout << 0 << "\n";
}