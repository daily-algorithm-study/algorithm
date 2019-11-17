import java.util.ArrayList;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int kg = 0, s = 0;
        ArrayList<Integer> brgQ = new ArrayList<>();

        for (int i = 0; i < truck_weights.length; i++) {
            while (true) {
                // 다리의 맨 앞 트럭이 다리를 빠져나갈 수 있을 때
                if (brgQ.size() == bridge_length) {
                    // 다리 큐의 맨 앞의 트럭 제거
                    kg -= brgQ.get(0);
                    brgQ.remove(0);
                    s++;
                }
                // 다음 트럭이 다리에 올라갈 수 없다면
                if (weight - kg < truck_weights[i]) {
                    // 0으로 큐의 자리만 차지해준다
                    brgQ.add(0);
                } else {
                    // 큐에 대기 트럭 추가
                    brgQ.add(truck_weights[i]);
                    kg += truck_weights[i];
                    break;
                }
            }
        }
        
        return s + brgQ.size() + bridge_length;
    }
}
