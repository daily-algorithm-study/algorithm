#include <string>
#include <vector>

using namespace std;

int answer = 100;
bool visit[50];

void dfs(int idx, string begin, string target, vector<string> words, int cnt) {
    if(begin == target) {
        if(answer > cnt) 
            answer = cnt;
        return;
    }
    
    for(int i=0; i<words.size(); i++) {
        int temp = 0; // 몇개의 문자가 다른지 카운트
        
        // 방문하지 않았을때만
        if(!visit[i]) {
            for(int j=0; j<words[i].size(); j++) {
                if(words[i][j] != begin[j])
                    temp++;
            }
            // 1개의 문자만 다른 경우 탐색
            if(temp == 1) {
                visit[i] = true;
                dfs(i+1, words[i], target, words, cnt+1);
                visit[i] = false;
            }
        }
        
    }
}

int solution(string begin, string target, vector<string> words) {
    bool flag = false;
    
    // 타겟이 없으면 걍 리턴
    for(int i=0; i<words.size(); i++) {
        if(words[i] == target) {
            flag = true;
            break;
        }
    }
    if(flag == false) answer = 0;
    else dfs(0, begin, target, words, 0);
    
    return answer;
}
