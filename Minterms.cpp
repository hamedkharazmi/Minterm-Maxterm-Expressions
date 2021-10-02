#include <iostream>
#include <cmath>
#include "Minterms.h"
#define min(x,y) (x>y?y:x)

mint::mint()
{
	condition=EN;
	numOfMin=1;
	M=new int;
	numOfOne=sumOfCommenOne=0;
}

void mint::set(int numOfBit,int minterm,XTerm XT)
{
	bit=new short int[this->numOfBit=numOfBit];
	this->XT=XT;
	*M=minterm;
	for(int i=numOfBit-1;i+1;i--)
	{
		if(minterm!=0)
		{
		    bit[i]=minterm%2;
	    	if(minterm%2)numOfOne++;
		    minterm/=2;
	  	}
		else bit[i]=0;
	}
}

int mint::checkMatch(mint &ob)
{
	if(abs(numOfOne-ob.numOfOne)!=1)return -1;
	if(ob.sumOfCommenOne!=sumOfCommenOne)return -1;
	int A=0,ma=-1;
	for (int i=0;i<numOfBit;i++)
	{
		if(bit[i]==-1)continue ;
		if(bit[i]!=ob.bit[i])
		{
    		A++;
    		ma=i;
    	}
		if(A==2)return -1;
	}
	if(A==1)
	{
		condition=ob.condition=DI;
		return ma;
	}
	return -1;
}

void mint::outputXT(void)
{
	if(XT==miT)
	{
		for(int i=0;i<numOfBit;i++)
		{
			if(bit[i]==-1)continue;
			cout <<(char)('A'+i);
			if(bit[i]==0)cout << "'";
			else cout <<' ';
		}
	}
	else {
		bool A=false;
		cout << "(";
		for(int i=0;i<numOfBit;i++)
		{
			if(bit[i]==-1)continue;
			if(A==true)cout << '+';
			else A=true;
			cout <<(char)('A'+i);
			if(bit[i]==1)cout << "'";
			else cout <<' ';
		}
		cout <<")";
	}
}

void mint::operator=(mint &ob)
{
	delete[] bit;
	bit= new short int [numOfBit=ob.numOfBit];
	for(int i=0;i<numOfBit;i++)bit[i]=ob.bit[i];
	delete[] M;
	M=new int [numOfMin=ob.numOfMin];
	for(int i=0;i<numOfMin;i++)M[i]=ob.M[i];
	numOfOne=ob.numOfOne;
	condition=ob.condition;
	XT=ob.XT;
	sumOfCommenOne=ob.sumOfCommenOne;
}

void mint::match(mint & ob,int maNum,mint &newM)
{
	newM=ob;
    newM.bit[maNum]=-1;
	newM.numOfOne=min(numOfOne,ob.numOfOne);
	newM.sumOfCommenOne=sumOfCommenOne+abs(M[0]-ob.M[0]);
	newM.condition=EN;
	delete[] newM.M;
	newM.M=new int[newM.numOfMin=2*numOfMin];
	int j=0,jp=0;
	for(int i=0;i<newM.numOfMin;i++)
	{
		if(j==numOfMin)
		{
			newM.M[i]=ob.M[jp++];
			continue;
		}
		if(jp==ob.numOfMin)
		{
			newM.M[i]=M[j++];
			continue;
		}
		newM.M[i]=(M[j]>ob.M[jp]?ob.M[jp++]:M[j++]);
	}
}

void mint::getMinterm(vector<int>& mints)
{
	for(int i=0;i<numOfMin;i++)
		mints[i]=M[i];
}

void mint::delCommenXTerm(vector<int>& Minterms)
{
	for(int i=0;i<numOfMin;i++)
	{
		for(int ip=0;ip<Minterms.size();ip++)
			if(M[i]==Minterms[ip])
			{
				Minterms.erase(Minterms.begin()+ip);
				break;
			}
	}
}
