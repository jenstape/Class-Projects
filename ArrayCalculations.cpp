//Jenelle Stapleton, CISC 1600 Section R02 
#include <iostream> 
#include <string>

using namespace std;

//This function inputs elements into the array while the value that's read 
//from the user isn't negative and the maximum number of elements entered into 
//the function's parameters isn't reached 

int fillArray(int inputArray[], int maxNumElements) 

{

	cout << "Please enter up to 50 non-negative whole numbers separated by space." << endl; 
	cout << "Mark the end of the input list with a negative number: " << endl; 

	int i = 0; 
	int oneValue; 

	do
	{
		cin >> oneValue; 
		inputArray[i] = oneValue;
		i++; 

	} while ((oneValue >= 0) && (i < maxNumElements)); 

	return(i-1);

}

//This function prints out the elements of the array entered into the parameters 

void printArrayElements(int inputArray[], int numElements) 
{
	for (int i = 0; i < numElements; i++) 

	{

		cout << inputArray[i] << " ";
	}

	cout << endl; 
}

//This function finds the minimum value of the array entered into the parameters 

int arrayMinimum (int inputArray[], int numElements) 
{
	
	int minimum = inputArray[0];

	for (int i = 1; i < numElements; i++) 
	{
	       if(inputArray[i] <  minimum) 
	       {

			minimum = inputArray[i]; 
	       }
	}

	return minimum; 
}

//This function finds the maximum value of the array entered into the parameters 

int arrayMaximum(int inputArray[], int numElements) 
{
	int maximum = inputArray[0];

        for (int i = 1; i < numElements; i++)
        {
               if(inputArray[i] >  maximum)
               {

                        maximum = inputArray[i];
               }
        }

	return maximum; 
}

//This function calculates the sum that includes all values in the array entered into the parameters 

int arraySum(int inputArray[], int numElements) 
{
	int sum = 0; 

	for(int i = 0; i < numElements; i++) 

	{
		sum = sum + inputArray[i];

	}

	return sum; 
}

//This function finds the average number of all values in the array entered into the parameters 

double arrayAverage(int inputArray[], int numElements) 

{

	double average = 0; 

	for (int i = 0; i < numElements; i++)

	{
		average = average + inputArray[i]; 

	}

	average = average / numElements; 

	return average; 
}

//This function verifies the element entered into the parameters is in the array by sorting through the array
//then returns a value of true if the element is found and false if not 

bool isInArray (int inputArray[], int numElements,int targetElement) 
{
	bool isInArray;

	for (int i = 0; i < numElements; i++) 

	{
		if(inputArray[i] == targetElement) 
		{
			isInArray = true;
		       	break;	
		}
		
		else 
		{

			isInArray = false; 
		}

	}

	return isInArray;
}

//This function searches the array entered into the parameters for the inputted element and tracks its 
//frequency with the variable counter 

int arrayFrequency(int inputArray[], int numElements, int targetElement) 

{
	int count = 0; 

	for(int i = 0; i < numElements; i++) 
	{
		if(inputArray[i] == targetElement) 

		{ 
			count++;
		}
	}

	return count; 
}



int main() {

	//Declared variables needed for the functions 
	
	int const NUM_ELEMENTS = 50;
       
	//Hard codes the array to have 50 elements  
	int mainArray[NUM_ELEMENTS]; 
	int mainNumElements = 0;
	int targetElement; 	
	bool isNumInArray; 
	
	//If the variable that's outputted is of type double, the main functions sets the number stored in
	//the variable to two decemial places 
	
	cout.setf(ios::fixed);
        cout.setf(ios::showpoint); //show decimals even if not needed
        cout.precision(2);//show 2 digits to right of decemial  
	mainNumElements = fillArray(mainArray,NUM_ELEMENTS);
										
	//The following code calls the array calculation functions created 
	//And outlines their call with notice statements 

	printArrayElements(mainArray, mainNumElements); 
 	cout << "The minimum value in the array is " << arrayMinimum(mainArray, mainNumElements)  << endl;  
	cout << "The maximum value in the array is " << arrayMaximum(mainArray, mainNumElements) << endl; 
	cout << "The sum of all the elements in the array is " << arraySum(mainArray, mainNumElements) << endl;
	cout << "The average of all the elements in the array is " << arrayAverage(mainArray, mainNumElements) << endl; 
	cout << "Please enter the value you want to search in the array: "; 
	
	cin >> targetElement;
     	isNumInArray = isInArray(mainArray, mainNumElements, targetElement); 

	if (isNumInArray == true) 
	{

		cout << "Found your target: " << targetElement << endl;  

	}

	else 

	{
		cout << "Could not find " << targetElement << endl; 

	}	
	
	cout << "Please enter the value you want to know the frequency of: "; 
	
	cin >> targetElement; 
	
	int mainArrayFrequency = arrayFrequency(mainArray, mainNumElements,  targetElement); 
	
	cout << "The number " << targetElement << " has occurred " << mainArrayFrequency << " time(s) in the array" << endl;   	
	
	return 0; 
}
