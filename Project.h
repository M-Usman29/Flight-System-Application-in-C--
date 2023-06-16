/*
Name: Muhammad Usman
Roll no: 20i-0416
Section: E
BS CS
Project .h file
*/

#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <bitset>
using namespace std;

//LOGIN CLASS
class login{
	protected:
	//Admin..............................................
	int team_m_id;
	string team_m_nm;
	//user
	long int user_cnic;
	string user_password;
	string user_name;
	
	public:
	//FOR FILLING ADMIN.txt WITH DATA	
	void fill_adminfile(int,string);
	
	
	//for checking validity of admin details entered
		bool admin_login(int,string);

//user.........................................................
//function for stroing details of new user
void set_NewuserDetails(string,char[]);

//function to check existing user account if it exists or not
bool checkuser_valid(string,string);

//getter for username
string get_username();

};




//Flight Schedule class
class FlightSchedule{
string flight_no;
string flight_route;
int route_dist;
bool trvl_sts_local;
bool trvl_sts_intl;
int trvl_hrs;
int avlb_seats;
public:
//setters
    void set_flight_no(string);
    
	void set_flight_route(string);
	
	void set_route_dist(int);
	
	void set_trv_sts_local(bool);
	
	void set_trv_sts_intl(bool);
	
	void set_trvl_hrs(int);
	
	void set_avlb_seats(int);
	
//getters
	 string get_flight_no();
	  
	string get_flight_route();
	
	int get_route_dist();
	
	bool get_trv_sts_local();
	
	bool get_trv_sts_intl();
	
	int get_trvl_hrs();
	
	int get_avlb_seats();
	
	
	//function to display flight schedules to all users
	void Display_schedule();

//Function to display schedule details to logged in  user
 void DisplayFlight_det(FlightSchedule[]);

};




//PASSENGER CLASS
class passengers:public login {

string pass_holder;
string pass_type;
bool pass_valid;
bool pass_visa_stamp;
public:
	//default constructor
	passengers();

//setters
void set_pass_holder(string);

void set_pass_type(string);

void set_pass_valid(bool);

void set_pass_visa_stamp(bool);

//getters
string get_pass_holder();

string get_pass_type();

bool get_pass_valid();

bool get_pass_visa_stamp();


//validity of passport
	void check_validity_passport(passengers[],string);


// show most travelled country
   void most_visited(passengers[],string);

};




//Booking class
class booking:public login{

//SOME TASKS OF BOOKING CLASS IS DONE IN FLIGHTSCHEDULE>> 	
/*FUNCTIONS LIKE SELECTING FLIGHT AND SEAT RESERVATION IN AVAILABLE SCHEDULE OF FLIGHTS IS  DONE
 IN FLIGHT SCHEDULE CLASS IN DisplayFlight_det(); FUNCTION  */

 
//COST FUNCTION

//ADMIN BLOCK COUNTRY DUE TO COVID
public:
void admin_block();


	
};



class payment{
double ticket_price;
public:
	void display_costof_flights();
	
	void set_ticketprice(double);
	
	double get_ticketprice();
	
};


