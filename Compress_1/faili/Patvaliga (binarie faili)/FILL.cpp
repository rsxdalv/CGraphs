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
   clientData client;
   FILE *fPtr;

   if ((fPtr = fopen("credit.dat", "rb+")) == NULL) //rb+ rakstisana un lasisana binara rezima
	  cout << "File(s) could not be opened." << endl;
   else{
	  cout << "Enter account number (1 to 100, 0 to end input)" << endl;
	  scanf("%d", &client.accNum);

	  while (client.accNum != 0){
		 cout << "Enter lastname, firstname, balance" << endl;
		 cin >> client.Sur >> client.Name >> client.balance;
		 fseek(fPtr, (client.accNum-1) * sizeof(clientData), SEEK_SET);
		 // parametri: 1-fails, 2-pozicija, 3-meklesanas veids
		 // 2-pozicija saja gadijuma tas noteikts sareizinot kartas numuru ar mainiga izmeru

		 //SEEK_SET ³  0  ³ Seeks from beginning of file
		 //SEEK_CUR ³  1  ³ Seeks from current position
		 //SEEK_END ³  2  ³ Seeks from end of file

		 fwrite(&client, sizeof(clientData), 1, fPtr);
		 cout << "Enter account number" << endl;
		 cin >> client.accNum;
	  }
   }

   fclose(fPtr);
   system("Pause");
   return 0;

}
