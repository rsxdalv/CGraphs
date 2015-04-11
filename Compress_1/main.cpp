#include <iostream>
using namespace std;
#include <vector>
#include <string.h>
#include <queue>

void Search (char elem, vector<char> &src, vector<int> &num)
{
    for(int x=0;x<src.size();x++){
        if(elem==src[x]) {
            num[x]++;
            return; }
    }
    src.push_back(elem);
    num.push_back(1);
    return;
}

int Scan (char * str, int siz, vector<char> &dest, vector<int> &num)
{
    dest.push_back(str[0]);
    num.push_back(1);
    for(int b=1;b<siz;b++){
        Search(str[b],dest,num);
    }

    return 0;
}

void Min_pair() {
    int x=0,y=0;

    }

int main(){
    char table[256];
    vector<char> CharTable;
    vector<int> NumTable;
    char a[]="AHFBHCEHEHCEAHDCEEHHHCHHHDEGHGGEHCHH";
    Scan( a,strlen(a), CharTable, NumTable);
    cout<<a<<" "<<endl;
    for(int c=0;c<CharTable.size();c++)
        cout << CharTable[c]<< " ";
    cout << endl;
    for(int c=0;c<NumTable.size();c++)
        cout << NumTable[c]<< " ";
    cout<<endl<<endl;
    return 0;
}
