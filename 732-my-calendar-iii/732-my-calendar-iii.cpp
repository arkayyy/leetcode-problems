class MyCalendarThree {
    private:
    map<int,int> bookings;
    int kBookings = 0;
public:
    MyCalendarThree() {
        
    }
    //INTUITION: Similar to interview scheduling type problems (like interview scheduling, corporate flight booking)
    
    //ALGO: We increase the count of every point of time when a booking start date is, and decrease the count of every point when a booking end date is.
    //So the recurring sum of these counts will denote the recurring number of bookings at any specific point of time.
    //At any point of time, we update the kBookings with the max recurringBookings encountered, and return it.
    
    int book(int start, int end) {
        bookings[start]++;
        bookings[end]--;
        int recurringBookings = 0;
        
        for(auto&b: bookings)
        {
            recurringBookings+=b.second;
            kBookings = max(kBookings,recurringBookings);
        }
        return kBookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */