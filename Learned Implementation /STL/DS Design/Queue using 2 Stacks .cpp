struct Queue_using_stack {
    stack<int> s1,s2;
    void push(int x){
        s2.push(x);
    }
    int pop(){
        if(!s1.empty()) {int t=s1.top();s1.pop();return t;}
        else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            if(!s1.empty()) {int t=s1.top();s1.pop();return t;}
        }
    }
    int front(){
        if(!s1.empty()) return s1.top();
        else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            if(!s1.empty()) return s1.top();
        }
    }

};
