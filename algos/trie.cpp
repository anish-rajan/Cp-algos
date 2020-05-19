#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long n;
const int MAX = 1e6 + 2, ALF = 26 + 2;
pair<int, int> trie[MAX][ALF];
int currnode = 1;
int trie_construct()
{
    for (int _ = 0; _ < MAX; ++_)
        for (int __ = 0; __ < ALF; ++__)
        {
            trie[_][__].first = 0;
            trie[_][__].second = 0;
        }
}

int trie_insert(string word)
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
        if (idx != wordlength - 1)
            node = currnode;
        ++currnode;
    }
    trie[node][word[idx] - 'a'].second = 1;
}

int trie_search(string word)
{
    int node = 0, idx = 0;
    int wordlength = word.length();
    while (trie[node][word[idx] - 'a'].first && idx < wordlength)
    {
        if (idx != wordlength - 1)
            node = trie[node][word[idx] - 'a'].first;
        ++idx;
    }
    return trie[node][word[idx] - 'a'].second;
}

/*
struct Trie
{
    using S = int;
    struct node
    {
        S next;
        S isFinal;
        node() : next(0), isFinal(0) {}
    };
    S nxt;
    vector<vector<node>> data;
    Trie(S maxLen = 1e6 + 1, S ch = 26)
    {
        nxt = 1;
        data.resize(maxLen, vector<node>(ch));
    }
    void insert(string s)
    {
        if (s.size() == 0)
            return;
        S idx = 0;
        S prev = 0;
        for (S i = 0; i < (S)s.size(); i++)
        {
            S ch = (s[i] - 'a');
            if (data[idx][ch].next == 0)
            {
                data[idx][ch].next = nxt++;
            }
            prev = idx;
            idx = data[idx][ch].next;
        }
        data[prev][s[(S)s.size() - 1] - 'a'].isFinal++;
    }
    void remove(string s)
    {
        if (s.size() == 0)
            return;
        S idx = 0;
        for (S i = 0; i < (S)s.size() - 1; i++)
        {
            S ch = (s[i] - 'a');
            if (data[idx][ch].next == 0)
                return;
            idx = data[idx][ch].next;
        }
        data[idx][s[(S)s.size() - 1] - 'a'].isFinal--;
    }
    S find(string s)
    {
        if (s.size() == 0)
            return 0;
        S idx = 0;
        for (S i = 0; i < (S)s.size() - 1; i++)
        {
            S ch = (s[i] - 'a');
            if (data[idx][ch].next == 0)
                return 0;
            idx = data[idx][ch].next;
        }
        return data[idx][s[(S)s.size() - 1] - 'a'].isFinal;
    }
};

*/

/*
    #include <bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;

const ll MaxN = 1e5+1; // Size of the 2-D arr
const ll chset = 26; // Character Set

ll trie[MaxN][chset];
ll finish[MaxN][chset]; // Tell if it is the end or not.
ll nxt = 1;

void addTrie(string &s) {
    ll len = s.size();
    ll idx = 0;
    ll prev = 0;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (trie[idx][c] == 0) trie[idx][c] = (nxt++);
        prev = idx;
        idx = trie[idx][c];
    }
    finish[prev][s[len-1] - 'a'] = 1;
}

ll findTrie(string &s) {
    ll idx = 0;
    ll len = s.size();
    ll prev = 0;
    for(ll i=0; i<len; i++) {
        if(trie[idx][s[i]-'a'] == 0)
            return 0;
        else {
            prev = idx;
            idx = trie[idx][s[i]-'a'];
        }
    }
    
    if(finish[prev][s[len-1] - 'a'] == 1) return 1;
    else return 0;
}

int main(){
    ll n;
    cin >> n;
    string s;
    for(ll i=0;i<n;i++) {
        cin >> s;
        addTrie(s);
    }
    ll q;
    cout << "Query : " << endl;
    cin >> q;
    n = q;
    while(q--) {
        cin >> s;
        ll val = findTrie(s);
        cout << n-q << " " << val << endl;
    }
    
    return 0;
}
*/

/*

    * To reduce memory consumption change (#define ll long long int) to #define ll int.
    * In root any character can be passed.
    * In TrieSearch function empty string "" is passed

#include <bits/stdc++.h>
#define ll long long int
#define v vector
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    char data;
    ll leaf = 0;
};

TrieNode* TrieCreateNode(char data){
    TrieNode* ele = new TrieNode;
    ele->data = data;
    ele->leaf = 0;
    for(ll i=0;i<26;i++) ele->child[i] = NULL;
    return ele;
}

void TrieInsert(TrieNode* root, string s){
    TrieNode* temp = root;
    for(ll i=0;i<s.size();i++){
        if(temp->child[s[i]-'a'] == NULL)
            temp->child[s[i]-'a'] = TrieCreateNode(s[i]);
        temp = temp->child[s[i]-'a'];
    }
    temp->leaf++;
}

bool TrieSearch(TrieNode* root, string s){
    TrieNode* crawl = root;
    ll ind = 0;
    while(ind < s.size() && crawl != NULL){
        crawl = crawl->child[s[ind]-'a'];
        ind++;
    }
    
    if(crawl != NULL && crawl->leaf > 0) return true;
    else return false;
}

void TrieListAll(TrieNode* root, string a){
    if(root->leaf > 0)
        cout << a << endl;
    for(ll i=0;i<26;i++){
        if(root->child[i] != NULL)
            TrieListAll(root->child[i], a+root->child[i]->data);
    }
    return;
}

int main(){
    TrieNode* trie = TrieCreateNode(' ');
    TrieInsert(trie,"hello");
    TrieInsert(trie,"helloworld");
    TrieInsert(trie,"goodbye");
    cout << "All entries in the trie are : " << endl;
    TrieListAll(trie,"");
    cout << endl;
    cout << "String hello is present : " << TrieSearch(trie,"hello") << endl;
    cout << "String helworld was : " << TrieSearch(trie,"helworld") << endl;
    return 0;
}
*/