class OrderedStream {
    vector<string> vec;
    int size, ptr;
public:
    OrderedStream(int n) {
        vec.resize(n);
        size = n;
        ptr = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        vec[idKey - 1] = value;
        vector<string> result;
        for(int key{ptr}; key < size; key++){
            ptr++;
            if(vec[key] == ""){
                ptr = key;
                break;
            }
            result.push_back(vec[key]);
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */