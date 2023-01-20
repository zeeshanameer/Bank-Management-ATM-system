#include <iostream>		//for input output streams...
#include <conio.h>
#include <stdlib.h>		//for standard library...
#include <string>		//for string data type...
#include <iomanip>		//for custom spacing...
#include <fstream>		//for file management...
#include <windows.h>	//for color and delay...

using namespace std;

class Main{
	protected:
		int userBalance , found = 0;
		string userFirstName , userSecondName , userCNIC , userPhoneNumber , userAddress , userId , userPin;
		fstream dataFile , tempFile;
		char mainOption;
	public:	
		void mainScreen();		
};

class Bank : public Main{
	private:
		char optionAdminAccess;
		char adminScreenOption;
		int bal;
		string fn ,  sn , cnic , no , adr , id , pin;
		string checkUserId;
		string checkUserPin;
		string adminPassword;
		string adminUserName;
	public:	
		void adminAccess();
		void bankManagement();
		void withdrawMoney();
		void depositMoney();
		void addNewAccount();
		void searchUserRecord();
		void checkRequests();
};

class Atm : public Main{
	private:
		char chooseOption;
		string checkUserId;
		string checkUserPin;
	public:
		void creatingRequest();
		void customerCare();
		void accountRemainingBalance();
		void userMenuScreen();
		void userWithdrawMoney();
		void userDepositMoney();
};

void Main::mainScreen(){
	system("cls");

	cout<<"\n\n\t\t***************** M & Z BANK *****************\n";
	cout<<"\t\t|	For Admin Access     Press [1].	     |\n		|	For User  Access     Press [2].	     |\n		|	To End\t\t     Press [3].	     |\n";
	cout<<"\t\t**********************************************\n";
	cout<<"\n		Enter Your Choice: "; 
	Bank B;
	Atm A;                            
	mainOption = getch();
	switch(mainOption)
	{
		case '3':
			exit(0);
			break;
		case '1':
			B.adminAccess();
			break;
		case '2':
			A.userMenuScreen();
			break;
		default:
			mainScreen();
			break;
	}
}

//------------------------------------------------------------------------------------------------------------

void Bank::addNewAccount(){
	system ("cls");
	cout<<"\n\n\t\tEnter User First Name: ";
	cin>>userFirstName;
	cout<<"\n\t\tEnter User Second Name: ";
	cin>>userSecondName;
	cout<<"\n\t\tEnter User ID: ";
	cin>>userId;															
	cout<<"\n\t\tEnter User PIN (4 digit) : ";
	cin>>userPin;																																																																																	
	cout<<"\n\t\tEnter User CNIC: ";
	cin>>userCNIC;
	cout<<"\n\t\tEnter User Phone Number: ";
	cin>>userPhoneNumber;
	cout<<"\n\t\tEnter User Address: ";
	cin>>userAddress;
	cout<<"\n\t\tEnter Starting Balance:  $ ";
	cin>>userBalance;
	dataFile.open("M & Z Bank Management.txt" , ios::in | ios::app | ios::out);
	if(!dataFile)
	{
		dataFile.open("M & Z Bank Management.txt" , ios::in | ios::app | ios::out);
		dataFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance;
		dataFile.close();
		
		cout<<"\n\n\n\n\t\t\tError Opening The File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			system("cls");
			
		cout<<"\n\n\t\tSending You back to Management Screen";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				bankManagement();	
			
	}
	else
	{
		dataFile>>fn>>sn>>id>>pin>>cnic>>no>>adr>>bal;
		while(!dataFile.eof())
		{
			
			if (id == userId)
			{
				system("cls");
				int addUserSubMenu;
			
				cout<<"\n\n\n\n\t\t\tUser ID Already Exists";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				dataFile.close();
				system("cls");
				
				cout<<"\n\n\t\tSending You back to Management Screen";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				bankManagement();

			}
			dataFile>>fn>>sn>>id>>pin>>cnic>>no>>adr>>bal;
			
		}
		dataFile.close();
		dataFile.open("M & Z Bank Management.txt" ,ios::app | ios::out);
		dataFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;
		dataFile.close();
		system("cls");
		
		cout<<"\n\n\n\n\t\t\tSuccessfully Added New User";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		system("cls");
		
		cout<<"\n\n\t\tSending You back to Management Screen";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		bankManagement();
		}
}

