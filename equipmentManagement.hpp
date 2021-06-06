#ifndef EQUIPMENT_MANAGEMENT_HPP
#define EQUIPMENT_MANAGEMENT_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "attributes.hpp"

/** Node Declaration*/ 
struct node
{   
    int listNum;
    // item attributes below
    std::string name;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    int HP;
    int ID;
    int reqLvl;

    struct node *next;
    struct node *prev;
} * start; /*Class Declaration*/
class equipment : public Attributes
{
public:
    int cnt = 0;
    void create_list(items addThisItem);
    void add_begin(items addThisItem);
    void add_after(items addThisItem, int position);
    void delete_element(items addThisItem);
    void search_element(items addThisItem);
    void display_dlist();
    void count();
    void reverse();
    equipment() { start = NULL; }

    void dispAttributes(){};
    bool findingItem(string itemName, vector<items> vecItem, int i);
};

#endif