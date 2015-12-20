#include "Coins.h"

int main()
{
	cout << "Welcome to the Coin Interface! \n Your default coin storage object will be called myCoins" << endl;
	Coins myCoins(0,0,0,0);
	char option = '\0';
	cout << "You can either deposit or withdraw money or print your current balance \nPress s and enter to start\n" << endl;
	while (cin >> option)
	{
		int quart = 0;
		int dime = 0;
		int nick = 0;
		int penny = 0;

		int extract = 0;

		switch(option)
		{
			case 'd' :
				{cout << "\nPlease enter the amount of Quarters, Dimes, Nickels, and Pennies that you have \nQuarters: ";
				cin >> quart;
				cout << "Dimes : ";
				cin >> dime;
				cout << "Nickels: ";
				cin >> nick;
				cout << "Pennies: ";
				cin >> penny;
				Coins coindeposit(quart,dime,nick,penny);
				myCoins.depositChange(coindeposit);
				cout << "Current Balance: " << myCoins << endl;
				break;}

			case 'e':
				cout << "\nPlease input the amount in cents for extraction: ";
				cin >> extract;
				if (myCoins.hasSufficientAmount(extract))
					myCoins.extractChange(extract);
				else
					cout << "Insufficient Funds..." << endl;
				cout << "\nCurrent Balance: " << myCoins << endl;
				break;

			case 'p':
				cout << "\nCurrent Balance: " << myCoins<< "\n\n";
				break;
		}
		cout << "\nPlease choose one of the following options: " << endl;
		cout << "d - deposit change" << endl;
		cout << "e - extract change" << endl;
		cout << "p - print your myCoins balance\n" << endl;

	}
	return 0;
}
