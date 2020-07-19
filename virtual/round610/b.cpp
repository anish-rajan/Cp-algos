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
#define N 300005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e6 + 2);
v<ll> primes;

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

void Sieve()
{
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e6 + 2; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    while (t--)
    {
        ll n, p, k;
        cin >> n >> p >> k;
        v<ll> a(n + 1), a1(n + 1);
        v<v<ll>> a2(n + 1);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.begin() + n);
        for (ll i = 0; i < n; i++)
        {
            a1[i + 1] = a1[i] + a[i];
            if (i + k - 1 < n)
                if (a2[i % k].size() == 0)
                    a2[i % k].pb(a[i + k - 1]);
                else
                    a2[i % k].pb(a[i + k - 1] + a2[i % k].back());
        }
        ll ans = 0;
        // for (ll i = 0; i < k; i++)
        // {
        //     for (ll j = 0; j < a2[i].size(); j++)
        //         cout << a2[i][j] << " ";
        //     cout << "\n";
        // }
        for (ll i = 1; i <= n; i++)
        {
            ll p1 = (i - 1) % k, p2 = (i - 1) / k;
            ll s = p2 > 0 ? p + a2[p1][p2 - 1] : p;
            ll s1;
            auto l = upper_bound(a2[p1].begin() + p2, a2[p1].end(), s) - a2[p1].begin() - p2;
            l--;
            // if (l == -1)
            //     cout << l << " " << a2[p1][l + 1] << " ";
            if (l >= 0)
                ans = max(ans, (l + 1) * k), s1 = s - a2[p1][l + p2];
            else
                s1 = p;
            ll l1;
            if (i > 1)
            {
                l1 = upper_bound(a1.begin() + 1, a1.begin() + i, s1) - a1.begin();
                l1--;
                if (l1 >= 1)
                    ans = max(ans, (l + 1) * k + l1);
                // cout << i << " " << ans << " " << s1 << " " << a1[l1 + 1] << "\n";
            }
            // cout << i << " " << l << " " << l1 << " " << a2[p1][l] << " " << ans << "\n";
        }
        cout << ans << "\n";
    }
}