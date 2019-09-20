#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	(void)ac;
	int i = 5;
	char *new;
	char *name = "Sully_";
	char *tmp;
	char *test;
	if (strchr(av[0], '_') && i >= 0)
		i--;
	if (i >= 0)
	{
		char c = i + '0';(void)c;
		asprintf(&tmp,"%s%d",name,i);
		asprintf(&new,"%s%s",tmp,".c");
		FILE * fp = fopen (new, "w+");
		char*a="#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c%cint main(int ac, char **av)%c{%c%c(void)ac;%c%cint i = %i;%c%cchar *new;%c%cchar *name = %cSully_%c;%c%cchar *tmp;%c%cchar *test;%c%cif (strchr(av[0], %c_%c) && i >= 0)%c%c%ci--;%c%cif (i >= 0)%c%c{%c%c%cchar c = i + %c0%c;(void)c;%c%c%casprintf(&tmp,%c%cs%cd%c,name,i);%c%c%casprintf(&new,%c%cs%cs%c,tmp,%c.c%c);%c%c%cFILE * fp = fopen (new, %cw+%c);%c%c%cchar*a=%c%s%c;%c%c%cfprintf(fp,a,10,10,10,10,10,10,9,10,9,i,10,9,10,9,34,34,10,9,10,9,10,9,39,39,10,9,9,10,9,10,9,10,9,9,39,39,10,9,9,34,37,37,34,10,9,9,34,37,37,34,34,34,10,9,9,34,34,10,9,9,34,a,34,10,9,9,10,9,9,10,9,9,34,37,37,37,34,10,9,9,10,9,9,9,10,9,9,10,9,9,9,10,9,10,10);%c%c%cfclose(fp);%c%c%casprintf(&test,%cclang -Wall -Wextra -Werror -o %cs %cs ; ./%cs%c,tmp,new,tmp);%c%c%cif (i > 0)%c%c%c%csystem(test);%c%c%celse if (i == 0)%c%c%c%csystem(test);%c%c}%c}%c";
		fprintf(fp,a,10,10,10,10,10,10,9,10,9,i,10,9,10,9,34,34,10,9,10,9,10,9,39,39,10,9,9,10,9,10,9,10,9,9,39,39,10,9,9,34,37,37,34,10,9,9,34,37,37,34,34,34,10,9,9,34,34,10,9,9,34,a,34,10,9,9,10,9,9,10,9,9,34,37,37,37,34,10,9,9,10,9,9,9,10,9,9,10,9,9,9,10,9,10,10);
		fclose(fp);
		asprintf(&test,"clang -Wall -Wextra -Werror -o %s %s ; ./%s",tmp,new,tmp);
		if (i > 0)
			system(test);
		else if (i == 0)
			system(test);
	}
}
