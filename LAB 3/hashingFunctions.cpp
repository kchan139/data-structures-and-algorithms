long int midSquare(long int seed) {
    long int squared = seed * seed;
    squared /= 100;
    
    return squared % 10000;
}

long int moduloDivision(long int seed, long int mod) {
    return seed % mod;
}

long int digitExtraction(long int seed, int* extractDigits, int size) {
    string seedStr = to_string(seed);
    string result = "";
    int len = seedStr.length();
    
    for (int i = 0; i < size; i++) {
        if (extractDigits[i] < len) {
            result += seedStr[extractDigits[i]];
        }
    }
    
    if (result.empty()) return 0;
    return stol(result);
}