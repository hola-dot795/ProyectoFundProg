#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Jugador
{
	char *Username;
	char *Password;
	int JuegosJugados;
	int JuegosGanados;
};
int n = 1, Op;
char Nombre[20], Contra[20];
Jugador *Users, *User;
FILE *DataFile;

void Play();
void LogIn();
void Stadistics();
void CreateProfile();
main()
{	
	do
	{
		printf("bienvenido al juego, que deseas hacer?\n1-Iniciar sesion\n2.-Crear perfil\n3.-Estadisticas\n4.-Jugar\n5.-Salir\n");
		scanf("%i",&Op);
		switch(Op)
		{
			case 1: //Iniciar sesion
				LogIn();
				break;
			case 2:	//Crear perfil
				CreateProfile();
				break;
			case 3:	//Estadisticas
				Stadistics();
				break;
			case 4:	//Jugar
				Play();
				break;
			default:
			case 5:	//Salir
				
				break;
		}
	}while(Op != 5);
}

void LogIn()
{
	DataFromFile();
		
}

void CreateProfile()
{
	
}

void Play()
{

}

void Stadistics()
{
	
}

void DataFromFile()	//carga el archivo de perfiles
{
	Users = (Jugador*)malloc(sizeof(Jugador));
	DataFile = fopen("file.txt" , "r");
	if(DataFile == NULL) 
	{
		perror("Error opening file");
	}
	printf("asdased");
	int i = 0;
	while(feof(DataFile) == NULL)
	{
		fscanf(DataFile,"%s %s %i %i\n", &Users[i].Username, &Users[i].Password, &Users[i].JuegosJugados, &Users[i].JuegosGanados);
		i++;
	}
}

void DataToFile()	//salva el struct de perfiles en el archivo
{
	
}
