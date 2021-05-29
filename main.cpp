#include <iostream>
#include <fstream>
#include <time.h>

#include "attributes.cpp"
#include "fileManagement.cpp"
#include "HeroCreation.cpp"
#include "MonsterCreation.cpp"
#include "heroClasses.cpp"
#include "battle.cpp"
#include "battleLog.cpp"
#include "loot.cpp"
#include "equipmentManagement.cpp"

using namespace std;

int main(void)
{
    srand(time(NULL));
    system("cls");
    string n = ""; // hero name
    HeroCreation hero(n, 0, 0, 0, 0, 0);

    // battle log
    battleLog bl;
    battleList *p;

    // equiping items
    equipment_DoubleLList EQ;

    int userChoice;
    bool exitGame = false;
    bool monstersCreated = false;
    int battleLogCounter = 0;

    while (exitGame == false)
    {
        system("cls");
        cout << "\tWelcome!" << endl;

        if (n.length() != 0)
        {
            hero.dispAttributes();
        }

        cout << "\n\tPlease choose one of the following options: " << endl;
        cout << "\t\t1. Create new character" << endl;
        cout << "\t\t2. Load existing character" << endl;
        cout << "\t\t3. Generate monsters" << endl;
        cout << "\t\t4. Go on an adventure" << endl;
        cout << "\t\t5. Display the session battle log" << endl;
        cout << "\t\t6. Display the items available to obtain in the game" << endl;
        cout << "\t\t7. Hero inventory" << endl;
        cout << "\t\t8. How to play" << endl;
        cout << "\t\t9. Exit" << endl;
        cout << "\n\tPlease enter: ";
        cin >> userChoice;

        while (cin.fail())
        {
            cout << "Error! Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> userChoice;
            system("CLS");
        }

        if (userChoice == 1)
        { // creating character
            int s, d, e, i, c, classChoice;
            enum heroClass
            {
                warrior_class = 1,
                thief_class = 2,
                berserk_class = 3,
                mage_class = 4
            };

            cout << "Please select the name for your character: ";
            cin >> n;
            cout << endl;
            cout << "Please select the strength stat: ";
            cin >> s;
            cout << endl;
            while (s < 1 || s > 10)
            {
                cout << "The given value has to be in the range 1-10!" << endl;
                cout << "Try again." << endl;
                cout << "Please select the strength stat: ";
                cin >> s;
                cout << endl;
            }
            cout << "Please select the dexterity stat: ";
            cin >> d;
            cout << endl;
            while (d < 1 || d > 10)
            {
                cout << "The given value has to be in the range 1-10!" << endl;
                cout << "Try again." << endl;
                cout << "Please select the dexterity stat: ";
                cin >> d;
                cout << endl;
            }
            cout << "Please select the endurance stat: ";
            cin >> e;
            cout << endl;
            while (e < 1 || e > 10)
            {
                cout << "The given value has to be in the range 1-10!" << endl;
                cout << "Try again." << endl;
                cout << "Please select the endurance stat: ";
                cin >> e;
                cout << endl;
            }
            cout << "Please select the intelligence stat: ";
            cin >> i;
            cout << endl;
            while (i < 1 || i > 10)
            {
                cout << "The given value has to be in the range 1-10!" << endl;
                cout << "Try again." << endl;
                cout << "Please select the intelligence stat: ";
                cin >> i;
                cout << endl;
            }
            cout << "Please select the charisma stat: ";
            cin >> c;
            cout << endl;
            while (c <= 0 || c > 10)
            {
                cout << "The given value has to be in the range 1-10!" << endl;
                cout << "Try again." << endl;
                cout << "Please select the charisma stat: ";
                cin >> c;
                cout << endl;
            }

            hero.createHero(n, s, d, e, i, c);
            hero.dispAttributes();
            system("pause");

            cout << endl
                 << "Choose the class:" << endl;
            cout << "1. Warrior" << endl;
            cout << "2. Thief" << endl;
            cout << "3. Berserker" << endl;
            cout << "4. Mage" << endl;

            cin >> classChoice;

            switch (classChoice)
            {
            case warrior_class:
            {
                Warrior w;
                w.increaseAttribute(hero);
                break;
            }
            case thief_class:
            {
                Thief t;
                t.increaseAttribute(hero);
                break;
            }
            case berserk_class:
            {
                Berserk b;
                b.increaseAttribute(hero);
                break;
            }
            case mage_class:
            {
                Mage m;
                m.increaseAttribute(hero);
                break;
            }
            default:
                cout << "Error, wrong entry!" << endl;
                exit(0);
            }

            hero.dispAttributes();

            cout << "Do you want to save the character? (y/n)" << endl;
            char userDecision;
            cin >> userDecision;

            if (userDecision == 'y')
            {
                hero.list_update();
                hero.save(false);
            }
            else if (userDecision == 'n')
            {
                cout << "Character has not been saved!" << endl;
                system("pause");
                n.clear(); // clearing contents
                continue;
            }
            else if (!isalpha(userDecision))
                cout << "Wrong entry.";
        }
        else if (userChoice == 2)
        {
            // loading character
            bool noSuchHero = true;
            vector<string> listOfCharacters;
            system("cls");
            cout << "You chose to load an existing character." << endl
                 << endl;

            FileManagement fileData;
            listOfCharacters = fileData.dispList();

            if (listOfCharacters.size() == 0)
            {
                cout << "You have to create a character first!" << endl;
                system("pause");
                continue;
            }

            cout << "Please enter the name of your character: ";
            cin >> n;

            for (int i = 0; i < listOfCharacters.size(); i++)
            {
                if (listOfCharacters[i] == n)
                {
                    noSuchHero = false;
                }
            }

            if (noSuchHero)
            {
                cout << "No such hero detected." << endl;
                system("pause");
                n.clear(); // clearing contents
                continue;
            }
            else
            {
                hero.createHero(n, 0, 0, 0, 0, 0);
                hero.load(false, 0);
                hero.dispAttributes();
                system("pause");
            }
        }
        else if (userChoice == 3)
        { // generating monsters
            system("cls");
            int monsterHowMany = 5;
            cout << "Proceeding to create five monsters." << endl;
            MonsterCreation monster[monsterHowMany];

            for (int i = 0; i < monsterHowMany; i++)
            {
                monster[i].save(true);
            }

            monstersCreated = true;
        }
        else if (userChoice == 4)
        { // battle
            if (monstersCreated)
            {
                if (n.length() == 0)
                {
                    cout << "Wrong hero name, create or load an existing hero." << endl;
                    system("pause");
                    continue;
                }
                cout << "Chosen hero: " << n << endl;
                system("pause");
                MonsterCreation monster[5];

                int whichMonster = rand() % 5;
                // loading the characters
                hero.load(false, 0);
                monster[whichMonster].load(true, whichMonster);

                battleMechanics battle;
                if (battle.battleResult(battle.battleSimulation(hero, monster[whichMonster]), hero, monster[whichMonster], hero.endurance))
                { // battle log hero wins
                    battleLogCounter++;
                    p = new battleList;
                    p->key = battleLogCounter;
                    p->nameHero = hero.name;
                    p->nameMonster = monster[whichMonster].name;
                    p->result = "Hero won.";
                    bl.push_head(p);
                }
                else
                { // battle log monster wins
                    battleLogCounter++;
                    p = new battleList;
                    p->key = battleLogCounter;
                    p->nameHero = hero.name;
                    p->nameMonster = monster[whichMonster].name;
                    p->result = "Monster won.";
                    bl.push_head(p);
                }
                system("pause");
            }
            else
            {
                system("cls");
                cout << "Going on an adventure!" << endl;
                Sleep(1000);
                cout << "Walking..." << endl;
                Sleep(1000);
                cout << "Looking for monsters..." << endl;
                Sleep(1000);
                cout << "Walking..." << endl;
                Sleep(1000);
                cout << "Being bored..." << endl;
                Sleep(1000);

                cout << "Seems like there is nobody to fight with around, that is very odd!" << endl
                     << "You should consider adding monsters by using the 3rd option in the main menu" << endl
                     << "in order to have a chance to prove yourself worthy of being called a hero." << endl;

                system("pause");
            }
        }
        else if (userChoice == 5)
        {
            // battle log display
            if (bl.size() > 0 && bl.size() <= 10)
            {
                system("cls");
                bl.showElements();
                system("pause");
            }
            else if (bl.size() == 0)
            {
                cout << "The hero has not yet fought in any battle!" << endl;
                system("pause");
            }
        }
        else if (userChoice == 6)
        {
            // displaying all items available
            Items itemLoad;
            itemLoad.itemLoad();
            itemLoad.disp_all_items();
        }
        else if (userChoice == 7)
        {
            int eq_userChoice;
            int item_userChoice;
            vector<int> temp_itemID;
            int equipCnt = 0;
            bool itemExists = false;
            int item_pos = 0;

            system("cls");
            // displaying all items in inventory
            hero.dispInventory();

            for (int i = 0; i < hero.inventory.size(); i++)
            {
                temp_itemID.push_back(hero.inventory[i].ID);
            }

            cout << "Choose:" << endl;
            cout << "1. Equip item" << endl;
            cout << "2. View equipped items" << endl;
            cout << "3. Return to main menu" << endl;
            cout << "Please enter: ";
            cin >> eq_userChoice;

            if (eq_userChoice == 1)
            {
                cout << "Enter the ID of the item that you want to equip: ";
                cin >> item_userChoice;
                for (int i = 0; i < temp_itemID.size(); i++)
                {
                    if (temp_itemID[i] == item_userChoice)
                    {
                        item_pos = i;
                        itemExists = true;
                        break;
                    }
                    else
                    {
                        itemExists = false;
                    }
                }
                if (itemExists)
                {
                    if (hero.level >= hero.inventory[item_pos].reqLvl)
                    {
                        cout << "Equipping the selected item..." << endl;
                        if (equipCnt == 0)
                        {
                            EQ.create_list(hero.inventory[item_pos]);
                            // updating the hero statistics
                            hero.strength += hero.inventory[item_pos].strength;
                            hero.dexterity += hero.inventory[item_pos].dexterity;
                            hero.endurance += hero.inventory[item_pos].endurance;
                            hero.intelligence += hero.inventory[item_pos].intelligence;
                            hero.charisma += hero.inventory[item_pos].charisma;
                            hero.HP += hero.inventory[item_pos].HP;
                        }
                        else
                        {
                            EQ.add_begin(hero.inventory[item_pos]);
                            // updating the hero statistics
                            hero.strength += hero.inventory[item_pos].strength;
                            hero.dexterity += hero.inventory[item_pos].dexterity;
                            hero.endurance += hero.inventory[item_pos].endurance;
                            hero.intelligence += hero.inventory[item_pos].intelligence;
                            hero.charisma += hero.inventory[item_pos].charisma;
                            hero.HP += hero.inventory[item_pos].HP;
                        }
                        equipCnt++;
                    }
                    else 
                    {
                        cout << "The hero has to become more experienced before making use of such a powerful item." << endl;
                        system("pause");
                    }
                }
            }
            else if (eq_userChoice == 2)
            {
                system("cls");
                EQ.display_dlist();
                system("pause");
            }
            else if (eq_userChoice == 3)
            {
                // go back to menu
            }
            else
            {
                cout << "Invalid entry!";
                system("pause");
            }
        }
        else if (userChoice == 8)
        { // how to
            system("cls");
            cout << "In order to play the game, you have to start with creating your own hero (1st option)." << endl
                 << "To do that, you are required to type in the name of the hero, and then choose numbers from 0 to 10 for each attribute." << endl
                 << "The total sum of statistics in the case of your hero can not breach the number 35" << endl
                 << "so in order to gain an advantage, you can also choose a class, which will increase one of your attributes by 2." << endl
                 << endl
                 << "After hero creation, you can load (2nd option) the existing hero every time you decide to play the game." << endl
                 << "To load the hero, you have to type the name of one of the heroes visible in the displayed list." << endl
                 << endl
                 << "In order to go on an adventure, it is necessary for you to create the opponents (3rd option), which your hero will face." << endl
                 << "Now you are ready to participate in your first adventure (4th option)." << endl
                 << endl
                 << "During the monster encounter you will have 2 choices available, to fight with a melee weapon or by casting spells." << endl
                 << "The first option is influenced by the strength of your character and the other - with intelligence and also with the intelligence of your enemy," << endl
                 << "so that your spells, fireball in particular, are more effective against enemies who are not as astute as you in the ways of the arcane." << endl
                 << endl
                 << "When it comes to the spell choice, you have 3 spells available, which are: the before mentioned fireball, which deals damage once and takes a full turn to cast," << endl
                 << "a thunderstorm, which, casted once, will keep it's effect of damaging the enemy for the remaining turns of the battle." << endl
                 << "Third and last spell which is available as a resource for not only the mages around, is the divine intervention, which prevents the hero " << endl
                 << "from taking damage in the next turn and is not influenced by any attribute." << endl
                 << endl
                 << "It is important to note that in each battle you can cast only one spell, so be wary and choose wisely." << endl
                 << endl
                 << "The mechanic of turns is based on the endurance of your hero and the endurance of the monsters." << endl
                 << "Each turn, respectively, the hero's and monster's decrements and when it reaches 0 - the battle ends." << endl
                 << "Apart from attacking, you and the monster alike, are capable of dodging a melee attack, the higher the dexterity - the bigger the chance of a dodge to occur." << endl
                 << endl
                 << "You can gain experience by being successfull in combat, but slaughter is not allways necessary and you may find yourself sparing the beast." << endl
                 << endl
                 << "Good luck!" << endl
                 << endl
                 << "*Any existing bugs please report directly to the creator via email (awitczak@student.agh.edu.pl)." << endl
                 << "Existing issues: 1) sum of stats does not cap at 35" << endl
                 << "                 2) main.cpp needs rewriting" << endl;

            system("pause");
        }
        else if (userChoice == 9)
        { // quit
            system("cls");
            cout << "Shutting down..." << endl;
            exitGame = true;
        }
        else
        { // wrong entry
            system("cls");
            cout << "Not a valid choice! Error (A27).";
            Sleep(3000);
        }
    }
    return 0;
}