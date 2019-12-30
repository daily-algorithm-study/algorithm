#include <string>
#include <vector>
#include <queue>

using namespace std;

//bfs 마지막에 큐에 남아있던 노드 수가 정답.

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> que;
    bool visited[20010];
    vector<int> v[20010];
    int cur;
    int size;
    int i;
    
    for(i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    que.push(1);
    visited[1] = true;
    while(!que.empty()){
        size = que.size();
        answer = size;
        while(size--){
            cur = que.front();
            que.pop();
            
            for(i=0;i<v[cur].size();i++){
                if(!visited[v[cur][i]]){
                    que.push(v[cur][i]);
                    visited[v[cur][i]] = true;
                }
            }
        }
    }
    
    return answer;
}
