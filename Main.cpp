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

//function prototypes
bool openInputFile(ifstream& inputfile, string filename);
bool validTemperature(int temperature);
int printbar(int temperature);

int main()
{

	ifstream inputfile;
	inputfile.open("Tempinput.cpp");

		if (!openInputFile(inputfile, "Tempinput.cpp" ))
		{
			cout << "File failed to open";
			return 1;
		}

	int temperature;

	cout << "Hourly Temperature Bar Chart" << endl;
	cout << "Each * represents 3 degrees" << endl;
	cout << endl;

	//read temps from the file
	while (inputfile >> temperature)
	{
		if(validTemperature(temperature))
		{
			printbar(temperature);
		}
		else
		{
			cout << "Invalid temperature: "
				<< temperature << endl;
			inputfile.close();
			return 0;
	}
		
	//function to open file
	bool openInputFile(ifstream& inputfile, string filename)
	{
		inputfile.open(filename);
		return inputfile.is_open();
	}
	
	//Function to validate temperatures
	bool validTemperature(int temperature)
	{
		return temperature >= -30 && temperature <= 120;
	} 
	
	//Function to print the bar chart
	int printBar(int temperature)
	{
		int starCount = abs(temperature)/ 3;

		int zeroPosition = 10;

		cout << temperature << "\t";
		
		if (temperature < 0)
		{

			for (int i = 0; i < zeroPosition - starCount; i++)
			{
				cout << " ";
			}
		}
			for (int i = 0; i < starCount; i++)
			{
				cout << "*";
			}
		else
		{
			for(int i =0; i < zeroPosition;) i++)
			{
				cout << " ";
				}
				for (int i = 0; i < starCount; i++)
				{
					cout << "*";
				}
		}

			
		cout << endl; 
		return starCount;
	

}