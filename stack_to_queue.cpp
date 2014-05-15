#include <stack>
#include <stdexcept>

template <class T> class Queue{
    public:
        /**Queue(){}
        ~Queue(){}*/
        void appendTail(const T&);
        T deleteHead();
        bool empty(){
            return stack1.empty()&&stack2.empty();
        }
    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
};

template <class T>
void Queue<T>::appendTail(const T& node){
    stack1.push(node);
}

template <class T>
T Queue<T>::deleteHead(){
    if(!stack2.empty()){
        T s = stack2.top();
        stack2.pop();
        return s;
    }else{
        if(stack1.empty())
            throw std::runtime_error("no elememts!");
        while(stack1.size() > 1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        T s = stack1.top();
        stack1.pop();
        return s;
    }
}
