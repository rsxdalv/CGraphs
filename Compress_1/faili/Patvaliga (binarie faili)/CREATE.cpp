#include <stdio.h>
#include <iostream.h>

struct clientData{
   int accNum;
   char Sur[15];
   char Name[10];
   float balance;
};

int main(){

   int i;
   clientData blankClient = {0, "", "", 0.0};
   //ieraksts ar tuksumiem
   FILE *fPtr;

   if ((fPtr = fopen("credit.dat", "wb")) == NULL) //wb - rakstisana binara rezima
	  cout << "File(s) could not be opened." << endl;
   else{
	  for (i=1; i<=100; i++)
		 fwrite(&blankClient, sizeof(clientData), 1, fPtr);
		 //parametri 1-mainigais, 2-mainiga izmers, 3-mainigo skaits, 4-atsauce uz failu
	  fclose(fPtr);
   }
   system("Pause");
   return 0;

}
