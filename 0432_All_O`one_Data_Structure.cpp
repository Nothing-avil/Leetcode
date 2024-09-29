// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class AllOne {
    struct Node{
        int c;
        list<string> st;
        Node *prev, *next;
        Node(int a){
            c=a;
            prev= nullptr;
            next= nullptr;
        }
    };
    unordered_map<string, Node*> mp;
    Node *head, *tail;

    Node* addNodeAfter(Node *prevNode, int count) {
        Node *newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if (tail == prevNode) {
            tail = newNode;
        }
        return newNode;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (tail == node) {
            tail = node->prev;
        }
        delete node;
    }

public:

    AllOne() {
        head = new Node(0);
        tail = head;
    }
    
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            if (head->next == nullptr || head->next->c != 1) {
                addNodeAfter(head, 1);
            }
            head->next->st.push_front(key);
            mp[key] = head->next;
        } else {
            Node *curNode = mp[key];
            int curCount = curNode->c;
            if (curNode->next == nullptr || curNode->next->c != curCount + 1) {
                addNodeAfter(curNode, curCount + 1);
            }
            curNode->next->st.push_front(key);
            mp[key] = curNode->next;
            curNode->st.remove(key);
            if (curNode->st.empty()) {
                removeNode(curNode);
            }
        }
    }
    
    void dec(string key) {
        Node *curNode = mp[key];
        int curCount = curNode->c;
        curNode->st.remove(key);
        if (curCount == 1) {
            mp.erase(key);
        } else {
            if (curNode->prev == head || curNode->prev->c != curCount - 1) {
                addNodeAfter(curNode->prev, curCount - 1);
            }
            curNode->prev->st.push_front(key);
            mp[key] = curNode->prev;
        }
        if (curNode->st.empty()) {
            removeNode(curNode);
        }
    }
    
    string getMaxKey() {
        return (tail == head) ? "" : tail->st.front();
    }
    
    string getMinKey() {
        return (head->next == nullptr) ? "" : head->next->st.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
