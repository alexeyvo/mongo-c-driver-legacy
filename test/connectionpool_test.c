/* connect_test.c */
/* this file should be removed when mongo_connect changes from deprecated to eliminated */

#include "test.h"
#include "mongo.h"
#include "connection_pool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    mongo_connection_dictionary dict;
    mongo_connection_pool *pool;
    mongo_connection *conn;    

    INIT_SOCKETS_FOR_WINDOWS;

    mongo_connection_dictionary_init( &dict );
    pool = mongo_connection_dictionary_get_pool( &dict, "mongodb://localhost/");

    ASSERT( pool );

    conn = mongo_connection_pool_acquire( pool );

    ASSERT( conn );

    if(conn->err == MONGO_CONNECTION_SUCCESS ) 
    {
      mongo_connection_disconnect( conn );
    }
    else
    {
      printf("fail connecting/n");
    }

    mongo_connection_pool_release( pool, conn );
	
	mongo_connection_dictionary_destroy( &dict );
    
    return 0;
}
