#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> diff;
    ll ans = -1;
    ll ind = 0;
    for (; ind < n; ind++)
    {
        if (s[ind] == '.')
            break;
    }
    if (ind > 8 || ind >= n || ind <= 0)
        ans = 0;
    diff.push_back(ind - 1);
    for (ll i = ind + 1; i < n; i++)
    {
        ll j = i;
        while (j < n)
        {
            if (s[j] == '.')
            {
                break;
            }
            j++;
        }
        diff.push_back(j - 1);
        i = j;
    }
    ll n1 = diff.size();
    if (s[n - 1] == '.')
        ans = 0;
    for (ll i = 1; i < n1; i++)
    {
        // cout << ans;
        // cout << diff[i] << " ";
        if (i == n1 - 1)
        {
            if (diff[i] - diff[i - 1] - 1 > 3 || diff[i] - diff[i - 1] - 1 < 1)
                ans = 0;
        }
        else
        {
            // cout << diff[i] - diff[i - 1] - 1;
            if (diff[i] - diff[i - 1] - 1 > 11 || diff[i] - diff[i - 1] - 1 <= 1)
                ans = 0;
        }
    }
    if (ans == 0)
    {
        cout << "NO\n";
        return 0;
    }
    ll t = 0;
    ll i;
    cout << "YES\n";
    for (i = 0; i < n; i++)
    {
        cout << s[i];
        if (diff[t] == i)
        {
            cout << ".";
            t++;
            i++;
            break;
        }
    }
    i++;
    for (; i < n; i++)
    {
        if (t == n1 - 1)
            break;
        if (diff[t] - diff[t - 1] - 1 <= 3)
        {
            cout << s[i] << "\n";
            i++;
            while (diff[t] + 1 != i)
            {
                cout << s[i];
                i++;
            }
            cout << ".";
            t++;
        }
        else
        {
            cout << s[i] << s[i + 1] << s[i + 2] << "\n";
            i += 3;
            while (diff[t] + 1 != i)
            {
                cout << s[i];
                i++;
            }
            cout << ".";
            t++;
        }
    }
    for (; i < n; i++)
        cout << s[i];
    cout << "\n";
}