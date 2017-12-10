#include <stdio.h>
#include <string.h>

int selection();
void display();
char* user_login();
void insert_review();

void menu_check()
{
    char *name;
    int sel = selection();
    printf("In menucheck()");
    if(sel == 1)
    {
        display();
    }

    else
    {
        strcpy(name, user_login());

        //if(strlen(name > 0))
            //insert_review(name);
    }
}
