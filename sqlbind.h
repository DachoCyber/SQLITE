#ifndef _SQLBIND_H_
#define _SQLBIND_H_


/**
    sqlite3_bind_text binds text to sql query. For instance, if
    const char* query = "INSERT INTO table_name (column1, column2, ...) VALUES (?, ?, ...);";
    then for each question mark, function sqlite_bind_text inserts char* text
    Parameter void(*)(void*) = SQLITE_TRANSIENT
*/
void sqlite3_bind_text(sqlite3_stmt* stmt, int col, char* text, int nByte, void(*)(void*));


/**
    sqlite3_bind_int binds integer valueToBind to column in sqlite3_stmt* stmt
*/


void sqlite3_bind_int(sqlite3_stmt* stmt, int col, int value);




/**
    BLOB stands for “Binary Large Object” and represents a
    database type to store binary data.
    Specifically, examples of BLOBs (Binary Large Objects) are complex files
    such as images, video, and audio.
*/
void sqlite3_blob(sqlite3*, const char *zDb, const char *zTable, const char *zColumn, sqlite3_int64 iRow, int flags, sqlite3_blob **ppBlob);
/**
    const char *zDb = "main";
    const char *zTable = "my_table";
    const char *zColumn = "my_blob_column";
    sqlite3_int64 iRow = 1;
    int flags = SQLITE_BLOB_READ/SQLITE_BLOB_WRITE;

    int flags: Specifies the read/write access mode for the BLOB. The value can be one of the following:
    SQLITE_BLOB_READ: Open the BLOB for read-only access.
    SQLITE_BLOB_WRITE: Open the BLOB for read and write access.

    sqlite3_int64: The row ID of the row containing the BLOB you want to access. This identifies the specific row in the table.

    // Open the database connection
    sqlite3_open("my_database.db", &db);

    // Open a handle to the BLOB
    sqlite3_blob_open(db, zDb, zTable, zColumn, iRow, flags, &blob);

    // Perform read/write operations on the BLOB using sqlite3_blob_read or sqlite3_blob_write

    // Close the BLOB handle
    sqlite3_blob_close(blob);

    // Close the database connection
    sqlite3_close(db);

*/

#endif // _SQLBIND_H_
