class ExamRoom {
private:
     int capacity;
     set<int> s;
public:
    
    ExamRoom(int n) {
        capacity = n;
    }
    
    int seat() {
        int dist = 0, curr = 0;
        if(!s.empty())
        {
            auto it = s.begin();
            
            dist = *it;
            //distance from the beginning
            if(dist==0) it++;
            
            //calculate distance in between 
            while(it!=s.end())
            {
                int mid_dist = (*it - *prev(it))/2;
                if(mid_dist > dist) //if we find any group of empty seats such that the number of consecutive empty seats is more than the max no. of consecutive seats stored before (dist = max no. of consecutive unoccupied seats)
                {
                    dist = mid_dist; //we update dist to maximum
                    curr = *prev(it) + dist; //we set the curr pointer to half the distance between iterator it and it+1 (since dist is half the distance b/w it and it+1)
                }
                it++;
            }
            
            //calculate distance at the end (between end of capacity and lastmost index where any student is seated)
            if(((capacity-1) - *(s.rbegin())) > dist ) //if the number of consecutive empty seats at last is greater than the max number of consecutive empty seats stored before
                curr = capacity - 1; // we place the student at last seat
        }
        
        s.insert(curr);
        return curr;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */