#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll n, z;
v<ll> arr(N);
v<ll> matched(N);
ll way1()
{
    ll counter = 0;
    ll p1 = -1, p2 = -1;
    for (ll i = 1; i < n; i++)
    {
        ll temp = lower_bound(arr.begin(), arr.begin() + i - 1, arr[i] - z) - arr.begin();
        ll temp1 = lower_bound(arr.begin() + i + 1, arr.begin() + n, arr[i] + z) - arr.begin();
        if (arr[temp] <= arr[i] - z && p1 == -1 && temp1 < n)
            p1 = i;
        if (temp1 >= n && p2 == -1)
            p2 = i;
    }
    // cout << p1 << " " << p2 << endl;
    ll ind = p2;
    for (ll i = 0; i < p2; i++)
    {
        if (matched[i])
            continue;
        ll temp = lower_bound(arr.begin() + ind, arr.begin() + n, arr[i] + z) - arr.begin();
        if (temp >= n)
            break;
        matched[i] = 1;
        matched[temp] = 1;
        counter++;
        ind = temp + 1;
    }
    ind = p1;
    if (p1 != -1)
        for (ll i = 0; i < p2; i++)
        {
            if (matched[i])
                continue;
            for (ll j = ind; j < p2; j++, ind++)
            {
                if (arr[j] >= arr[i] + z)
                {
                    counter++;
                    matched[i] = 1;
                    matched[j] = 1;
                    ind++;
                    break;
                }
            }
        }
    return counter;
}
ll way2()
{
    ll counter = 0;
    ll ind = 1;
    for (ll i = 0; i < n; i++)
    {
        if (matched[i])
            continue;
        ll temp = lower_bound(arr.begin() + ind, arr.begin() + n, arr[i] + z) - arr.begin();
        // cout << i << " " << temp << endl;
        if (temp >= n)
            break;
        counter++;
        matched[temp] = 1;
        matched[i] = 1;
        ind = temp + 1;
    }
    return counter;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> z;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n);
    ll counter = way1();
    fill(matched.begin(), matched.end(), 0);
    counter = max(counter, way2());
    cout << counter << endl;
}