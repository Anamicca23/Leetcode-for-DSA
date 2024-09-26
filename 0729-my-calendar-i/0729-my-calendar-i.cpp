class MyCalendar {
    struct Node {
        int start, end;
        Node(int start, int end) : start(start), end(end) {}
        bool operator<(const Node& other) const { return other.start >= end; }
    };
    set<Node> s;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        auto it = s.lower_bound({start, end});
        if (it != s.end() && it->start < end)
            return false;
        s.insert({start, end});
        return true; 
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */