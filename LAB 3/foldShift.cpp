int foldShift(long long key, int addressSize) {
    string str = to_string(key);
    int size = str.length();
    int sum = 0;
    
    for (int i = 0; i < size; i += addressSize) {
        string segment = str.substr(i, min(addressSize, size - i));
        sum += stoi(segment);
    }

    string sumStr = to_string(sum);
    int resultSize = sumStr.length();
    
    string res = "";
    if (resultSize >= addressSize)
        res = sumStr.substr(resultSize - addressSize, addressSize);
    else res = sumStr;

    return stoi(res);
}

int rotation(long long key, int addressSize) {
    string str = to_string(key);
    int size = str.length();

    string rotatedStr = str.back() + str.substr(0, size - 1);
    long long rotatedKey = stoll(rotatedStr);

    return foldShift(rotatedKey, addressSize);
}