void Bank::adminAccess(){
	system("cls");
	cout<<"\n\n\tEnter Adimn Username: ";
	cin>>adminUserName;
	cout<<"\tEnter Password: ";
	cin>>adminPassword;
	if(adminUserName == "admin" && adminPassword == "1234")
	{
		bankManagement();
	}
	else
	{
		if(adminUserName != "admin")
		{
			system("cls");
			
			cout<<"\n\n\t\t--------Username is Wrong.--------\n";
			Sleep(2000);	
			system("cls");
			cout<<"Enter [1] to try again or Enter [2] to go back: ";
			optionAdminAccess=getch();
			switch(optionAdminAccess)
			{
				case '2':
					mainScreen();
					break;
				case '1':
					adminAccess();
					break;
				default:
					mainScreen();
					break;	
			}
		}
		else
		{
			
			cout<<"--------Password is Wrong.--------\n";
			cout<<"Enter [1] to try again or Enter [2] to go back: ";
			optionAdminAccess=getch();
			switch(optionAdminAccess)
			{
				case '2':
					mainScreen();
					break;
				case '1':
					adminAccess();
					break;
				default:
					mainScreen();
					break;	
			}
		}
	}
	
}

void Bank::bankManagement(){
	system("cls");
	cout<<"\n\n\t\t     ...Bank Management System...\n\n";
	cout<<"\t1. Add Account\t\t\t\t2. Search User Records\n\t3. Deposit\t\t\t\t4. Withdraw\n";
	cout<<"\t5. Check Account Requests.\t\t6. Go Back.\n\t--------------------------------------------------------------";
	cout<<"\n\n\tEnter Your Choice: ";
	adminScreenOption = getch();
	switch(adminScreenOption)
	{
	case '1':
		addNewAccount();
		break;
	case '2':
		searchUserRecord();
		break;
	case '3':
		depositMoney();
		break;
	case '4':
		withdrawMoney();
		break;
	case '5':
		checkRequests();
		break;	
	case '6':
		mainScreen();
		break;
	default:
		bankManagement();
		break;
}
}

void Bank::checkRequests(){
	system("cls");
	dataFile.open("Account Creation Request.txt" , ios::in | ios::out | ios::app);
	if(!dataFile)
	{

		cout<<"\n\tError Opening File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
		system("cls");
	
		cout<<"\n\n\t\tSending You back to Bank Management Screen";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
		bankManagement();	
	}
	else
	{
		dataFile>>userFirstName>>userSecondName>>userPhoneNumber;
		while(!dataFile.eof())
		{
			cout<<"\n\tName: "<<userFirstName<<" "<<userSecondName;
			cout<<"\n\tContact Info: "<<userPhoneNumber;
			cout<<"\n\n``````````````````````````````````````";
			dataFile>>userFirstName>>userSecondName>>userPhoneNumber;
		}
		dataFile.close();
		cout<<"\n\n\t";
		system("pause");
		system("cls");
		cout<<"\n\n\t\tSending You back to Bank Management Screen";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
		bankManagement();			
	}	
}

void Bank::depositMoney(){
	system("cls");
	cout<<"\n\n\t\t\t\tDeposit Amount Option";
	dataFile.open("M & Z Bank Management.txt" , ios::in);
	if(!dataFile)
	{
		
	cout<<"\n\n\t\tError Opening the File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
	system("cls");

	cout<<"\n\n\t\tSending You back to Bank Management Screen";
	dataFile.close();
	for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
	bankManagement();
	}
	else
	{
		cout<<"\n\n\tEnter Your ID: ";
		cin>>checkUserId;
		tempFile.open("Temp File.txt" , ios::app | ios::out);
		dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
		while(!dataFile.eof())
		{
			
			if(checkUserId == userId)
			{	
				found++;
				system("cls");
				
				cout<<"\n\n\t\t\tAccount Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
				system("cls");	
				
				float updateBalance;
				cout<<"\n\n\tEnter Amount of Money you want to Deposit: $";
				cin>>updateBalance;
				userBalance = userBalance + updateBalance;
				system("cls");
				
				cout<<"\n\n\t\t\t\tSuccesfully Deposited";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
				system("cls");
			
				cout<<"\n\n\t\tTotal Amount of Money in your bank: $"<<userBalance<<endl;
				tempFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;								
				cout<<"\n\n\t\t";
				system("pause");
			}
			dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;	
		}
			dataFile.close();
			tempFile.close();
			remove("M & Z Bank Management.txt");
			rename("Temp File.txt" , "M & Z Bank Management.txt");
		if(found == 0)
		{
			
		cout<<"\n\n\t\tDoes not Exists";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
		}
			system("cls");
		
			cout<<"\n\n\t\tSending You back to Bank Management Screen";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			bankManagement();	
	}
}

