#include <stdio.h>
#include <string.h>

void ltrim(char p[])
{
	int i;
	for (i=0; i<strlen(p)-1; i++)
	{
		p[i] = p[i+1];
	}
	printf("\nNew code ");
	puts(p);
}

int main()
{
	char data[12];
	char divisor[12];
	char code[12];
	int i,j,data_length,div_length,k=0;
	strcpy(code,"");
	printf("Enter the data : ");
	gets(data);
	printf("\nEnter the divisor : ");
	gets(divisor);
	for (i=0; i<strlen(divisor); i++)
	{	
		if (divisor[i] == data[i])
		{
			code[i] = '0';
		}
		else
		{
			code[i] = '1';
		}
	}

	for (i=strlen(divisor); i<strlen(data); i++)
	{
		while(code[0] == '0')
		{
			if (k==1)
				i++;
			ltrim(code);
			k = 1;
			code[strlen(divisor)-1] = data[i];
			
		}
		k = 0;
		printf("\nNext code");
		puts(code);
		for(j=0; j<strlen(divisor); j++)
		{
			if(divisor[j] == code[j])
			{
				code[j] = '0';
			}
			else
				code[j] = '1';
		}
	}
	printf("\nThe final code bits are : ");
	for (i=1; i<strlen(divisor); i++)
		printf("%c ", code[i]);
	return 0;
}	
