#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 5002
ll n, m;
v<ll> a(N), f(N), cumg(N);
set<ll> b;
vector<ll> primes;
vector<ll> prime_check(100002);
ll comp(ll val)
{
    ll c = 0;
    for (ll j = 0; primes[j] <= sqrt(val); j++)
    {
        ll temp = 0, temp1 = val;
        while (val % primes[j] == 0)
        {
            temp++;
            val /= primes[j];
        }
        if (temp1 % primes[j] == 0)
        {
            auto itr = b.find(primes[j]);
            if (itr != b.end())
                c -= temp;
            else
                c += temp;
        }
    }
    if (val != 1)
    {
        auto itr = b.find(val);
        if (itr != b.end())
            c--;
        else
            c++;
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (ll i = 2; i <= 100000; i++)
    {
        if (!prime_check[i])
            for (ll j = 2 * i; j <= 100000; j += i)
            {
                prime_check[j] = 1;
            }
    }
    for (ll i = 2; i <= 100000; i++)
    {
        if (!prime_check[i])
            primes.push_back(i);
    }
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll j = 0; j < m; j++)
    {
        ll v1;
        cin >> v1;
        b.insert(v1);
    }
    cumg[0] = a[0];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        f[i] = comp(a[i]);
        // cout << f[i] << " ";
        if (i >= 1)
            cumg[i] = __gcd(cumg[i - 1], a[i]);
        ans += f[i];
    }
    // cout << "\n";
    ll div = 1;
    ll sub = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        cumg[i] /= div;
        ans -= sub;
        ll temp = comp(cumg[i]);
        if (temp < 0)
        {
            ans -= temp;
            sub += temp;
            div *= cumg[i];
        }
        // cout << ans << " ";
    }
    cout << ans << "\n";
}