void Bank::searchUserRecord(){
	system("cls");
	cout<<"\n\n\t\t\tSearch User Records\n\n";
	dataFile.open("M & Z Bank Management.txt" , ios::in );
	if(!dataFile)
	{
		
		cout<<"\n\n\t\t\tError Opening The File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		system("cls");
		
		cout<<"\n\n\t\tSending you back to Bank Management";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		dataFile.close();
		bankManagement();
	}
	else
	{
		cout<<"\n\n\t\tEnter User ID: ";
		cin>>checkUserId;
		dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
		while(!dataFile.eof())
		{
			
			if(checkUserId == userId)
			{
				found++;
				cout<<"\n\n\t\t\tFull Name: ";
				cout<<userFirstName<<" "<<userSecondName;
				cout<<"\n\t\t\tID: ";
				cout<<userId;															
				cout<<"\n\t\t\tPIN (4 digit) : ";
				cout<<userPin;																																																																																
				cout<<"\n\t\t\tCNIC: ";
				cout<<userCNIC;
				cout<<"\n\t\t\tEnter User Phone Number: ";
				cout<<userPhoneNumber;
				cout<<"\n\t\t\tAddress: ";
				cout<<userAddress;
				cout<<"\n\t\t\tTotal Balance:  $ ";
				cout<<userBalance;
				cout<<"\n\n\t\t\t";
				system("pause");											
			}
			dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
			
		}
			dataFile.close();
			if(found == 0)
			{
			
			cout<<"\n\n\t\tDoes not Exists";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}	
			}
			system("cls");
			
			cout<<"\n\n\t\tSending you back to Bank Management";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			bankManagement();
	}
}

void Bank::withdrawMoney(){
	system("cls");
	cout<<"\n\n\t\t\t\tWithdraw Amount Option";
	dataFile.open("M & Z Bank Management.txt" , ios::in);
	if(!dataFile)
	{
	
	cout<<"\n\n\t\tError Opening the File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
	{
		cout<<".";
		Sleep(1000);
		sleepLoop++;
	}
	system("cls");

	cout<<"\n\n\t\tSending You back to Bank Management Screen";
	for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
	{
		cout<<".";
		Sleep(1000);
		sleepLoop++;
	}
	bankManagement();
	}
	else
	{

		cout<<"\n\n\tEnter Your ID: ";
		cin>>checkUserId;
		tempFile.open("Temp File.txt" , ios::app | ios::out);
		dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
		while(!dataFile.eof())
		{
		
			if(checkUserId == userId)
			{	
				found++;
				system("cls");
				
				cout<<"\n\n\t\t\tAccount Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				system("cls");	
			
				float updateBalance;
				cout<<"\n\n\tEnter Amount of Money you want to Withdraw: $";
				cin>>updateBalance;
				if(userBalance >= updateBalance)
				{
					userBalance = userBalance - updateBalance;
					system("cls");
				
					cout<<"\n\n\t\t\t\tSuccesfully Withdrawn";
					for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
					system("cls");
				
					cout<<"\n\n\t\tAmount of Money Left in your Bank Account: $"<<userBalance<<endl;
					cout<<"\n\n\t\t";
					system("pause");
					tempFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;
				}
				else
				{
					system("cls");
			
					tempFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;
					cout<<"\n\n\t\t\tNot Enough Money in your Account!";
					dataFile.close();
					tempFile.close();
					remove("M & Z Bank Management.txt");
					rename("Temp File.txt" , "M & Z Bank Management.txt");
					Sleep(1000);
					system("cls");
			
					cout<<"\n\n\t\tSending You Back to Bank Management Screen";
					for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
					bankManagement();
				}								
			}
			dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
			
			}
			dataFile.close();
			tempFile.close();
			remove("M & Z Bank Management.txt");
			rename("Temp File.txt" , "M & Z Bank Management.txt");
			if(found == 0)
			{
		
			cout<<"\n\n\t\tAccount Does not Exists";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			}
			system("cls");
		
			cout<<"\n\n\t\tSending You back to Bank Management Screen";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			bankManagement();
		}
}

//------------------------------------------------------------------------------------------------------------


