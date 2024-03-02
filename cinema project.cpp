#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

// declarations
void start();
void errorScreen();
void errorSelect();
void mainScreen();
void mainSelect();
void registerScreen();
void registerSelect();
void loginScreen();
void loginSelect();
void adminScreen();
void adminSelect();
void editmovieScreen();
void editmovieSelect();
void aboutScreen();
void movies();
void bookmovieScreen();
void selectseat();

// classes
class cinema // the main class
{
public:
	string movieName;
	string status;
	string genre;
	string rating;
	// price of seats
	int priceGold;
	int priceSiverl;
	int pricePlat;
	// number of seats
	bool seatGold;
	bool seatSilver;
	bool seatPlat;
	cinema()
	{
		priceGold = 150;
		priceSiverl = 80;
		pricePlat = 250;

	}
	void editPrice(int gold, int silver, int plat)
	{

		priceGold = gold;
		priceSiverl = silver;
		pricePlat = plat;
	}
} C;
class seats : public cinema // to control all cinema seats
{
public:
	int selectedMovie;
	string myMovie;
	string myName;
	vector<string> seatcheck[10];


} se;
class movies : public cinema // for admin section
{

public:
	void addmovies(string m, string g, string s, string r)
	{
		movieName = m;
		genre = g;
		status = s;
		rating = r;
	}
} M[10];
class admin : public cinema
{
public:
	string AdminUsername = "qqq";
	int password = 1234;

} A;
class user : cinema // for user section
{
public:
	string username;
	int password, id;

	void set_user(string username, int password, int id)
	{
		this->id = id;
		this->username = username;
		this->password = password;
	}
} u[100];

