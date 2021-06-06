#include "equipmentManagement.hpp"

using namespace std;

void equipment::create_list(items addThisItem)
{
    struct node *s, *temp;
    temp = new (struct node);

    temp->listNum = cnt;
    temp->name = addThisItem.name;
    temp->strength = addThisItem.strength;
    temp->dexterity = addThisItem.dexterity;
    temp->endurance = addThisItem.endurance;
    temp->intelligence = addThisItem.intelligence;
    temp->charisma = addThisItem.charisma;
    temp->HP = addThisItem.HP;
    temp->ID = addThisItem.ID;
    temp->reqLvl = addThisItem.reqLvl;

    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }

    cnt++;
} /** Insertion at the beginning*/
void equipment::add_begin(items addThisItem)
{
    if (start == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node *temp;
    temp = new (struct node);
    temp->prev = NULL;
    
    temp->listNum = cnt;
    temp->name = addThisItem.name;
    temp->strength = addThisItem.strength;
    temp->dexterity = addThisItem.dexterity;
    temp->endurance = addThisItem.endurance;
    temp->intelligence = addThisItem.intelligence;
    temp->charisma = addThisItem.charisma;
    temp->HP = addThisItem.HP;
    temp->ID = addThisItem.ID;
    temp->reqLvl = addThisItem.reqLvl;

    temp->next = start;
    start->prev = temp;
    start = temp;
    cout << "Element Inserted" << endl;

    cnt++;
} /** Insertion of element at a particular position*/
void equipment::add_after(items addThisItem, int pos)
{
    if (start == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node *temp, *q;
    int i;
    q = start;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout << "There are less than ";
            cout << pos << " elements." << endl;
            return;
        }
    }
    temp = new (struct node);
    
    temp->listNum = cnt;
    temp->name = addThisItem.name;
    temp->strength = addThisItem.strength;
    temp->dexterity = addThisItem.dexterity;
    temp->endurance = addThisItem.endurance;
    temp->intelligence = addThisItem.intelligence;
    temp->charisma = addThisItem.charisma;
    temp->HP = addThisItem.HP;
    temp->ID = addThisItem.ID;
    temp->reqLvl = addThisItem.reqLvl;


    if (q->next == NULL)
    {
        q->next = temp;
        temp->next = NULL;
        temp->prev = q;
    }
    else
    {
        temp->next = q->next;
        temp->next->prev = temp;
        q->next = temp;
        temp->prev = q;
    }
    cout << "Element Inserted" << endl;

    cnt++;
} /** Deletion of element from the list*/
void equipment::delete_element(items addThisItem)
{
    struct node *tmp, *q; /*first element deletion*/
    if (start->listNum == addThisItem.ID)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout << "Element Deleted" << endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    { /*Element deleted in between*/
        if (q->next->listNum == addThisItem.ID)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout << "Element Deleted" << endl;
            free(tmp);
            return;
        }
        q = q->next;
    } /*last element deleted*/
    if (q->next->listNum == addThisItem.ID)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout << "Element Deleted" << endl;
        return;
    }
    cnt--;
} /** Display elements of Doubly Link List*/
void equipment::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout << "The hero has no items equipped!" << endl;
        return;
    }
    q = start;
    cout << "The hero has the following items equipped: " << endl;
    while (q != NULL)
    {
        cout << q->listNum << ". ";
        cout << q->name << endl;
        cout << "\tItem ID: \t" << q->ID << endl;
        cout << "\tStrength: \t" << q->strength << endl;
        cout << "\tDexterity: \t" << q->dexterity << endl;
        cout << "\tEndurance: \t" << q->endurance << endl;
        cout << "\tIntelligence: \t" << q->intelligence << endl;
        cout << "\tCharisma: \t" << q->charisma << endl;
        cout << "\tHP: \t" << q->HP << endl;
        cout << "\tRequired level: \t" << q->reqLvl << endl;

        q = q->next;
    }
    cout << endl;
} /** Number of elements in Doubly Link List*/
void equipment::count()
{
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout << "Number of elements are: " << cnt << endl;
} /** Reverse Doubly Link List*/
void equipment::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout << "List Reversed" << endl;
}
bool equipment::findingItem(string itemName, vector<items> vecItem, int i) 
{   
    int vectorSize = vecItem.size();
    if (i >= vectorSize) 
    {
        return false;
    }
    if (vecItem[i].name != itemName)
    {
        return findingItem(itemName,vecItem,i+1);
    }
    if (vecItem[i].name == itemName)
    {
        cout << "The found item is: " << vecItem[i].name << endl;
        return true;
    }
    return false;
}