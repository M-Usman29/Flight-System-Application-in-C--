/*
Name: Muhammad Usman
Roll no: 20i-0416
Section: E
BS CS
Project .CPP file
*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <bitset>

#include "Project.h"
using namespace std;




//									LOGIN CLASS Functions

	//FOR FILLING ADMIN.txt WITH DATA	
	void login::fill_adminfile(int id,string nm ){
		ofstream outputfile("Admin.txt",ios::app);
		team_m_id=id;
		outputfile<<team_m_id<<endl;
		team_m_nm=nm;
		outputfile<<team_m_nm<<endl;
		outputfile.close();
	}
	
	
	//for checking validity of admin details entered
		bool login::admin_login(int id,string nm ){
			bool flag=false;
		ifstream inputfile("Admin.txt");
		inputfile>>team_m_id;
		while(!inputfile.eof()){
		if(team_m_id==id){
			flag=true;
		}
		inputfile>>team_m_nm;
		if(team_m_nm==nm){
			flag=true;}
		}
		return flag;
	   inputfile.close();
}



//user.........................................................
//function for stroing details of new user
void login::set_NewuserDetails(string usr_nm,char pass[9]){
	ofstream outputfile("Passengers.txt",ios::app);
		for(int i=0;i<8;i++){
		user_password[i]=pass[i];
		outputfile<<user_password[i];
		}
		outputfile<<endl;
		user_name=usr_nm;
		outputfile<<user_name<<endl;
		outputfile.close();
	
}


//function to check existing user account if it exists or not
bool login::checkuser_valid(string n,string pswrd){
		bool flag_usr=false;
		ifstream inputfile("Passengers.txt");
		inputfile>>user_password;
		while(!inputfile.eof()){
		if(user_password==pswrd){
			flag_usr=true;
		}
		inputfile>>user_name;
		if(user_name==n){
			flag_usr=true;}
		}
		return flag_usr;
	   inputfile.close();
}  

//getter for username
string login::get_username(){
	return user_name; 
}





//										Flight Schedule class functions


//setters
    void FlightSchedule::set_flight_no(string fn){
    	flight_no=fn;
	}
	void FlightSchedule::set_flight_route(string fr){
		flight_route=fr;
	}
	void FlightSchedule::set_route_dist(int rd){
		route_dist=rd;
	}
	void FlightSchedule::set_trv_sts_local(bool tl){
		trvl_sts_local=tl;
	}
	void FlightSchedule::set_trv_sts_intl(bool ti){
		trvl_sts_intl=ti;
	}
	void FlightSchedule::set_trvl_hrs(int hr){
		trvl_hrs=hr;
	}
	void FlightSchedule::set_avlb_seats(int s){
		avlb_seats=s;
	}
	
//getters
	  string FlightSchedule::get_flight_no(){
    	return flight_no;
	}
	string FlightSchedule::get_flight_route(){
		return flight_route;
	}
	int FlightSchedule::get_route_dist(){
		return route_dist;
	}
	bool FlightSchedule::get_trv_sts_local(){
		return trvl_sts_local;
	}
	bool FlightSchedule::get_trv_sts_intl(){
		return trvl_sts_intl;
	}
	int FlightSchedule::get_trvl_hrs(){
		return trvl_hrs;
	}
	int FlightSchedule::get_avlb_seats(){
		return avlb_seats;
	}


	//function to display flight schedules to all users
	void  FlightSchedule::Display_schedule(){
		ifstream inputfile("Schedule.txt");
		string str;
		cout<<endl;
		while(!inputfile.eof()){
		cout<<endl;
		getline(inputfile,str);
		cout<<str<<endl;
				
}
}




//Function to display schedule details to logged in  user
 void FlightSchedule::DisplayFlight_det(FlightSchedule f_arr_intl[4]){
 	cout<<endl<<"*******International Flight schedule********"<<endl;
 	cout<<"Flight no:"<<"\t"<<"Route: "<<"\t\t\t\t\t\t\t"<<"Available seats:"<<"\t"<<endl;
  	cout<<f_arr_intl[0].get_flight_no()<<"\t\t"<<f_arr_intl[0].get_flight_route()<<"\t\t\t\t\t\t"<<f_arr_intl[0].get_avlb_seats();
  	cout<<endl<<f_arr_intl[1].get_flight_no()<<"\t\t"<<f_arr_intl[1].get_flight_route()<<"\t\t\t\t"<<f_arr_intl[1].get_avlb_seats();
  	cout<<endl<<f_arr_intl[2].get_flight_no()<<"\t\t"<<f_arr_intl[2].get_flight_route()<<"\t\t\t\t\t"<<f_arr_intl[2].get_avlb_seats();
  	cout<<endl<<f_arr_intl[3].get_flight_no()<<"\t\t"<<f_arr_intl[3].get_flight_route()<<"\t\t\t\t\t"<<f_arr_intl[3].get_avlb_seats();
  char ch;
  	cout<<endl<<"-> To view shortest FLIGHT between these Flights click 'Y' else click 'N' "<<endl;
  	cin>>ch;
  	if(ch=='Y'||ch=='y'){
  		int min,index; 
  	//TO get mimimum travelling hours out of all available flights
	  	min=f_arr_intl[0].get_trvl_hrs();
	 for(int i=0;i<4;i++){
	 if(f_arr_intl[i].get_trvl_hrs()<min){
	 	min=f_arr_intl[i].get_trvl_hrs();
	 	index=i;
	 }
	
	 }
	  cout<<"Shortest Flight:"<<endl;
	cout<<"Flight no:"<<"\t"<<"Route: "<<"\t\t\t\t\t\t\t"<<"Available seats:"<<"\t"<<endl;
  	cout<<f_arr_intl[index].get_flight_no()<<"\t\t"<<f_arr_intl[index].get_flight_route()<<"\t\t\t\t\t\t"<<f_arr_intl[index].get_avlb_seats();
	  }
	  else if(ch=='N'||ch=='n'){
	  int pos;
	  string temp_fno;
	  cout<<"-> if you want to choose flight yourself, Enter the flight number:"<<endl;
  	cin>>temp_fno;
  	for(int i=0;i<4;i++){
	  if(f_arr_intl[i].get_flight_no()==temp_fno){
	  	pos=i;
	  }
	  }
	  cout<<"****Flight Seat resrved for you until you are in process of booking and payment...****"<<endl;
	  cout<<"Flight no:"<<"\t"<<"Route: "<<"\t\t\t\t\t\t\t"<<"Available seats:"<<"\t"<<endl;
  	cout<<f_arr_intl[pos].get_flight_no()<<"\t\t"<<f_arr_intl[pos].get_flight_route()<<"\t\t\t\t\t\t"<<f_arr_intl[pos].get_avlb_seats()-1;
	  
	  
  }
 } 
 
 
 
 
 //											PASSENGER CLASS Functions
 
 
	//default constructor
	passengers::passengers(){
	pass_holder=" ";
 pass_type="local";
 pass_valid=false;
pass_visa_stamp=false;
	}

//setters
void passengers::set_pass_holder(string ph){
	pass_holder=ph;
}
void passengers::set_pass_type(string pt){
	pass_type=pt;
}
void passengers::set_pass_valid(bool pv){
	pass_valid=pv;
}
void passengers::set_pass_visa_stamp(bool pv_s){
	pass_visa_stamp=pv_s;
}


//getters
string passengers::get_pass_holder(){
	return pass_holder;
}
string passengers::get_pass_type(){
	return pass_type;
}
bool passengers::get_pass_valid(){
	return pass_valid;
}
bool passengers::get_pass_visa_stamp(){
	return pass_visa_stamp;
}



//validity of passport
	void passengers::check_validity_passport(passengers p_det[3],string u_name){
	string name_passenger;
	name_passenger=u_name;
	int loc;
	for(int i=0;i<3;i++){
		if(p_det[i].get_pass_holder()==name_passenger){
			loc=i;
		}
	}
	if(p_det[loc].get_pass_valid()==true){
		cout<<"**Passport is valid for travelling. Proceeding further>>"<<endl;
	}
	else{
		cout<<"**Passport is not valid for travelling sorry your booking is being Cancelled"<<endl;
	}
}


// show most travelled country
   void passengers::most_visited(passengers p_det[3],string u_nme){
	int dest;
	string arr[3];
	arr[0]="USA";
	arr[1]="CHINA";
	arr[2]="switzerland";
	for(int i=0;i<3;i++){
		if(p_det[i].get_pass_holder()==u_nme){
			dest=i;
		}
	}
	cout<<endl<<"Most visited country by you is:"<<arr[dest]<<endl;
}




//												Booking class Functions


//SOME TASKS OF BOOKING CLASS IS DONE IN FLIGHTSCHEDULE>> 	
/*FUNCTIONS LIKE SELECTING FLIGHT AND SEAT RESERVATION IN AVAILABLE SCHEDULE OF FLIGHTS IS  DONE
 IN FLIGHT SCHEDULE CLASS IN DisplayFlight_det(); FUNCTION  */

 
