using namespace std;
#include <iostream>
#include <libpq-fe.h>

PGconn *cnn = NULL;
PGresult *result = NULL;
PGresult *prom = NULL;


char *host = "sebastian.cl";
char *port = "5432";
char *dataBase = "iswdb";
char *user = "isw";
char *passwd = "isw";

