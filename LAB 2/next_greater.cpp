vector<int> nextGreater(const vector<int>& arr) 
{
    int n = arr.size();
    vector<int> result(n, -1); 
    stack<int> st;  

    for (int i = 0; i < n; ++i) 
    {
        while (!st.empty() && arr[i] > arr[st.top()]) 
        {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}