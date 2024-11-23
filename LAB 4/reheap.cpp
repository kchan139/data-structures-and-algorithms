void reheapDown(int maxHeap[], int numberOfElements, int index) 
{
    int largerChild;
    int item = maxHeap[index];

    while (index < numberOfElements / 2) 
    {
        int leftChild = 2 * index + 1;
        int rightChild = leftChild + 1;

        if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[leftChild])
            largerChild = rightChild;
        else
            largerChild = leftChild;

        if (item >= maxHeap[largerChild])
            break;

        maxHeap[index] = maxHeap[largerChild];
        index = largerChild;
    }

    maxHeap[index] = item;
}

void reheapUp(int maxHeap[], int numberOfElements, int index) 
{
    int parent = (index - 1) / 2;
    int newItem = maxHeap[index];

    while (index > 0 && newItem > maxHeap[parent]) 
    {
        maxHeap[index] = maxHeap[parent];
        index = parent;
        parent = (index - 1) / 2;
    }

    maxHeap[index] = newItem;
}