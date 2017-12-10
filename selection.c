#include <stdio.h>
#include <stdlib.h>

int selection()
{
    int input;

    printf("\n\nMain menu:");
    printf("\n----------");
    printf("\n\n1.Display Review's \n");
    printf("2.Insert  Review's \n");
    printf("3.Ratting Score \n");
    printf("0.Exit \n\n>_ ");

    scanf("%d", &input);
    while(1)
    {
        if(input == 1)
            return 1;

        else if(input == 2)
            return 2;

        else if(input == 3)
            return 3;

        else if(input == 0)
        {
            exit(1);
        }

        printf("\nWrong input!");
        printf("\nPlease Enter following Command.");
        printf("\n\nMain menu:");
        printf("\n----------");
        printf("\n\n1.Display Review's \n");
        printf("2.Insert  Review's \n");
        printf("3.Ratting Score \n");
        printf("0.Exit \n\n>_ ");
        scanf("%d", &input);
    }
}

