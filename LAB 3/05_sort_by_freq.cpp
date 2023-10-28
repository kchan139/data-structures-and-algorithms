#include <vector>

struct Element 
{
    int value;
    int frequency;
    int index;  
};

bool compareFrequency(const Element& a, const Element& b) 
{
    if (a.frequency == b.frequency)
        return a.index < b.index; 
    return a.frequency > b.frequency;  
}

void sortByFrequency(int* arr, int n) 
{
    vector<Element> elements;
    for (int i = 0; i < n; ++i) 
    {
        bool found = false;
        for (auto & element : elements) 
        {
            if (element.value == arr[i]) 
            {
                element.frequency++;
                found = true;
                break;
            }
        }
        if (!found)
            elements.push_back({arr[i], 1, i});  
    }

    sort (elements.begin(), elements.end(), compareFrequency);

    int index = 0;
    for (const auto& element : elements)
        for (int i = 0; i < element.frequency; ++i) 
            arr[index++] = element.value;
}
