//Jenelle Stapleton, CISC 1600 Section R02 
#include <iostream> 
#include <string>
#include <cmath> //for sin function 
		
using namespace std; 

//Declares and assigns a PI constant for calculations 

const double PI = 3.14159265358979323846;  

//Defines a function that converts an angle from degrees to radians 

double Degrees2Radians(double degrees)

{

	return (degrees * PI/180);  

}

//Draws a line based on input from the user 

void drawLine(char charToPrint, int numReptitions) 
{


	for (int i = 0; i < numReptitions; i++) 
	{
		cout << charToPrint;  

	}

	cout << endl; 

}

//Prints out an angle according to sin and increments it according to user input  

void doPrinting (int angle, int angleIncrement, char charToPrint, int numberOfCharsToPrint) 
{ 	
	
	//Loops through the angle increments starting from 0 up until the user's 
	//inputted angle according to the sin function  

	for (int i = 0; i <= angle; i+= angleIncrement) 
	{
		cout << "sin(" <<  i << ") = "  << sin(Degrees2Radians(i)) << endl; 

		//If the angle is divisble by 90 then a line will be printed 

		if (i%90 == 0)  
		{	
			drawLine(charToPrint,numberOfCharsToPrint); 
		
		}
	}

}

//Prints a sin wave with spacing that's equivalent to sin in radians and other calulations 

void doGraphing(int angle, int angleIncrement) 
{

	
	for(int i = 0; i <= angle; i+= angleIncrement) 
	{ 

	 	int spaces = sin(Degrees2Radians(i))*20 +20; 

		for (int i = 0; i < spaces; i++) 

		{
			cout << " "; 			

		}

		cout << "X";
	       	cout << endl; 	
	}

}	
		 

int main() 
{

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint); //show decimals even if not needed 
	cout.precision(5);//show 5 digits to right of decinal 


	//Declares varaibles needed for main function

	double angle; 
	int angleIncrement; 
	char graphOrNot; 
	char lineChar; 
	int numberOfCharsToPrint; 

	//Ask users for input and will call the appropriate function accordingly 

	cout << "Perform calculations from angle=0 to what value (in degrees)? ";
	cin >> angle; 

	cout << "How often should the angle be incremented? ";
	cin >> angleIncrement; 

	cout << "Graph it? "; 
	cin >> graphOrNot; 


	//If user does not want to graph, the program will simply print out sin 	equivalents of the inputted angle with lines formatted by the user 
	
	if(graphOrNot == 'N')

	{
		cout << "Make the line from what character? "; 
		cin >> lineChar; 

		cout << "How many characters form a line? "; 
		cin >> numberOfCharsToPrint;
		

		doPrinting(angle, angleIncrement, lineChar, numberOfCharsToPrint);  

	}

	else 
	{
		
		doGraphing(angle, angleIncrement); 

	}

	return 0; 

} //end main 
