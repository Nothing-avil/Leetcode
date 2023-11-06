class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> ans;
    int i=0;
    SeatManager(int n) {
        i=1;
    }
    
    int reserve() {
        int s;
        if(!ans.empty()){
            s=ans.top();
            ans.pop();
            return s;
        }
        s=i;
        i++;
        return s;
    }
    
    void unreserve(int seatNumber) {
        ans.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
