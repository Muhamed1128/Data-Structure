#include <iostream>
#include<cassert>
using namespace std;
const int max_s = 7;
template<class t>
class queue {
    t item[max_s];
    t cure1;
    int rear;
    int front;
    int count;
public:
    t ldi;
    queue() :front(0), rear(4), count(0), cure1(0) { ldi = 0; }
    bool isfull() {
        return count == max_s;
    }
    bool isempty() {
        return count == 0;
    }
    t getfront() {
        assert(!isempty());
        return item[front];
    }
    t getrear() {
        assert(!isempty());
        return item[rear];
    }
    void enqueue(t newitem) {
        if (!isfull()) {
            rear = (rear + 1) % max_s;
            item[rear] = newitem;
            count++;
        }
        else
            cout << "Queue is Full can't enqueue....." << endl;

    }
    void dequeue() {
        if (!isempty()) {
            ldi = item[front];
            front = (front + 1) % max_s;
            count--;
        }
        else
            cout << "Queue is Empty can't dequeue....." << endl;
    }

    void display() {
        if (!isempty()) {
            cure1 = front;
            for (int i = count; i > 0; i--) {
                cout << "[" << item[cure1] << "]" << endl;
                cure1 = (cure1 + 1) % max_s;
            }
        }
        else
            cout << "The Queue is Empty can't Display...." << endl;
    }
};
int main()
{
    queue<int>  q1;
    q1.enqueue(6);
    q1.enqueue(3);
    q1.enqueue(0);
    q1.enqueue(61);
    q1.display();
    q1.dequeue();
    cout << q1.getfront() << endl;
    cout << q1.getrear() << endl;
}
