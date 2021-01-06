#include <iostream>
using namespace std;
template <class t>
class linked {
    struct list { t item; list* next; };
    list* head;
    int length;
public:
    linked() :head(NULL), length(0) {                 }
    bool is_empty()
    {
        return length == 0;
    }

    void front_add(t n_item)
    {
        list* new_list = new list;
        new_list->item = n_item;
        new_list->next = head;
        head = new_list;
        length++;
    }

    void back_add(t n_item)
    {
        if (is_empty())
        {
            list* new_list = new list;
            new_list->item = n_item;
            new_list->next = head;
            head = new_list;
            length++;
            return;
        }
        list* new_list = new list;
        new_list->item = n_item;
        list* add = head;
        for (int i = 0; i < length - 1; i++)
        {
            add = add->next;
        }
        add->next = new_list;
        new_list->next = NULL;
        length++;
    }

    void display()
    {
        list* dis = head;
        cout << "Items[";
        for (int i = 0; i < length; i++)
        {
            cout << dis->item;
            dis = dis->next;
        }
        cout << "]" << endl;
    }

    void search(int ex_item)
    {
        list* sea = head;
        for (int i = 0; i < length; i++)
        {
            if (sea->item == ex_item)
            {
                cout << "The item is here in Index :  " << i << endl;
                return;
            }
            sea = sea->next;
        }
        cout << "It isn't exist...." << endl;
    }

    void front_delete()
    {
        if (is_empty())
        {
            cout << "The list is Empity can't Delete..." << endl;
            return;
        }
        list* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void back_delete(int index)
    {
        if (is_empty() || index >= length)
        {
            cout << "The list is Empty , The Index biger or Lower than Length can't Delete..." << endl;
            return;
        }
        if (index < length) {
            list* cur, * pre;
            cur = head->next;
            pre = head;
            for (int i = 0; i < index - 1; i++)
            {
                pre = pre->next;
                cur = cur->next;
            }
            pre->next = cur->next;
            delete cur;
            length--;
        }
    }
    void reverse()
    {
        list* cur, * perv, * nextt;
        cur = head;
        perv = NULL;
        nextt = cur->next;
        for (int i = 0; i < length; i++)
        {
            nextt = cur->next;
            cur->next = perv;
            perv = cur;
            cur = nextt;
        }
        head = perv; w_
    }
};

class doubly_linked
{
    struct list { int item; list* next, * pre; };    list* head, * last;    int length;
public:
    void back_add(int n_item);
    bool is_empty();
    void front_add(int n_item);
    void front_delete();

    doubly_linked();
    ~doubly_linked();
};

void doubly_linked::back_add(int n_item)
{
    list* new_list = new list;
    new_list->item = n_item;
    new_list->next = NULL;
    new_list->pre = last;
    last->next = new_list;
    last = new_list;
    length++;
    if (is_empty())
        head = new_list;

}

bool doubly_linked::is_empty()
{
    return length == 0;
}

void doubly_linked::front_add(int n_item)
{
    list* new_list = new list;
    new_list->item = n_item;
    new_list->next = head;
    new_list->pre = NULL;
    head = new_list;
    length++;
    if (is_empty())
        last = new_list;


}

void doubly_linked::front_delete()
{
    list* cur;
    cur = head;
    head = head->next;
    head->pre = NULL;
    cur->next = NULL;
    delete cur;
    length--;
}

doubly_linked::doubly_linked() :head(NULL), last(NULL), length(0)
{
}

doubly_linked::~doubly_linked()
{
}
int main()
{
    linked<int>l1;
    l1.back_add(9);
    l1.back_add(7);
    l1.back_add(8);
    l1.front_add(11);
    l1.reverse();
    l1.display();
    l1.back_delete(8);
    l1.display();
}

