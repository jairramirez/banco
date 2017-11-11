#include <stdio.h>
#include <string.h>
#include <cstring>
#include <stdlib.h>
struct usuario{
	int clave;
	char nombre[30];
	int tramite;
	char fechaNacimiento[30];
	int estado;
	int buscar;
};
struct datos{
	char nombre[30];
	int nit;
	char gerente[30];
	char direccion[30];
	char correo[30];
	char telefono[20];
};
usuario cliente[100];
datos banco={
	"BANCO SOCIAL DEL ESTADO",
		891234321,
		"Jair Ramirez Velasquez",
		"Calle 18a # 16-15",
		"bancosocial@decartago.com",
		"2128336",
};
int i;
void insertarCliente(usuario cliente[],int &tamanio);
void clientesNoAtendidos(usuario cliente[],int tamanio);
void clientesAtendidos(usuario cliente[],int tamanio);
void consignacionClientes(usuario cliente[],int tamanio);
void asesoriasClientes(usuario cliente[],int tamanio);
void atenderCliente(usuario cliente[],int tamanio);
void editarCliente(usuario cliente[], int tamanio);
void editarBanco(datos &banco);
void menu();

int tamanio=0;
int main()
{
	
	menu();
	return 0;
}
void menu()
{
	int opcion=9999;
	
	while(opcion!=0)
	{
		
		printf("\t\tBanco %s \n",banco.nombre);
		printf("\t\tNit:%d \n",banco.nit);
		printf("\t\tGerente: %s \n",banco.gerente);
	    printf(">>>>>>>>>>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
		printf("\t\tElija una opcion \n");
		printf("\t\t0.Salir \n");
		printf("\t\t1.Insertar clientes \n");
		printf("\t\t2.Editar clientes \n");
		printf("\t\t3.Atender clientes  \n");
		printf("\t\t4.Listar clientes atendidos \n");
		printf("\t\t5.Listar clientes sin atender  \n");
		printf("\t\t6.Listar clientes para consignacion\n");
		printf("\t\t7.Listar clientes para asesorias  \n");
		printf("\t\t8.Editar datos del banco  \n");
		printf("-------------------------------------------------------------\n");
		printf("\t\tDireccion: %s \n",banco.direccion);
		printf("\t\tCorreo: %s \n",banco.correo);
		printf("\t\tTelefono: %s \n\n",banco.telefono);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 0: exit(0);
		
		case 1:  insertarCliente(cliente,tamanio);
		break;
		
		case 2: editarCliente(cliente,tamanio);
		break;
		
		case 3: atenderCliente(cliente,tamanio);
		break;
		
		case 4: clientesAtendidos(cliente,tamanio);
		break;
		case 5: clientesNoAtendidos(cliente,tamanio);
		break;
		case 6: consignacionClientes(cliente,tamanio); 
		break;
		case 7: asesoriasClientes(cliente,tamanio);
		break;
		case 8: editarBanco(banco);
		break;
		default: printf("Opcion no valida \n");
		
		}
		
	}
	
	
}



void insertarCliente(usuario cliente[],int &tamanio)
{
	
	int lon;
	printf("Ingrese la cantidad de clientes a  crear menor a 100 \n");
	scanf("%d",&lon);
	
	if (lon>100){
		printf ("\ncantidad no valida.\n");	
	}else{
		printf ("\ningrese los datos del cliente: ");
		
		for(i=tamanio;i<tamanio+lon;i++)
		{
			fflush(stdin);
			printf("\n Ingrese clave de 4 digitos \n ");
			scanf("%d",&cliente[i].clave);
			
			fflush(stdin);
			printf("Ingrese nombre \n");
			fgets(cliente[i].nombre,30,stdin);
			
			fflush(stdin);
			printf("Ingrese una opcion 1.consignaciones 2.Asesoria \n");
			scanf("%d",&cliente[i].tramite);
			
			fflush(stdin);
			printf("Ingrese fecha de nacimiento \n");
			fgets(cliente[i].fechaNacimiento,30,stdin);
			
			fflush(stdin);
			printf("Ingrese estado del cliente 1.No atendido  2.Atendido \n");
			scanf("%d",&cliente[i].estado);
			
			
		}
		tamanio=tamanio+lon;
	}
}
void atenderCliente(usuario cliente[],int tamanio)
{
	printf(">>>>>>>>>>>>>>TURNOS <<<<<<<<<<<<<<<<<\n");
	
	for(i=0;i<tamanio;i++)
	{
		if(cliente[i].estado==1){
			
			if(cliente[i].tramite==1)
			{
				printf("%s consignacion turno %i \n",cliente[i].nombre,i+1);
				
				
			}
			else{
				printf("%s asesoria comercial turno %i \n",cliente[i].nombre,i+1);
				
			}
		}	
	}
	printf("__________________________________\n");
}


