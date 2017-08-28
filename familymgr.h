#ifndef FAMILYMGR_H
#define FAMILYMGR_H

#include <iostream>
#include <fstream>
#include "hashtable.h"

using namespace std;

class familymgr
{
    private:
        hashtable * families;
        ofstream outFile;
    public:
        // Constructors/Destructors
        familymgr();
        ~familymgr();
        
        // Accessors
        void printAllFamilies();
        void printGroup(family *);
        void printSmallCircle(char *);
        
        // Mutators
        void addFamily(family &);
};

#endif