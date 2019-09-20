#include <stdio.h>
void lol(){}
/*
	lol1
*/
int main()
{
	char*a="#include <stdio.h>%cvoid lol(){}%c/*%c%clol1%c*/%cint main()%c{%c%cchar*a=%c%s%c;%c%cprintf(a,10,10,10,9,10,10,10,10,9,34,a,34,10,9,10,9,10,9,10,9,9,10,9,10,10);%c%clol();%c%c/*%c%c%clol2%c%c*/%c}%c";
	printf(a,10,10,10,9,10,10,10,10,9,34,a,34,10,9,10,9,10,9,10,9,9,10,9,10,10);
	lol();
	/*
		lol2
	*/
}
