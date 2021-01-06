#include <iostream>
using namespace std;
const int max_s = 100;
template<class t>
class stack {
    t item[max_s];
    int top;
public:
    t ldi;
    stack() :top(-1) { ldi = 0; }
    bool isfull() {
        return top == max_s-1;
    }
    bool isempty() {
        return top == -1;
    }
    t get_top() {
        if(!isempty());
        return item[top];
    }
    
    void push(t newitem) {
        if (!isfull()) {
            top++;
            item[top] = newitem;
        }
        else
            cout << "Stack is Full can't Push....." << endl;

    }
    void pop() {
        if (!isempty()) {
            ldi = top;
            top--;
        }
        else
            cout << "Stack is Empty can't pop....." << endl;
    }

    void display() {
        if (!isempty()) {
            for (int i = top; i >= 0; i--) {
                cout << "[" << item[i] << "]" << endl;
            }
        }
        else
            cout << "The Stack is Empty can't Display...." << endl;
    }
};
int main()
{
    stack<int>  q1;
    q1.push(6);
    q1.push(3);
    q1.push(0);
    q1.push(61);
    q1.display();
    q1.pop();
    cout << q1.get_top() << endl;

}


