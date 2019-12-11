#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//MST문제
//크루스칼 알고리즘 : costs를 비용 기준으로 정렬 -> 비용순으로 각 간선을 보면서 양끝 노드가 같은 트리에 있는지 유니온파인드를 통해 판별. 

int parent[100];

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void union_(int a, int b){
    a = find(a);
    b = find(b);
    
    parent[a] = b;
}

bool comp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int i;
    
    for(i=0;i<n;i++) parent[i] = i;
    
    sort(costs.begin(), costs.end(), comp);
    for(i=0;i<costs.size();i++){
        if(find(costs[i][0]) != find(costs[i][1])){
            answer+=costs[i][2];
            union_(costs[i][0], costs[i][1]);
        }
    }
    
    return answer;
}
