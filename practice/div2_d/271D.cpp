#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef long long int int;
#define N 1505
vector<vector<int>> dp(N, vector<int>(N));
vector<int> nodes(N);
string s, bad;
int k;
int ans;
int n;
const int MAX = 2253001, ALF = 26 + 2;
pair<int, int> trie[MAX][ALF];
int currnode = 1;
void trie_construct()
{
    for (int _ = 0; _ < MAX; ++_)
        for (int __ = 0; __ < ALF; ++__)
        {
            trie[_][__].first = 0;
            trie[_][__].second = 0;
        }
}

void trie_insert(string word)
{
    int node = 0, idx = 0;
    int wordlength = word.length();
    while (trie[node][word[idx] - 'a'].first && idx < wordlength)
    {
        node = trie[node][word[idx] - 'a'].first;
        ++idx;
    }
    //printf("ans is %d\n", ans);
    for (; idx < wordlength; ++idx)
    {
        trie[node][word[idx] - 'a'].first = currnode;
        //printf("new path from %d to %d via %c\n", node, numm1, word[idx]);
        node = currnode;
        ++currnode;
    }
}

int trie_search(int &node, char word)
{

    int temp = trie[node][word - 'a'].second;
    trie[node][word - 'a'].second = 1;
    node = trie[node][word - 'a'].first;
    return temp;
}

int main()
{
    cin >> s;
    n = s.size();
    cin >> bad;
    cin >> k;
    trie_construct();
    for (int i = 0; i < n; i++)
    {
        trie_insert(s.substr(i, n - i));
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i + j - 1 < n; i++)
        {
            if (j == 1)
            {
                dp[i][i + j - 1] = !(bad[s[i] - 'a'] - 48);
                // cout << bad[s[i] - 'a'] - 48;
            }
            else
            {
                dp[i][i + j - 1] = dp[i][i + j - 2] + !(bad[s[i + j - 1] - 'a'] - 48);
            }
            if (dp[i][i + j - 1] <= k)
            {
                if (!trie_search(nodes[i], s[i + j - 1]))
                    ans++;
            }
            // cout << dp[i][i + j - 1] << " " << i << " " << i + j - 1 << " " << ans << "\n";
        }
    }
    cout << ans << "\n";
}