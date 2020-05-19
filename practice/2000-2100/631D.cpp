#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define pii pair<ll, ll>
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353

ll n, m, ans;
v<pair<ll, char>> s(N), t(N), s1, t1;
v<ll> pi(N);
ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

vector<long long int> prefix_function(v<pair<ll, char>> s)
{
    long long int n = (long long int)s.size();
    vector<long long int> pi(n);
    for (long long int i = 1; i < n; i++)
    {
        long long int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void KMPSearch(v<pair<ll, char>> pat, v<pair<ll, char>> txt)
{
    long long int m = pat.size();
    long long int n = txt.size();

    vector<long long int> pi;
    pi = prefix_function(pat);

    long long int i = 0; // index for txt[]
    long long int j = 0; // index for pat[]
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            if (i - m - 1 >= 0 && i < n)
            {
                if (t1[0].se == txt[i - m - 1].se && t1[0].fi <= txt[i - m - 1].fi && t1[m + 1].se == txt[i].se && t1[m + 1].fi <= txt[i].fi)
                {
                    ans++;
                }
            }
            j = pi[j - 1];
        }

        // mismatch after j matches
        else if (i < n && pat[j] != txt[i])
        {
            // Do not match pi[0..pi[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = pi[j - 1];
            else
                i = i + 1;
        }
    }
}

void concat(v<pair<ll, char>> a, ll n, v<pair<ll, char>> &a1)
{
    for (ll i = 0; i < n; i++)
    {
        ll j = i;
        ll sum = 0;
        while (j < n)
        {
            if (a[j].se != a[i].se)
                break;
            sum += a[j].fi;
            j++;
        }
        a1.pb(mp(sum, a[i].se));
        if (i == n - 1)
            break;
        i = j - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    char c;
    for (ll i = 0; i < n; i++)
        cin >> s[i].fi >> c >> s[i].se;
    for (ll i = 0; i < m; i++)
        cin >> t[i].fi >> c >> t[i].se;
    concat(s, n, s1);
    concat(t, m, t1);
    // cout << s1.size() << " ";
    if (t1.size() >= 3)
    {
        v<pair<ll, char>> t2(t1.begin() + 1, t1.end() - 1);
        KMPSearch(t2, s1);
    }
    else if (t1.size() == 2)
    {
        for (ll i = 0; i < s1.size() - 1; i++)
        {
            if (t1[0].se == s1[i].se && t1[0].fi <= s1[i].fi && t1[1].se == s1[i + 1].se && t1[1].fi <= s1[i + 1].fi)
            {
                ans++;
            }
        }
    }
    else
    {
        for (ll i = 0; i < s1.size(); i++)
        {
            if (t1[0].se == s1[i].se && t1[0].fi <= s1[i].fi)
            {
                ans += s1[i].fi - t1[0].fi + 1;
            }
        }
    }
    cout << ans << "\n";
}