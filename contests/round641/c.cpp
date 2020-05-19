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
#define N 100005
#define N1 200005
#define mod 1000000007
ll n;
v<ll> a(N);
v<pair<ll, ll>> dp(N1, mp(INT_MAX, INT_MAX));
vector<ll> primes;
vector<ll> prime_check(N1), cnt(N1);
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
    for (ll i = 2; i <= 200005; i++)
    {
        if (!prime_check[i])
            for (ll j = 2 * i; j <= 200005; j += i)
            {
                prime_check[j] = 1;
            }
    }
    for (ll i = 2; i <= 200005; i++)
    {
        if (!prime_check[i])
            primes.push_back(i);
    }
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < primes.size(); j++)
        {
            if (primes[j] > sqrt(a[i]))
                break;
            ll power = 0;
            cnt[primes[j]]++;
            while (a[i] % primes[j] == 0)
            {
                a[i] /= primes[j];
                power++;
            }
            if (dp[primes[j]].fi >= power)
            {
                dp[primes[j]].se = dp[primes[j]].fi;
                dp[primes[j]].fi = power;
            }
            else if (dp[primes[j]].se >= power)
                dp[primes[j]].se = power;
        }
        if (a[i] != 1)
        {
            cnt[a[i]]++;
            if (dp[a[i]].fi >= 1)
            {
                dp[a[i]].se = dp[a[i]].fi;
                dp[a[i]].fi = 1;
            }
            else if (dp[a[i]].se >= 1)
                dp[a[i]].se = 1;
        }
    }

    ll ans = 1;
    for (ll i = 0; i < primes.size(); i++)
    {
        // if (primes[i] <= 19)
        //     cout << primes[i] << " " << cnt[primes[i]] << " " << dp[primes[i]].fi << "\n";
        if (dp[primes[i]].se != INT_MAX && cnt[primes[i]] == n)
            ans *= (ll)pow(primes[i], dp[primes[i]].se);
        else if (dp[primes[i]].fi != INT_MAX && cnt[primes[i]] == n - 1)
        {
            ans *= (ll)pow(primes[i], dp[primes[i]].fi);
        }
        // if (dp[primes[i]].se != INT_MAX)
        //     cout << primes[i] << " " << dp[primes[i]].se << "\n";
    }
    cout << ans << "\n";
}