void Atm::userMenuScreen(){
	system("cls");
	
	cout<<"\n\n\t\t\t   ...Bank Management System...\n\n";
	cout<<"\t1. Withdraw Money.\t\t\t\t2. Deposit Money.\n\t3. Check Balance.\t\t\t\t4. Create a New Account.\n";
	cout<<"\t5. Need any Help.\t\t\t\t6. Go to Previous Menu.\n\t7. Create Account.\t\t\t\t8. Exit.\n\t-----------------------------------------------------------------------";
	cout<<"\n\n\tEnter Your Choice: ";
	chooseOption = getch();
	switch(chooseOption)
		{
			case '1':
				userWithdrawMoney();
				break;
			case '2':
				userDepositMoney();
				break;
			case '3':
				accountRemainingBalance();
				break;
			case '4':
				creatingRequest();
				break;
			case '5':
				customerCare();
				break;
			case '6':
				mainScreen();
				break;
			case '7':
				creatingRequest();
				break;
			case '8':
				exit(0);
				break;			
			default:
				userMenuScreen();	
				break;	
		}
}

void Atm::accountRemainingBalance(){
	system("cls");
	cout<<"\n\n\t\t\tSearch User Records\n\n";
	dataFile.open("M & Z Bank Management.txt" , ios::in );
	if(!dataFile)
	{
		
		cout<<"\n\n\t\t\tError Opening The File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		system("cls");
		
		cout<<"\n\n\t\t\tSending You Back to Menu Screen";
		dataFile.close();
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		userMenuScreen();
	}
	else
	{
		
		cout<<"\n\n\tEnter User ID: ";
		cin>>checkUserId;
		cout<<"\tEnter Your Pin: ";
		cin>>checkUserPin;
		system("cls");
		dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
		while(!dataFile.eof())
		{
			
			if(checkUserId == userId && checkUserPin == userPin)
			{
				found++;
				system("cls");
				
				cout<<"\n\n\t\t\tAccount Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				cout<<"\n\n\t\t\tPin Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				system("cls");
				
				cout<<"\n\n\t\t\t";
				cout<<userFirstName<<" "<<userSecondName;
				cout<<"\n\n\t\t\tRemaining Balance:  $ ";
				cout<<userBalance;
				cout<<"\n\n\t\t\t";
				system("pause");
			}
			dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
			
		}
		dataFile.close();
			if(found == 0)
			{
			
			cout<<"\n\n\t\tDoes not Exists";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}	
			
			}
		system("cls");
		
		cout<<"\n\n\t\tSending You back to User Menu Screen";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
		userMenuScreen();
	}
}

void Atm::creatingRequest(){
	system("cls");
	cout<<"\n\n\tEnter Your First Name: ";
	cin>>userFirstName;
	cout<<"\tEnter Your Last Name: ";
	cin>>userSecondName;
	cout<<"\tEnter Your Contact Information: ";
	cin>>userPhoneNumber;
	
	dataFile.open("Account Creation Request.txt" , ios::in | ios::out | ios::app);
	if(!dataFile)
	{
		cout<<"error opening file...";
	}
	else
	{
		dataFile<<userFirstName<<" "<<userSecondName<<" "<<userPhoneNumber<<endl;							
		system("cls");
		cout<<"\n\n\t\tRequest Generated Succesfully";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
	}
	dataFile.close();
	system("cls");
	cout<<"\n\n\t\tSending You back to User Menu Screen";
	for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
	{
		cout<<".";
		Sleep(1000);
		sleepLoop++;
	}
	userMenuScreen();	
}

void Atm::customerCare(){
	system("cls");
	cout<<"\n\n\tStep-1: Pick up the phone next to you.\n\tStep-2: Dial **** to contact the bank for any help.\n\n\t";
	system("pause");
	userMenuScreen();
}

