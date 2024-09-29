int Train::allocate(int containerSize) {
    Train::TrainCar* current = head->next;
    Train::TrainCar* bestFit = nullptr;
    int bestIndex = -1;
    int currentIndex = 1;
    
    while (current != nullptr) {
        if (current->remainingSpace >= containerSize) {
            if (bestFit == nullptr || current->remainingSpace < bestFit->remainingSpace) {
                bestFit = current;
                bestIndex = currentIndex;
            }
        }
        current = current->next;
        currentIndex++;
    }
    
    if (bestFit != nullptr) {
        bestFit->remainingSpace -= containerSize;
        return bestIndex;
    }
    
    return -1;
}

int Train::totalRemainingSpace() {
    Train::TrainCar* current = head->next;
    int totalSpace = 0;

    while (current != nullptr) {
        totalSpace += current->remainingSpace;
        current = current->next;
    }
    return totalSpace;
}
