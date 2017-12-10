#include <stdio.h>

int teacher_select()
{
    char teacher_no;

    printf("\n\n1.Mahabub Alom\n");
    printf("2.Milon Biswas\n");
    printf("3.Shamim Reza\n");
    printf("0.Main menu.\n\n>_");

    while(1)
    {
        scanf(" %c", &teacher_no);

        if(teacher_no >= 48 && teacher_no <= 51)
        {
            break;
        }

        printf("\n\nWrong Input!");
        printf("\n\n1.Mahabub Alom\n");
        printf("2.Milon Biswas\n");
        printf("3.Shamim Reza\n");
        printf("0.Main menu\n\n>_");
    }

    return ((int)teacher_no - 48);
}
