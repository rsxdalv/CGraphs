#include <iostream>

// Pieliku komentārus lai kļūtu nedaudz skaidrāka darbība
using namespace std;

struct link {
  int source,size;
};

#define MAX_VALUE 2048
#define XQ MAX_VALUE

int main(int argc, char ** argv)
{
    #define sized 7

    int Matrix[sized][sized]={
0,	6,	XQ,	11,	5,	XQ,	XQ,
6,	0,	15,	18,	8,	XQ,	XQ,
XQ,	15,	0,	8,	XQ,	XQ,	XQ,
11,	18,	8,	0,	XQ,	10,	7,
5,	8,	XQ,	XQ,	0,	15,	9,
XQ,	XQ,	XQ,	10,	15,	0,	XQ,
XQ,	XQ,	XQ,	7,	9,	XQ,	0


};

    int mark[sized]={0};
    link Mi[sized]={MAX_VALUE};
    for(int a=0;a<sized;a++)
    {
        Mi[a].source=-1;
        Mi[a].size=MAX_VALUE;
    }

    int count=0;
    int next=0;
    int length=0;

    int maing[sized]={0};
    int groupn=0;

    for(;;)
    {
        count++;
        //kad sasniegts maks lielums.
        if(count==sized) break;

        int minn=XQ;
        int alpha=-1,beta=-1;
        for(int i=0;i<sized;i++)
        { // Pret katru virsotni
            for(int k=i+1;k<sized;k++)
            {
                if(mark[k]==0 || mark[i]==0 || mark[i]!=mark[k])
                //Ja viena no virstonem ir neiezimeta
                //if((!mark[k])||mark[i]!=mark[k])
                //atskirigas grupas virsotnes
                if(Matrix[i][k]<minn)
                {
                //ir loks mazaks par min
                    alpha=i;beta=k;
                    minn=Matrix[i][k];
                }
            }
            //if(mark[i])
        }
        if(alpha==-1||beta==-1) cout<<"Nesasniedzama virsotne!"<<endl;
        if(minn==XQ) cout<<"kluuda!"<<endl;
        else
            length+=Matrix[alpha][beta];
        if(mark[alpha]==0)
        {
            if(mark[beta]==0)
            {
                mark[alpha]=mark[beta]=++groupn;
            }
            else
                mark[alpha]=mark[beta];
        }
        else if(mark[beta]==0)
            mark[beta]=mark[alpha];
        else
        {
            int repl=mark[beta];
            int rep=mark[alpha];
            for(int x=0;x<sized;x++)
                if(mark[x]==repl)
                    mark[x]=rep;
        }
        cout<<"Link V"<<alpha+1<<" - V"<<beta+1<<endl;

    }

    /*for(;;)
    {
    mark[next]=1;
    count++;
    if(count==sized) break;
    for(int a=0;a<sized;a++)
    {
        if(a!=next)
        //salidzinam esosos attalumus ar jauniegutajiem
        {
            if(Mi[a].size>Matrix[next][a])
            {
                Mi[a].source=next;
                Mi[a].size=Matrix[next][a];
            }
        }
    }
    //atrod minimālo attālumu no neizīmētajām virsotnēm
    int mini=MAX_VALUE;
    for(int a=0;a<sized;a++)
    {
        if(!mark[a])
         if(Mi[a].size<mini)
         {
             mini=Mi[a].size;
             next=a;
         }
    }
    // Un pēc tam atsāk ciklu no tās tādā veidā panākot, ka minimālie attālumi vienmēr būs pareizi.
    // Izvada iegūto rezultātu :
    cout<<"Link made V"<<next+1<<"-V"<<Mi[next].source+1<<endl;
    //next=mini;
    length+=Mi[next].size;
    //Ja kāda virsotne nav pievienota visam pārējam, tad rodas kļūda, par kuru vienkārši paziņo :
    if(mini==MAX_VALUE) cout << "Kluda...\n";

    }
    */

    cout<<"Length : "<<length<<endl;
/*
    for(int a=0;a<sized;a++)
    {

    }
*/
    return 0;
}
