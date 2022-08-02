class MyCircularQueue {
    vector<int> list;
    int size;
    int topIndex, backIndex;
public:
    MyCircularQueue(int k) {
        size = k;
        list.resize(k);
        topIndex = -1, backIndex = -1;
    }
    
    bool enQueue(int value) {
        if(topIndex == -1){
            topIndex++;
            backIndex++;
            list[topIndex] = value;
        }
        else{
            if(backIndex > topIndex)
            {
                if(backIndex < size - 1){
                    backIndex++;
                    list[backIndex] = value;
                }
                else if(topIndex > 0){
                    backIndex = 0;
                    list[backIndex] = value;
                }
                else
                    return false;
        }
        else if(backIndex < topIndex){
            if(topIndex - backIndex > 1)
            {
                backIndex++;
                list[backIndex] = value;
            }
            else
                return false;
        }
        else{
            if(backIndex == 0 && size == 1)
                return false;
            else{
                if(backIndex < size - 1){
                   backIndex++;
                }
               else{
                   backIndex = 0;
               }
               list[backIndex] = value;
            }
          }
        }
        return true;
    }
    
    bool deQueue() {
        if(topIndex == backIndex){
            if(topIndex == -1)
                return false;
            topIndex = backIndex = -1;
        }
        else{
            if(backIndex > topIndex){
                topIndex++;
            }
            else{
                if(topIndex < size - 1){
                    topIndex++;
                }
                else{
                    topIndex = topIndex + 1 - size;
                }

            }
        }
        return true;
    }
    
    int Front() {
        if(topIndex == -1)
            return -1;
        return list[topIndex];
    }
    
    int Rear() {
        if(backIndex == -1)
            return -1;
        return list[backIndex];
    }
    
    bool isEmpty() {
        return topIndex == backIndex && backIndex  == -1;
    }
    
    bool isFull() {
        return (topIndex == 0 && backIndex == size - 1) || (topIndex - backIndex == 1);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */