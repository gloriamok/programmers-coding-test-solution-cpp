#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    bool visited[200]{};
    int nwNum = 0;
    for(int i=0;i<n;i++) {
        if (!visited[i]) {
            visited[i] = 1;
            nwNum++;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int f = q.front();
                q.pop();
                for(int j=0;j<n;j++) {
                    if (computers[f][j] && computers[j][f] && !visited[j]) {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    }
    return nwNum;
}