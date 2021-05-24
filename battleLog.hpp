#ifndef BATTLE_LOG_HPP
#define BATTLE_LOG_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

struct battleList
{
    battleList *next;
    int key;
    string nameHero;
    string nameMonster;
    string result;
};

class battleLog
{
public:
    battleList *head, *tail;
    int cnt;

    battleLog();
    ~battleLog();
    // returning list size
    unsigned size();
    // adding element at the front of the list
    battleList *push_head(battleList *el);
    // adding elemet at the end of the list
    battleList *push_tail(battleList *el);
    // adding an element el1 after el2
    battleList *insert(battleList *el1, battleList *el2);
    // deleting the first element of the list
    battleList *rmHead();
    // deleting the last element of the list
    battleList *rmTail();
    // deleting el element of the list
    battleList *erase(battleList *el);
    // returning nth element of the list
    battleList *index(int n);
    // displaying the list
    void showElements();
    void initializingList();
};

#endif