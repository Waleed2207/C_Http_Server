
#include "httpd.h"
#include "includes.h"

#define BUF_SIZE 1024

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        char* responst = getIndex();
        printf("%s", responst);
        free(responst);
    }


    ROUTE_POST("/home")
    {
        char *page = loadHome(payload);
        printf("%s",  page);
        free(page);
    }

    ROUTE_POST("/register") 
    {
        char *page = signUP(payload);
        printf("%s",  page);
        free(page);
    }
  
    ROUTE_END()
}
