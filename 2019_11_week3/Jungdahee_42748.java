#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) { //K번째수 - success
    vector<int> answer;
        
    for(int i = 0; i < commands.size(); i++){
        vector<int> tmp;
        
        //i부터 j까지의 원소 tmp vector에 삽입
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++) tmp.push_back(array[j]);
        
        //오름차순으로 정렬
        sort(tmp.begin(), tmp.end()); 
        //정렬된 vector에서 찾고자 하는 k번째 원소 결과에 추가
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}