void Atm::userDepositMoney(){
	system("cls");
	cout<<"\n\n\t\t\t\tDeposit Amount Option";
	dataFile.open("M & Z Bank Management.txt" , ios::in);
	if(!dataFile)
	{

	cout<<"\n\n\t\tError Opening the File";
		for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
	system("cls");

	cout<<"\n\n\t\tSending You back to User Menu Screen";
	dataFile.close();
	for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
		{
			cout<<".";
			Sleep(1000);
			sleepLoop++;
		}
	userMenuScreen();
	}
	else
	{

		cout<<"\n\n\tEnter Your ID: ";
		cin>>checkUserId;
		cout<<"\tEnter Your Pin: ";
		cin>>checkUserPin;
		tempFile.open("Temp File.txt" , ios::app | ios::out);
		dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
		while(!dataFile.eof())
		{
			
			if(checkUserId == userId && checkUserPin == userPin)
			{	
				found++;
				system("cls");
				
				cout<<"\n\n\t\t\tAccount Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				cout<<"\n\n\t\t\tPin Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				system("cls");	
		
				float updateBalance;
				cout<<"\n\n\tEnter Amount of Money you want to Deposit: $";
				cin>>updateBalance;
				userBalance = userBalance + updateBalance;
				system("cls");
			
				cout<<"\n\n\t\t\t\tSuccesfully Deposited";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				system("cls");
			
				cout<<"\n\n\t\tTotal Amount of Money in your bank: $"<<userBalance<<endl;
				tempFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;								
				cout<<"\n\n\t\t";
				system("pause");
			}
			dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;	
		}
			dataFile.close();
			tempFile.close();
			remove("M & Z Bank Management.txt");
			rename("Temp File.txt" , "M & Z Bank Management.txt");
		if(found == 0)
		{
		cout<<"Does not Exists....";
		Sleep(2000);	
		}
			system("cls");
		
			cout<<"\n\n\t\tSending You back to User Menu Screen";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			userMenuScreen();	
	}
}

void Atm::userWithdrawMoney(){
	system("cls");
	cout<<"\n\n\t\t\t\tWithdraw Amount Option";
	dataFile.open("M & Z Bank Management.txt" , ios::in);
	if(!dataFile)
	{
	
	cout<<"\n\n\t\tError Opening the File";
	for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
	system("cls");

	cout<<"\n\n\t\tSending You back to Main Screen";
	for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
	userMenuScreen();
	}
	else
	{

		cout<<"\n\n\tEnter Your ID: ";
		cin>>checkUserId;
		cout<<"\tEnter Your Pin: ";
		cin>>checkUserPin;
		tempFile.open("Temp File.txt" , ios::app | ios::out);
		dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
		while(!dataFile.eof())
		{
		
			if(checkUserId == userId && checkUserPin == userPin)
			{	
				found++;
				system("cls");
			
				cout<<"\n\n\t\t\tAccount Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				cout<<"\n\n\t\t\tPin Verified";
				for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
				{
					cout<<".";
					Sleep(1000);
					sleepLoop++;
				}
				system("cls");	
			
				float updateBalance;
				cout<<"\n\n\tEnter Amount of Money you want to Withdraw: $";
				cin>>updateBalance;
				if(userBalance >= updateBalance)
				{
					userBalance = userBalance - updateBalance;
					system("cls");
			
					cout<<"\n\n\t\t\t\tSuccesfully Withdrawn";
					for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
					system("cls");
			
					cout<<"\n\n\t\tAmount of Money Left in your Bank Account: $"<<userBalance<<endl;
					cout<<"\n\n\t\t";
					system("pause");
					tempFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;
				}
				else
				{
					system("cls");
			
					tempFile<<userFirstName<<" "<<userSecondName<<" "<<userId<<" "<<userPin<<" "<<userCNIC<<" "<<userPhoneNumber<<" "<<userAddress<<" "<<userBalance<<endl;
					cout<<"\n\n\t\t\tNot Enough Money in your Account";
					dataFile.close();
					tempFile.close();
					remove("M & Z Bank Management.txt");
					rename("Temp File.txt" , "M & Z Bank Management.txt");
					for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
					system("cls");
			
					cout<<"\n\n\t\tSending You Back to User Menu Screen";
					for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
					{
						cout<<".";
						Sleep(1000);
						sleepLoop++;
					}
					userMenuScreen();
				}								
			}
			dataFile>>userFirstName>>userSecondName>>userId>>userPin>>userCNIC>>userPhoneNumber>>userAddress>>userBalance;
			
			}
			dataFile.close();
			tempFile.close();
			remove("M & Z Bank Management.txt");
			rename("Temp File.txt" , "M & Z Bank Management.txt");
			if(found == 0)
			{
		
			cout<<"\n\n\t\tDoes not Exists";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}	
			}
			system("cls");
		
			cout<<"\n\n\t\tSending You back to User Menu Screen";
			for(int sleepLoop=0 ; sleepLoop<=4 ; sleepLoop++)
			{
				cout<<".";
				Sleep(1000);
				sleepLoop++;
			}
			userMenuScreen();
		}
}

int main()
{
	system("Color 70");
	Main M;
	M.mainScreen();	
	return 0;
}
