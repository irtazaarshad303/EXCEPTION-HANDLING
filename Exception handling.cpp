#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class account {
private:
	string name;
	double balance;
public:
	account(string n, double b) :name(n), balance(b) {
		if (balance < 0) {
			throw invalid_argument("THE ERROR CAUGHT BECAUSE BALANCE CANNOT BE BELOW ZERO");
		}
		cout << "THE COSNTRCUTOR CALLED FOR THE NAME   :  " << name << endl;


	}
	
	void withdraw(double amount) {
		if (amount > balance) {
			throw runtime_error("NOT ENOUGH BALANCE TO WITHDRAW ");
		}
		balance -= amount;
		cout << "THE CASH HAS BEEN WITHDRAWN  :  " << amount << endl;
		cout << "THE REMAINING BALANCE IS    : " << balance << endl;
	}
	~account() {
		cout << "THE DESTRCUOTR CALLED FOR THE NAME  :  " << name << endl;
	}

};
int main() {
	try {
		account* A = new account("Irtaza", -200);
		delete A;
	}
	catch (exception& e) {
		cout << "EXCEPTION CAUGHT IN MAIN" << e.what() << endl;
	}
	try {
		account* B = new account("HAMZA", 1500);

		try {
			B->withdraw(1700);
		}
		catch (exception& e) {
			cout << "EXCEPTION CAUGHT IN MAIN" << e.what() << endl;
		}
		delete B;
	}
	catch (exception& e) {
		cout << "EXCEPTION CAUGHT IN THE MAIN" << e.what() << endl;
	}
	return 0;
}
