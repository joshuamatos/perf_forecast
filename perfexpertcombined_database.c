/*
 * Copyright (c) 2011-2016  University of Texas at Austin. All rights reserved.
 *
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * This file is part of PerfExpert.
 *
 * PerfExpert is free software: you can redistribute it and/or modify it under
 * the terms of the The University of Texas at Austin Research License
 *
 * PerfExpert is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.
 *
 * Authors: Antonio Gomez-Iglesias, Leonardo Fialho and Ashay Rane
 *
 * $HEADER$
 */
 
#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>

#include "perfexpert_database.h"

/*  db: database to disconnect 
 *  filename: name of the file in disk (with path)
 */
int perfexpert_database_disconnect(sqlite3 *db, char *filename) {
    char *my_file = NULL;
    sqlite3_backup *pBackup;
    sqlite3 *disk_db;

    /* Sanity check: only disconnect from a DB which is connected */
    if (NULL == db) {
        return PERFEXPERT_SUCCESS;
    }

    /* Open the DB on disk */
    my_file = (char *) malloc((strlen(filename)+1)*sizeof(char));

    sprintf(my_file, "%s", filename);

    if (SQLITE_OK != sqlite3_open(my_file, &disk_db)) {
        printf ("ERROR while opening database (%s) -> %s\n", my_file, sqlite3_errmsg(disk_db));
        return PERFEXPERT_ERROR;
    }

    /* Copy the data from disk DB to in-memory DB */
    pBackup = sqlite3_backup_init(disk_db, "main", db, "main");
    if (pBackup){
      (void)sqlite3_backup_step(pBackup, -1);
      (void)sqlite3_backup_finish(pBackup);
    }
    if (SQLITE_OK != sqlite3_errcode(db)) {
        printf ("ERROR while writting to database (%s) -> %s\n", my_file, sqlite3_errmsg(disk_db));
        free(my_file);
        return PERFEXPERT_ERROR;
    }
    free (my_file);

    sqlite3_close(db);
    sqlite3_close(disk_db);

    printf ("Disconnected from database (saved in %s)\n", filename);

    return PERFEXPERT_SUCCESS;
}

/* perfexpert_database_connect */
/*  db: database connected
 *  file: path of the file 
 */
int perfexpert_database_connect(sqlite3 **db, const char *file) {
    sqlite3_backup *pBackup;
    sqlite3 *disk_db;
    char *error = NULL;

    /* Check if file exists */
    if (-1 == access(file, F_OK)) {
        printf ("Error: file not found (%s)\n", file);
        sqlite3_close(*db);
        sqlite3_close(disk_db);
        return PERFEXPERT_ERROR;
    }

    /* Open the DB on disk */
    if (SQLITE_OK != sqlite3_open(file, &disk_db)) {
        printf ("Error opening database (%s)\n", file);
        sqlite3_close(*db);
        sqlite3_close(disk_db);
        return PERFEXPERT_ERROR;
    }

    /* Open the DB in memory */
    if (SQLITE_OK != sqlite3_open(":memory:", db)) {
        printf ("Error opening database in memory (%s)\n", file);
        sqlite3_close(*db);
        sqlite3_close(disk_db);
        return PERFEXPERT_ERROR;
    }

    /* Copy the data from disk DB to in-memory DB */
    pBackup = sqlite3_backup_init(*db, "main", disk_db, "main");
    if (pBackup) {
        (void)sqlite3_backup_step(pBackup, -1);
        (void)sqlite3_backup_finish(pBackup);
    }
    if (SQLITE_OK != sqlite3_errcode(*db)) {
        sqlite3_close(*db);
        sqlite3_close(disk_db);
        return PERFEXPERT_ERROR;
    }
    
    printf ("Connected to %s\n", file);

    return PERFEXPERT_SUCCESS;
}

/* perfexpert_database_get_int */
/*  This function returns an int in var */
int perfexpert_database_get_int(void *var, int count, char **val,
    char **names) {
    int *temp = (int *)var;
    if (NULL != val[0]) {
        *temp = atoi(val[0]);
    }
    return PERFEXPERT_SUCCESS;
}

/* perfexpert_database_get_unsigned_long_long_int */
/*  This function returns a long long int in var */
int perfexpert_database_get_long_long_int(void *var, int count, char **val,
    char **names) {
    int *temp = (int *)var;
    if (NULL != val[0]) {
        *temp = strtoll(val[0], NULL, 10);
    }
    return PERFEXPERT_SUCCESS;
}

/* perfexpert_database_get_double */
/*  This function returns a double in var */
int perfexpert_database_get_double(void *var, int count, char **val,
    char **names) {
    double *temp = (double *)var;
    if (NULL != val[0]) {
        *temp = atof(val[0]);
    }
    return PERFEXPERT_SUCCESS;
}

/* perfexpert_database_get_string */
/*  This function returns a string in var */
int perfexpert_database_get_string(void *var, int count, char **val,
    char **names) {
    char **temp = (char **)var;
    if (NULL != val[0]) {
        *temp = (char*) malloc(strlen(val[0] + 1)*sizeof(char));
        strcpy(*temp, val[0]);
    }
    return PERFEXPERT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
