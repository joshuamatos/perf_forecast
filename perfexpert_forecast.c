
/*sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";*/
//ESTOY BUSCANDO LA MANERA DE COMO PONER LO DE ARRIBA EN UN LOOP//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include "perfexpert_database.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stderr, "Opened database successfully\n"); //abracadabra
      fprintf(stderr,"Its alive Its alive \n");
   }

//SQLITE

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

//THIS IS THE INFORMATION THAT IM GOING TO ASK THE USER FOR//
int given_counter,age,c_snprintf,c_snprintf2;
char names[35];
char buffer[100];
char buffer_2[100]
//

//THIS PRINTF IS GOING TO DICTATE HOW BIG IS GOING TO BE THE DATABASE
//sprintf & sscanf if it does not work//
printf("Enter de number of column you are going to add in the database\n");
scanf(%d,&given_counter);

//THIS LOOP IS TO DO THE SAME THAT IS IN THE CORNER UP BUT DOING IT MANUALLY//
//MUST INCLUDE A OPTION JUST IN CASE, THE INFORMATION INPUT IS WRONG//
for (int counter = 0; counter < given_counter; ++counter)
{
	// THIS IS GOING TO ASK FOR ALL THE SQL INFORMATION NECESSARY FOR THE NECESSARY COLUMNS 
	sql ="INSERT INTO DATABASE(ID,NAME,AGE,ADDRESS)"
	//REMEBER TO INCLUDE ALL THE PRINTF//
//######################################################################################//
c_snprintf=snprintf (sql,buffer,100,"INSERT INTO DATABASE'%d','%s','%d',%s;",ID,NAME,AGE,ADDRESS);
//###############THIS##IS##INCORRECT###################################################//

//NO SE SI ES & o el Pointer *
          //"VALUES(&counter,'&names','&age','company_name',&salary)"
//system("cls");THIS IS JUST IN CASE....
}//Chewie we are home...
