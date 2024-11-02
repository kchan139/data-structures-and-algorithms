#include <algorithm>

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    
    int peopleCount = 0;
    int personIndex = 0;
    int rsize = rooms.size(), psize = people.size();
    
    for (int i = 0; i < rsize && personIndex < psize; i++) {
        if (abs(rooms[i] - people[personIndex]) <= k) {
            peopleCount++;
            personIndex++;
        }
        else if (rooms[i] < people[personIndex] - k)
            continue;
            
        else if (rooms[i] > people[personIndex] + k) {
            personIndex++;
            i--;
        }
    }
    
    return peopleCount;
}