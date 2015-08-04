#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
class AccountBalance{
    public:
    	int processTransactions(int startingBalance, vector<string> transactions);
};
int AccountBalance::processTransactions(int startingBalance, vector<string> transactions){
    	for(int i = 0; i < transactions.size(); i++){
			int amount;
            char tt;
            sscanf(transactions[i].c_str(), "%c%d", &tt, &amount);
            	if(tt == 'C')
                    startingBalance += amount;
            	else
                    startingBalance -= amount;
            }
    	return startingBalance;
    }
	
int main(){
	vector<string> t;
	t.push_back("C 250");
	t.push_back("C 250");
	t.push_back("D 400");
	AccountBalance a;
	cout<<a.processTransactions(0, t)<<endl;
	
	int x = 5;
	int &b = x;
	cout<<b<<endl;
	b = 10;
	cout<<x<<endl;

	return 0;
}
