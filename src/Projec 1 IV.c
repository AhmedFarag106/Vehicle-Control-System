/*
 ============================================================================
 Name        : Project.c
 Author      : Ahmed Farag Ahmed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/***** 		Includes		 ****/
#include <stdio.h>
#include <stdlib.h>

/***** 		Defines		 ****/
#define ON 1
#define OFF 0
#define True 1
#define False 0

#define WITH_ENGINE_TEMP_CONTROLLER True


/***** 		Globals		 ****/
char Traffic_Color = 'G';
int Room_Temp = 25 , Engine_Temp=110 , Vehicle_Speed=0;

/***** 		Functions Declarations		 ****/
void Print_State();
void Sensor_Set_Menu();
void Engine_State_Select();





/***** 		Main		 ****/
int main(void) {

	char Sensor_Selector=' '; // Sensors Selection -> temperature / traffic light /...
	char State_Selector=' '; // car state selector -> on / off / terminate

	Engine_State_Select(&State_Selector); // calling the main menu at the begging of the program

	while(1)
	{
		switch(State_Selector)
		{
		case 'a': // Turning the car on
		case 'A':
			Sensor_Set_Menu(&Sensor_Selector);

			if (Sensor_Selector!='a')
			{
				Print_State();
			}

			break;

		case 'b': // Turning the car off
		case 'B':

			Engine_State_Select(&State_Selector);
			break;

		case 'c': // terminate the program
		case 'C':
			return 0;
			break ;

		default:  // for wrong input
			printf("\nWrong Input\n");
			Engine_State_Select(&State_Selector);

		} // end of switch

		if( Sensor_Selector=='a')
		{
			Engine_State_Select(&State_Selector);
		}

	} /// end of while 1

} /// end of main




/***** 		User main menu		 ****/
void Engine_State_Select(char* Vehicle_State)
{
	/***** 		Printing main menu		 ****/
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	fflush(stdout);

	scanf(" %c",Vehicle_State);

	switch(*Vehicle_State)
	{

	case 'a': //Turn on the vehicle engine
	case 'A':

		printf("\n****  Turn on the vehicle engine  ****\n\n");
		break;


	case 'b': //Turn off the vehicle engine
	case 'B':

		printf("\n****  Turn off the vehicle engine  ****\n\n");
		break;


	case 'c': //Quit the system
	case 'C':
		printf("\n****  Quit the system  ****\n\n");
		break;
	}
}




/***** 		Setting sensors states according to user order		 ****/
void Sensor_Set_Menu(char* Sensor_Selection)
{

	/***** 		Printing User Options		 ****/
	printf("a. Turn off the vehicle engine\n");
	printf("b. Set the traffic color\n");
	printf("c. Set the room temperature (temperature sensor) \n");

	#if (WITH_ENGINE_TEMP_CONTROLLER)
		printf("d. Set the engine temperature");
	#endif

	printf("\n\n");
	fflush(stdout);

	/***** 		flushing the input buffer every time the user enters the FN 		 ****/
	fflush(stdin);
	scanf(" %c",Sensor_Selection);

	switch(*Sensor_Selection)
	{

	case 'b': //Set the traffic color
	case 'B':
		printf("\n****  Enter the required color  ****\n\n");
		fflush(stdout);

		scanf(" %c", &Traffic_Color);
		break;

	case 'c': //Set the room temperature (temperature sensor)
	case 'C':
		printf("\n****  Set the room temperature  ****\n\n");
		fflush(stdout);

		scanf("%d", &Room_Temp);
		break;

	case 'd': //Set the engine temperature
	case 'D':

		#if (WITH_ENGINE_TEMP_CONTROLLER)

				printf("\n****  Set the engine temperature  ****\n\n");
				fflush(stdout);

				scanf("%d", &Engine_Temp);
		#endif

		break;
	}

}




/***** 		Printing sensors states		 ****/
void Print_State()
{
	char AC_State = OFF;
	#if (WITH_ENGINE_TEMP_CONTROLLER)
		 char Temp_control_State=OFF;
	#endif

	/***** 		Making Decisions according to sensors states		 ****/

	/***** 		1- Traffic Light		 ****/
	if (Traffic_Color=='g' || Traffic_Color=='G') Vehicle_Speed = 100;
	else if (Traffic_Color=='o' || Traffic_Color=='O') Vehicle_Speed = 30;
	else if (Traffic_Color=='r' || Traffic_Color=='R') Vehicle_Speed = 0;

	/***** 		2- Room Temperature		 ****/
	if (Room_Temp<10 || Room_Temp>30)
	{
		AC_State=ON;
		Room_Temp = 20;
	}
	else  AC_State=OFF;

	/***** 		3- Engine Temperature		 ****/
	#if (WITH_ENGINE_TEMP_CONTROLLER)

		if (Engine_Temp<100 || Engine_Temp>150)
		{
			Temp_control_State=ON;
			Engine_Temp = 125;
		}
		else  Temp_control_State=OFF;
	#endif

	/***** 		speed of 30 kmh conditions		 ****/
	if(Vehicle_Speed==30)
	{
		AC_State=ON;
		Room_Temp = (Room_Temp* 5/4) +1;
		#if (WITH_ENGINE_TEMP_CONTROLLER)

			Temp_control_State=ON;
			Engine_Temp = (Engine_Temp *5/4) +1;
		#endif
	}


	/***** 		Printing sensors states		 ****/
	printf("\nEngine is ON");
	printf("\nAC is %s",AC_State? "ON" : "OFF");
	printf("\nVehicle Speed: %d Km/Hr",Vehicle_Speed);
	printf("\nRoom Temperature: %d c",Room_Temp);

	#if (WITH_ENGINE_TEMP_CONTROLLER)
		printf("\nEngine Temperature Controller is %s",Temp_control_State? "ON" : "OFF");
		printf("\nEngine Temperature: %d c",Engine_Temp);
	#endif

	printf("\n\n");
	fflush(stdout);

}
