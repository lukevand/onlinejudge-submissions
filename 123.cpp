#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    set<string> badWords;
    vector<pair<string,vector<string>>> titles;
    while (cin >> s, s != "::") {
        badWords.insert(s);
    }
    string line;
    while (true) {
        getline(cin, line);
        if (cin.eof()) {
            break;
        }

        transform(line.begin(), line.end(), line.begin(), ::tolower);
        istringstream iss(line);
        vector<string> titleSplit;
        string newword;
        while (iss >> newword) {
            titleSplit.push_back(newword);
        }

        for (auto word: titleSplit) {
            if (badWords.find(word) == badWords.end()) {
                string tmp(word);
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
                titles.push_back({tmp, titleSplit});
            }
        }

    }

    sort(titles.begin(), titles.end());
    for (auto p: titles) {
        int c=0;
        for (auto x: p.second) {
            string newWord;
            if (c++ > 0) cout << ' ';
            transform(x.begin(), x.end(), back_inserter(newWord), ::toupper);
            if (newWord == p.first) {
                cout << newWord;
            } else {
                cout << x;
            }
        }
        cout << '\n';
    }

    return 0;
}

