#include <iostream>

using namespace std;

#define min(a,b) (((a) < (b)) ? (a) : (b))

#define QQ 1024
int main(int argc,char **argv)
{
    #define sized 9
    int matrix[sized][sized]={

    0,  13, 0,  24, 0,  0,  0,  0,  0,
    0,  0,  9,  8,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  11, 0,  0,  17, 0,
    0,  0,  0,  0,  24, 0,  0,  0,  0,
    0,  10, 0,  0,  0,  26, 7,  0,  0,
    0,  0,  0,  0,  0,  0,  6,  7,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  15,
    0,  0,  0,  0,  0,  0,  0,  0,  20,
    0,  0,  0,  0,  0,  0,  0,  0,  0,

    };

    int res;
	int loop=1;

    int rmatrix[sized][sized]={0};

    int todelete=2;
	//while(loop)
	while(todelete--)
	{


    int Iter[sized]={0};
    //0 - Blank 1 - Checked 2 - Finished
    int Iez[sized][2]={0};
    #define Ssrc 0
    #define Sval 1
	// 0 - Pozitivs vai negativa iezime uz virsotni 1 - sakaitlis

    Iter[0]=1;
	Iez[0][Ssrc]=0; // source
    Iez[0][Sval]=QQ;

    int stack[sized];
    for(int c=0;c<sized;c++)
        stack[c]=-1;
    stack[0]=0;
    int next=0; // Lasa
    int wnext=1;  // Raksta
    for(;;)
	{

	    //int Iez2[sized];
		for(int i=0;i<sized;i++)
		{
		    int last=0;
		    if(matrix[ stack[next] ][i]!=0)
		    {
                cout<<stack[next]<<"  Iter "<<i<<endl;
                if(Iter[i]==0){// Ja matrica nav iezimeta, to apskata
                stack[wnext++]=i;
                Iter[i]=1; // 1. to ieziimee.
                Iez[i][Ssrc]=stack[next];
                Iez[i][Sval]=min(Iez[ stack[next] ][Sval],matrix[ stack[next] ][i]-rmatrix[ stack[next] ][i]);
                if(Iez[i][Sval]!=0)
                    last=1;
                cout<<Iez[i][Sval]<<" Flow"<<endl;
                }
            }
            if(!last) loop=0;

		}

		Iter[ stack[next] ]=2; // Finished
		next++;
		if( stack[next] == sized-1) break;
		//ptr=next;

	}

    int value=Iez[sized-1][Sval];
    int rptr=sized-1;
    while(rptr) // kamēr nav sasniegts 0 jeb sākums
    {
        int src=Iez[rptr][Ssrc];
        rmatrix[src][rptr]+=value;
        //cout<<" RPTR un SRC un Value :"<<src+1<<"    "<<rptr+1<<"  "<<value<<endl;
        cout<<"No V"<<src+1<<" uz V"<<rptr+1<<" ("<<value<<"/"<<matrix[src][rptr]<<")"<<endl;
        rptr=src;
    }


	/*for(int ptr=0;ptr<sized;ptr++)
	{
	    //int Iez2[sized];
		int next=0;
		for(int i=0;i<sized;i++)
		{
		    int last=0;
		    if(matrix[ptr][i]!=0)
		    {
                cout<<ptr<<"  Iter "<<i<<endl;
                if(Iter[i]==0){// Ja matrica nav iezimeta, to apskata
                Iter[i]=1; // 1. to iezime.
                Iez[i][Ssrc]=ptr;
                Iez[i][Sval]=min(Iez[ptr][Sval],matrix[ptr][i]-rmatrix[ptr][i]);
                if(Iez[i][Sval]!=0)
                    last=1;
                cout<<Iez[i][Sval]<<" Flow"<<endl;
                }
            }
            if(!last) loop=0;

		}

		Iter[ptr]=2; // Finished
		//ptr=next;

	}*/

	}

	for(int k=0;k<sized;k++)
        for(int j=0;j<sized;j++)
        {
            cout<<" V"<<k<<" -V"<<j<<" Value="<<rmatrix[k][j]<<endl;
        }

    return 0;
}
