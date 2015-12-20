#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
  Coins( int q, int d, int n, int p )
  {quarters = q;
	dimes = d;
	  nickels= n;
	  pennies = p;
  };
  void depositChange( Coins c )
  {quarters += c.quarters;
	  dimes += c.dimes;
	  nickels += c.nickels;
	  pennies += c.pennies;
  };
  bool hasSufficientAmount( int amount )
  {if (totalcents(quarters,dimes,nickels,pennies) >= amount)
  return true;
  return false;
  }
	  Coins extractChange( int amount )
	  { Coins extract(0,0,0,0);
		Coins original(0,0,0,0);
	  int total = totalcents(quarters, dimes, nickels, pennies);
	  int newtotal = total - amount;
		  if (!hasSufficientAmount(amount))
		  {Coins c(0,0,0,0);
			  cerr << "NOT ENOUGH MONEY FOR ITEM" << endl;
			return c;}
		  extract.depositChange(newCoin(amount));
		  original.depositChange(newCoin(newtotal));
		  quarters = original.quarters;
		  dimes = original.dimes;
		  nickels = original.nickels;
		  pennies = original.pennies;
	  return extract;
	};
  void print( ostream & out )
  {
	  out << quarters << " quarters, ";
	  out << dimes << " dimes, ";
	  out << nickels << " nickels, ";
	  out << pennies << " pennies\n";
	  out << "Total Cents: " << totalcents(quarters,dimes,nickels,pennies);
      };
private:
  int quarters, dimes, nickels, pennies;
  int totalcents(int q, int d, int n, int p)
 {return q*CENTS_PER_QUARTER + d*CENTS_PER_DIME + n*CENTS_PER_NICKEL + p;}
  Coins newCoin(int amount)
  {
	  int quarter = 0;
	  int dime = 0;
	  int nickel = 0;
	  int penny = 0;
	  while (amount >= CENTS_PER_QUARTER)
	  {
		  amount-= CENTS_PER_QUARTER;
		  quarter += 1;
	  }
	  while (amount >= CENTS_PER_DIME)
	  {
		  amount-= CENTS_PER_DIME;
		  dime += 1;
	  }
	  while (amount >= CENTS_PER_NICKEL)
	  {
		  amount-= CENTS_PER_NICKEL;
		  nickel += 1;
	  }
	  while (amount >= 1)
	  {
		  amount-= 1;
		  penny += 1;
	  }
	  Coins c(quarter, dime,nickel,penny);
	  return c;
  }
};
ostream & operator << ( ostream & out, Coins & c )
{
  c.print( out );
  return out;
};
