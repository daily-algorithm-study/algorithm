#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int i;
    long long sum = 0;
    
    sort(weight.begin(), weight.end());
    for(i=0;i<weight.size();i++){
        if(sum+1 < weight[i]) break;
        
        sum += weight[i];
    }
    
    return sum + 1;
}
