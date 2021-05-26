#include "fileManagement.hpp"

using namespace std;

void FileManagement::save(bool ifMonster)
{
    fstream characterFile;
    filename = name + ".txt";

    if (ifMonster)
    {
        filename = "monsters.txt";
        characterFile.open(filename, std::ios_base::app);
    }
    else
    {
        characterFile.open(filename, std::ios_base::out);
    }

    if (!characterFile)
        cout << "Error during the file creation!" << endl;
    else
        cout << "File created successfully!" << endl;

    characterFile << name << " ";
    characterFile << strength << " ";
    characterFile << dexterity << " ";
    characterFile << endurance << " ";
    characterFile << intelligence << " ";
    characterFile << charisma;

    if (!ifMonster)
    {
        characterFile << " ";
        characterFile << level << " ";
        characterFile << XP;
        cout << "Adding xp" << endl;
        system("pause");
    }

    if (ifMonster)
    {
        characterFile << endl;
    }

    cout << "Save successful!" << endl;

    characterFile.close();
}

void FileManagement::load(bool ifMonster, int whichMonster)
{
    filename = name + ".txt";

    if (ifMonster)
    {
        filename = "monsters.txt";
    }

    fstream characterFile;
    characterFile.open(filename, ios::in);

    if (ifMonster)
    {
        for (int i = 0; i < whichMonster; i++)
        {
            characterFile.ignore(50, '\n');
        }
    }

    if (characterFile.good())
    {
        system("cls");
        characterFile >> name;
        characterFile >> strength;
        characterFile >> dexterity;
        characterFile >> endurance;
        characterFile >> intelligence;
        characterFile >> charisma;
        if (!ifMonster)
        {
            characterFile >> level;
            characterFile >> XP;
        }
    }
    else
        cout << "File access forbidden!" << endl;

    characterFile.close();
}

void FileManagement::list_update()
{
    fstream characterFile;
    filename = "heroList.txt";

    characterFile.open(filename, std::ios_base::app);

    characterFile << name << endl;

    if (!characterFile)
        cout << "Error during the file creation!" << endl;
    else
        cout << "List updated successfully!" << endl;

    characterFile.close();
}

vector<string> FileManagement::dispList()
{
    vector<string> listOfCharacters;
    string line;
    int counter = 0;
    fstream characterFile;
    filename = "heroList.txt";

    characterFile.open(filename, std::ios_base::in);

    cout << "Existing characters: " << endl;
    while (getline(characterFile, line))
    {
        counter++;
        cout << counter << ". " << line << endl;
        listOfCharacters.push_back(line);
    }
    characterFile.close();

    return listOfCharacters;
}

int FileManagement::itemLoad()
{   
    int itemCount;
    filename = "items.txt";
    fstream itemFile;
    itemFile.open(filename, ios::in);

    if (itemFile.good())
    {   
        itemCount = 0;
        while (!itemFile.eof())
        {   
            itemCount++;
            items newItem;
            itemFile >> newItem.name;
            itemFile >> newItem.strength;
            itemFile >> newItem.dexterity;
            itemFile >> newItem.endurance;
            itemFile >> newItem.intelligence;
            itemFile >> newItem.charisma;
            itemFile >> newItem.HP;
            itemFile >> newItem.dropRate;
            itemFile >> newItem.ID;

            Item.push_back(newItem);
        }
    }
    else
        cout << "File access forbidden!" << endl;

    itemFile.close();

    return itemCount;
}

