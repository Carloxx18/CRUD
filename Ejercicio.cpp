#include <iostream>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void crear();
void leer();
void actualizar();
void eliminar();
main(){
	int ops, b;
	cout<<"\t\t\t\tINGRESE EL NUMERO DE LA ACCION QUE DESEE USAR"<<endl;
	cout<<"\t\t\t\tCreado por: Carlos Andres De Leon Andrade"<<endl<<endl;
	
	cout<<"1- Ver registros"<<endl;
	cout<<"2- Crear registros"<<endl;
	cout<<"3- Modificar registros"<<endl;
	cout<<"4- Eliminar registros"<<endl;
	cin>>ops;
	system ("cls");
	switch(ops){
		case 1:
		leer();
		break;

		case 2:
		crear();
		break;

		case 3:
		actualizar();
		break;

		case 4:
		eliminar();
		break;
	}

	cout<<"\n";
	cout<<"--------------------------------------------"<<endl;
	cout<<"Desea regresar al menu?"<<endl;
			cout<<"si = 1"<<endl;
			cout<<"no= 2"<<endl;	
			cin>> b;
			if (b==1)
			{
			system("cls");
			return	main();
			}else{
				exit (-1);
			}
	
	
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desa Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:  ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	
}
void eliminar(){


	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID del registro que desee eliminar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);

	estudiante.codigo=0;
	estudiante.	nombres[50]=0;
	estudiante.apellidos[50]=0;
	estudiante.	telefono=0;
	
	cout<<"\nSE ELIMINO EL REGISTRO"<<endl;
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	
}


