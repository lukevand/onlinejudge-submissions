#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << "DEBUG: " << x << '\n'
string inWord;
string targetWord;

void dfs(int i, int j, size_t opcount, string stack, string popped, string ops) {
    if (opcount == 2*inWord.size()) {
        if (popped == targetWord) {
            cout << ops << '\n';
        }
        return;
    }

    if (i < (int) inWord.size()) {
        dfs(i+1, j, opcount+1, stack+inWord[i], popped, ops+(opcount==0 ? "i" : " i"));
    }

    if (!stack.empty() && stack[stack.size()-1] == targetWord[j]) {
        dfs(i, j+1, opcount+1, stack.substr(0, stack.size()-1), popped+targetWord[j], ops+" o");
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> inWord >> targetWord, !cin.eof()) {
        cout << "[\n";
        dfs(0, 0, 0, "", "", "");
        cout << "]\n";
    }
}

