void insert(int key) 
{
    int index = hash(key);
    data[index].push_back(key);
}

void remove(int key) 
{
    int index = hash(key);
    list<int>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
    {
        if (*it == key)
        {
            data[index].erase(it);
            break;
        }
    }
    if (it == data[index].end())
        throw "Not found";
}

bool search(int key) 
{
    int index = hash(key);
    return find(data[index].begin(), data[index].end(), key) != data[index].end();
}