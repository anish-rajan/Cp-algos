#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;
    ll n = s.size();
    ll yes = -1;
    if (a * k > n || n / b > k || (n / b == k && n % b > 0))
    {
        yes = 0;
    }
    if (yes == 0)
    {
        cout << "No solution"
             << "\n";
        return 0;
    }
    ll avg = n / k;
    ll rem = n % k;
    if (rem > 0)
        avg++;
    ll temp = 0;
    ll temp1 = 0;
    for (ll i = 0; i < n; i++)
    {
        cout << s[i];
        temp++;
        if (temp == avg)
        {
            temp1++;
            cout << "\n";
            if (temp1 == rem)
            {
                avg--;
                temp1++;
            }
            temp = 0;
        }
    }
}