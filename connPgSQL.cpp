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

int main(int argc, char * argv[])
{
    int i;
    cnn = PQsetdbLogin(host,port,NULL,NULL,dataBase,user,passwd);

    cout << " Integrantes "<<endl;
    cout << " Astudillo Loreta "<<endl;
    cout << " Ibarra Mario "<<endl;
    cout << " Muñoz Abraham "<<endl;



    if (PQstatus(cnn) != CONNECTION_BAD)
    {
        cout << "Conectado a PostgreSQL!" << endl;

        result = PQexec(cnn, "SELECT * FROM cursos");

        if (result != NULL)
        {
  result =PQexec(cnn,"SELECT distinct docente_id FROM cursos");
  int tuplas = PQntuples(result);
         int campos = PQnfields(result);
  for (i=0; i<tuplas; i++) {
                for (int j=0; j<campos; j++) {
      cout <<"ID Docente : ";
                    cout << PQgetvalue(result,i,j) << " | ";

                }
                cout << endl;
                }

        // liberar la memoria
        PQclear(result);
        }
    }

    else {
        cout << "Error de conexion" << endl;
        return 0;
    }

    PQfinish(cnn);

    return 0;
}
