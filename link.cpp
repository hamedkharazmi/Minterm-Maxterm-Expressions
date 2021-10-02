#include "link.h"

void linkList::push_back(int numOfBit,int minterm,XTerm XT)
{
    linkList* counter;
    for(counter=this;counter->link!=0;counter=counter->link);
    counter->link=new linkList;
    lengthOfList++;
    counter=counter->link;
    counter->link=0;
    counter->ob.set(numOfBit,minterm,XT);
}
void linkList::push_back(void)
{
    linkList* counter;
    for(counter=this;counter->link!=0;counter=counter->link);
    counter->link=new linkList;
    lengthOfList++;
    counter=counter->link;
    counter->link=0;
}

mint& linkList::operator[](int number)
{
    linkList* counter=link;
    if(number>lengthOfList)
    {
        cout<<"wrong!"<<endl;
        exit(0);
    }
    for(int i=0;i<number;i++,counter=counter->link);
    return counter->ob;
}
