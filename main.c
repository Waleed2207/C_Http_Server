
#include "httpd.h"
#include "includes.h"
#include "router.c"

int main(int argc, char *argv[])
{
    serve_forever("8005");
    return 0;
}


