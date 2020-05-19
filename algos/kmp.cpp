#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
            cout << "Found pattern at index " << i - j;
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