// definitions
void start()
{
	u[0].username = "abdo";
	u[0].password = 1234;
	u[0].id = 1;
	movies();
	mainScreen();
}
void errorScreen() // to display ERROR screen
{                  // to display error screen if user enterd a rong input
	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                        something went wrong                                                        " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "     press 1 to go back to main sceen                                                                           " << endl;
	cout << "     press 2 to exit                                                                                                           " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "           your choice -----)> ";
	errorSelect();
}
void errorSelect() // to select from the ERROR srceen
{                  // to select an option from the error screen
	int input;
	cin >> input;
	if (input == 1)
	{
		mainScreen();
	}
	if (input == 2)
	{
		cout << endl
			<< endl
			<< "                                                              thank you for visiting Le Grand Rex !!                                                            " << endl
			<< endl;
	}
}
void mainScreen() // to display the main screen
{

	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                  Welcome To Le Grand Rex!!                                                      " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "  1.Register                                                                               " << endl;
	cout << "  2.Login                                                                                   " << endl;
	cout << "  3.Admin Login                                                                                                            " << endl;
	cout << "  4.About                                                                                                                       " << endl;
	cout << "  5.Exit                                                                                                                            " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                   ****************************************************                                   " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "           your choice -----)>  ";
	//----------------------------------------------------------------------------------

	mainSelect();
}
void mainSelect() // to select an option from the main screen
{
	int input;
	do
	{
		cin >> input;
	} while (input > 5 || input < 1);

	if (input == 1)
	{
		registerScreen();
	}

	if (input == 2)
	{
		loginScreen();
	}
	if (input == 3)
	{
		adminScreen();
	}
	if (input == 4)
	{
		aboutScreen();
	}
	if (input == 5)
	{
		cout << endl
			<< endl
			<< "                                                              thank you for visiting Le Grand Rex !!                                                            " << endl
			<< endl;
	}
}
void registerScreen() // to display the register screen
{

	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                              Register                                                                        " << endl;
	cout << "                                      Create a new account                                                             " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "     press 1 to continue                                                                                                  " << endl;
	cout << "     press 2 to go back to main screen                                                                         " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                   ****************************************************                                   " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "           your choice -----)> ";
	registerSelect();
}
void registerSelect() // to select an option from the register screen
{
	int input;
	cin >> input;
	if (input == 1)
	{
		string username;
		int password;
		int id = -1;

		cout << "please enter id from (1-100) : " << endl;
		cout << "unavilabale ids : " << endl;
		cout << "                   ****************************************************                                  " << endl;

		for (int i = 0; i < 100; i++) // displays the unavilable ids
		{
			if (u[i].id != 0)
				cout << u[i].id << "  ";
		}
		do
		{
			if ((id > 100) || (id < 1)) // make sure the input is 100>n>0
			{
				cout << endl
					<< "the id should be from 1 to 100" << endl;
			}
			cout << "ID : ";
			cin >> id;
		} while ((id > 100) || (id < 1));

		cout << "enter a username : ";
		cin >> username;
		cout << endl;
		cout << "enter a password (numbers): ";
		cin >> password;
		cout << endl;
		u[id].set_user(username, password, id); // sends the username and the id to the user class
		cout << "                   ****************************************************                                  " << endl;
		cout << "                                  User Registered Succesfully !" << endl;
		cout << "                                   you may login to continue" << endl
			<< endl;
		cout << " press 1 to go to  Login screen  " << endl;
		cout << " press 2 to go to  main screen  " << endl
			<< endl;
		cout << "           your choice -----)>  ";

		int input2;
		cin >> input2;
		if (input2 == 1)
		{
			loginScreen();
		}
		if (input2 == 2)
		{
			mainScreen();
		}
	}

	if (input == 2)
	{
		mainScreen();
	}
}
void loginScreen() // to diplay Login screen
{

	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                    Login into your Account                                                          " << endl;
	cout << "                                                                                                                                        " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "     press 1 to continue to Login                                                                                   " << endl;
	cout << "     press 2 to Register                                                                                                  " << endl;
	cout << "     press 3 to go back to main screen                                                                         " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                   ****************************************************                                   " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "           your choice -----)> ";
	loginSelect();
}
void loginSelect() // to select an option from the Login screen
{
	int input;
	cin >> input;
	if (input == 1)
	{
		string username;
		int password;
		bool check_username = 0;
		cout << "username : ";
		cin >> username;
		for (int i = 0; i < 100; i++) // to check if the username exists
		{
			if (username == u[i].username)
			{
				check_username = 1;
				cout << "password : ";
				cin >> password;
				if (password == u[i].password)
				{
					cout << "welcome back " << u[i].username << "!!" << endl;
					se.myName = username;
					// new screen has the movies
					bookmovieScreen();
				}
				if (password != u[i].password)
				{
					cout << "wrong username or password !! " << endl;
					errorScreen();
				}
			}
		}
		if (check_username == 0)
		{
			cout << "wrong username or password !! " << endl;
			errorScreen();
		}
	}
	if (input == 2)
	{
		registerScreen();
	}
	if (input == 3)
	{
		mainScreen();
	}
}
void movielistScreen() // to diplay movie list screen
{

	cout << "                   ****************************************************                                  " << endl;
	cout << "                                 avilable movies at Le Grand Rex                                                " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " " << endl;
	}

	cout << "           your choice -----)>  ";
}
void adminScreen() // to diplay admin Login screen
{
	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                  Welcome To admin screen                                                        " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "  1.Login                                                                                                                         " << endl;
	cout << "  2. Go to main screen                                                                                                   " << endl;
	cout << "                                                                                                                                        " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                   ****************************************************                                   " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "           your choice -----)>  ";
	adminSelect();
}
void adminSelect() // to select an option from the admin Login screen
{
	int input;
	do
	{
		cin >> input;
	} while (input > 2 || input < 1);

	if (input == 1)
	{

		string username;
		int password;
		bool check_username = 0;
		cout << "Admin username : ";
		cin >> username;

		if (username == A.AdminUsername)
		{
			check_username = 1;
			cout << "password : ";
			cin >> password;

			if (password == A.password)
			{
				cout << "welcome back " << A.AdminUsername << "!!" << endl;

				editmovieScreen();
			}
			if (password != A.password)
			{
				cout << "wrong username or password !! " << endl;
				errorScreen();
			}
		}

		if (check_username == 0)
		{
			cout << "wrong username or password !! " << endl;
			errorScreen();
		}
	}

	if (input == 2)
	{
		mainScreen();
	}
}
void editmovieScreen() // to diplay edit movie  screen
{

	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                  Welcome ADMIN  !!                                                                   " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "  1.edit movies                                                                                                              " << endl;
	cout << "  2.edit prices                                                                                                                " << endl;
	cout << "  3.Exit                                                                                                                            " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                   ****************************************************                                   " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "           your choice -----)>  ";
	editmovieSelect();
}
void editmovieSelect() // to select an option from the edit movie  screen
{
	int input;
	do
	{
		cin >> input;
	} while (input > 3 || input < 1);

	if (input == 1)
	{
		cout << "list of movies :" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << "." << M[i].movieName << endl;
		}
		cout << "press 1 to add movies or 2 for main screen :  ";
		int input;
		cin >> input;
		if (input == 1)
		{
			string m, g, s, r;
			cout << "enter movie name : ";
			cin >> m;
			cout << endl
				<< "enter movie genre : ";
			cin >> g;
			cout << endl
				<< "enter movie status : ";
			cin >> s;
			cout << endl
				<< "enter movie rating  : ";
			cin >> r;
			cout << "enter the number you want movie to be in(1-10) : ";
			int n;
			cin >> n;
			M[n - 1].addmovies(m, g, s, r);
			cout << "movie added !!" << endl;
			cout << "press 1 to go to main screen : ";

			int input1;
			do
			{
				cin >> input1;
			} while (input1 > 1 || input1 < 1);

			if (input1 == 1)
			{
				mainScreen();
			}
			else
			{
				errorScreen();
			}
		}
	}
	else if (input == 2)
	{
		cout << "current prices : " << endl
			<< "Gold : " << A.priceGold << endl
			<< "selver : " << A.priceSiverl << endl
			<< "platinum : " << A.pricePlat << endl;
		int input2;
		do
		{
			cout << "press 1 to edit prices :  ";
			cin >> input2;
		} while (input2 > 1 || input2 < 1);
		if (input2 == 1)
		{
			int g, s, p;
			cout << "enter the new price for gold : ";
			cin >> g;
			cout << "enter the new price for silver : ";
			cin >> s;
			cout << "enter the new price for platinum : ";
			cin >> p;
			A.editPrice(g, s, p);
			cout << "prices was successfully edited !! " << endl;
			cout << "press 1 to back to main screen :  ";
			int in;
			cin >> in;
			if (in == 1)
			{
				mainScreen();
			}
		}
	}
	else if (input == 3)
	{

		mainScreen();
	}
	else
	{
		errorScreen();
	}
}
void movies() // to assign the default movies
{
	M[0].addmovies("the God Father ", "Drama", "Avilable", "+16");
	M[1].addmovies("interstellar", "SI-FI", "Avilable", "+10");
	M[2].addmovies("Fight Club", "Drama", "Avilable", "+12");
	M[3].addmovies("Oppenheimer", "Drama", "Coming soon", "+12");
}
void bookmovieScreen()
{
	cout << "                   ****************************************************                                  " << endl;
	cout << "                                                                                                                                       " << endl;
	cout << "                                  Welcome To Le Grand Rex!!                                                      " << endl;
	cout << "please press 1 to see movie list :  ";
	int input;
	cin >> input;
	if (input == 1)
	{

		cout << "                   ****************************************************                                  " << endl;
		cout << "                                                                                                                                       " << endl;
		cout << "                                  Welcome To Le Grand Rex!!                                                      " << endl;
		cout << "                                                                                                                                       " << endl;
		cout << "   "
			<< "#"
			<< "      "
			<< "NAME"
			<< "      "
			<< "GENRE"
			<< "      "
			<< "RATING"
			<< "      "
			<< "STATUS" << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << "   " << i + 1 << "." << M[i].movieName << "      " << M[i].genre << "      " << M[i].rating << "      " << M[i].status << endl;
		}

		cout << "                   ****************************************************                                   " << endl;
		cout << "                                                                                                                                       " << endl;
		cout << "           your choice -----)>  ";

		int selectedMovie;
		cin >> selectedMovie;
		se.myMovie = M[selectedMovie - 1].movieName;
		se.selectedMovie = selectedMovie;
		cout << "you selected :  " << M[selectedMovie - 1].movieName << "      " << M[selectedMovie - 1].genre << "      " << M[selectedMovie - 1].rating << "      " << M[selectedMovie - 1].status << endl;
		cout << "press 1 to select seats : ";
		int input1;
		cin >> input1;

		if (input1 == 1)
		{
			selectseat();
		}
		else
		{
			errorScreen();
		}
	}
	else
	{
		errorScreen();
	}
}
void selectseat()
{
	//cout << "how many tickets you wish to book(4 maximam ) : ";
	int input = 1;
	//cin >> input;
	vector<char> seats;
	vector<int> seatss;
	for (int i = 0; i < input; i++)
	{

		cout << "                        *****************************************************************" << endl
			<< endl;

		cout << "----------------Silver Tier Seats [A1-D20]-------------------" << endl;
		cout << endl;
		cout << "A: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;
		cout << "B: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;
		cout << "C: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;
		cout << "D: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl
			<< endl;

		cout << "----------------Gold Tier Seats  [E1-K16]---------------------" << endl;
		cout << "E:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "F:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "G:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "H:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;
		cout << "I:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "J:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "K:      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;

		cout << "----------------Platinium Tier Seats [L1-N20]------------------" << endl;
		cout << "L: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "M: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 " << endl;
		cout << "N: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;

		cout << "select your #" << i + 1 << " seat row(A-N) :";
		char seat;
		cin >> seat;
		cout << "select your #" << i + 1 << " seat num(1-20) :";
		int num;
		cin >> num;
		seats.push_back(seat);
		seatss.push_back(num);
	}

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 252; j++)
		{

			if (false // seats[i] == se.seatcheck[se.selectedMovie][i]
				)
			{
				cout << "unavilable seat !! ";
				cout << "press 1 to select seat or 2 for mainscreen : ";
				int input2;
				cin >> input2;
				if (input2 == 1)
				{

					selectseat();
				}
				else if (input2 == 2)
				{
					mainScreen();
				}
				else
				{
					errorScreen();
				}
			}
			else
			{
				for (int i = 0; i < input; i++)
				{
					// se.seatcheck[se.selectedMovie].push_back(seats[i]);
				}
			}
		}
	}
	cout << "you selected :  " << endl;
	for (int i = 0; i < input; i++)
	{
		cout << seats[i] << seatss[i] << endl;
	}

	int sum = 0;

	for (int i = 0; i < 1; i++)
	{
		char a = seats[i];
		if (a == 'a' || a == 'b' || a == 'c' || a == 'd')
		{
			sum += C.priceSiverl;
		}
		else if (a == 'e' || a == 'f' || a == 'g' || a == 'h' || a == 'i' || a == 'j' || a == 'k')
		{
			sum += C.priceGold;
		}
		else if (a == 'l' || a == 'm' || a == 'n' || a == 'o')
		{
			sum += C.pricePlat;
		}
	}
	cout << "your total is : " << sum << " EURO!!" << endl << endl;

	//============================
	//  movie name - seats - name - total money - time

	cout << "MOVIE :           " << se.myMovie << endl;
	cout << "SEAT :    ";
	for (int i = 0; i < input; i++)
	{
		cout << seats[i] << seatss[i] << "  ";
	}

	cout << endl << "NAME :           " << se.myName << endl
		<< "TOTAL :           " << sum << "-EURO !!" << endl
		<< "TIME :     9-PM" << endl
		<< "SCREEN :     2 " << endl
		<< "DATE :      31/12/2022" << endl << endl;

	cout << "would you like to print the receipt ?(Y/N) : ";
	char c;
	cin >> c;
	if (c == 'y') {

		string path;
		path = se.myName + ".txt";
		ofstream receipt;
		receipt.open(path);
		receipt << "MOVIE :           " << se.myMovie << endl
			<< "SEAT :    " << seats[0] << seatss[0] << "  "
			<< endl << "NAME :           " << se.myName << endl
			<< "TOTAL :           " << sum << "-EURO !!" << endl
			<< "TIME :     9-PM" << endl
			<< "SCREEN :     2 " << endl
			<< "DATE :      31/12/2022" << endl << endl;
		receipt.close();
		cout << "thank you for booking " << se.myMovie << " at Le Grand Rex !!" << endl << "we will be wating for you to visit again]!!" << endl;
		cout << "press any key to go to main screen !!";
		string ms;
		cin >> ms;
		if (true) {
			mainScreen();
		}
	}
	else {
		cout << "thank you for booking " << se.myMovie << " at Le Grand Rex !!" << endl << "we will be wating for you to visit again]!!" << endl;
		cout << "press any key to go to main screen !!";
		string ms;
		cin >> ms;
		if (true) {
			mainScreen();
		}

	}
}
void aboutScreen() {




	cout << "                   ****************************************************                                        " << endl;
	cout << "                                                                                                               " << endl;
	cout << "              ----------------------------- Le Grand Rex -----------------------------						    " << endl;
	cout << "                                                                                                               " << endl;
	cout << "                                  This Program Was Created With Love                                           " << endl;
	cout << "                                                 BY :                                                          " << endl;
	cout << "                                                                                                               " << endl;
	cout << "                             Abdulrahman mohamed - Abdulrahamn diab                                            " << endl;
	cout << "                                    Ahmed lashen - Anas ibrahim                                                " << endl;
	cout << "                                    Hadeer gamal - Menna tallah sayed                                          " << endl;
	cout << "                                                                                                               " << endl;
	cout << "                                            About Le Grand Rex  :                                              " << endl;
	cout << "                                                                                                               " << endl;
	cout << "                             Le Grand Rex is a Parisian cinema and concert venue.                              " << endl;
	cout << "                                                                                                               " << endl;
	cout << "                             Exceptional Art Deco Auditorium-Style Movie Theater.                              " << endl;
	cout << "                                                                                                               " << endl;
	cout << "                             Le Grand Rex, The Biggest Movie Theater in Paris.                                 " << endl;
	cout << "                                                                                                               " << endl;
	cout << "         This iconic art deco cinema is much more than just a movie theater. Sure, you can see the latest movies here"                                   << endl <<
		"         , But the main attraction is actually its Grand Auditorium, a 2800-seat salle that hosts world premiers, showings of the biggest blockbusters,"     << endl <<
		"         Sing-along movie nights, live orchestra ciné concerts, and much more."                                                                              << endl <<
		"         The luxurious interior transports you back to a time when going to the movies was a truly special occasion. Walking in, you might think you’re"     << endl <<
		"         At the theater or even the opera. There are balconies, loges, and of course those magnificently rich plush red velvet seats."                       << endl;
	cout << "                                                                                                                                        " << endl;
	cout << "                                                                                                                                        " << endl;
	cout << "                                                                                                                                        " << endl;
	cout << "                   ****************************************************                              " << endl;
	cout << "  press any key to back to main screen :                                                                        " << endl;
	
	mainScreen();
	//----------------------------------------------------------------------------------

}
// mainFunction

int main()
{
	start();
}
