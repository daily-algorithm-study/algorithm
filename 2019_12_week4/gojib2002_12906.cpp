#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int i;
    
    answer.push_back(arr[0]);
    for(i=1;i<arr.size();i++)
    {
        if(arr[i] == arr[i-1]) continue;
        answer.push_back(arr[i]);
    }

    return answer;
}
