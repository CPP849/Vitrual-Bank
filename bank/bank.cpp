/*
 * bank.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: praneel
 */
// ***Virtual Bank v1.0.0*** //
// 130% percent
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <future>

using namespace std;

void intro();
void main_menu();
void create_account();
void show_account();
void modify_account();
void deposit();
void withdraw();
void delete_account();
void loans();
void pay_debt();

string null;
string first_name;
string last_name;
string account_number;
string username;
string password;
double balance;
double deposit_money;
double withdraw_money;
double debt;
double loan_price;
double take_loan;
double pay_loan;

int main() {
	intro();
	main_menu();
}

void main_menu() {
	system("clear");
	int choiceNum;
	cout << "		██╗░░░██╗██╗██████╗░████████╗██╗░░░██╗░█████╗░██╗░░░░░  ██████╗░░█████╗░███╗░░██╗██╗░░██╗" << endl;
	cout << "		██║░░░██║██║██╔══██╗╚══██╔══╝██║░░░██║██╔══██╗██║░░░░░  ██╔══██╗██╔══██╗████╗░██║██║░██╔╝" << endl;
	cout << "		╚██╗░██╔╝██║██████╔╝░░░██║░░░██║░░░██║███████║██║░░░░░  ██████╦╝███████║██╔██╗██║█████═╝░" << endl;
	cout << "		░╚████╔╝░██║██╔══██╗░░░██║░░░██║░░░██║██╔══██║██║░░░░░  ██╔══██╗██╔══██║██║╚████║██╔═██╗░" << endl;
	cout << "		░░╚██╔╝░░██║██║░░██║░░░██║░░░╚██████╔╝██║░░██║███████╗  ██████╦╝██║░░██║██║░╚███║██║░╚██╗" << endl;
	cout << "		░░░╚═╝░░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚═╝░░╚═╝╚══════╝  ╚═════╝░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝" << endl;
	cout << "							█░█ ▄█ ░ █░█ ░ █▀█" << endl;
	cout << "					   	    	▀▄▀ ░█ ▄ ▀▀█ ▄ █▄█\n\n\n\n\n\n" << endl;
	cout << "						Main Menu\n\n";
	cout << "						(01)	Create an Account" << endl;
	cout << "						(02)	Show Account" << endl;
	cout << "						(03)	Modify Account" << endl;
	cout << "						(04)	Deposit Money" << endl;
	cout << "						(05)	Withdraw Money" << endl;
	cout << "						(06)	Loans" << endl;
	cout << "						(07)	Pay Debt" << endl;
	cout << "						(08)	DELETE ACCOUNT\n\n";
	cout << "				Pick an Option From the Main Menu:	";
	cin >> choiceNum;
	if (choiceNum == 1) {
		create_account();
	} if (choiceNum == 2) {
		show_account();
	} if (choiceNum == 3) {
		modify_account();
	} if (choiceNum == 4) {
		deposit();
	} if (choiceNum == 5) {
		withdraw();
	} if (choiceNum == 6) {
		loans();
	} if (choiceNum == 7) {
		pay_debt();
	}
	if (choiceNum == 8) {
		delete_account();
	}
}

void show_account() {
	system("clear");
	cout << "Name:    " << first_name << " " << last_name << endl;
	cout << "Account Number:    " << account_number << endl;
	cout << "Balance:    " << balance << endl;
	cout << "Debt:    " << debt << endl;
	cout << "Loans:    " << loan_price << endl;
	cout << "Username:    " << username << endl;
	cout << "Password:    " << password << endl;
	sleep(2);
	cout << "\n\nIf you don't see anything, try creating an account first." << endl;
	cout << "Type in \"return\" to leave" << endl;
	cin >> null;
	main_menu();
}

void create_account() {
	system("clear");
	cout << "First Name:    ";
	cin >> first_name;
	cout << "\nLast Name:	";
	cin >> last_name;
	cout << "\nAccount Number:    ";
	cin >> account_number;
	cout << "\nUsername:	";
	cin >> username;
	cout << "\nPassword:	";
	cin >> password;
	balance = 1000;
	system("clear");
	main_menu();
}


void modify_account() {
	int choice;
	system("clear");
	cout << "What would you like to change?" << endl;
	cout << "(01) Username	(02)	Password	(03)	Account Number:    ";
	cin >> choice;
	if (choice == 1) {
		cout << "Pick a new Username:    ";
		cin >> username;
		cout << "Updation Complete" << endl;
		sleep(1);
		main_menu();
	}
	if (choice == 2) {
		cout << "Pick a new Password:    ";
		cin >> password;
		sleep(1);
		main_menu();
	}
	if (choice == 3) {
		cout << "Pick a new Account Number:    ";
		cin >> account_number;
		sleep(1);
		main_menu();
	}
	if (choice > 3) {
		cout << "Please Try again";
		sleep(1);
		system("clear");
		modify_account();
	}
}

