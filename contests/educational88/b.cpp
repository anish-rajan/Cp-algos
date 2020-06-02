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
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        v<string> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 0; j < m;)
            {
                // cout << a[i][j] << " ";
                if (a[i][j] == '.')
                {
                    if (j < m - 1)
                    {
                        if (a[i][j + 1] == '.')
                        {
                            ans += min(2 * x, y);
                            j += 2;
                        }
                        else
                            ans += x, j++;
                    }
                    else
                        ans += x, j++;
                }
                else
                    j++;
            }
        }
        cout << ans << "\n";
    }
}