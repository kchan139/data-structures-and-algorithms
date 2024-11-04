void insert(int key) {
    int index = hash(key);
    
    data[index].push_front(key);
}

void remove(int key) {
    int index = hash(key);
    string result = "";
    list<int> &slot = data[index];
    bool found = false;
    
    for (auto it = slot.begin(); it != slot.end(); it++) {
        if (!result.empty())
            result += ",";
        result += to_string(*it);
            
        if (*it == key) {
            slot.erase(it);
            found = true;
            break;
        }
    }
    
    cout << result << ",";
    if (!found)
        throw runtime_error ("Not found!");
}

bool search(int key) {
    int index = hash (key);
    string result = "";
    list<int> &slot = data[index];
    
    for (auto it = slot.begin(); it != slot.end(); it++) {
        if (!result.empty())
            result += ",";
        result += to_string(*it);
            
        if (*it == key) {
            cout << result;
            return true;
        }
    }
    
    cout << result << endl;
    return false;
}