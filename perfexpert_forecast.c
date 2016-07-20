//INTRO BLAHBLAH//
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
   int rc,given_counter,age,a_snprintf,b_snprintf,c_snprintf2,counter,id,edit_option,primary_key;
   int architecture = 6;
   float lower_bound,upper_bound,forecast;
   char sql[4096];
   char name[35];
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
	/*Creating SQLite perfexpert_forecast Table*/
	sql = "CREATE TABLE database1.db("	\
	"ID INT primary_key NOT NULL UNIQUE,"	\
	"architecture INT NOT NULL,"	\
	"lower_bound REAL NOT NULL,"	\
	"upper_bound REAL NOT NULL,"	\
	"forecast INT NOT NULL;)";

/*This will creat the table with certain arquitecture
a_snprintf = snprintf(sql,4096,"CREATE TABLE database1.db ID INT primary_key NOT NULL UNIQUE,architecture INT NOT NULL
,lower_bound REAL NOT NULL,upper_bound REAL NOT NULL,forecast INT NOT NULL;"); 
);//end of a_snprintf */

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
/* so that I can try to insert data manually
while{
	printf("Enter Lower_Bound data");
	scanf("%f",&lower_bound);
	printf("Enter Upper_Bound data");
	scanf("%f",&upper_bound );
	printf("Enter Forecast data")// this will be given in the future but for reference
	scanf("%f",&forecast);
      }(counter<=given_counter);//end of while
*/    
/*Expected function is to read what is in the table*/
while{
	//c_snprintf = snprintf(sql,4096,"'%s', %d,'%s',%d;",excution_sql,counter,name,age);
      	c_snprintf = snprintf(sql,4096,"INSERT INTO database1.db VALUES (%d,%d,%f,%f,%f",counter,architecture,lower_bound,upper_bound,forecast);
		printf("%s\n",sql);
			counter++;
}(counter<=given_counter);//end of while      
    
   sqlite3_close(db);
   return 0;
}//end of int main


/*
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
