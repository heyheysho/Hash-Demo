#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "family.h"

using namespace std;

class hashtable
{
    private:
        // Hash Entry Node
        struct hashEntry
        {
            // Constructors/Destructors
            hashEntry(const family & fam)
            {
                data = fam;
                next = NULL;
            }
            
            family data;
            hashEntry * next;
        };
        
        const size_t MAX_CAP = 7877;
        int tableCount;
        int tableSize;
        hashEntry ** famTable;
    public:
        // Constructors/Destructors
        hashtable();
        hashtable(int);
        ~hashtable();
        
        // Accessors
        family * lookup(char *) const;
        int getSize() const;
        void dumpTable();
        
        // Mutators
        void insert(char *, const family &);
        size_t hash(char *) const;
        void destroyTable();
        
        // Operators
        friend ostream & operator << (ostream &, hashtable &);
        const hashtable & operator = (const hashtable &);
};

#endif