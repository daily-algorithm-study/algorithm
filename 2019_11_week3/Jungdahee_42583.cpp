#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) { //다리를 지나는 트럭 - success
    int answer = 0;
    int bridge_weight = 0;
    queue<int> bridge;
    
    for(int i = 0; i < truck_weights.size(); i++){
        while(true){
            //현재 다리 위에 올라가 있는 트럭의 수가 다리 길이와 같은 경우
            if(bridge.size() == bridge_length) {
                bridge_weight -= bridge.front(); //가장 앞에 있는 트럭의 무게를 다리 위의 트럭 무게에서 제거
                bridge.pop(); //큐에서 트럭 제거
                answer++; //다리를 다 건넜기 때문에 1초 증가
            }

            //다리 위에 있는 트럭의 총 무게 + 다리를 건너려는 트럭의 무게를 합했을 때 다리의 하중보다 클 경우 건너기 불가
            if(bridge_weight + truck_weights[i] > weight) bridge.push(0); //트럭이 아닌 무의미한 숫자 삽입, 트럭의 위치 표시 기능
            
            //다리 위에 있는 트럭의 총 무게 + 다리를 건너려는 트럭의 무게를 합했을 때 다리의 하중보다 작은 경우 건너기 가능
            else{ 
                bridge.push(truck_weights[i]); //다리 위 건너기 시작
                bridge_weight += truck_weights[i]; //다리 위 트럭 무게에 건너기 시작한 트럭의 무게를 추가
                break;
            }
        }
    }
    
    //빠져나온 트럭의 수 + 현재 다리 위에 있는 트럭의 수 + 다리의 길이
    return answer + bridge.size() + bridge_length;
}
