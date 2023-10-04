class MyHashMap {
public:
    vector<list<pair<int,int>>> mps;
    int size = 10000;
    MyHashMap() {
        mps.resize(size);
    }
    
    void put(int key, int value) {
        int no= key%size;
        auto &line = mps[no];
        for(auto &it: line){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        line.emplace_back(key, value);
    }
    
    int get(int key) {
        int no= key%size;
        auto &line = mps[no];
        if(line.empty()){
            return -1;
        }
        for(auto &it: line){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int no= key%size;
        auto &line = mps[no];
        for(auto it= line.begin(); it != line.end(); it++){
            if(it->first==key){
                line.erase(it);
                return;
            }
        }
    }
};
