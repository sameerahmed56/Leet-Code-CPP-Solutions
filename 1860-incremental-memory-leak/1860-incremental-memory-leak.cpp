class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> arr{memory1,memory2};
        int time = 1;
        while(true){
            if(arr[0]>= arr[1]){
                if(arr[0] >= time){
                    arr[0] -= time;
                }
                else{
                    break;
                }
            }
            else{
                if(arr[1] >= time){
                    arr[1] -= time;
                }
                else{
                    break;
                }
            }
            time++;
        }
        return {time,arr[0],arr[1]};
    }
};