
#include "httpd.h"
#include "includes.h"

#define BUF_SIZE 1024

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        char* response = get_Data();
        printf("%s", response);
        free(response);
    }


    ROUTE_POST("/home")
    {
        char *page = HomePage(payload);
        printf("%s",  page);
        free(page);
    }

    ROUTE_POST("/register") 
    {
        char *page = SignUP(payload);
        printf("%s",  page);
        free(page);
    }
  
    ROUTE_END()
}
