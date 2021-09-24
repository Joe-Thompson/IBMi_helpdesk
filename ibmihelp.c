#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	bool running = true;
	char select[15];

	printf("\n\n-----IBM i Command Help Desk-----\n");
	
	while (running)
	{
		printf("\nE: End Program   LC: List Commands   <insert cmd>: Displays Informatrion\n");
		printf("Please enter a command:  ");
		scanf("%s", &select);
		

		printf("\n%s\n", select);

		for (int i = 0; i <= strlen(select); i++)
		{
			printf("%c", toupper(select[i]));
		}

		if(strlen(select) <= 1)
		{
			running = false;
		}


	}
	


	return 0;
}