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

   if ((fPtr = fopen("credit.dat", "rb")) == NULL)
	  cout << "File(s) could not be opened." << endl;
   else{
	  cout << "Account   " << "Surname   " << "Name   " << "Ballance" << endl;
	 while(!feof(fPtr)){ // lasam lidz faila beigam
		 fread(&client, sizeof(clientData), 1, fPtr);
		 if (client.accNum !=0)
			cout << client.accNum <<"   " << client.Sur << "   " << client.Name << "   " << client.balance << endl;
	  }
   }
   fclose(fPtr);
   system("Pause");
   return 0;


}
