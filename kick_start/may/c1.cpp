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
#define N 10000007
#define N1 100005
#define mod 1000000007
#define INF INT64_MAX
ll t, n;
v<ll> squares;
v<ll> pref(70000007, 0);
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
bool check(ll no)
{
    ll temp = (ll)sqrt(no);
    if (temp * temp == no)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 0; i <= 10000003; i++)
    {
        ll x = (ll)sqrt(i);
        if (x * x == i)
            squares.pb(i);
    }
    for (ll test = 1; test <= t; test++)
    {
        cin >> n;
        v<ll> a(n + 1);
        ll maxi = -INF;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxi = max(maxi, abs(a[i]));
        }
        ll off = 3 * n * maxi;
        pref[off] = 1;
        ll count = 0, sum = 0;
        for (ll i = 1; i <= n; i++)
        {
            sum += a[i];
            for (ll j = 0; j < squares.size(); j++)
            {
                if (squares[j] <= maxi * n)
                    count += pref[sum - squares[j] + off];
                else
                    break;
                // cout << count << " " << sum << " " << squares[j] << "\n";
            }
            pref[sum + off]++;
        }
        fill(pref.begin(), pref.begin() + 7 * n * maxi, 0);
        cout << "Case #" << test << ": " << count << "\n";
    }
}