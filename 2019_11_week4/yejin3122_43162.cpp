// DFS
#include <string>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>> computers, bool visit[]) {
    visit[start] = true;
    printf("%d\n", start);
    
    for(int i=0; i<computers[start].size(); i++) {
        if(i == start) continue;  // 자기 자신이면 pass
        
        if(computers[start][i] && !visit[i])
            dfs(i, computers, visit);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visit[n];
    fill(visit, visit+n, false);
    
    for(int i=0; i<n; i++) {
        if(!visit[i]) {
            answer++;
            dfs(i, computers, visit);
        }
    }
    
    return answer;
}
