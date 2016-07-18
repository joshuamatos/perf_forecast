/*sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";*/
 // blah blah
//ESTOY BUSCANDO LA MANERA DE COMO PONER LO DE ARRIBA EN UN LOOP//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include "perfexpert_database.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }//end of for
   printf("\n");
   return 0;
}//end of static int callback

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc,given_counter,age,a_snprintf,b_snprintf,c_snprintf2,counter,id,edit_option;
   int architecture = 6;
   float lower_bound,upper_bound,forecast;
   char sql[4096],char name[35];
   char excution_sql[] = "INSERT VALUE INTO";
   
   /* Open database */
   rc =  perfexpert_database_connect(&db,"perf_forecasttable.db");
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
 	     return(0);
           }	
   else{
      fprintf(stderr, "Opened database successfully\n"); //abracadabra
       }

/*This will creat the table with certain arquitecture*/
a_snprintf = snprintf(sql,4096,"CREATE TABLE database1.db (ID INT PRIMATY KEY NOT NULL UNIQUE,ARCHITECTURE INT NOT NULL
,LOWER_BOUND REAL NOT NULL,UPPER_BOUND REAL NOT NULL,FORECAST INT NOT NULL);" 
);//end of a_snprintf

printf("Table Created Successfully")


	/*SQLITE*/
  	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  	
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      	sqlite3_free(zErrMsg);
   }
   
   else{
      fprintf(stdout, "Records created successfully\n");
       }

/*THIS PRINTF IS GOING TO DICTATE HOW BIG IS GOING TO BE THE DATABASE*/
	printf("Enter de number of column you are going to insert in the database\n");
		scanf("%d",&given_counter);

/*This loop will insert one by one the values desire */

//MUST INCLUDE A OPTION JUST IN CASE, THE INFORMATION INPUT IS WRONG//
while{
//	c_snprintf = snprintf(sql,4096,"'%s', %d,'%s',%d;",excution_sql,counter,name,age);
	printf("Enter Lower_Bound data");
	scanf("", );
	printf("Enter Upper_Bound data");
	scanf("", );
	printf("Enter Forecast data")/* this will be given in the future but for reference*/
	scanf("",)
     /* printf("Is the data correct?, please enter 0 if incorrect")
	scanf("%d",&exit); 
     */
	printf("%s\n",sql);
	counter++;
	if(edit_option==0)
	{
	//
	}
//   }(counter<=given_counter);
//     }(counter<=given_counter && edit_option!=0 );
     
   sqlite3_close(db);
   return 0;
}//end of int main


for (counter = 0; counter < given_counter; ++counter)
{
	// THIS IS GOING TO ASK FOR ALL THE SQL INFORMATION NECESSARY FOR THE NECESSARY COLUMNS 
//######################################################################################//
c_snprintf = snprintf(sql,4096,"INSERT INTO PERFEXPERT_FORECAST %d,'%s',%d;",counter,name,age);
printf("%s\n",sql);
//###############THIS##IS##INCORRECT###################################################//

//system("cls");THIS IS JUST IN CASE....
}
*/
