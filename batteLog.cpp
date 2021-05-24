#include <iostream>
#include <string.h>

#include "battleLog.hpp"

using namespace std;

struct battleLog_element
{
    battleLog *next;
    int key;
    string monsterName;
    string heroName;
    string result;
};

class battleLog
{
    battleLog_element *head, *tail;
    int cnt;

    public:
    battleLog()
    {
        head = tail = NULL;
        cnt = 0;
    }
    ~battleLog() {
        battleLog_element *el;
        while (head)
        {
            el = head -> next;
            delete head;
            head = el;
        }
    }
    // returning list size
    unsigned size() 
    {
        return cnt;
    }
    // adding element at the front of the list
    battleLog_element *push_head(battleLog_element *el)
    {
        el -> next = head;
        head = el;
        if (!tail) tail = head;
        cnt++;
        return head;
    }
    // adding elemet at the end of the list
    battleLog_element *push_tail(battleLog_element *el) 
    {
        if (tail) tail -> next = el;
        el -> next = NULL;
        tail = el;
        if (!head) head = tail;
        cnt++;

        return tail;
    }
    // adding an element el1 after el2
    battleLog_element *insert(battleLog_element *el1, battleLog_element *el2)
    {
        el1 -> next = el2 -> next;
        el2 -> next = el1;

        if (!(el1 -> next)) tail = el1;
        cnt++;
        return el1;
    }
    // deleting the first element of the list
    battleLog_element *rmHead()
    {
        battleLog_element *el;
        if (head)
        {
            el = head;
            head = head -> next;
            if (!head) tail = NULL;
            cnt--;
            return el;
        }
        else return NULL;
    }
    // deleting the last element of the list
    battleLog_element *rmTail()
    {
        battleLog_element *el;
        if (tail)
        {
            el = tail;
            if (el == head) head = tail = NULL;
            else 
            {
                tail = head;
                while (tail -> next != el) tail = tail -> next;
                tail -> next = NULL;
            }
            cnt--;
            return el;
        }
        else return NULL;
    }
    // deleting el element of the list
    battleLog_element *erase(battleLog_element *el) 
    {
        battleLog_element *el1;
        if (el == head) return rmHead();
        else 
        {
            el1 = head;
            while (el1 -> next != el) el1 = el1 -> next;
            el1 -> next = el -> next;
            if (!(el1 -> next)) tail = el1;
            cnt--;
            return el;
        }
    }
    // returning nth element of the list
    battleLog_element *index(int n)
    {
        first_el *el;
        if ((!n) || (n > cnt)) return NULL;
        else if (n == cnt) return tail;
        else 
        {
            el = head;
            while (--n) el = el -> next;
            return el;
        }
    }
    // displaying the list
    void showKeys()
    {
        battleLog_element *el;
        if (!head) cout << "List is empty." << endl;
        else 
        {
            el = head;
            while (el)
            {
                cout << el -> key << " ";
                el = el -> next;
            }
            cout << endl;
        }
    }
    void showNames() 
    {
        battleLog_element *el;
        if (!head) cout << "List is empty." << endl;
        else 
        {
            el = head;
            while (el)
            {
                cout << el -> name << " ";
                el = el -> next;
            }
            cout << endl;
        }
    }
    void showElements() 
    {
        battleLog_element *el;
        if (!head) cout << "List is empty." << endl;
        else 
        {
            el = head;
            while (el)
            {
                cout << "Name: " << el -> name << " | Key: " << el -> key << " ";
                el = el -> next;
            }
            cout << endl;
        }
    }
};

int main() {
    battleLog sl;
    battleLog_element *p;
    int i;

    cout << "List should be empty: ";
    sl.showKeys();

    // adding 5 el at front of list
    for (i = 1; i <= 5; i++) 
    {
        p = new first_el;
        p -> key = i;
        cout << "Enter name of the element: ";
        cin >> p -> name;
        sl.push_head(p);
    }

    cout << "Now there should be " << sl.size() << " elements in the lsit: ";
    sl.showElements();
    cout << endl;
    cout << "Program also displays single fields of the elements" << endl;
    cout << "Keys: ";
    sl.showKeys();
    cout << endl;
    cout << "Names: ";
    sl.showNames();
    cout << endl;

    

    return 0;
}