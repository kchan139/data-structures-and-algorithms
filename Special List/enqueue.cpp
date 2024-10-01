void enqueue (const E& it)
{
    Assert (((rear + 2) % maxSize) != front, "Queue is full");
    rear = (rear + 1) % maxSize;
    listArray[rear] = it;
}