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
#define N 1000006
#define mod 1000000007
#define INF 1e15

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(N);
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

// void init_fact()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
// }

// ll C(ll n, ll r)
// {
//     if (n < r)
//         return 0;
//     ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
//     temp *= powmod(fact[n - r], mod - 2, mod);
//     temp %= mod;
//     return temp;
// }

// void Sieve()
// {
//     for (ll i = 2; i < 1e8; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j < 1e8; j += i)
//             prime_check[j] = i;
//     }
// }
// ll phi(ll n)
// {
//     ll i, res = n;
//     for (i = 2; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n /= i;
//             res -= res / i;
//         }
//     if (n > 1)
//         res -= res / n;
//     return res;
// }

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll t;
string s;

string cmp(ll k)
{
    k = s.size() - k;
    set<char> c, c1;
    for (auto x : s)
        c.insert(x);
    for (ll i = 'a'; i <= 'z'; i++)
        if (c.find(i) == c.end())
            c1.insert(i);
    string ans;
    ll i;
    ll pos = 1;
    for (i = 0; i < k; i++)
    {
        if (c1.empty())
        {
            pos = 0;
            break;
        }
        auto itr = c1.begin();
        ans += *itr;
        c1.erase(itr);
    }
    if (pos == 0)
        return "-1";
    ans += s.substr(k, s.size() - k);
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
        cin >> s;
        ll k;
        cin >> k;
        sort(s.begin(), s.end());
        string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        string ans1 = ans;
        for (ll i = 0; i <= k; i++)
        {
            string temp = cmp(i);
            reverse(s.begin(), s.end());
            string temp1 = cmp(i);
            if (temp != "-1")
            {
                sort(temp.begin(), temp.end());
                ans = min(ans, temp);
            }
            if (temp1 != "-1")
            {
                sort(temp1.begin(), temp1.end());
                ans = min(ans, temp1);
            }
        }
        if (ans1 == ans)
        {
            cout << "NOPE\n";
        }
        else
            cout << ans << "\n";
    }
}