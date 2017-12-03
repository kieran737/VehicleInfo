/*-----------------------------------------------------------------------------

Name: Kieran Hodge

Date: 30/04/2015

Lab number: 7

--------------------------------------------------------------------------------
Program Description: This is a 'simple' program that will allow the user to input 
information about their Car or Lorry and if the user wants they can input both
by using the add function within each section, this program is functioned usings 
3 classes which are Vehicles, Cars and Lorry's these classes will guide the user
through the input process, if the user want to repeat the program the will have 
the option to at the end of the program and they can repeat this process as many
times as they want.
--------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>

using namespace std;

class Vehicles{
	private:
			string Manufacturer;
			int Year;
			string registrationNumber;
			string secondManufacturer;
			int secondYear;
			string secondRegistrationNumber;
	public:
		void vehiclesInput(){
			//Opening the text file for the program to write too.
			ofstream outFile;
			outFile.open("vehicle.txt");
			//Entering Informaiotn into Class.
			cout << "Enter Manufacturer Of Your Vehicle: ";
			cin >> Manufacturer;
			outFile << Manufacturer;
			cout << "Enter the Year Your Vehicle Was Manufacturered: ";
			cin >> Year;
			outFile << Year;
			cout << "Enter Your Registration Number: ";
			cin >> registrationNumber;
			outFile << registrationNumber;
			//Closing the text File and Saving Data.
			outFile.close();
			cout << "\n\n" << "Your Information Has Been Saved To Vehicles.txt" << "\n\n";
			//This simply Prints what the user has inputted into the class.
			cout << "Printout Of Your Vehicle's Information" << endl;
			cout << "Manufacturer: " << Manufacturer << '\n' << "Year The Vehicle Was Manufacturered: " << Year << '\n' << "Your Registration Number: " << registrationNumber << "\n\n";
		}
		//This VOID allows the user to input all the functions above a second time.
		void secondInput(){
			ofstream outFile;
				outFile.open("vehicle.txt");
				cout << "Enter Manufacturer Of Your Vehicle: ";
				cin >> secondManufacturer;
				outFile << secondManufacturer;
				cout << "Enter the Year Your Vehicle Was Manufactured: ";
				cin >> secondYear;
				outFile << secondYear;
				cout << "Enter Your Registration Number: ";
				cin >> secondRegistrationNumber;
				outFile << secondRegistrationNumber;
				outFile.close();
				cout << "\n\n" << "Your Information Has Been Saved To Vehicles.txt" << "\n\n";
				cout << "Printout Of Your Vehicle's Information" << endl;
				cout << "Manufacturer: " << secondManufacturer << '\n' << "Year The Vehicle Was Manufactured: " << '\n' << secondYear << "Your Registration Number: " << '\n' << secondRegistrationNumber << "\n\n";
			}
		void Printout(){
			cout << "Manufacturer"<< Manufacturer << endl;
			cout << "Year Manufacturered" << Year << endl;
			cout << "Registration Number" << registrationNumber << endl;
			cout << "IF ENTERED" << endl;
			cout << "Extra Manufacturer" << secondManufacturer << endl;
			cout << "Extra Year Manufactured" << secondYear << endl;
			cout << "Extra Registration Number" << secondRegistrationNumber << endl;
		}
};

class Car{
	private:
		int numberPassengers;
		string carType;
	public:
		void carInput(){
			//Opening the text file for the program to write too.
			ofstream outFile;
			outFile.open("vehicle.txt");
			cout << "Car Details" << endl;
			//Entering Information into Class.
			cout << "Enter Number Of Passengers: ";
			cin >> numberPassengers;
			outFile << numberPassengers;
			cout << "Enter Car Type: ";
			cin >> carType;
			outFile << carType;
			//Closing the text File and Saving Data.
			outFile.close();
			cout << "\n\n" << "Your Information Has Been Saved To Vehicles.txt" << "\n\n";
			//This simply Prints what the user has inputted into the class.
			cout << "Printout Of Your Car's Information" << endl;
			cout << "Number Of Passengers: " << numberPassengers << '\n' << "Car Type: " << carType << "\n\n";
		}
};
class Lorry{
	private:
		float Tonnage;
		string bodyType;
	public:
		void lorryInput(){
			//Opening the text file for the program to write too.
			ofstream outFile;
			outFile.open("vehicle.txt");
			cout << "Lorry Details" << endl;
			//Entering Information into Class.
			cout << "Enter Lorries Weight in Tonnes: ";
			cin >> Tonnage;
			outFile << Tonnage;
			cout << "Enter Body Type: ";
			cin >> bodyType;
			outFile << bodyType;
			//Closing the text File and Saving Data.
			outFile.close();
			cout << "\n\n" << "Your Information Has Been Saved To Vehicles.txt" << "\n\n";
			//This simply Prints what the user has inputted into the class.
			cout << "Printout Of Your Lorry's Information" << endl;
			cout << "Weight of Lorry: " << Tonnage << '\n' << "Body Type: " << bodyType << "\n\n";
		}
};
int main ()
{
	cout << "Instructions" << endl;
	cout << "Please Enter All Data Into The Program WITHOUT Spaces" << endl;
	cout << "" << endl;
	system("PAUSE");
	system ("cls");
	while(TRUE) {
		//The user will start off by entering their data into the Vehicle Class.
		Vehicles vehicleObject;
		vehicleObject.vehiclesInput();
		//This is where the user chooses between Car or Lorry.
		char Answer;
			while(true) { 
				system ("color 07");
				cout << "What Type of Vehicle Would You Like to Select Car or Lorry (C/L)";
				cin >> Answer;
				cout << endl;
				system ("cls");
				//If the User Inputs 'C' then it will all them to enter into the Car Class.
				if(Answer == 'c' || Answer == 'C')
				{					
					Car carObject;
					carObject.carInput();
					//Allowing the user to Add another Vehicle.
					char addAnswer;
						cout << "Would You Like to ADD A Lorry (y/n) ?";
						cin >> addAnswer;
						system ("cls");
						if(addAnswer == 'y' || addAnswer == 'Y')
						{
							Vehicles vehicleObject;
							vehicleObject.secondInput();						
							Lorry lorryObject;
							lorryObject.lorryInput();
							break;
						}
						else if (addAnswer == 'n' || addAnswer == 'N')
						{
							break;
						}
					break;
				}
				//If the User Inputs 'L' then it will all them to enter into the Lorry Class.
				else if(Answer == 'l'|| Answer == 'L')
				{
					Lorry lorryObject;
					lorryObject.lorryInput();
					//Allowing the user to Add another Vehicle.
					char addAnswer;
						cout << "Would You Like to ADD A Car (y/n) ?" << endl;
						cin >> addAnswer;
						system ("cls");
						if(addAnswer == 'y' || addAnswer == 'Y')
						{
							Vehicles vehicleObject;
							vehicleObject.vehiclesInput();						
							Car carObject;
							carObject.carInput();
							break;
						}
						else if (addAnswer == 'n' || addAnswer == 'N')
						{
							break;
						}
					break;
				}
			}
			////Printing out all Vehicles.
			//cout << "Printout Of All Your Vehicle Details" << endl;
			//Vehicles printoutObject;
			//printoutObject.Printout();
			
			//Restart Loop For Program.
			char answerRestart;
			while(true) { 
				system ("color 07");
				cout << "Would You Like To Restart (y/n)\n ";
				cin >> answerRestart;
				if(answerRestart == 'y' || answerRestart == 'Y' || answerRestart == 'n'|| answerRestart == 'N') {
					system ("cls");
					break;
				}			
				else
					system ("color 04");
				cout << "Invalid\n\n";
				Sleep (500);
			}
			if (answerRestart == 'n' || answerRestart == 'N') {
				system ("color 05");
				cout << "\n\n\n\n\n\n";
				cout << setw (58) << "Thank You For Contributing!";
				Sleep (2000);
				break;
			}	
		}	
}