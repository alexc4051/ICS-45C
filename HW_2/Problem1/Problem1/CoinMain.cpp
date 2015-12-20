#include "Coins.h"
const int CENTS_FOR_CHIPS = 68;
const int CENTS_CHANGE_TO_POCKET = 132;
int main()
{
	Coins pocket(5,3,6,8), piggyBank(50,50,50,50), vacuum(1,2,3,4);
	pocket.extractChange(CENTS_FOR_CHIPS);
	cout << "I have " << pocket << " left in my pocket." << endl;
	pocket.depositChange(piggyBank.extractChange(CENTS_CHANGE_TO_POCKET));
	cout << "I have " << pocket << " in my pocket and " << piggyBank << " in my PiggyBank." << endl;
	piggyBank.depositChange(vacuum);
	cout << "I have " << piggyBank << " in my PiggyBank." << endl;
	return 0;
}
