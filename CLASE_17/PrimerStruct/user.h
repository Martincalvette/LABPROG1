#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
typedef struct
{
  int id;
  char name[33];
  char email[65];
} User;

User* new_user();
User* user_NewParametros(int id, char* name, char email);
int user_Setid(User* this,int id);
int user_Setname(User* this,char* name);
int user_SetEmail(User* this,char* email);
void user_delete(User* this);
void listarUser(User* this);

#endif // USER_H_INCLUDED
