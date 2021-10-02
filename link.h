#include <cstdlib>
#include "Minterms.h"

class linkList{
    mint ob;
    linkList* link;
    int lengthOfList;
public:
    linkList()
    {
        lengthOfList=0;
        link=0;
    }
    ~linkList()
    {
        delete link;
    }
    void push_back(int numOfBit,int minterm,XTerm XT);
    void push_back(void);
    int size(void){ return lengthOfList; }
    mint& operator[](int number);
};
