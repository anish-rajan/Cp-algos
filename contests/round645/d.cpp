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
#define N 400005
#define mod 1000000007
#define INF INT_MAX

ll n, x;
v<ll> a(N);

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

ll factdiv(ll fact1, ll fact2, ll fact3)
{
    ll ans = 1, j = 1;
    for (ll i = fact2 + 1; i <= fact1; i++)
    {
        ans *= i;
        if (j <= fact3)
            ans /= j;
        j++;
    }
    return ans;
}

ll firstn(ll p)
{
    return ((p) * (p + 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        a[n + i] = a[i];
    }
    ll i = 1, j = 1, sum = 0, sum1 = 0, ans = 0;
    while (j <= 2 * n)
    {
        if (sum1 + a[j] < x)
        {
            sum1 += a[j];
            sum += firstn(a[j]);
            j++;
        }
        else if (sum1 + a[j] > x)
        {
            ans = max(ans, sum + firstn(x - sum1));
            // cout << ans << " " << sum1 << " " << sum << "\n";
            sum1 += a[j];
            sum += firstn(a[j]);
            // cout << ans << " " << sum1 << " " << sum << "\n";
            while (sum1 - a[i] > x)
                sum1 -= a[i], sum -= firstn(a[i]), i++;
            // cout << ans << " " << sum1 << " " << sum << "\n";
            ans = max(ans, sum - firstn(sum1 - x));
            sum1 -= a[i];
            sum -= firstn(a[i]);
            i++, j++;
        }
        else
        {
            sum += firstn(a[j]);
            sum1 += a[j];
            ans = max(ans, sum);
            sum1 -= a[i];
            sum -= firstn(a[i]);
            i++, j++;
        }
    }
    cout << ans << "\n";
}