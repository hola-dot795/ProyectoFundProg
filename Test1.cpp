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
int n = 1, Op, UserIndex, ArraySize;
char Nombre[20], Contra[20];
Jugador *Users/*, *User*/;
FILE *DataFile;

void Play();
void LogIn();
void Stadistics();
void CreateProfile();
void DataFromFile();
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
	char VarUsName[20], VarPassW[20];
	
	bool IsValid = false;
	//printf("%i, %i, %i", ArraySize, VarInArraySize, Size);
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
				printf("Comparando %s con %s", VarUsName, Users[i].Username);
				if(strcmp(Users[i].Username, VarUsName) != 0 || strcmp(Users[i].Password, VarPassW))
				{
					IsValid == true;
					UserIndex = i;
					/*User[0].JuegosJugados == Users[i].JuegosJugados;
					User[0].JuegosGanados == Users[i].JuegosGanados;
					User[0].Password == Users[i].Password;
					User[0].Username == Users[i].Username;*/
				}
			}
		}
	}while(IsValid == false);
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
			//printf("Line Found");
		}
		//printf("%c", c);
	}
	//printf("\n");
	Users = (Jugador*)malloc(i*sizeof(Jugador));
	ArraySize = (i);
	//printf("%i\n", ArraySize);
	while(!feof(DataFile))
	{
		fscanf(DataFile,"%s %s %i %i\n", &Users[i].Username, &Users[i].Password, &Users[i].JuegosJugados, &Users[i].JuegosGanados);
		printf("%s %s %i %i\n", &Users[i].Username, &Users[i].Password, &Users[i].JuegosJugados, &Users[i].JuegosGanados);
		i++;
	}
}

void DataToFile()	//salva el struct de perfiles en el archivo
{
	
}
