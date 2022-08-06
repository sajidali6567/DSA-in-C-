class MyCalendar {
public:
    vector<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto event:events) {
            if(end <= event.first || start >= event.second);
            else return false; 
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */