#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

//estructura
struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion[50];
	int telefono;
};
 void ingresar_estudiante();
void abrir_estudiante();
 void modificar_estudiante();
 void buscar_codigo();
 void eliminar_estudiante();
int main (){
	abrir_estudiante();
 	ingresar_estudiante();
	modificar_estudiante();
	//buscar_codigo();
	eliminar_estudiante();
	return 0;	
}

void buscar_codigo(){
		FILE* archivo = fopen(nombe_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);	
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Direccion: "<<estudiante.direccion<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   }
	   fread(&estudiante,sizeof(Estudiante),1,archivo);	
	} while(feof(archivo)==0);
	fclose(archivo);
}

void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Direccion: " << estudiante.direccion << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);
}


void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"__________________________________________________________________________________________"<<endl;
	cout << "ID" <<"|"<< "Codigo" <<"|"<< "Nombre"<<"|"<<"Apellido"<<"|"<<"Dirección"<<"|"<<"Telefonó"<<"|"<<endl;	
		do{
		cout<<"______________________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" | "<<estudiante.apellido<<" | "<<estudiante.direccion<<" | "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	
	
		Estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
	//buscar_indice();	
	buscar_codigo();
}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	Estudiante estudiante;
    
		cout << "Escriba el ID que desea modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}
void eliminar_estudiante(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	Estudiante estudiante;
	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
	int id=0,i=0;
		cout<<"ingrese el id para eliminar al estudiante:"; 
	cin>>id; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
			
			if (i != id){
				fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
			} 
			
			i++; 
		}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombe_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	abrir_estudiante();
		system("PAUSE");
}