void clientesNoAtendidos(usuario cliente[],int tamanio)
{
	printf(">>>>>>>>>>>>>>LISTA DE CLIENTES POR ATENDER <<<<<<<<<<<<<<<<<\n");
	
	for(i=0;i<tamanio;i++)
	{
		if(cliente[i].estado==1){
			
			printf("Clave %d \n",cliente[i].clave);
			printf("Nombre: %s \n",cliente[i].nombre);
			printf("Fecha de nacimiento: %s \n",cliente[i].fechaNacimiento);
			
			if(cliente[i].tramite==1)
			{
				printf("Tramite: consignacion \n\n");
				
			}
			else{
				printf("Tramite: asesoria comercial \n\n");
			}
		}	
	}
	printf("__________________________________\n");
}

void clientesAtendidos(usuario cliente[],int tamanio)
{
	printf(">>>>>>>>>>>>>>>>LISTA DE CLIENTES ATENDIDOS<<<<<<<<<<<< \n");
	
	for(i=0;i<tamanio;i++)
	{
		if(cliente[i].estado==2){
			
			printf("Clave %d \n",cliente[i].clave);
			printf("Nombre: %s \n",cliente[i].nombre);
			printf("Fecha de nacimiento: %s \n",cliente[i].fechaNacimiento);
			
			if(cliente[i].tramite==1)
			{
				printf("Tramite: consignacion \n\n");
			}
			
			else{
				printf("Tramite: asesoria comercial \n\n");
			}
		}
	}
	printf("__________________________________\n");
}

void consignacionClientes(usuario cliente[],int tamanio)
{
	printf(">>>>>>>>>>>LISTA DE CLIENTES PARA CONSIGNACIONES<<<<<<<<<<<<\n");
	
	for(i=0;i<tamanio;i++)
	{
		if(cliente[i].tramite==1)
		{
			printf("Clave %d \n",cliente[i].clave);
			printf("Nombre: %s \n",cliente[i].nombre);
			printf("Fecha de nacimiento: %s \n",cliente[i].fechaNacimiento);
			
			if(cliente[i].estado==1)
			{
				printf("Estado: No atendido \n");
			}
			else if(cliente[i].estado==2)
			{
				printf("Estado; Atendido \n");
			}
		}	
	}
	printf("__________________________________\n");
}

void asesoriasClientes(usuario cliente[],int tamanio)
{
	printf(">>>>>>>>>>>LISTA DE CLIENTES PARA ASESORIAS<<<<<<<<<<<<\n");
	
	for(i=0;i<tamanio;i++)
	{
		if(cliente[i].tramite==2){
			
			printf("Clave %d \n",cliente[i].clave);
			printf("Nombre: %s \n",cliente[i].nombre);
			printf("Fecha de nacimiento: %s \n",cliente[i].fechaNacimiento);
			
			if(cliente[i].estado==1)
			{
				printf("Estado: No atendido \n");
			}
			else{
				printf("Estado: Atendido \n");
			}
		}
	}
	
	printf("__________________________________\n");
}

void editarCliente(usuario cliente[], int tamanio)
{
	int edit;
	bool encontrado=false;
	
	
	printf ("Ingrese clave de cliente a editar: \n");
	scanf ("%d",&edit);
	for(int i=0;i<tamanio;i++)
	{
		if(cliente[i].clave==edit)
		{
			encontrado=true;
			edit=i;
			break;
		}
	}
		 if(encontrado){
	
	printf ("Ingrese nueva clave:\n ");
	scanf("%d",&cliente[edit].clave);
	
	fflush(stdin);
	printf ("ingrese nuevo nombre: \n");
	fgets(cliente[edit].nombre,30,stdin);
	
	
	
	
	printf ("ingrese nuevo tramite: \n");
	scanf ("%d",&cliente[edit].tramite);
	
	
	fflush(stdin);
	printf ("ingrese nueva fecha de nacimiento: \n");
	fgets(cliente[edit].fechaNacimiento,30,stdin);
	
	
	printf ("La nueva informacion del cliente es: \n");
	printf ("clave: %d \n ",cliente[edit].clave);
	printf("Nombre: %s \n",cliente[edit].nombre);
	printf("Tramite: %d \n",cliente[edit].tramite);
	printf("Fecha de nacimiento: %s \n",cliente[edit].fechaNacimiento);
	}else{printf("el cliente no esta en la lista \n");
		 }
	
}
void editarBanco(datos &banco)
{
	
	
	fflush(stdin);
	printf ("ingrese nuevo nombre del banco \n");
	fgets(banco.nombre,30,stdin);
	
	printf ("Ingrese nuevo nit \n ");
	scanf("%d",&banco.nit);
	
	fflush(stdin);
	printf ("ingrese nombre del nuevo gerente \n");
	fgets(banco.gerente,30,stdin);
	
	fflush(stdin);
	printf ("ingrese nueva direccion  \n");
	fgets(banco.direccion,30,stdin);
	
	fflush(stdin);
	printf("ingrese nuevo correo  \n");
	fgets(banco.correo,30,stdin);
	
	fflush(stdin);
	printf("ingrese nuevo telefono \n");
	fgets(banco.telefono,20,stdin);
}













