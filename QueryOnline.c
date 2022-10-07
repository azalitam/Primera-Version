#include <stdio.h>
//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	} //Crea la conexion a la base de datos, retorna 1 si no puede.
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "Juego", 0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	} //Inntenta iniciar conexion recien creada, retorna 1 si no pude.

	err = mysql_query(conn, "SELECT * FROM Usuarios");
	if (err != 0) {
		printf("Error al consultar datos de la base %u %s\n",
			mysql_errno(conn), mysql_error(conn));
		exit(1);
	}//consulta la tabla con todos los datos, retorna 1 si no puede
	resultado = mysql_store_result(conn); //Tabla de memoria virtual con todos los datos

	row = mysql_fetch_row(resultado);
	if (row == NULL)
		printf("No se han obtenido datos en la consulta\n");
	else
		while (row != NULL) {
			// la columna 0 contiene una palabra -->id
			// la convertimos a entero 
			id = atoi(row[0]);
			// las columnas 1 y 2 y 3 contienen nombre, Contraseña y Estado 
			printf("nombre: %s, Contraseña: %s, Estado: %d\n", row[1], row[2],row[3], id);
			// obtenemos la siguiente fila
			row = mysql_fetch_row(resultado);
		}

	// construimos la consulta SQL
	strcpy(consulta, "SELECT Usuarios.nombre FROM (Usuarios) WHERE Usuarios.Estado= 'Online'");
	strcat(consulta, Estado);
	strcat(consulta, "'");
	// hacemos la consulta 
	err = mysql_query(conn, consulta);
	if (err != 0) {
		printf("Error al consultar datos de la base %u %s\n",
			mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	resultado = mysql_store_result(conn);
	row = mysql_fetch_row(resultado);
	if (row == NULL)
		printf("No se han obtenido datos en la consulta\n");
	else
		
		printf("Personas Online: %s\n", row[0]);
	mysql_close(conn);
	exit(0);
}



	