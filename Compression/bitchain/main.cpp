#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

static unsigned char buffer = 0;
static unsigned int bits_used   = 0;


unsigned int asctobin(char *bit_seq) //f-ja paarveido char* virkni par bitu virkni
{
    unsigned int coded = 0;
    int lenBS = strlen(bit_seq);
  
    for(int i=0;i<lenBS; i++)
    {
        coded <<= 1;    //izdalam vietu prieks naakosaa bita
        coded |= (bit_seq[i]=='1') ? 1 : 0; // |-bitu operaacija VAI
    }
    return coded;
    
    //kas seit notiek? :)
    //coded = 0, moziimee ka visi coded biti vienaadi ar 0, jeb 0000000000000000
    //coded <<= 1 taa ir nobiide par vienu bitu uz kreiso pusi, jeb:
    //0000000000000000<<1 tas bits kas staaveeja kreisaa pusee pazud, labaa pusee paraadaas bits ar veertiibu 0 
    //coded |= (bit_seq[i]=='1') ? 1 : 0; |-bitu operaacija VAI, zemaak paskaidrojums
    //ja bija 0000000000000000
    //                |
    //        0000000000000000 rezultaats ir 0000000000000000
    //
    //bet ja  0000000000000000
    //                |
    //        0000000000000001 rezultaats ir 0000000000000001
    //
    //attieciibaa uz sito piemeeram   char *b = "0101" izskataas sekojisi
    //0000000000000000
    //<<1
    //0000000000000000
    //coded |= (bit_seq[i]=='1') ? 1 : 0 ===== 0
    //0000000000000000
    //<<1
    //0000000000000000
    //coded |= (bit_seq[i]=='1') ? 1 : 0 ===== 1
    //0000000000000001
    //<<1
    //0000000000000010
    //coded |= (bit_seq[i]=='1') ? 1 : 0 ===== 0
    //0000000000000010
    //<<1
    //0000000000000100
    //coded |= (bit_seq[i]=='1') ? 1 : 0 ===== 1
    //0000000000000101
    //rezultaataa tiks izvadiits skaitlis 5, jo 101 binaaraa skaitliisanas sisteemaa ir 5
}


int output_bits(int bit_seq, int seq_len)
{
    
    int i;

    bit_seq <<= (16 - seq_len);         //pirmais pareizais bits tagad kreisaakaa poziicijaa
    //attieciibaa uz "0101"
    //bija  0000000000000101
    //kluva 0101000000000000

    for (i = 0; i < seq_len; i++)
    {
        buffer <<= 1;                        //izdalam vietu prieks naakosaa bita buferii
        buffer |= ((bit_seq & 0x8000) != 0) ? 1 : 0; //paarrakstaam kaarteejo bitu buferii 
        //te jaauzzin kaadu bitu jaaieraksta buferii
        //mees to daram saliidzinot savu bitu saciibu (bit_seq) ar 0x8000 (tas ir 1000000000000000 heksadecimaalais pieraksts)
        //izmantojot bitu operatoru & (AND) mees padaram par nulleem visus bitus iznemot iespeejams pirmo
        //ja pirmais bits ir 1 tad (1_un_nakamie_biti & 1000000000000000) = 1
        //ja pirmais bits ir 0 tad (0_un_nakamie_biti & 1000000000000000) = 0
        //tatad 1 vai 0 tiks pievienoti buferii attieciigaa poziicijaa
        bit_seq <<= 1; //parbiidam bitus lai apstraadaat naakamo
        bits_used++;
        if (bits_used == 8)                  //kad sakraasim veselo baitu tad...
        {
            cout << buffer << endl; //izvadam
            bits_used = 0; //bitu skaititajs = 0
            buffer    = 0; //iztiiram buferu, gatavojam vietu naakamam simbolam
        }
    }
    
    return bits_used; //neizvadiito bitu skaits buferii
}


int main()
{
  int tail = 0;
  
  char *a = "010000";
  char *b = "0101";// 0x8000
  char *c = "1100";
  char *d = "0111";
  char *e = "000";
  char *f = "1";
  
  cout << "Bitu veertiibas:" << endl;
  cout << asctobin(a) << endl;
  cout << asctobin(b) << endl;
  cout << asctobin(c) << endl;
  cout << asctobin(d) << endl;
  cout << asctobin(e) << endl;
  cout << asctobin(f) << endl;
  
  cout << endl << "Rezulteejosas bitu virknes veertiibas sadalot pa char(iem):" << endl;
  
  output_bits(asctobin(a), strlen(a));
  output_bits(asctobin(b), strlen(b));
  output_bits(asctobin(c), strlen(c));
  output_bits(asctobin(d), strlen(d));
  output_bits(asctobin(e), strlen(e));
  tail = output_bits(asctobin(f), strlen(f));
  if (tail > 0) cout << buffer << endl << endl; //izvadam buferii palikuso dalu
   
  system("PAUSE");	
  return 0;
}
