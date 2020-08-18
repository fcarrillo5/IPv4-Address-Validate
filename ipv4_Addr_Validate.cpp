//============================================================================
// Name        : ipv4_Addr_Validate
// Author      : Freddy Carrillo
// Version     : 1.0
// Date        : 17 August 2020
// Description : Basic program that checks / validates IPv4 address.
//               N1.N2.N3.N4 network address. 
//               Constrain 0 <= N <= 255. For example, 192.168.88.1 displays
//               VALID. For 192.168.10.256 displays INVALID
//============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char	str[16];		// IPv4 characters
	char 	*tok;			// tokens
	int  	k;				// holds conversion from string to int
	int 	cntr = 0;		// counter for each 8-bit section in IP addr

	printf("Enter IP address: ");	// Input IPv4
	fflush(stdout);
	scanf("%15s", str);

	tok = strtok(str, ".");			// get first token

	while (tok != NULL)
	{
		printf("<<%s>>\n", tok);
		k = atoi(tok);				// convert to int
		if ((k >= 0) && (k <= 255)) // validate (0 <= n <= 255)
		{
			cntr++;
			if (cntr == 4)			// if pass all four network sections
			{
				printf("\nVALID\n\n"); // display valid
				break;
			}
		}
		else
		{
			printf("\nINVALID\n\n"); // display invalid otherwise
			break;
		}

		tok = strtok(NULL, ".");	// get next token until NULL
	}

    return 0;
}
