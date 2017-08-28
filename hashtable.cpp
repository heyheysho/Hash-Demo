#include "hashtable.h"

// -------------------------------------------------------------
//                  Constructors/Destructors
// -------------------------------------------------------------

hashtable::hashtable()
{
    tableCount = 0;
    tableSize = MAX_CAP;
    famTable = new hashEntry * [tableSize];

    for (int i = 0; i < tableSize; i++)
    {
        famTable[i] = NULL;
    }
}

hashtable::hashtable(int x)
{
    tableCount = 0;
    tableSize = x;
    famTable = new hashEntry * [tableSize];

    for (int i = 0; i < tableSize; i++)
    {
        famTable[i] = NULL;
    }
}

hashtable::~hashtable()
{
    destroyTable();
}

// -------------------------------------------------------------
//                          Accessors
// -------------------------------------------------------------

family * hashtable::lookup(char * id) const
{
    size_t i = hash(id);
    
    hashEntry * curr = famTable[i];
       
    while(curr)
    {
        if(curr->data.getId())
        {
            char * tID = new char[strlen(curr->data.getId())];
            strcpy(tID,curr->data.getId());
            
            if(strcmp(id, tID) == 0)
            {
                delete tID;
                return & curr->data;
            }
            else
            {
                delete tID;
                curr = curr->next;
            }           
        }
    }
    
    curr = NULL;
    return NULL;
}

int hashtable::getSize() const
{
    return tableSize;
}

void hashtable::dumpTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        for(hashEntry * curr = famTable[i]; curr; curr = curr->next)
        {
            cout << curr->data << endl;
        }
    }
}

// -------------------------------------------------------------
//                          Mutators
// -------------------------------------------------------------

void hashtable::insert(char * id, const family & fam)
{
    size_t i = hash(id);
    
    hashEntry * temp = new hashEntry(fam);
    
    temp->next = famTable[i];
    famTable[i] = temp;
    tableCount++;
}

size_t hashtable::hash(char * id) const
{
    size_t index = id[0];
    size_t length = strlen(id);
    
    for(int i = 1; i < length; i++)
    {
        index = (int) id[i] + (index * 32);
    }
    
    return index % tableSize;
}

void hashtable::destroyTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        hashEntry * head = famTable[i];
        hashEntry * curr;
        
        while(head)
        {
            curr = head->next;
            head->next = NULL;
            
            delete head;
            
            head = curr;
        }
    }
    
    delete [] famTable;
}

// -------------------------------------------------------------
//                         Operators
// -------------------------------------------------------------

ostream & operator << (ostream & buffer, hashtable & entry)
{
    hashtable::hashEntry * curr;
    
    for(int i = 0; i < entry.tableSize; i++)
    {
        buffer << "table[" << i << "]:" << endl << "List:" << endl;
        
        for(curr = entry.famTable[i]; curr; curr = curr->next)
        {
            buffer << curr->data;
        }
        
        buffer << setw(20) << right << setfill('-') << "" << endl;
    }
    
    return  buffer;
}

const hashtable & hashtable::operator = (const hashtable & temp)
{
    if(this == & temp)
    {
        return *this;
    }
    else
    {
        destroyTable();
       
        famTable = new hashEntry * [MAX_CAP];
       
        tableCount = temp.tableCount;
        tableSize = temp.tableSize;
        
        for(int i = 0; i < tableSize; i++)
        {
            if(temp.famTable[i] == NULL)
            {
                famTable[i] = NULL;
            }
            else
            {
                famTable[i] = new hashEntry(temp.famTable[i]->data);
                
                hashEntry * curr = temp.famTable[i]->next;
                hashEntry * tNext = famTable[i];
                
                while(curr)
                {
                    tNext->next = new hashEntry(tNext->data);
                    curr = curr->next;
                    tNext = curr->next;
                }
                
                tNext->next = NULL;
            }
        }
        
        return * this;
    }
}