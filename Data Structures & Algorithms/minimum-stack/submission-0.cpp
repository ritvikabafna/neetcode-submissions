class MinStack {
public:
 stack<int> s;
        stack<int> mini;
    MinStack() {
       
    }
    
    void push(int val) {
       if(s.empty()){
        s.push(val);
        mini.push(val);
       } 
       else{
        s.push(val);
        mini.push(min(mini.top(),val));
       }
    }
    
    void pop() {
        if(!s.empty()){
        s.pop();
        mini.pop();
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top();
        }
    }
    
    int getMin() {
        if(!mini.empty())
            return mini.top();
    }
};
