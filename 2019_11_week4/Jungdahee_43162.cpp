#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[200];

int solution(int n, vector<vector<int>> computers) { //네트워크 - success
    int answer = 0;
    queue<int> q;
    
    for(int i = 0; i < n; i++){
        if(visit[i] == 0){
            answer++;
            q.push(i);
            visit[i] = 1;
        }
        
         while(!q.empty()){ //BFS로 탐색
            int current = q.front();
            q.pop();
        
            for(int i = 0; i < n; i++){
                if(computers[current][i] == 1 && visit[i] == 0){ //연결되어 있는 네트워크인 경우
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
    }
    return answer;
}
