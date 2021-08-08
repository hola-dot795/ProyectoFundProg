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

//void Play(Player *Users);
void Play();
void LogIn();
void Stadistics();
void CreateProfile();
//fscanf
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
	/*
	Users[0].Username = "12345";
	Users[0].Password = "12345";
	Users[0].PlayedGames = 5;
	Users[0].WinnedGames = 2;
	Users[0].LossedGames = 3;
	do
	{
		printf("Dame tu usuario: ");
		gets(VarUsName);
		printf("Dame tu contraseña: ");
		gets(VarPassW);
	}while(strcmp(Users[0].Username, VarUsName) != 0 || strcmp(Users[0].Password, VarPassW));
	printf("bienvenido al sistema");
	Play(&Users[0]);*/
	//printf("Has jugado %i, has ganado %i y has perdido %i", Users[0].PlayedGames, Users[0].WinnedGames, Users[0].LossedGames);
}

void LogIn()
{
	DataFromFile();
		
}

void CreateProfile()
{
	
}

//void Play(Player *Users)
void Play()
{
	/*Users -> PlayedGames++;
	int Tries = 3, Num;
	RandVal = rand() % 10 + 1;
	do
	{
		printf("Adivina el numero: ");
		scanf("%i",&Num);
		Tries--;
	}while(Tries > 0 && RandVal != Num);
	if(Num == RandVal)
	{
		printf("Ganaste");
		Users -> WinnedGames++;
	}
	else
	{
		printf("Perdiste");
		Users -> LossedGames++;
	}*/
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

void DataToFile()	//salva el archivo de perfiles
{
	
}
