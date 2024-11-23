#include <queue>
class file 
{
    public:
        int    priority;
        string fileName;
        int    timestamp;
        
        file (int priority, string fileName, int timestamp) : 
              priority(priority), fileName(fileName), timestamp(timestamp) {}

        bool operator<(const file & other) const 
        {
            if (priority != other.priority) 
                return priority < other.priority;
            return timestamp > other.timestamp;
        }
};

class PrinterQueue
{
    priority_queue<file> qq;
    int timestamp;

    public:
        PrinterQueue() : timestamp(0) {}
        void addNewRequest(int priority, string fileName)
        {
            qq.push(file(priority, fileName, timestamp++));
        }

        void print()
        {
            if (qq.empty()) 
            {
                cout << "No file to print" << endl;
                return;
            }
            cout << qq.top().fileName << endl;
            qq.pop();
        }
};