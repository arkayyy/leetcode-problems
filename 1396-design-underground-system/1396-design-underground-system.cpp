class UndergroundSystem {
    unordered_map<int,pair<int,string>> lastCheckIn;
    map<pair<string,string>, vector<int>> times;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(lastCheckIn.find(id)!=lastCheckIn.end()) return;
        lastCheckIn[id] = {t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(lastCheckIn.find(id)==lastCheckIn.end()) return;
        times[{lastCheckIn[id].second,stationName}].push_back(t-lastCheckIn[id].first);
        lastCheckIn.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> t = times[{startStation, endStation}];
        return (double)((double)accumulate(t.begin(),t.end(),0)/(double)t.size());
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */