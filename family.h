#ifndef FAMILY_H
#define FAMILY_H

#include <iostream>
#include <string.h>

using namespace std;

class family
{
    private:
        const int MAX_FRIENDS = 3;
        char * ID;
        char * name;
        int members;
        int nFriends;
        char * friends[3];
    public:
        // Constructors/Destructors
        family();
        family(char*, char*, int);
        ~family();
        
        // Accessors
        char * getId();
        char * getName();
        int getMembers();
        int getFriendCount();
        char * getFriend(int) const;
        void getFriends(ostream & buffer);
        
        // Mutators
        bool addFriend(const char *);
        
        // Operators
        const family & operator = (const family &);
        friend ostream & operator << (ostream &, family &);
};

#endif