#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) { //단어 변환 - success
    int answer = 0;
    bool check = false;
    vector<bool> visit;
    
    for (int i = 0; i < words.size(); i++) {
        if (target == words[i]) {
            check = true; 
            break;
        }
    }
    if (!check) return 0;
    
    queue<pair<string, int>> q;
    visit.resize(words.size(), false);
    
    q.push(make_pair(begin, 0));
    
    while (!q.empty()) {
        string current = q.front().first;
        int num = q.front().second;
        q.pop();
        
        if (current.compare(target) == 0) {
            answer = num;
            break;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (visit[i]) continue;
            int count = 0;
            
            for (int j = 0; j < current.size(); j++) {
                if (current[j] != words[i][j]) count++;
            }
            
            if (count == 1) {
                visit[i] = true;
                q.push(make_pair(words[i], num + 1));
            }
        }
    }
    
    return answer;
}
