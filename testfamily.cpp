#include <iostream>
#include "family.h"

using namespace std;

bool addFriendHelper(family & fam,const char * myfriend)
{
    if (!fam.addFriend(myfriend))
    {
        cout << "Too many friends for " << fam.getId() << endl;
        return false;
    }
    else
        return true;
}

int main()
{
    // Test some of the basic family functionality. Normally a test like this
    // should be self-checking but for this class I am just having it print to
    // screen since I think that will be more helpful for you (the students)

    family fam("Test001","Test",3);
    cout << fam;

    family fam1 = fam;
    cout << fam1;
    
    fam = family("Test002","Yee",4);
    
    if(addFriendHelper(fam,"Friend001"))
        cout << fam;


    if(addFriendHelper(fam1,"Friend002"))
        cout << fam1;

    if(addFriendHelper(fam,"Friend003"))
        cout << fam;

    if(addFriendHelper(fam1,"Friend004"))
        cout << fam1;

    return(0);
}
