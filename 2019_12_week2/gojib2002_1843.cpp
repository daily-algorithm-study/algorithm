#include <vector>
#include <string>
using namespace std;


//pair<int,int> dp[s][e] : s부터 e까지 식에서 나올 수 있는 최솟값과 최댓값
//s부터 e까지를 계산하는 여러 경우의 수가 있는데 그중 s+1번에 있는 연산자를 마지막에 계산하는 경우, s+3번에 있는 연산자를 마지막에 계산하는 경우, s+5번에 있는 연산자를 마지막에 계산하는 경우...등으로 나눈다.
//만약 s+3번 연산자를 마지막에 계산한다면 그 최댓값은 s+3번 연산자가 +라면 (s~s+2까지 계산의 최댓값) + (s+4~e까지 계산의 최댓값)이다.
//s+3번 연산자가 -라면 (s~s+2까지 계산의 최댓값) - (s+4~e까지 계산의 최솟값)이다.
//위 로직으로 백트래킹이 가능한데, s~e까지 계산의 최댓값과 최솟값은 고정된 값이기 때문에 메모이제이션이 가능하다.

int parseInt(string str){
    int i;
    int ret = 0;
    
    for(i=0;i<str.length();i++){
        ret *= 10;
        ret += str[i] - '0';
    }
    
    return ret;
}

pair<int,int> dp[200][200];

pair<int,int> recur(int s, int e, vector<string> &arr){
    int i;
    pair<int,int> ret = make_pair(-1000000000,1000000000);
    
    if(s > e) return make_pair(0,0);
    else if(s == e) return make_pair(parseInt(arr[s]), parseInt(arr[s]));
    if(dp[s][e].first != 0 || dp[s][e].second != 0) return dp[s][e];
    
    for(i=s;i<e;i+=2){
        if(arr[i+1].compare("-") == 0){
            ret.first = max(ret.first, recur(s,i,arr).first - recur(i+2,e,arr).second);
            ret.second = min(ret.second, recur(s,i,arr).second - recur(i+2,e,arr).first);
        }else{
            ret.first = max(ret.first, recur(s,i,arr).first + recur(i+2,e,arr).first);
            ret.second = min(ret.second, recur(s,i,arr).second + recur(i+2,e,arr).second);
        }
    }
    
    return dp[s][e] = ret;
}

int solution(vector<string> arr)
{
    return recur(0, arr.size()-1,arr).first;
}
