class MyCalendar {
    private:
    map<int,int> bookings;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bookings[start]++;
        bookings[end]--;
        int recurringBookings = 0;
        
        for(auto&b: bookings)
        {
            recurringBookings+=b.second;
            if(recurringBookings==2)
            {
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */