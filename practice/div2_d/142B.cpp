#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 1003
vector<vector<ll>> dp(N, vector<ll>(N));
ll n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll temp = max(n, m), temp1 = min(n, m);
    n = temp, m = temp1;
    if (m <= 2)
    {
        if (m == 1)
        {
            cout << n << endl;
            return 0;
        }
        else
        {
            ll temp = n / 4, temp1 = n % 4;
            temp *= 4;
            if (temp1 == 1)
            {
                temp += 2;
            }
            else if (temp1 >= 2)
            {
                temp += 4;
            }
            cout << temp << "\n";
            return 0;
        }
    }
    else
    {
        if (n % 2 == 0 || m % 2 == 0)
        {
            cout << (n * m) / 2 << "\n";
            return 0;
        }
        else
        {
            cout << (n * m) / 2 + 1 << "\n";
            return 0;
        }
    }
}