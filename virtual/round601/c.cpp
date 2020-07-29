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
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(1e6 + 2);
// v<ll> primes;

// long long powmod(long long x, long long y, long long m)
// {
//     long long res = 1LL;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % m;
//         x = (x * x) % m;
//         y /= 2;
//     }
//     return res;
// }

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
//     for (ll i = 2; i <= 1e6 + 1; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j <= 1e6 + 2; j += i)
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

ll n;
v<ll> a(N), b(N), c(N);
set<pair<pair<ll, ll>, ll>> t;
map<pair<ll, ll>, ll> cnt;
map<ll, ll> cnt1;
v<ll> ans, ans1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    for (ll i = 1; i <= n - 2; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        cnt1[a[i]]++, cnt1[b[i]]++, cnt1[c[i]]++;
        v<ll> nos = {a[i], b[i], c[i]};
        sort(nos.begin(), nos.end());
        for (ll i = 1; i <= 6; i++)
            t.insert(mp(mp(nos[0], nos[1]), nos[2])), cnt[{nos[0], nos[1]}]++, cnt[{nos[1], nos[2]}]++, next_permutation(ALL(nos));
    }
    pair<pair<ll, ll>, ll> beg, beg1;
    for (ll i = 1; i <= n; i++)
    {
        v<ll> nos = {a[i], b[i], c[i]};
        ll f = 0;
        sort(nos.begin(), nos.end());
        for (ll i = 1; i <= 6; i++)
        {
            auto temp = mp(nos[0], nos[1]), temp1 = mp(nos[1], nos[2]), temp2 = mp(nos[2], nos[0]);
            ll l1 = cnt[temp] + cnt[{temp.se, temp.fi}];
            ll l2 = cnt[temp1] + cnt[{temp1.se, temp1.fi}];
            ll l3 = cnt[temp2] + cnt[{temp2.se, temp2.fi}];
            if (l1 == 4 && l2 == 8 && l3 == 4 && cnt1[nos[0]] == 1)
            {
                beg = {temp, nos[2]};
                beg1 = {{temp.fi, nos[2]}, temp.se};
                f = 1;
                break;
            }
            next_permutation(ALL(nos));
        }
        if (f == 1)
            break;
    }
    ll len = 3;
    ans.pb(beg.fi.fi), ans.pb(beg.fi.se), ans.pb(beg.se);
    while (len < n)
    {
        auto itr = t.lower_bound({{beg.fi.se, beg.se}, -INF});
        while (itr->se == beg.fi.fi)
            itr++;
        ans.pb(itr->se);
        beg = mp(mp(beg.fi.se, beg.se), itr->se);
        len++;
    }
    ll len1 = 3;
    ans1.pb(beg1.fi.fi), ans1.pb(beg1.fi.se), ans1.pb(beg1.se);
    while (len1 < n)
    {
        auto itr = t.lower_bound({{beg1.fi.se, beg1.se}, -INF});
        while (itr->se == beg1.fi.fi)
            itr++;
        ans1.pb(itr->se);
        beg1 = mp(mp(beg1.fi.se, beg1.se), itr->se);
        len1++;
    }
    ll f = 1;
    for (ll i = 0; i < ans.size() - 2; i++)
    {
        if (t.find({{ans[i], ans[i + 1]}, ans[i + 2]}) == t.end())
            f = 0;
    }
    if (f == 0)
        for (ll i = 0; i < ans1.size(); i++)
            cout << ans1[i] << " ";
    else
        for (ll i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    cout << "\n";
}