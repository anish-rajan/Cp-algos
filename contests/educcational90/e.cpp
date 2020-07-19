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
#define maxN 99999999999999999
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

ll construct(ll b, ll k, ll sum, ll x)
{
    ll ans = 0, s1 = sum / k;
    ans = b;
    ll p = 1;
    while (s1 > 0)
    {

        ll no = 0;
        for (ll i = 1; i <= 9 && i <= s1; i++)
            no = max(no, i);
        ans = (ll)pow(10, p) * no + ans;
        p++;
        s1 -= no;
    }
    return ans;
}
ll construct1(ll b, ll k, ll sum, ll x)
{
    ll ans = INF;
    for (ll i = 0; 9 * i <= sum; i++)
    {
        ll t1 = sum + (i * 9 - 1) * x;
        if (t1 >= 0 && t1 % k == 0)
        {
            ll ans1 = b, p = 1, temp = (sum + (i * 9 - 1) * x) / k;
            for (ll j = 1; j <= i; j++)
                ans1 = (ll)pow(10, p++) * 9 + ans1, temp -= 9;
            ll range = 8;
            while (temp > 0 && ans1 < maxN)
            {
                ll no = 0;
                // if (b == 9 && i == 0)
                //     cout << temp << " " << x << " " << ans1 << "\n";
                for (ll i = 1; i <= range && i <= temp; i++)
                    no = max(no, i);
                range = 9;
                ans1 = (ll)pow(10, p++) * no + ans1, temp -= no;
            }
            if (temp == 0)
                ans = min(ans, ans1);
            // if (b == 0)
            //     cout << ans1 << " ";
        }
    }
    return ans;
}

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
        ll n, k;
        cin >> n >> k;
        ll ans = INF;
        k++;
        for (ll i = 0; i <= 9; i++)
        {
            ll x = 0, sum = 0, temp = n;
            for (ll j = i; j < (i + k); j++)
            {
                if (j > 9)
                    x++;
                sum += (j % 10);
            }
            temp -= sum;
            // if (temp >= 0 && temp % k == 0 && i + k - 1 <= 9)
            // {
            //     ans = min(ans, construct(i, k, temp, x));
            // }
            if (temp >= 0)
            {
                ll t1 = construct1(i, k, temp, x);
                if (t1 != INF)
                    ans = min(ans, t1);
            }
            // cout << i << " " << x << " " << sum << " " << temp << " " << i + k - 1 << " " << ans << "\n";
        }
        if (ans != INF)
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
}