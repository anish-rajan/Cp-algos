#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
#define mod 1000000007
string s, t;
vector<ll> occur;
vector<ll> dp(N), cum(N);
vector<long long int> prefix_function(string s)
{
    long long int n = (long long int)s.length();
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

void KMPSearch(string pat, string txt)
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
            occur.push_back(i - 1);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    KMPSearch(t, s);
    ll p = 0;
    ll sz = occur.size();
    for (ll i = 1; i <= n; i++)
    {
        if (i != 1)
            dp[i] = (2 * dp[i - 1] - dp[i - 2] + mod) % mod;
        else
            dp[i] = (2 * dp[i - 1]) % mod;
        if (p < sz)
        {
            if (occur[p] == i - 1)
            {
                if (i != 1)
                    dp[i] = (dp[i] + cum[i - m] + i - m + 1 - dp[i - 1] + dp[i - 2] + mod) % mod;
                else
                    dp[i] = (dp[i] + cum[i - m] + i - m + 1 - dp[i - 1] + mod) % mod;
                p++;
            }
        }
        cum[i] = (cum[i - 1] + dp[i]) % mod;
        // cout << i << " " << cum[i] << " " << dp[i] << "\n";
    }
    cout << dp[n] << "\n";
}