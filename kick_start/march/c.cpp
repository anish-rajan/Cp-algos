#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 200005
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll ans, n, k;
        vector<ll> arr(N);
        multiset<ll> diff;
        cin >> n >> k;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 1; i < n; i++)
        {
            diff.insert(arr[i] - arr[i - 1]);
        }
        ll h = diff.size();
        // for (auto itr1 = diff.begin(); itr1 != diff.end(); itr1++)
        // {
        //     cout << *itr1 << " ";
        // }
        // cout << "\n";
        while (k--)
        {
            auto itr = diff.end();
            itr--;
            ll val = *itr;
            if (val == 1)
                break;
            ll val2;
            if (h >= 2)
            {
                --itr;
                val2 = *itr;
                itr++;
            }
            else
                val2 = 1;
            diff.erase(itr);
            if (val2 == val)
            {
                diff.insert(val2 / 2);
                diff.insert(val2 / 2 + (val2 % 2));
            }
            else
            {
                ll p = val / 2;
                if (val % 2 == 1)
                    p++;
                if (val2 >= p)
                {
                    diff.insert(val / 2);
                    diff.insert(val / 2 + val % 2);
                }
                else
                {
                    p = val / val2;
                    if (val % val2 == 0)
                        p--;
                    ll p1 = val / val2 + (val % val2);
                    double p2 = log2(p1);
                    ll p3 = (ll)p2;
                    if (p3 < p2)
                        p3++;
                    // cout << p3 << " ";
                    if (p <= k && p < p3)
                    {
                        diff.insert(val2);
                        diff.insert(val - val2);
                    }
                    else
                    {
                        diff.insert(val / 2);
                        diff.insert(val / 2 + (val % 2));
                    }
                }
            }

            // for (auto itr1 = diff.begin(); itr1 != diff.end(); itr1++)
            // {
            //     cout << *itr1 << " ";
            // }
            // cout << "\n";
        }
        auto itr = diff.end();
        itr--;
        ans = *itr;
        cout << "Case #" << i << ": " << ans << "\n";
    }
}