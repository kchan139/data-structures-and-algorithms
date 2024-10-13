string removeDuplicates(string S){
    /*TODO*/
    stack<char> st;
    
    for (char c : S) {
        if (!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}