#include "familymgr.h"

// -------------------------------------------------------------
//                  Constructors/Destructors
// -------------------------------------------------------------

familymgr::familymgr()
{
    families = new hashtable();
    outFile.open("assigned.txt");
}

familymgr::~familymgr()
{
    if(families)
        delete families;
    outFile.close();
}

// -------------------------------------------------------------
//                          Accessors
// -------------------------------------------------------------

void familymgr::printAllFamilies()
{
    outFile << * families;
}

void familymgr::printGroup(family *)
{
    
}

void familymgr::printSmallCircle(char * thing)
{
    family * fam = families->lookup(thing);
    outFile << "Printing family and immediate friends " << thing << endl;
    outFile << "== Family ==" << endl;
    outFile <<  * fam << endl;
    outFile << "== Friends (1 level) ==" << endl;
    
    cout << endl<< endl<< endl<< endl<< endl<< fam->getFriendCount() << endl;
    for(int i = 0; i < 3; i++)
    {
        if(families->lookup(fam->getFriend(i)))
            outFile << * families->lookup(fam->getFriend(i));
    }
}

// -------------------------------------------------------------
//                          Mutators
// -------------------------------------------------------------

void familymgr::addFamily(family & fam)
{
    families->insert(fam.getId(),fam);
}