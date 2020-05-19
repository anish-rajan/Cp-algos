#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
ll t;
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
ll minpalindrome(string s)
{
    ll n = s.size();
    ll i = 0;
    while (i < n - i - 1)
    {
        // cout << s[i] << " " << s[n - i - 1] << "\n";
        if (s[i] == s[n - i - 1])
            i++;
        else
            break;
    }
    return i;
}
ll maxpalindrome(string s)
{
    string t = s + "#";
    reverse(s.begin(), s.end());
    t += s;
    vector<ll> pi = prefix_function(t);
    return pi[t.size() - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        ll k = minpalindrome(s);
        string t = s.substr(k, n - 2 * k);
        ll p = maxpalindrome(t);
        reverse(t.begin(), t.end());
        ll p1 = maxpalindrome(t);
        // cout << k << " " << p << " " << p1 << "\n";
        if (p > p1)
        {
            cout << s.substr(0, k) + s.substr(k, p) + s.substr(n - k, k) << "\n";
        }
        else
        {
            cout << s.substr(0, k) + s.substr(n - k - p1, k + p1) << "\n";
        }
    }
}