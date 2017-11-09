/*Program to parse the text file input received from the user*/
#include <iostream>
#include<string>
#include <fstream> //Objects belong to this class are associated with files opened for input and output purposes
#include <sstream> //Header providing string stream classes
#include <algorithm>
#include <ctime>
#include "Project_1.h"
#include <cstdlib> // Header providing standard lib
#include <cmath> // Header providing math functions
//#include "myfunction.cpp"
using namespace std;
int column, row;
/*class dimensions
{
	
public :
int column , row;
};*/
// defining simulated annealing function
int project_1()
{
	int val = 0;
	int typo;
	cout << "which file would you like to chose?"<< "\n"<<"1. hard 10 \n2. soft 10 \n3.hard 30 \n4.soft 30 \n5.hard 50 \n6.soft 50\n \n";
	cin >> val;
	ifstream file;
	
	

	switch(val)
	{
		case 1 : 
		cout <<" You have selected file 1"<<endl; 
		column = 9;
		row = 10;
		file.open("try.txt"); // reading the dummy file created
		break;
		
		case 2 :
		cout <<" You have selected file 2"<<endl; 
		column = 4;
		row = 10;
		file.open("soft10.txt"); // reading the dummy file created
		break;
		
		case 3 :
		cout <<" You have selected file 3"<<endl; 
		column = 9;
		row = 30;
		file.open("hard30.txt"); // reading the dummy file created
		break;	
		
		case 4 :
		cout <<" You have selected file 4"<<endl; 
		column = 4;
		row = 30;
		file.open("soft30.txt"); // reading the dummy file created
		break;
		
		case 5 :
		cout <<" You have selected file 5"<<endl; 
		column = 9;
		row = 50;
		file.open("hard50.txt"); // reading the dummy file created
		break;	
		
		case 6 :
		cout <<" You have selected file 6"<<endl; 
		column = 4;
		row = 50;
		file.open("soft50.txt"); // reading the dummy file created
		break;	
			
	}
	string line;
	//Find the number of lines and allocate the rowSize
	float b[row][column]; //size allocated assuming the number of lines and columns are known, otherwise you can allocate using 'new' operator
	int para1[row]= {0}, para2[row]={0}, area[row]={0}; 


	int k = 0; //This also gives the number of lines after loop is done

	while (std::getline(file, line))
	{
		//istringstream iss(line);
		for (int i = 0; i < (int)line.size(); ++i)
		{
			if (line.find("softrectangular")!= std::string::npos)//finding the type of system
			{
			//cout << "found"<<endl;
			typo = 1;
		}
			else
			typo = 0;
			//cout << typo<< endl;
			
			if (((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))) //extracting numerics and removing alphanumeric values in the text file
			{
				line[i] = ' \0 ';
			}
			// removing  all extras
			line.erase(std::remove(line.begin(), line.end(), ','), line.end());
			line.erase(std::remove(line.begin(), line.end(), '('), line.end());
			line.erase(std::remove(line.begin(), line.end(), ')'), line.end());
			

		}
		
		istringstream iss(line);

		//Number of columns
		// If this is constant across different files its ok otherwise have to fing out this number also!

			for (int j = 0; j < column; j++)
			{
				iss >> b[k][j];
				cout << b[k][j] <<" ";
				
				
			
			}
			

			if (column==9)
				{
					for (int i =0; i<row; i++)
					{
					int x1 =b[i][2];
					int y1 = b[i][3];
					int x2 =b[i][4];
					int y2 = b[i][5];
					int x3 = b[i][6];
					int y3 = b[i][7];
				//	cout << "\n"<<l;
					para1[i] = sqrt ((x1 - x2)*(x1 - x2) + (y1-y2)*(y1-y2));
					para2[i]= sqrt((x3 - x2)*(x3 - x2) + (y3-y2)*(y3-y2));
					area[i]= para1[i]*para2[i];
					
					}
				}
				
				
			

			cout << endl;
			k++;

	}
	
// Finding the type of file we are looking for
if (typo ==1)
cout << " Hey! we are coding for soft rectiliniear"<< endl;
else
cout << "Hey! we are coding for hard rectilinear"<< endl;

cout << " \n areas are :"<< endl;
for 
				(int i =0; i< row; ++i)
				{
					cout << area[i]<<" ";
				}
				cout << endl;
/*for 
				(int i =0; i< row; ++i)
				{
					cout << para1[i]<<" ";
				}
				cout << endl;
for 
				(int i =0; i< row; ++i)
				{
					cout << para2[i]<<" ";
				}
				cout << endl;
*/
	return 1;
}



