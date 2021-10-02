#include <iostream>
#include <vector>
using namespace std;

enum XTerm {MAT,miT };
enum con {DI,EN };

class mint
{
private:
	short int *bit;
	XTerm XT;
	con condition;
	int numOfBit,numOfOne,*M,numOfMin,sumOfCommenOne;
public:
	mint();
	~mint()
	{
		delete[] bit;
		delete[] M;
	}
	void set(int numOfBit,int minT,XTerm XT);
	void setCondition(con Condition){ condition=Condition; }
	void operator=(mint &ob);
	void outputXT(void);
	int getNumOfBit(void){ return numOfBit; }
	int getNumOfMin(void){ return numOfMin; }
	void getMinterm(vector<int> & mints);
	con getCondition(void){ return condition; }
	XTerm getXTerm(void){ return XT; }
	int checkMatch(mint &ob);
	friend bool checkSubClass(mint &obT,mint &ob1,mint &ob2);
	void match(mint & ob,int,mint &newM);
	void delCommenXTerm(vector<int>& Minterms);
};
