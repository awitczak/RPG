#include "battleLog.hpp"

using namespace std;

class battleLog;

battleLog::battleLog()
{
    head = tail = NULL;
    cnt = 0;
}
battleLog::~battleLog()
{
    battleList *el;
    while (head)
    {
        el = head->next;
        delete head;
        head = el;
    }
}
// returning list size
unsigned battleLog::size()
{
    return cnt;
}
// adding element at the front of the list
battleList *battleLog::push_head(battleList *el)
{
    if (cnt == 10) {
        rmTail();
    }
    el->next = head;
    head = el;
    if (!tail)
        tail = head;
    cnt++;
    return head;
}
// adding elemet at the end of the list
battleList *battleLog::push_tail(battleList *el)
{
    if (tail)
        tail->next = el;
    el->next = NULL;
    tail = el;
    if (!head)
        head = tail;
    cnt++;

    return tail;
}
// adding an element el1 after el2
battleList *battleLog::insert(battleList *el1, battleList *el2)
{
    el1->next = el2->next;
    el2->next = el1;

    if (!(el1->next))
        tail = el1;
    cnt++;
    return el1;
}
// deleting the first element of the list
battleList *battleLog::rmHead()
{
    battleList *el;
    if (head)
    {
        el = head;
        head = head->next;
        if (!head)
            tail = NULL;
        cnt--;
        return el;
    }
    else
        return NULL;
}
// deleting the last element of the list
battleList *battleLog::rmTail()
{
    battleList *el;
    if (tail)
    {
        el = tail;
        if (el == head)
            head = tail = NULL;
        else
        {
            tail = head;
            while (tail->next != el)
                tail = tail->next;
            tail->next = NULL;
        }
        cnt--;
        return el;
    }
    else
        return NULL;
}
// deleting el element of the list
battleList *battleLog::erase(battleList *el)
{
    battleList *el1;
    if (el == head)
        return rmHead();
    else
    {
        el1 = head;
        while (el1->next != el)
            el1 = el1->next;
        el1->next = el->next;
        if (!(el1->next))
            tail = el1;
        cnt--;
        return el;
    }
}
// returning nth element of the list
battleList *battleLog::index(int n)
{
    battleList *el;
    if ((!n) || (n > cnt))
        return NULL;
    else if (n == cnt)
        return tail;
    else
    {
        el = head;
        while (--n)
            el = el->next;
        return el;
    }
}
// displaying the list
void battleLog::showElements()
{
    battleList *el;
    if (!head)
        cout << "List is empty." << endl;
    else
    {
        el = head;
        while (el)
        {
            cout << "Battle: " << el->nameHero << " vs " << el->nameMonster << "\t\t | Result: " << el->result << "\t| Battle ID: " << el->key << endl;
            el = el->next;
        }
    }
}
