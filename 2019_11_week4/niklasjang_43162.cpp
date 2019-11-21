//dfs
#include <string>
#include <vector>

using namespace std;

void dfs(int i, vector<vector<int>> &computers, vector<bool> &check){
    check[i] = true;
    int size = computers[i].size();
    for(int j=0; j<size; j++){
        if(computers[i][j] && !check[j]){
            dfs(j,computers,check);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> check(n,false);
    for(int i=0; i<n; i++){
        if(!check[i]){
            dfs(i, computers, check);
            answer++;
        }
        
    }
    return answer;
}

//bfs
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> check(n,false);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(!check[i]){
            answer++;
            q.push(i);
            check[i] = true;
            while(!q.empty()){
                int front = q.front(); q.pop();
                for(int j=0; j<n; j++){
                    if(computers[front][j] && !check[j]){
                        q.push(j);
                        check[j] = true;
                    }
                }
            }
        }
        
    }
    return answer;
}