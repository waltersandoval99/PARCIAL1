#include <iostream>
#include <fstream>
#include <windows.h>
//Walter Antonio Sandoval López
//Ingenieria en Sistemas
//Sede Florida seccion A
//Agusto Armando Cardona

using namespace std;
int menu(){
	int x;
	system("cls");
	cout<<"PROGRAMA DE EMPLEADOS PARCAIL 1"<<endl;
	cout<<"PROGRAMACION 1 "<<endl;
	cout<<"________________________________"<<endl<<endl;
	cout<<"========BIENBENIDO======="<<endl<<endl;
	cout<<"1. Agregar Empleado"<<endl;
	cout<<"2. Ver Empleado"<<endl;
	cout<<"3. Buscar Empleado"<<endl;
	cout<<"4. modificar Empleado"<<endl;
	cout<<"5. Eliminar Empleado"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"========================="<<endl;
	cout<<"Opcion: ";
	cin>>x;
	return x;
	
}

bool verifica(string Id){
 ifstream leer ("registro.dat", ios::in);
 string id;
 string nom;
 string Ap;
 string pu;
 int su;
 int bo;
 int sum;
 leer>>id;
 while(!leer.eof()){
  leer>>Ap;
  leer>>nom;
  leer>>pu;
  leer>>su;
  leer>>bo;
  leer>>sum;
  if(id == Id){
   cout<<"\n\n\tError: Registro duplicado.\n\n";
   system("pause");
   leer.close();
   return false;
  }
  leer>>id;
 }
   leer.close();
   return true; 
}
void agregar(ofstream &es) {
	system("cls");
	string id;
	string Ap;
	string nom;
	string pu;
	int su;
	int bo;
	int sum;
	es.open("registro.dat", ios::out| ios::app);
	cout<<"id:  ";
	cin>>id;
	cout<<"Apellido    :";
	cin>>Ap;
	cout<<"Nombre      :";
	cin>>nom;
	cout<<"Puesto      :";
	cin>>pu;
	cout<<"Sueldo      :";
	cin>>su;
	cout<<"Bonificacion:";
	cin>>bo;
	sum = su + bo;
	cout<<"El sueldo total es: "<<sum<<endl;
	
	if(verifica(id))
		es<<id<<" "<<Ap<<" "<<nom<<" "<<pu<<" "<<su<<" "<<bo<<" "<<sum<<"\n";
	es.close();
	}

void verRegistros(ifstream &Lec){
	system("cls");
	string id;
 	string nom;
 	string Ap;
 	string pu;
 	int su;
 	int bo;
 	int sum;
 	Lec.open("registro.dat", ios::in);
 	if(Lec.is_open()){
	 	cout<<"-------Empleados guardados-------"<<endl<<endl;
	 	Lec>>id;
	 	while(!Lec.eof()){
			Lec>>Ap;
			Lec>>nom;
			Lec>>pu;
			Lec>>su;
			Lec>>bo;
			Lec>>sum;
			cout<<"ID--------------: "<<id<<endl;
			cout<<"Nombre----------: "<<nom<<endl;
			cout<<"Apellido--------: "<<Ap<<endl;
			cout<<"Puesto----------: "<<pu<<endl;
			cout<<"sueldo----------: "<<su<<endl;
			cout<<"bonificacion----: "<<bo<<endl;
			cout<<"Sueldo a rec----: "<<sum<<endl;
			cout<<"----------------------"<<endl;
			Lec>>id;
		 }
		 Lec.close();
	}else
		cout<<"Error"<<endl;
	 system("pause");
}



void buscarregistro(ifstream &Lec){
	system("cls");
	Lec.open("registro.dat", ios::in);
	string id, Ap, nom, pu, idaux;
	int su, bo, sum;
	bool encontrado = false;
	cout<<"Digite la ID: ";
	cin>>idaux;
	Lec>>id;
	while(! Lec.eof() && !encontrado){	
		Lec>>id;
		Lec>>Ap;
		Lec>>nom;
		Lec>>pu;
		Lec>>su;
		Lec>>bo;
		Lec>>sum;
		if(id == idaux){
			cout<<"==Id========: "<<id<<endl;
			cout<<"==Nombre====: "<<nom<<endl;
			cout<<"==Apellido==: "<<Ap<<endl;
			cout<<"==Puesto====: "<<pu<<endl;
			cout<<"==Sueldo====: "<<su<<endl;
			cout<<"==Bonifi...=: "<<bo<<endl;
			cout<<"==Total=====: "<<sum<<endl;
			cout<<"----------------------"<<endl;
			encontrado = true;
		}	
		Lec>>id;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"DATO NO ENCONTRADO"<<endl<<endl;
	system("pause");
}

void modificar(ifstream &Lec){
	system("cls");
 	string Ap;
 	string id;
	string nom;
	string pu;
	int su;
	int bo;
	int sum;
	string idaux;
	string Apaux;
	string nomaux;
	string puaux;
	int suaux;
	int boaux;
	int sumaux;
	Lec.open("registro.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Palabras a modificar--------------------"<<endl;
		cout<<"Ingrese dato id:  ";
		cin>>idaux;
		Lec>>id;
		while(!Lec.eof()){
		  	Lec>>Ap;
			Lec>>nom;
			Lec>>pu;
			Lec>>su;
			Lec>>bo;
			if(id == idaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingr. apellido----:";
				cin>>Apaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingr Nombre-------:";
				cin>>nomaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingr Puesto-------:";
				cin>>puaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingr Sueldo-------:";
				cin>>suaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingr bonificacion-:";
				cin>>boaux;
			
				sumaux = suaux + boaux;
				aux<<id<<" "<<Apaux<<" "<<nomaux<<" "<<puaux<<" "<<suaux<<" "<<boaux<<" "<<sumaux<<"\n";
				cout<<"--------------------------------------"<<endl;
			}else{
				sum = su + bo;
				aux<<id<<" "<<Ap<<" "<<nom<<" "<<pu<<" "<<su<<" "<<bo<<" "<<sum<<"\n";
			}
			
			
			Lec>>id;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
		
	}else 
		cout<<"Error"<<endl;
	remove ("registro.dat");
	rename("auxiliar.dat", "registro.dat");
}

void eliminar(ifstream &Lec){
	system("cls");
 	string Ap;
 	string id;
	string nom;
	string pu;
	int su;
	int bo;
	int sum;
	string idaux;
	string Apaux;
	string nomaux;
	string puaux;
	int suaux;
	int boaux;
	int sumaux;
	Lec.open("registro.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------ID a modificar--------------------"<<endl;
		cout<<"Ingrese id:  ";
		cin>>idaux;
		Lec>>id;
		while(!Lec.eof()){
		  	Lec>>Ap;
			Lec>>nom;
			Lec>>pu;
			Lec>>su;
			Lec>>bo;
			Lec>>sum;
			if(id == idaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"------Fue eliminada existosamente-----"<<endl;
				Sleep(1500);
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<id<<" "<<Ap<<" "<<nom<<" "<<pu<<" "<<su<<" "<<bo<<" "<<sum<<"\n";
				
			}
			
			Lec>>id;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Error"<<endl;
	remove ("registro.dat");
	rename("auxiliar.dat", "registro.dat");	
	
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar(Esc);
			break;
			case 2:
				verRegistros(Lec);
			break;
			case 3:
				buscarregistro(Lec);
			break;
			case 4:
				modificar(Lec);
			break;
			case 5:
				eliminar(Lec);
			break;	
		}	
	}while(op != 6);
	return 0;
}
