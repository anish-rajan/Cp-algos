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
#define N 200005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
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
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
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

ll n, k;
v<ll> a(N);

ll pos(ll x)
{
    v<ll> arr1, arr2;
    ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (arr1.size() % 2)
            arr1.pb(a[i]), ans3 = max(ans3, a[i]);
        else if (a[i] <= x)
            arr1.pb(a[i]), ans1 = max(ans1, a[i]);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (arr2.size() % 2 == 0)
            arr2.pb(a[i]), ans4 = max(ans4, a[i]);
        else if (a[i] <= x)
            arr2.pb(a[i]), ans2 = max(ans2, a[i]);
    }
    ans1 = min(ans1, ans3);
    ans2 = min(ans2, ans4);
    if (arr1.size() >= k && arr2.size() >= k)
        return min(ans1, ans2);
    else if (arr1.size() >= k)
        return ans1;
    else if (arr2.size() >= k)
        return ans2;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    ll l = 1, r = 1e9;
    ll ans = INF;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll temp = pos(mid);
        // cout << temp << " ";
        if (temp)
        {
            r = mid - 1;
            ans = min(ans, temp);
        }
        else
            l = mid + 1;
    }
    cout << ans << "\n";
}