#include <iostream>
#include "Function.h"

int main()
{
    linkList* jadvalMint;
    int chose,numVar,columnOfXT;
    cout <<"Enter number of variable:";
    cin >>numVar;
    jadvalMint=new linkList[numVar];

    cout <<"1-Minterm\t2-Maxterm"<<endl<<"Which case are you enter?";
line1:
    cin >>chose;
    switch (chose) {
    case 1:
        cout <<"1-SOP\t2-POS" <<endl <<"Enter mode of your method to show:";
line2:
        cin >>chose;
        switch (chose)
        {
        case 1:
            getMinterms(jadvalMint[0],numVar);
            break;
        case 2:
            setMaxterms(jadvalMint[0],numVar);
            break;
        default:
            cout <<"Wrong order!" <<endl<<"Enter agane:";
            goto line2;
        }
        break;
    case 2:
        cout <<"1-SOP\t2-POS" <<endl <<"Enter mode of your method to show:";
line3:
        cin >>chose;
        switch (chose)
        {
            case 1:
                setMinterms(jadvalMint[0],numVar);
                break;
            case 2:
                getMaxterms(jadvalMint[0],numVar);
                break;
            default:
                cout <<"Wrong order!" <<endl<<"Enter agane:";
                goto line3;
        }
        break;
    default:
        cout <<"Wrong order!" <<endl<<"Enter agane:";
        goto line1;
    }

    for(columnOfXT=1;findAndMatcher(jadvalMint[columnOfXT-1],jadvalMint[columnOfXT])==true;columnOfXT++);

    for(int i=1;i<columnOfXT;i++)
    {
        for(int ip=0;ip<jadvalMint[i].size();ip++)
        {
            if(jadvalMint[i][ip].getCondition()==DI)continue;
            delUselessMinterm(jadvalMint,columnOfXT,i,ip);
        }
    }

    output(jadvalMint,columnOfXT);
    delete[] jadvalMint;
    return 0;
}
