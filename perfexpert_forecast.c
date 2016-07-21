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
   rc =  perfexpert_database_connect(&db,"database.db"); //Changed the name of the DB to database.db
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
 	     return(0);
           }	
   else{
      fprintf(stderr, "Opened database successfully\n"); //abracadabra
       }
	/*Creating SQLite perfexpert_forecast Table*/
   snprintf (sql, 4096, "CREATE TABLE perfexpert_forecast (ID INT primary_key NOT NULL UNIQUE, \
             architecture INT NOT NULL, lower_bound REAL NOT NULL, upper_bound REAL NOT NULL, \
             forecast INT NOT NULL);"); 
             
/*	sql = "CREATE TABLE perfexpert_forecast (" \ //Created table perfexpert_forecast in database.db
	"ID INT primary_key NOT NULL UNIQUE," \
	"architecture INT NOT NULL," \
	"lower_bound REAL NOT NULL," \
	"upper_bound REAL NOT NULL," \
	"forecast INT NOT NULL;)";
*/
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
//	printf("Enter de number of column you are going to insert in the database\n");
//		scanf("%d",&given_counter);

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
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (1,6,0,0.5,16)");
    // Put here the command to run a sql statement
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (2,6,0.5,0.6,14)");
    // Again, put here the command to run a sql statement
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (3,6,0.5,0.6,12)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (4,6,0.65,0.65,10)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (5,6,0.70,0.70,8)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (6,6,0.75,0.75,6)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (7,6,0.80,0.80,5)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (8,6,0.90,0.90,4)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (9,6,1.00,1.00,3)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (10,6,1.50,1.50,2)");
      snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (11,6,2.50,100,1)");

    // Here, add the next values to the table until the table is created
    /*  
while{
	//c_snprintf = snprintf(sql,4096,"'%s', %d,'%s',%d;",excution_sql,counter,name,age);
    rc = snprintf(sql,4096,"INSERT INTO perfexpert_forecast VALUES (%d,%d,%f,%f,%f",counter,architecture,lower_bound,upper_bound,forecast);
		printf("%s\n",sql);
			counter++;
}(counter<=given_counter);//end of while      
    */
   sqlite3_close(db);
   return 0;
}//end of int main
