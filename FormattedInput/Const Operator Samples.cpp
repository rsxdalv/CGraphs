int MyFunction (const int a)
//funkcija MyFunction nevar mainiit a mainiigas veertiibu
{
	a=5;//kluuda
}


int ManaKlase::MyFunction(int a, int b) const
//funkcija MyFunction nevar mainiit klases ManaKlase klases objektus
//jeb objektu elementu veertiibas


const int ManaKlase::MyFunction()
//nelauj mainiit elementu veertiibu caur atgriezto rezultaatu
{
	return data;
}

MansObjekts.MyFunction()=8; //kluuda
//jeb nelauj izmantot funkcijas rezultaatu pa kreisi no pieskirsanas operatora
