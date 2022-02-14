class RecentCounter {
    int size = 3000;
    queue<int> times;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        times.push(t);
        while(times.front() + size < t)
        {
            times.pop();
        }
        return times.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */