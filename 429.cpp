#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
#define ALL(x) x.begin(), x.end()

vector<vector<size_t>> G;
vector<string> words;

bool ccomp(const string s1, const string s2) {
    if (s1.size() != s2.size()) return false;
    size_t disorder = 0;
    for (size_t i=0; i<s1.size(); i++) {
        if (s1[i] != s2[i]) {
            disorder++;
            if (disorder > 1) return false;
        }
    }
    return disorder == 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    bool firsttime = true;
    unordered_map<string,int> wordmap;
    while (n--) {
        if (!firsttime) {
            cout << '\n';
        }
        firsttime = false;
        string s;
        words.clear();
        G.assign(200, vector<size_t>());
        for (int i=0; cin >> s, s[0] != '*'; i++) {
            words.push_back(s);
            wordmap[s] = i;
        }
        for (size_t i=1; i<words.size(); i++) {
            for (size_t j=0; j<i; j++) {
                if (ccomp(words[i], words[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        string starts, ends, line;
        getline(cin, line);
        while (getline(cin, line), !line.empty()) {
            vector<int> best(words.size(), -1);
            istringstream sin(line);
            sin >> starts >> ends;
            size_t start = wordmap[starts];
            size_t end = wordmap[ends];

            queue<size_t> q;
            q.push(start);
            best[start] = 0;
            bool done = false;
            while (!q.empty() && !done) {
                size_t p = q.front(); q.pop();
                for (size_t r: G[p]) {
                    if (best[r] == -1) {
                        best[r] = best[p]+1;
                        if (r == end) {
                            done = true;
                            break;
                        }
                        q.push(r);
                    }
                }
            }
            cout << starts << ' '<<ends<<' '<<best[end]<<'\n';
        }
    }
}

