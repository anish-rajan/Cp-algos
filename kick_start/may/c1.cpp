#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define mod 1000000007
#define INF INT64_MAX
ll t, n;
v<ll> a(N);
v<ll> is_square(N);
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
            is_square[i] = 1;
    }
    for (ll test = 1; test <= t; test++)
    {
        cin >> n;
        ll count = 0;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n; i++)
        {
            ll sum = 0;
            for (ll j = i; j <= n; j++)
            {
                sum += a[j];
                if (sum < 0)
                    continue;
                if (is_square[sum])
                    count++;
            }
        }
        cout << "Case #" << test << ": " << count << "\n";
    }
}