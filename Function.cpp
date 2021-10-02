#include <iostream>
#include <cmath>
#include "link.h"

void getMinterms(linkList& jadvalMint,int numVar)
{
    int numOfMint,maxOfmint,Mterm;
    maxOfmint=pow(2,numVar);
    cout << "Enter number of Minterms:";
    cin >> numOfMint;
    while (maxOfmint<numOfMint)
    {
        cout <<"Wrong! max of Mint:" << maxOfmint << "Enter again:";
        cin >> numOfMint;
    }
    if(numOfMint==0)
    {
        cout <<"f=0" <<endl;
        exit(0);
    }
    for(int i=0;i < numOfMint;i++)
    {
        cout <<"Enter "<<i+1<<"th Minterm:";
        cin >>Mterm;
        jadvalMint.push_back(numVar,Mterm,miT);
    }
    if(numOfMint==maxOfmint)
    {
        cout <<"f=1" <<endl;
        exit(0);
    }
}

void setMinterms(linkList& jadvalMint,int numVar)
{
    int numOfMint,maxOfmint,Mterm;
    maxOfmint=pow(2,numVar);
    cout << "Enter number of Maxterms:";
    cin >> numOfMint;
    while (maxOfmint<numOfMint)
    {
        cout <<"Wrong! max of Maxterm:" << maxOfmint << "Enter again:";
        cin >> numOfMint;
    }
    if(numOfMint==0)
    {
        cout <<"f=1" <<endl;
        exit(0);
    }
    int front=0;
    for(int i=0;i < numOfMint;i++)
    {
        cout <<"Enter "<<i+1<<"th Maxterm:";
        cin >>Mterm;
        for (int ip=front;ip<Mterm; ip++)
            jadvalMint.push_back(numVar,ip,miT);
        front=Mterm+1;
    }
    for (int ip=front;ip<maxOfmint; ip++)
        jadvalMint.push_back(numVar,ip,miT);
    if(numOfMint==maxOfmint)
    {
        cout <<"f=0" <<endl;
        exit(0);
    }
}

void getMaxterms(linkList& jadvalMint,int numVar)
{
    int numOfMint,maxOfmint,Mterm;
    maxOfmint=pow(2,numVar);
    cout << "Enter number of Maxterms:";
    cin >> numOfMint;
    while (maxOfmint<numOfMint)
    {
        cout <<"Wrong! max of Maxterm:" << maxOfmint << "Enter again:";
        cin >> numOfMint;
    }
    if(numOfMint==0)
    {
        cout <<"f=1" <<endl;
        exit(0);
    }
    for(int i=0;i < numOfMint;i++)
    {
        cout <<"Enter "<<i+1<<"th Maxterm:";
        cin >>Mterm;
        jadvalMint.push_back(numVar,Mterm,MAT);
    }
    if(numOfMint==maxOfmint)
    {
        cout <<"f=0" <<endl;
        exit(0);
    }
}

void setMaxterms(linkList& jadvalMint,int numVar)
{
    int numOfMint,maxOfmint,Mterm;
    maxOfmint=pow(2,numVar);
    cout << "Enter number of Minterms:";
    cin >> numOfMint;
    while (maxOfmint<numOfMint)
    {
        cout <<"Wrong! max of Minterm:" << maxOfmint << "Enter again:";
        cin >> numOfMint;
    }
    if(numOfMint==0)
    {
        cout <<"f=0" <<endl;
        exit(0);
    }
    int front=0;
    for(int i=0;i < numOfMint;i++)
    {
        cout <<"Enter "<<i+1<<"th Minterm:";
        cin >>Mterm;
        for (int ip=front;ip<Mterm; ip++)
            jadvalMint.push_back(numVar,ip,MAT);
        front=Mterm+1;
    }
    for (int ip=front;ip<maxOfmint; ip++)
        jadvalMint.push_back(numVar,ip,MAT);
    if(numOfMint==maxOfmint)
    {
        cout <<"f=1" <<endl;
        exit(0);
    }
}

bool findAndMatcher(linkList& xterms,linkList& matches)
{
    int i,ip,martabeh;
    bool A=false;
    for(i=0;i<xterms.size();i++)
    {
        for(ip=i+1;ip<xterms.size();ip++)
        {
            martabeh=xterms[i].checkMatch(xterms[ip]);
            if(martabeh==-1)continue;
            A=true;
            matches.push_back();
            xterms[i].match(xterms[ip],martabeh,matches[matches.size()-1]);
        }
    }
    return A;
}

void delUselessMinterm(linkList* & Minterms,int columnOfXT,int column,int row)
{
	vector<int> mints(Minterms[column][row].getNumOfMin());
    Minterms[column][row].getMinterm(mints);
    for(int i=1;i<columnOfXT;i++)
	{
		for(int ip=0;ip<Minterms[i].size();ip++)
		{
            if(i==column&&ip==row)continue;
            if(Minterms[i][ip].getCondition()==DI)continue;
			Minterms[i][ip].delCommenXTerm(mints);
            if(mints.size()==0)break;
		}
		if(mints.size()==0)
        {
            Minterms[column][row].setCondition(DI);
            return;
        }
	}
}

void output(linkList*& jadvalMint,int columnOfXT)
{
    bool A=false;
    cout <<"f=";
	if(jadvalMint[0][0].getXTerm()==miT)
	{
		for(int i=0;i<columnOfXT;i++)
	    	for(int ip=0;ip<jadvalMint[i].size();ip++)
	    	{
	    		if(jadvalMint[i][ip].getCondition()==EN)
	    		{
	    			if(A==true)cout <<'+';
                    else A=true;
					jadvalMint[i][ip].outputXT();
	    		}
	    	}
	}
    else for(int i=0;i<columnOfXT;i++)
        	for(int ip=0;ip<jadvalMint[i].size();ip++)
        	{
        		if(jadvalMint[i][ip].getCondition()==EN)
        		{
                    if(A==true)cout <<'.';
                    else A=true;
    				jadvalMint[i][ip].outputXT();
        		}

        	}

    cout <<endl;
}
