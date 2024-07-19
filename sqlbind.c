#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

void retrieve(sqlite3* db) {
    const char* query = "SELECT * FROM Computers;";
    sqlite3_stmt* stmt;
    int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

    if(result != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        return;
    }


    while((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        int n = sqlite3_column_count(stmt);
        for(int i = 0; i < n; i++) {
            switch(sqlite3_column_type(stmt, i)) {
                case SQLITE_INTEGER :
                    printf("%s\n", sqlite3_column_text(stmt, i));
                    break;
                case SQLITE_FLOAT :
                    printf("%s\n", sqlite3_column_double(stmt, i));
                    break;
                case SQLITE_TEXT :
                    printf("%s\n", sqlite3_column_text(stmt, i));
                    break;
                }
        }
    }


    if(result != SQLITE_DONE) {
        printf("Error: %s\n", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);
}
