#include"link.h"

void getMinterms(linkList& jadvalMint,int numVar);
void setMinterms(linkList& jadvalMint,int numVar);
void getMaxterms(linkList& jadvalMint,int numVar);
void setMaxterms(linkList& jadvalMint,int numVar);
bool findAndMatcher(linkList& xterms,linkList& matches);
void delUselessMinterm(linkList* & Minterms,int ROW,int column,int row);
void output(linkList*& jadvalMint,int row);