void deposit() {
	system("clear");
	cout << "How much would you like to deposit?    ";
	cin >> deposit_money;
	if (deposit_money < 10000) {
		balance = deposit_money + balance;
		if (balance < 0) {
			debt = balance;
			main_menu();
		} if (balance > 0) {
			debt = 0;
			main_menu();
		}
	}
	if (deposit_money > 10000) {
		cout << "You can not deposit more than $10000" << endl;
		sleep(2);
		deposit();
	}
}

void withdraw() {
	system("clear");
	cout << "How much would you like to withdraw?    ";
	cin >> withdraw_money;
	balance = balance - withdraw_money;
	if (balance < 0) {
		debt = balance;
	} if (balance > 0) {
		debt = 0;
	}
	main_menu();
}

void delete_account() {
	system("clear");
	int delete_decision;
	string delete_password;
	cout << "\nARE YOU SURE? (type in \"1\" to confirm)    ";
	cin >> delete_decision;
	if (delete_decision == 1) {
		system("clear");
		cout << "Type in password to confirm:    ";
		cin >> delete_password;
		if (delete_password == password) {
			system("clear");
			username = "";
			password = "";
			account_number = "";
			first_name = "";
			last_name = "";
			balance = 0;
			main_menu();
		} if (delete_password != password) {
			system("clear");
			sleep(5);
			main_menu();
		}
	}
	if (delete_decision > 1) {
		system("clear");
		sleep(5);
		main_menu();
	}
}

void loans() {
	int choice;
	system("clear");
	cout << "What would you like to do? (01) Take a Loan    (02) Pay Loans" << endl;
	cin >> choice;
	if (choice == 1) {
		if (loan_price < 500) {
			cout << "How much loan do you want?    ";
			cin >> take_loan;
			loan_price = loan_price + take_loan;
			balance = balance + loan_price;
			take_loan = 0;
			system("clear");
			main_menu();
		} else {
			cout << "Try paying off your loans and try again." << endl;
			sleep(2);
			system("clear");
			main_menu();
		}
	} if (choice == 2) {
		cout << "How much loan would you like to pay off?    ";
		cin >> pay_loan;
		loan_price = loan_price - pay_loan;
		balance = balance - pay_loan;
		system("clear");
		main_menu();
	}
}

void pay_debt() {
	double pay_debt_price;
	system("clear");
	cout << "How much debt would you like to pay?    ";
	cin >> pay_debt_price;
	debt = debt + pay_debt_price;
	balance = balance - pay_debt_price;
	pay_debt_price = 0;
}

void intro() {
	system("clear");
	cout << "		██╗░░░██╗██╗██████╗░████████╗██╗░░░██╗░█████╗░██╗░░░░░  ██████╗░░█████╗░███╗░░██╗██╗░░██╗" << endl;
	cout << "		██║░░░██║██║██╔══██╗╚══██╔══╝██║░░░██║██╔══██╗██║░░░░░  ██╔══██╗██╔══██╗████╗░██║██║░██╔╝" << endl;
	cout << "		╚██╗░██╔╝██║██████╔╝░░░██║░░░██║░░░██║███████║██║░░░░░  ██████╦╝███████║██╔██╗██║█████═╝░"<< endl;
	cout << "		░╚████╔╝░██║██╔══██╗░░░██║░░░██║░░░██║██╔══██║██║░░░░░  ██╔══██╗██╔══██║██║╚████║██╔═██╗░" << endl;
	cout << "		░░╚██╔╝░░██║██║░░██║░░░██║░░░╚██████╔╝██║░░██║███████╗  ██████╦╝██║░░██║██║░╚███║██║░╚██╗" << endl;
	cout << "		░░░╚═╝░░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚═════╝░╚═╝░░╚═╝╚══════╝  ╚═════╝░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝" << endl;
	cout << "							█░█ ▄█ ░ █░█ ░ █▀█" << endl;
	cout << "							▀▄▀ ░█ ▄ ▀▀█ ▄ █▄█\n\n\n" << endl;
	cout << "					  ████████████████████████████████████████▀█" << endl;
	cout << "					  █▄─▄███─▄▄─██▀▄─██▄─▄▄▀█▄─▄█▄─▀█▄─▄█─▄▄▄▄█" << endl;
	cout << "					  ██─██▀█─██─██─▀─███─██─██─███─█▄▀─██─██▄─█" << endl;
	cout << "					  ▀▄▄▄▄▄▀▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▀▀▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▄▄▀" << endl;
	sleep(5);
	system("clear");
}
