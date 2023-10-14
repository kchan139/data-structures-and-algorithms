void push(T item) 
{
    list.add(item);
}

T pop() 
{
    if (empty()) 
        return T();  
    
    return list.removeAt(list.size() - 1);
}

T top() 
{
    if (empty()) 
        return T();  
    
    return list.get(list.size() - 1);
}

bool empty() 
{
    return list.empty();
}

int size() 
{
    return list.size();
}

void clear() 
{
    list.clear();
}