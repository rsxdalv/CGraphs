#include <iostream>
#include <fstream>

#define M 7 //JANOMAINA

using namespace std;

class virsotnes
{
	public:
		virsotnes();
		bool bijis;
};

virsotnes::virsotnes()
{
	bijis = false;
}

bool cikls;
bool rek(int gatavs[][M], int v1, int v2, int from, int bijusie[M])
{
	for(int next=0; next<M; next++)
    {
        cout << "FROM: " << from << endl;
        int m=0;
        bool b=false;
        
        do
        {
            if(bijusie[m]==-1)
            {
                bijusie[m] = from;
                b = true;
            }
            m++;
            
        }
        while((b==false)&&(m<M));
        
        bool n=false;
        for(int m=0; (m<M)&&(bijusie[m]!=-1); m++)
        {
            if(bijusie[m]==next)
                n=true;
        }
        
		if((gatavs[v1][next]>0)&&(from!=next)&&(n!=true))
		{
            cout << "Atrada nakamo celu no " << v1 << " uz " << next << "    v2: " << v2 << endl;
			if(next==v2)
			{
				cikls=true;
				cout << "Cikls!" << endl;
                
			}
			else
			{
                //cout << v1 << "  " << v2 << "  " << next << endl;
                
                //system("PAUSE");
				rek(gatavs,  next, v2, v1, bijusie);
			}
		}
		else if((gatavs[v1][next]>0)&&(next==0)&&(from==0)&&(n!=true))
		{
            //cout << "Atrada nakamo celu no " << v1 << " uz " << next << "    v2: " << v2 << endl;
            cout << "2. veids" << endl;
            cout << "Atrada nakamo celu no " << v1 << " uz " << next << "    v2: " << v2 << endl;
			if(next==v2)
			{
				cikls=true;
				cout << "Cikls!" << endl;
                
			}
			else
			{
                //cout << v1 << "  " << v2 << "  " << next << endl;
                
                //system("PAUSE");
				rek(gatavs,  next, v2, v1, bijusie);
			}
		}
		//cout << next << endl;
		//system("PAUSE");
	}
	cout << "Cikls: " <<  cikls << endl;
	cout << "---------------------------------------------" << endl;
	return cikls;
}

int main()
{
	int x;
    ifstream matr;
    matr.open("kd.txt");
    matr >> x;
	int matrica[x][x];
	int bija[M];
	for(int i=0;i<x;i++)
	{
		for(int j=0; j<x;j++)
		{
			matr >> matrica[i][j];
		}
	}
	
	for(int i=0;i<x;i++)
	{
		for(int j=0; j<x;j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
	
	int isakie_celi[x][7]; // JANOMAINA
	for(int i=0;i<x;i++)
	{
		for(int j=0; j<x;j++)
		{
			isakie_celi[i][j] = 0;
		}
	}
	virsotnes virsotne[x];
	bool beigt=false;
	int rezultats = 0;
	int savienojumi = 0;
	int mazakais = INT_MAX;
	int x1, y1;
	while(beigt!=true)
	{
		mazakais = INT_MAX;
		for(int i=0; i<x; i++)
		{
			for(int j=0; j<x; j++)
			{
				//cout << "i: " << i << "  j: " << j << endl;
                //system("PAUSE");
                if((virsotne[i].bijis!=true)||(virsotne[j].bijis!=true))
				{
					if((mazakais>matrica[i][j])&&(matrica[i][j]>0))
					{
						mazakais = matrica[i][j];
						x1 = i;
						y1 = j;
					}
				}
				else if((virsotne[i].bijis==true)&&(virsotne[j].bijis==true)&&(i!=j)&&(isakie_celi[i][j]==0)&&(matrica[i][j]!=0))
				{
                    cout << "Ieiet rekursija  " << i << "  " << j << endl;
                    //system("PAUSE");
                    cikls = false;
                    for(int m=0;m<M;m++)
                    {
                        bija[m] = -1;
                    }
                    if(rek(isakie_celi, i, j, i, bija)==false)
				    {
						if((mazakais>matrica[i][j])&&(matrica[i][j]>0))
						{
							mazakais = matrica[i][j];
							x1 = i;
							y1 = j;
							cout << "Mazakais!  " << mazakais << endl;
						}
					}
					
				}
				
			}
		}
		
		cout << "Iziet no \"for\" ---------------- " << endl;
		isakie_celi[x1][y1] = matrica[x1][y1];
		isakie_celi[y1][x1] = matrica[y1][x1];
		virsotne[x1].bijis = true;
		virsotne[y1].bijis = true;
		rezultats+=matrica[x1][y1];
		savienojumi++;
		if(savienojumi==x-1)
			beigt=true;
		for(int i=0;i<x;i++)
    	{
    		for(int j=0; j<x;j++)
    		{
    			cout << isakie_celi[i][j] << " ";
    		}
    		cout << endl;
    	}
		system("PAUSE");
	};
	
	cout << endl;
	for(int i=0;i<x;i++)
	{
		for(int j=0; j<x;j++)
		{
			cout << isakie_celi[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Rezultats: " << rezultats << endl;
	
    
    
    system("PAUSE");
    return 0;
}
