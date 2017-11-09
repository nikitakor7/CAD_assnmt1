/*Main program 
Part 1 of the program aims at parsing the data 
Following are the files associated : 1) Project_1.cpp - parse the file  2)Sim_Annealing.cpp to carry out simulated annealing
Part 2 of the program aims at performing simulated annealing on the obtained  parsed data
/*********************************************************************************************************
Author : Nikita Korgaonkar
Subject : VLSI CAD 1 EE55301
Mini Project 1
Date 10/28/2017
For - Prof Sachin Sapatnekar*/

#include <iostream>
#include<string>
#include <fstream> //Objects belong to this class are associated with files opened for input and output purposes
#include <sstream> //Header providing string stream classes
#include <algorithm>
#include <ctime>
#include <cstdlib> // Header providing standard lib
#include <cmath> // Header providing math functions
#include"Project_1.cpp"

int main()
{
	cout << "Hi! I am going to parse the data for you :)\n"<<endl;
	project_1();
	
	return 0;
}
