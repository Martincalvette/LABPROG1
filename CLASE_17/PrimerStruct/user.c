#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "user.h"


static int isValidid(int id);
static int isValidname(char*name);
static int isValidEmail(char*email);

User* new_user()
 {
    return (User*) malloc (sizeof(User));
 }

User* user_NewParametros(int id, char* name, char email)
{
    User* this = new_user();
    if (this == NULL ||
        user_Setid(this,id) ||
        user_Setname(this,name) ||
        user_SetEmail(this,email))
        {
            user_delete(this);
            this =NULL;
        }
    return this;

}


int user_Setid(User* this,int id)
{
    int retorno=-1;

    if(this !=NULL && isValidid(id))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int user_Setname(User* this,char* name)
{
    int retorno=-1;

    if(this !=NULL && isValidname(name))
    {
         strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int user_SetEmail(User* this,char* email)
{
    int retorno=-1;

    if(this !=NULL && isValidEmail(email))
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}


 void user_delete(User* this)
 {
    free (this);
 }

static int isValidid(int id)
{
    return 1;
}
static int isValidname(char* name)
{
    return 1;
}

static int isValidEmail(char*email)
{
    return 1;
}

void listarUser(User* this)
{
    printf("\n %d - %s - %s",this->id,this->name,this->email);
}
