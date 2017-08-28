#include "family.h"

// -------------------------------------------------------------
//                  Constructors/Destructors
// -------------------------------------------------------------

family::family()
{
    ID = new char [4];
    strcpy(ID,"N/A");
    
    name = new char[4];
    strcpy(name,"N/A");
    
    members = 0;
    nFriends = 0;
}

family::family(char * tID, char * tName, int tMemebers)
{
    ID = new char [strlen(tID) + 1];
    strcpy(ID,tID);
    
    name = new char[strlen(tName) + 1];
    strcpy(name,tName);
    
    members = tMemebers;
    
    nFriends = 0;
    for (int i = 0; i < MAX_FRIENDS; i++)
        friends[i] = NULL;
}

family::~family()
{
    if(ID)
        delete[] ID;
    if(name)
        delete[] name;
    
    for(int i = 0; i < MAX_FRIENDS ; i++)
    {
        if(friends[i])
            delete friends[i];
    }
}

// -------------------------------------------------------------
//                          Accessors
// -------------------------------------------------------------

char * family::getId()
{
    return ID;
}

char * family::getName()
{
    return name;
}

int family::getMembers()
{
    return members;
}

int family::getFriendCount()
{
    return nFriends;
}

char * family::getFriend(int index) const
{
    return friends[index];
}

void family::getFriends(ostream & buffer)
{
    for(int i = 0; i < 3; i++)
    {
        if(friends[i])
            buffer << friends[i] << " ";
    }
}

// -------------------------------------------------------------
//                          Mutators
// -------------------------------------------------------------

bool family::addFriend(const char * tFriend)
{
    if (nFriends == MAX_FRIENDS)
    {
        return false;
    }
    else
    {
        friends[nFriends] = new char[strlen(tFriend) + 1];
        strcpy(friends[nFriends],tFriend);
        nFriends++;
        
        return true;
    }
}

// -------------------------------------------------------------
//                         Operators
// -------------------------------------------------------------

const family & family::operator = (const family & tempFam)
{
    if(this == & tempFam)
    {
        return *this;
    }
    else
    {
        if(ID)
            delete [] ID;
        ID = new char[strlen(tempFam.ID)];
        strcpy(this->ID,tempFam.ID);
        
        if(name)
            delete [] name;
        name = new char[strlen(tempFam.name)];
        strcpy(this->name,tempFam.name);
        
        this->members = tempFam.members;
        
        for(int i = 0; i < MAX_FRIENDS; i++)
        {
            if(friends[i])
            {
                delete friends[i];
            }
            
            if(tempFam.friends[i])
            {
                friends[i] = new char[strlen(tempFam.friends[i]) + 1];
                strcpy(this->friends[i],tempFam.friends[i]);
            }
        }
        
        return * this;
    }
}

ostream & operator << (ostream & buffer, family & fam)
{
    buffer << "Family ID: " << fam.getId() << endl;
    buffer << "  Name: " << fam.getName() << endl;
    buffer << "  Members: " << fam.getMembers() << endl;
    buffer << "  Friends: ";
    fam.getFriends(buffer);
    buffer << endl;
    
    return buffer;
}