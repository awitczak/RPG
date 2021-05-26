#include "loot.hpp"

using namespace std;

void Items::disp_all_items()
{
    for (int i = 0; i < loadingItems.Item.size(); i++)
    {
        cout << "Item name: \t" << loadingItems.Item[i].name << endl;
        cout << "Strength: \t" << loadingItems.Item[i].strength << endl;
        cout << "Dexterity: \t" << loadingItems.Item[i].dexterity << endl;
        cout << "Endurance: \t" << loadingItems.Item[i].endurance << endl;
        cout << "Intelligence: \t" << loadingItems.Item[i].intelligence << endl;
        cout << "Charisma: \t" << loadingItems.Item[i].charisma << endl;
        cout << "HP: \t\t" << loadingItems.Item[i].HP << endl;
        cout << endl;
    }
    system("pause");
    system("cls");
}
void Items::lvl_check(HeroCreation &hero) // hero can only equip items of a smaller or equal level to his experience level
{
}
int Items::monsterLootDetermination()
{
    int determinedItem;
    int dropRate;
    // the item is chosen randomly and then the dropRate parameter helps to determine if the monster will drop it or not
    determinedItem = rand() % itemCount;
    dropRate = loadingItems.Item[determinedItem].dropRate;

    if (1 == 1) // rand() % (100 / dropRate) + 1
    { // for instance 100 / 20 = 5, so the item drop chance is 1/5 -> 20%
        // if dropRate is lower, then 100 / 4 = 25, so the item drop chance is 1/25 -> 4%
        cout << "Determined item ID is : " << determinedItem << endl;
        system("pause");
        return determinedItem;
    }
    else
    {
        return 0;
    }
}
bool Items::gettingLoot(HeroCreation &hero)
{   
    int item_ID = monsterLootDetermination();
    if (item_ID != 0)
    {
        hero.inventory.push_back(loadingItems.Item[item_ID]);
        cout << "You have found the following item: " << loadingItems.Item[item_ID].name << endl;

        return true;
    }
    else
    {
        cout << "Sadly the monster did not have any useful items and you walk away with nothing but experience." << endl;
        return false;
    }
}
