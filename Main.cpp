/*
Gavin Davis
Computer Science
Temperature Project
10/22/2026
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

/*Description: Design and write a C++ program that inputs a series of hourly temperature
from a file, and outputs a bar chart (using stars) of the temperatures. The temperature
should be printed to the left of the corresponding bar, and there should be a heading
that gives the scale of the chart. The range of temperatures should be from -30 to 120.
Because it is hard to display 150 characters on the screen, you should have each star
represent a range of 3 degrees. That way, the bars will be at most 50 characters wide.
Use meaningful variable names, proper indentation, and appropriate comments.
Thoroughly test the program using your own data sets. Make sure to vet the values from
the input file. Use good programming practices including comments, and pre/post
conditions*/

using namespace std;

//Global input file
ifstream inputfile;

//function prototypes

//opens file
bool openInputFile(string filename);

// checks temperature range
bool validTemperature(int temperature);

//displays temperature bar
int printBar(int temperature);

int main()
{
	int temperature;

	// Pre-Condition: the temperatures.txt file must exist and be accesible to the program
	//test input file
	if (!openInputFile("Temperatures.txt"))
	{
		cout << "File failed to open";
		return 1;
	}

	//Post-Condition: The input file is succesfully opened

	//print chart title
	cout << "Temperature Bar Chart" << endl << endl;

	//titles for graph
	cout << "Hourly Temperature Bar Chart" << endl;
	cout << "Each * represents 3 degrees" << endl;
	cout << endl;

	//print temperature scale, and scale line
	cout << "       -30        0         30          60      90        120" << endl;
	cout << "        |---------|----------|----------|--------|--------|" << endl;


	//Pre condidtion: the input file must be open
	//read temps from the file
	while (inputfile >> temperature)
	{
		// check if temperatures are within the valid range
		if (validTemperature(temperature))
		{
			// print the temperature bar
			printBar(temperature);
		}
		else
		{
			//display an error for invalid temperatures
			cout << "Invalid temperature: "
			<< temperature << endl;
			//Post Condition: Every temperature in the file has been read
			// close file
			inputfile.close();
			return 0;
		}
	}
}
	//function to open file
	bool openInputFile(string filename)
	{
		//Pre-Condition: A valid filename must be provided
		inputfile.open(filename);
		//Post-Condition: Returns true if the file opened, otherwise returns false
		return inputfile.is_open();
	}
	
	//Function to validate temperatures
	bool validTemperature(int temperature)
	{
		//Pre-Condition: a temperature must be provided
		// temp must be inbetween -30 and 120
		if (temperature >= -30 && temperature <= 120)
		{
			//Post-Condition: Returns true for a valid temperature
			return true;
		}
		else
		{
			//Post-Condition: Return false for invalid temperature
			return false;
		}
	}
	
	//Function to print the bar chart
int printBar(int temperature)
	{
	// each star is 3 degrees
		int starCount = abs(temperature) / 3;

		int zeroPosition = 10;
		// display the temperature number
		cout << temperature << "\t";

		// if temperature is negative, print stars to the left
		if (temperature < 0)
		{
			// print spaces to put negative bar in position
			for (int i = 0; i < zeroPosition - starCount; i++)
			{
				cout << " ";
			}

			// print the negative stars
			for (int i = 0; i < starCount; i++)
			{
				cout << "*";
			}
			cout << "|";
		}
		else
		{
			//leave space for the negative side
			for (int i = 0; i < zeroPosition; i++)
			{
				cout << " ";
			}
			// print vertical lines
			cout << "|";
		}


		//if temperature is positive, print stars to the right
			if (temperature >0)
			{ 
				for (int i = 0; i < starCount; i++)
				{
					cout << "*";
				}
		}

			
		cout << endl; 
		return starCount;
	

}