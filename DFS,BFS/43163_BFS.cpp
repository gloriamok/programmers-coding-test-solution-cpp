#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(),words.end(),target) == words.end()) return 0;
    int n = begin.length();
    int visited[50]{};
    queue<int> q;
    for(int i=0;i<words.size();i++) {
        int notSame = 0;
        for (int j=0;j<n;j++) {
            if (begin[j] != words[i][j]) notSame++;
        }
        if (!notSame) visited[i] = 1;
        else if (notSame == 1) {
            q.push(i);
            visited[i] = 1;
            if (words[i] == target) return visited[i];
        }
    }
    while(!q.empty()) {
        int f = q.front();
        string fstr = words[f];
        q.pop();
        for(int i=0;i<words.size();i++) {
            if (!visited[i]) {
                int notSame = 0;
                for (int j=0;j<n;j++) {
                    if (fstr[j] != words[i][j]) notSame++;
                }
                if (notSame == 1) {
                    q.push(i);
                    visited[i] = visited[f] + 1;
                    if (words[i] == target) return visited[i];
                }
            }
        }
    }
    return 0;
}