class MyCalendar {
    private:
    map<int,int> bookings;
    
public:
    MyCalendar() {
        
    }
        //INTUITION: Similar to interview scheduling type problems (like interview scheduling, corporate flight booking)
    
    //ALGO: We increase the count of every point of time when a booking start date is, and decrease the count of every point when a booking end date is.
    //So the recurring sum of these counts will denote the recurring number of bookings at any specific point of time.
    //At any point of time, if this sum==3, then we return false and also delete the entry of this booking
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