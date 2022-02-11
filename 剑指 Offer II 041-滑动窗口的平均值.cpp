class MovingAverage {
    int size;
    queue<int> q;
    double sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if(q.size() == size)
        {
            sum -= q.front();
            q.pop();
            q.push(val);
            sum += val;
        }
        else
        {
            q.push(val);
            sum += val;
        }
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */