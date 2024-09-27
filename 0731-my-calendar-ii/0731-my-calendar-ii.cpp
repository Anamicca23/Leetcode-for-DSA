class MyCalendarTwo {
private:
    bool overlapped(int start1, int end1, int start2, int end2)
    {
        return max(start1,start2) < min(end1,end2);
    }
    pair<int,int> overlapped_interval(int start1,int end1, int start2, int end2)
    {
        return {max(start1,start2), min(end1,end2)};
    }
public:
    vector<pair<int,int>> cal;
    vector<pair<int,int>> overlap;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        bool tripple_overlap = false;
        for(pair<int,int> book : overlap)
        {
            if(overlapped(book.first,book.second,start,end))
                tripple_overlap = true;
        }
        if(tripple_overlap)
            return false;
        for(pair<int,int> book : cal)
        {
            if(overlapped(book.first,book.second,start,end))
                overlap.push_back(overlapped_interval(book.first,book.second,start,end));
        }
        cal.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */