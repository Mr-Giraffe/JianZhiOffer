#include <stack>
#include <assert.h>
using std::stack;

template <class T> class stack_with_min{
    public:
        void push(const T&);
        void pop();
        const T& min();
    private:
        stack<T> m_data;
        stack<T> m_min;
};

template <class T>
void stack_with_min<T>::push(const T &value){
    m_data.push(value);
    if(m_min.size() == 0||value<m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <class T>
void stack_with_min<T>::pop(){
    assert(m_data.size()&&m_min.size());
    m_data.pop();
    m_min.pop();
}

template <class T>
const T& stack_with_min<T>::min(){
    assert(m_data.size()&&m_min.size());
    return m_min.top();
}
