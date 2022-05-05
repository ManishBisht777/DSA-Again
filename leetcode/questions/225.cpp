class MyStack {
public:
    
    queue<int> q;
    
    void push(int x) {
        q.push(x);
        for(int i=1; i<q.size();i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int item=q.front();
        q.pop();
        return item;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};