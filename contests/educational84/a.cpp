#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if ((n + k) % 2)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            ll temp = (n + k) / 2, temp1 = (k * (k + 1)) / 2;
            if (temp1 > temp)
            {
                cout << "NO\n";
                continue;
            }
            else
            {
                cout << "YES\n";
                continue;
            }
        }
    }
}