//COST FUNCTION

//ADMIN BLOCK COUNTRY DUE TO COVID

void booking::admin_block(){
	cout<<endl<<"Flights to Canada have been blocked due to Covid restrictions.."<<endl;
}




//									Payment class Functions

	void payment::display_costof_flights(){
		cout<<">>One hour travel costs Rs.10,000 for a local & Rs.20,000 for international flights"<<endl; 
 cout<<">>Government charges tax: 5% on local flight and 10% on intl flight"<<endl;
	}
	
	
	void payment::set_ticketprice(double s){
		ticket_price=s;
	}
	double payment::get_ticketprice(){
		return ticket_price;
	}	
	
	
	
	
	
	
//												Main menu



int main(){
//For displaying schedule board to every visiter	
FlightSchedule f1;
f1.Display_schedule();
//----------------------------------------------	
	
//**************Login class work>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 	
	int adminORUser;
	string unvrsl_name;
cout<<"**********Welcome to NPAFS**********"<<endl<<endl;
cout<<"(1) LOGIN as ADMIN"<<endl<<"(2) Login as User"<<endl;
cin>>adminORUser;
if(adminORUser==1){
//admin...............................	
//filling data in admin.txt
login l1;
l1.fill_adminfile(1,"usman");
l1.fill_adminfile(2,"aftab");
l1.fill_adminfile(3,"ali");
//admin member logs in and his valididty is checked
login l2;
int id_admn;
string nm_admn;
cout<<"ENTER YOUR REGISTERERD STAFF NAME"<<endl;
cin>>nm_admn;
cout<<endl<<"ENTER YOUR REGISTERERD STAFF ID"<<endl;
cin>>id_admn;

bool sts;
sts=l2.admin_login(id_admn,nm_admn);
if(sts==true){
	cout<<"welcome To Admin Portal"<<endl;
}
else if(sts==false){

cout<<"This Staff Username or ID is incorrect"<<endl;
}

}

else if(adminORUser==2){

//user...................................
//storing existing cnic record for testing of program
long long *ptr;
ptr=new long long [4];//dynamic array used as per instructions of project
ptr[0]=1111111111111;
ptr[1]=2222222222222;
ptr[2]=3333333333333;
ptr[3]=4444444444444;
//...........................
//user account 
login l3;
int choice_login;
long long cnic_no;//cnic no entered by the user
string name;//user name
char *ptr1;
ptr1=new char[9];// Dynamic password array

char *ptr2;
ptr2=new char[9];//dynamic password array 2 for matching both passwords entered by new user
string name_existUSR;
string pass_existUSR;
bool user_loginV;
login:
cnic_jump:
cnic_jump2:	
cout<<endl<<"(1) LOGIN with an existing account"<<endl<<"(2) Register a new account"<<endl;
cin>>choice_login;
if(choice_login==1){
cout<<"Enter your username:"<<endl;
	cin>>name_existUSR;
	cout<<"Enter your 8 character Password:"<<endl;
	cin>>pass_existUSR;
	user_loginV=l3.checkuser_valid(name_existUSR,pass_existUSR);
	if(user_loginV==1){
		unvrsl_name=name_existUSR;//for use in later
		cout<<"WELCOME back "<<name_existUSR<<endl;
	}
	else{
		cout<<"User account with this name or password doesnot exists"<<endl;
		goto login;
	}
}

else if(choice_login==2){
cout<<endl<<"ENTER CNIC Number Wihtout any space and (-)"<<endl;
cin>>cnic_no;
long long cnic_temp=cnic_no;//copy of cnic to use when finding its legth
int check_13=0;
bool cnic_flag=true;
//For calculating length of cnic
while(cnic_temp!=0)
{
check_13++;
cnic_temp=cnic_temp/10;
}
if(check_13!=13){
cout<<"INVALID CNIC"<<endl;
cnic_flag=false;
goto cnic_jump;
}
if(cnic_flag!=false){
for(int i=0;i<4;i++){
	if(ptr[i]==cnic_no){
		cout<<"Sorry!!! An Account is already registered with this CNIC "<<endl;
	cnic_flag=false;
	goto cnic_jump2;
	}
}
}
if(cnic_flag==true){

cout<<"ENTER YOUR USERNAME:"<<endl;
cin>>name;
jump:
cout<<endl<<"ENTER Password for your new account:"<<endl;
cout<<"Requirements of password:"<<endl<<"(8 characters long"<<endl<<"Use of minimum one special character, uppercase, lowercase"<<endl<<"numeric digit is must..)"<<endl;
cout<<endl;
//******passwrod input******
label:
for(int i=0;i<8;i++){
	ptr1[i]=getch();
	cout<<"*";
}
//enter password again:
cout<<endl<<"Enter Password again:"<<endl;
for(int i=0;i<8;i++){
	ptr2[i]=getch();
	cout<<"*";
}
bool flag_re_password=true;
//check if user has typed the same password second time also or he has done any mistake
for(int i=0;i<8;i++){
if(ptr1[i]!=ptr2[i]){
	flag_re_password=false;
	cout<<endl<<"Passwords don't match"<<endl;
goto jump;
}
}


bool uppercase_flag=false;
bool lowercase_flag=false;
bool digit_flag=false;
bool specialCH_flag=false;
//checks on password for existence of digits character
for(int i=0;i<8;i++){
	if(ptr1[i]>=48 && ptr1[i]<=57){
	digit_flag=true;
	break;
	}
}
//checks on password for existence of uppercase character
for(int i=0;i<8;i++){
	if(ptr1[i]>=65 && ptr1[i]<=90){
	uppercase_flag=true;
	break;
	}
}

////checks on password for existence of lowercase character
for(int i=0;i<8;i++){
	if(ptr1[i]>=97 && ptr1[i]<=122){
	lowercase_flag=true;
	break;
	}
}

//checks for special character
//if the character doesnot belong to any of the ascii values for lower upper case and digits then it belongs to special character set
for(int i=0;i<8;i++){
if((ptr1[i]>=97 && ptr1[i]<=122)||(ptr1[i]>=48 && ptr1[i]<=57)||(ptr1[i]>=65 && ptr1[i]<=90)){
	specialCH_flag=false;
}	
else{
specialCH_flag=true;
break;
}
}


cout<<endl<<"Note: 0 means does not exist & 1 means exists"<<endl;
cout<<endl<<"upercase: "<< uppercase_flag<<endl;
cout<<"digits :"<<digit_flag <<endl;
cout<<"lower case: "<<lowercase_flag<<endl;
cout<<"special caracters: "<<specialCH_flag <<endl;
if(uppercase_flag==true&&lowercase_flag==true&&digit_flag==true&&specialCH_flag==true){
unvrsl_name=name;//for later use
l3.set_NewuserDetails(name,ptr1);
}
else{
cout<<"Password Doesnot match the requirements please Enter a new password again: "<<endl;
goto label;	
}



}
}
}
//***********************************************************************

//***************Flight Schedule class work>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//FlightSchedule f1;
//f1.Display_schedule();


//predefined routes
//international Flights TO USA for DEMO
FlightSchedule f_arr_intl[4];
f_arr_intl[0].set_flight_no("PK044");
f_arr_intl[0].set_flight_route("Pakistan---NewYork");
f_arr_intl[0].set_route_dist(12000);
f_arr_intl[0].set_trvl_hrs(13.5);
f_arr_intl[0].set_trv_sts_local(false);
f_arr_intl[0].set_trv_sts_intl(true);
f_arr_intl[0].set_avlb_seats(60);

f_arr_intl[1].set_flight_no("PK051");
f_arr_intl[1].set_flight_route("Pakistan---Washington(via turkey)");
f_arr_intl[1].set_route_dist(14000);
f_arr_intl[1].set_trvl_hrs(15.5);
f_arr_intl[1].set_trv_sts_local(false);
f_arr_intl[1].set_trv_sts_intl(true);
f_arr_intl[1].set_avlb_seats(60);

f_arr_intl[2].set_flight_no("PK080");
f_arr_intl[2].set_flight_route("Pakistan---MaryLand(Via Dubai)");
f_arr_intl[2].set_route_dist(16000);
f_arr_intl[2].set_trvl_hrs(20.5);
f_arr_intl[2].set_trv_sts_local(false);
f_arr_intl[2].set_trv_sts_intl(true);
f_arr_intl[2].set_avlb_seats(60);


f_arr_intl[3].set_flight_no("PK061");
f_arr_intl[3].set_flight_route("Pakistan---Boston(via turkey)");
f_arr_intl[3].set_route_dist(17000);
f_arr_intl[3].set_trvl_hrs(21.5);
f_arr_intl[3].set_trv_sts_local(false);
f_arr_intl[3].set_trv_sts_intl(true);
f_arr_intl[3].set_avlb_seats(60);
int c;

cout<<"Do you want To see (1)international or (2)local flights"<<endl;
cin>>c;
if(c==1){
f1.DisplayFlight_det(f_arr_intl);
}
//*****************************************************************************************************************
cout<<endl<<"Now checking your Passport details and veryfying requirements with your details in record to proceed towards booking procedure>> "<<endl;
//Passenger Class work>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Passport details of registered passengers
passengers p_det[3];
passengers p1;
p_det[0].set_pass_holder("usman");
p_det[0].set_pass_type("international");
p_det[0].set_pass_valid(true);
p_det[0].set_pass_visa_stamp(true);

p_det[1].set_pass_holder("aftab");
p_det[1].set_pass_type("local");
p_det[1].set_pass_valid(true);
p_det[1].set_pass_visa_stamp(false);

p_det[2].set_pass_holder("ali");
p_det[2].set_pass_type("international");
p_det[2].set_pass_valid(true);
p_det[2].set_pass_visa_stamp(true);
//CHECKING PASSPORT VALIDITY
p1.check_validity_passport(p_det,unvrsl_name);
char chose;
cout<<endl<<"Do you want to see the most visited country click 'y' "<<endl;
cin>>chose;
if(chose=='Y'||chose=='y'){
	p1.most_visited(p_det,unvrsl_name);
	cout<<endl<<"You might recieve a discount of 10% based on your travel history"<<endl;
}

//*****Booking class work>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
cout<<endl<<endl<<"Admin login beacause due to covid a country has to shutdown its flight operations due to covid"<<endl<<endl;
//admin member logs in and his valididty is checked
login l4;
int id_a;
string nm_a;
cout<<"ENTER YOUR REGISTERERD STAFF NAME"<<endl;
cin>>nm_a;
cout<<endl<<"ENTER YOUR REGISTERERD STAFF ID"<<endl;
cin>>id_a;

bool sts_2;
sts_2=l4.admin_login(id_a,nm_a);
booking b1;
if(sts_2==true){
	cout<<"welcome To Admin Portal"<<endl;
FlightSchedule f4;
f4.Display_schedule();
b1.admin_block();
}
cout<<endl<<"Finally moving towards payment as process needed to be stopped for checking that your flight doesnot fall into the coivd restriction area"<<endl<<endl;
//*****************Payment class work>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
payment py;
py.display_costof_flights();
cout<<endl;
char f_y;
cout<<"Do you want to confirm your flight"<<endl;
cin>>f_y;
if(f_y=='y'||f_y=='Y'){
py.set_ticketprice(20000*10+(200000*10/100));
}
cout<<endl<<"Your Flight cost is: "<<py.get_ticketprice();
cout<<endl<<"*******************************************THANK YOU FOR USING NPAFS**********************************************************************"<<endl;

//DEALLOCATING MEMORY
//delete [] ptr;
//delete [] ptr1;
//delete [] ptr2;


	return 0;
}
