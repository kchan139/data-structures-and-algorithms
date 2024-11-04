int insert(int key) {
    int bucketIndex = key % size;
    int firstSlot = bucketIndex * bucketSize;
    
    for (int i = 0; i < size * bucketSize; i++)
        if (status[i] == NON_EMPTY && data[i] == key)
            throw runtime_error("Duplicate key: " + to_string(key));
    
    for (int i = firstSlot; i < firstSlot + bucketSize; i++) {
        if (status[i] != NON_EMPTY) {
            status[i] = NON_EMPTY;
            data[i] = key;
            return i;
        }
    }
    
    int currentBucket = (bucketIndex + 1) % size;
    while (currentBucket != bucketIndex) {
        int startSlot = currentBucket * bucketSize;

        for (int i = startSlot; i < startSlot + bucketSize; i++) {
            if (status[i] != NON_EMPTY) {
                status[i] = NON_EMPTY;
                data[i] = key;
                return i;
            }
        }

        currentBucket = (currentBucket + 1) % size;
    }
    
    throw runtime_error("Overflow!");
}

void remove(int key) {
    string result;
    int bucketIndex = key % size;
    int currentBucket = bucketIndex;
    bool found = false;
    
    do {
        int startSlot = currentBucket * bucketSize;

        for (int i = startSlot; i < startSlot + bucketSize; i++) {
            if (status[i] == NON_EMPTY) {
                if (!result.empty()) 
                    result += ",";
                result += to_string(data[i]);
                
                if (data[i] == key) {
                    status[i] = DELETED;
                    found = true;
                    cout << result << ",";
                    return;
                }
            }
        }

        currentBucket = (currentBucket + 1) % size;
    } 
    while (currentBucket != bucketIndex && !found);
    
    cout << result << ",";
    throw runtime_error("Not found!");
}

int search(int key) {
    string result;
    int bucketIndex = key % size;
    int currentBucket = bucketIndex;
    
    do {
        int startSlot = currentBucket * bucketSize;

        for (int i = startSlot; i < startSlot + bucketSize; i++) {
            if (status[i] == NON_EMPTY) {
                if (!result.empty()) 
                    result += ",";
                result += to_string(data[i]);
                
                if (data[i] == key) {
                    cout << result << ",";
                    return i;
                }
            }
        }
        
        currentBucket = (currentBucket + 1) % size;
    }
    while (currentBucket != bucketIndex);
    
    cout << result << ",";
    return -1;
}