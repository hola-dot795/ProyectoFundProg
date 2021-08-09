#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Jugador
{
	char *Username;
	char *Password;
	int JuegosJugados;
	int JuegosGanados;
};
int n = 1, Op, UserIndex = -1, ArraySize;	//User index se puede usar como variable para checar si se ha 
											//iniciado sesion, se mantendra como -1 si no, se cambiara a 0->n si si
char Nombre[20], Contra[20];
Jugador *Users;
FILE *DataFile;

void Play();
void LogIn();
void Stadistics();
void CreateProfile();
void DataFromFile();
void DataToFile();
main()
{	
	do
	{
		printf("Menu de juego, selecciona la opcion que deseas hacer\n1.-Iniciar sesion\n2.-Crear perfil\n3.-Estadisticas\n4.-Jugar\n5.-Salir\n");
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
				if(UserIndex != -1)
				{
					DataToFile();
					free(Users);
				}
				break;
		}
	}while(Op != 5);
}

void LogIn()
{
	DataFromFile();
	char VarUsName[20], VarPassW[20];
	
	bool IsValid = false;
	do
	{
		fflush(stdin);
		printf("Dame tu usuario: ");
		fflush(stdin);
		gets(VarUsName);
		printf("Dame tu contraseña: ");
		gets(VarPassW);
		for(int i = 0; i < ArraySize; i++)
		{
			if(IsValid == false)
			{
				if(strcmp((char*)&Users[i].Username, VarUsName) == 0 && strcmp((char*)&Users[i].Password, VarPassW) == 0)
				{
					system("cls");
					printf("Bienvenido %s\n", &Users[i].Username);
					IsValid = true;
					UserIndex = i;
				}
			}
		}
	}while(IsValid == false);
}

void CreateProfile()
{
	if(UserIndex = -1)
		DataFromFile();
	DataFile = fopen("file.txt" , "a");
	char VarUsName[20], VarPassW[20];
	bool IsValid;
	do
	{
		printf("Dame tu usuario: ");
		fflush(stdin);
		gets(VarUsName);
		printf("Dame tu contraseña: ");
		gets(VarPassW);
		IsValid = true;
		for(int i = 0; i < ArraySize; i++)
		{
			if(IsValid == true)
			{
				if(strcmp((char*)&Users[i].Username, VarUsName) == 0)
				{
					printf("Ya hay un Usuario con ese nombre, elija otro por favor\n");
					IsValid = false;
				}
			}
		}
	}while(IsValid == false);
	fprintf(DataFile, "\n%s %s %i %i", VarUsName, VarPassW, 0, 0);
	printf("Se ha guardado su perfil\n");
	Sleep(3000);
	system("cls");
	fclose(DataFile);
}

void Play()
{

}

void Stadistics()
{
	
}

void DataFromFile()	//carga el archivo de perfiles
{
	DataFile = fopen("file.txt" , "r");
	if(DataFile == NULL) 
	{
		perror("Error opening file");
	}
	int i = 1;
	for (char c = getc(DataFile); c != EOF; c = getc(DataFile))
	{
		if (c == '\n')
		{
			i++;
		}
	}
	Users = (Jugador*)malloc(i*sizeof(Jugador));
	ArraySize = (i);
	i = 0;
	fclose(DataFile);
	DataFile = fopen("file.txt" , "r");
	while(i < ArraySize)
	{
		char Var[40], JJ[3], JG[3];
		int j = 0;
		for (char c = getc(DataFile); c != '\n'; c = getc(DataFile))
		{
			if (c != '\n' || c != EOF)
			{
				Var[j] = c;
				j++;
			}
			if(c == EOF)	break;
		}
		sscanf(Var,"%s %s %s %s", &Users[i].Username, &Users[i].Password, &JJ, &JG);
		Users[i].JuegosJugados = strtol(JJ,NULL,10);
		Users[i].JuegosGanados = strtol(JG,NULL,10);
		i++;
	}
	fclose(DataFile);
}

void DataToFile()	//salva el struct de perfiles en el archivo
{
	DataFile = fopen("file.txt" , "w");
	int i = 0;
	while(i < ArraySize)
	{
		if(i == ArraySize - 1)
			fprintf(DataFile, "%s %s %i %i", &Users[i].Username, &Users[i].Password, Users[i].JuegosJugados, Users[i].JuegosGanados);
		else
			fprintf(DataFile, "%s %s %i %i\n", &Users[i].Username, &Users[i].Password, Users[i].JuegosJugados, Users[i].JuegosGanados);
		i++;
	}
	fclose(DataFile);
}
