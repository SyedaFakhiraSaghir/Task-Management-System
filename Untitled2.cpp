#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "linkedlist.h"
#include "Feedback.h"
#define size 5

using namespace std;

class User{
		public:
		string name;
		string dateOfBirth;
		string email;
		string password;
		int code;
		linkedlist *l;
	
		
		//-------------------------------------------------------------C O N S T R U C T O R S-------------------------------------------------------------
		User()
		{	
			//1. Academic tasks\n2. Shopping taks\n3. Personal tasks\n4. Events\n5. Wish list\n6. Archived Tasks
			l=new linkedlist[6]; 
			name="-----";
			dateOfBirth="00";
			email="GDFGETHGDFC";
			password="DHGFHSDGJDGHD";
			code=0;
		}
		User(string n,string d,string e,string p)
		{
			//1. Academic tasks\n2. Shopping taks\n3. Personal tasks\n4. Events\n5. Wish list\n6. Archived Tasks
			l=new linkedlist[6];
			name=n;
			dateOfBirth=d;
			email=e;
			password=p;
			code=0;
		}
		//-------------------------------------------------------------U S E R   C L A S S   S E T T E R S-------------------------------------------------------------
		void setName(string n){
			name=n;
		}
		string getName(){
			return name;
		}
		void setDate(string d){
			dateOfBirth=d;
		}
		string getDate(){
			return dateOfBirth;
		}
		void setEmail(string e){
			email=e;
		}
		string getEmail(){
			return email;
		}
		void setPassword(string p){
			password=p;
		}
		string getPassword(){
			return password;
		}
		void setCode(int c){
			code=c;
		}
		int getCode(){
			return code;
		}
		
		//-------------------------------------------------------------ARCHIVE TASKS-------------------------------------------------------------
		
		void displayarchive()
		{
			task *t= l[5].head;
			system("Color 09");
	        cout<<"\n************TASK DETAILS************\n";
	        while(t!=NULL){
	        	cout<<"\n-----------------------------------------"<<endl;
	           cout<<"\nTask name: "<<t->getname();
	           cout<<"\tDeadline: "<<t->getdeadline();
	           cout<<"\nCategory: "<<t->getcategory();
	           cout<<"\tStatus: "<<t->getstatus();
	           cout << "\nDetails: " << t->getdetails();
	           cout<<"\nMissed tasks: "<<t->getmissedtask();
	           cout<<"\tTime: "<<t->gettimet();
	           cout<<"\n-----------------------------------------\n"<<endl;
	           t=t->next;
			}
		}
		void archivetasks(int use)
		{
		    string n;
		    task* tt = l[use].archive(); 
		    if(tt!=NULL)
		    {
				l[5].inserttask(tt);
			    displayarchive();
			    cout << "\nTASK ARCHIVED\n";
			    return;
			}
			cout << "\nTASK NOT FOUND\n";
			return;
		}
		
		//-------------------------------------------------------------INSERTION-------------------------------------------------------------
		
		void Input(){
			int digit=0,specialCharacter=0,character=0,Code;
		  	cout<<"Enter name:";
			fflush(stdin);
		  	getline(cin,name);
		  	cout<<"\nEnter date of birth:";
			fflush(stdin);
		  	getline(cin,dateOfBirth);
		  	scan:
		  	cout<<"Enter email:";
			fflush(stdin);
		  	getline(cin,email);
		  	if(!CheckObject("users.txt",email))
			{
				cout<<"\nEmail already exists\n";
			 	goto scan; 	
			}
			char ch;
		  	label:
		 	cout<<"Enter password:";
		 	while (true) 
			{
			  ch = _getwch();
	
				if (ch == 13) { // Enter key
					break;
				}
				else {
					cout << '*';
					password.push_back(ch);
				}
			}
			for (int i = 0; i < password.length(); i++) {
				if (password[i] >= 48 && password[i] <= 57) {
					digit++;
					//cout<<"Digit:"<<digit<<endl;
				}
				else if ((password[i] >= 65 && password[i] <= 90) || (password[i] >= 97 && password[i] <= 122)) {
					character++;
					//	cout<<"charac:"<<character<<endl;
				}
				else if ((password[i] >= 33 && password[i] <= 42) || password[i] == 64) {
					specialCharacter++;
					//cout<<"Special: "<<specialCharacter;
				}
			}
			if(specialCharacter>0 && character>0 && digit>0){
				cout<<"\nStrong password.";
			}
			else{
				cout<<"\nEnter character, digits, and special character as the password is not strong enough.\n";
				goto label;
			}
			srand(time(0));
			code=1000+rand()%8999;
			cout<<"\nYour code is: "<<code<<endl;
			label2:
			cout<<"\nEnter code: ";
			cin>>Code;
			if(code==Code)
			{
				cout<<"\n**********Successfully registered!**********\n";
				fstream file ("users.txt", ios :: app);
				file << this->name << endl;
				file << this->dateOfBirth << endl;
				file << this->email << endl;
				file << this->password << endl;
				file << this->code << endl;
				file.close();
			}
			else{
				cout<<"\nError.Enter the code again:";
				goto label2;
			}
		}
		
		//-------------------------------------------------------------USER CLASS OVERLOADING-------------------------------------------------------------
		
		User& operator=(const User& us) 
		{
	        for (int i = 0; i < 7; ++i) {
	            l[i].head = us.l[i].head;
	        }
	        return *this;
    	}
    
    //-------------------------------------------------------------CHECKING IF EMAIL EXISTS-------------------------------------------------------------
    
		bool CheckObject(string fname,string e)
		{
			bool save = true;
			fstream file;
			file.open(fname, ios::in);
			if(file.is_open())
			{
				string str;
				int i = 1;
				while(getline(file,str))
				{	
					
					if(i == 6)
					{
						i = 1;
					}
					if (i == 3 && str == e)
					{	
						save = false;
						cout << endl << endl;
						file.close();
						return false;
					}
					i++;
				}
			}
			return true;
		}
		
		//------------------------------------------------------------- CHECKING IF PASSWORD CORRECT -------------------------------------------------------------
		
		bool CheckPassword(string fname,string e)
		{
			bool save = true;
			fstream file;
			file.open(fname, ios::in);
			if(!file.is_open())
			{
				cout << endl << "Error in file opening"  << endl;
			}
			if(file.is_open())
			{
				string str;
				int i = 1;
				while(getline(file,str))
				{	
					
					if(i == 6)
					{
						i = 1;
					}
					if (i == 4 && str == e)
					{	
						save = false;
						cout << endl << endl << "Password found"  << endl;
						file.close();
						return false;
					}
					i++;
				}
			}
			return true;
		}
		
		bool LoadObject(string fname,User *user)
		{
			fstream file (fname,ios :: in);
			if(file.is_open())
			{
				string str;
				int i = 1;
				while(getline(file,str))
				{	
					if(i == 6)
					{
						i = 1;
					}
					if (i == 3 && str == user->getEmail())
					{	
						this->name = user->getName();
						this->dateOfBirth = user->getDate();
						this->email = str;
						this->password = user->getPassword();
						this->code = user->getCode();
						file.close();
						return true;
					}
					i++;
				}
				file.close();
			}
			cout << endl  << endl << "Object Does Not Exists" << endl;
			return false;
		}
		
	//Displaying users account
	void userDisplay()
	{
		cout<<"\n\n**********Displaying user's details**********";
		cout<<"\nName: "<<name;
		cout<<"\nDate of birth: "<<dateOfBirth;
		cout<<"\nEmail: "<<email;
		cout<<"\nPassword: "<<password;
	}

//------------------------------------------------------------- DISPLAY ALL LISTS -------------------------------------------------------------

void displayffff(User& user)
{
	for (int i = 0; i < 6; i++)
        {
            task *t = user.l[i].head;
            while (user.l[i].head != NULL)
            {
                cout << user.l[i].head->getname() << "\n";
                cout << user.l[i].head->getcategory() << "\n";
                cout << user.l[i].head->getdeadline() << "\n";
                cout << user.l[i].head->getdetails() << "\n";
                cout<< user.l[i].head->getmissedtask() << "\n";
                cout<< user.l[i].head->getstatus() << "\n";
                cout << user.l[i].head->gettimet() << "\n";
                cout << user.l[i].head->getkey() << "\n";

                user.l[i].head = user.l[i].head->next;
            }
            user.l[i].head = t; 
        }
}
};

int inputfunction()
{
    int type;
    again:
    system("Color 07"); 
	cout<<"\nDo you want to:\n1.Insert a task\n2.Update a task\n3.Delete a task\n4.Archive a task\n5.Search for a task\n6.Display tasks\n7.Sort a task\n8.exit\n";
	cin>>type;
	if(type>=1 && type<=8)
    {
    	return type;
	}
    else
    {
        cout<<"Error! Enter a valid choice\n";
        goto again;
    }
}

int chooselist()
{
	int it;
    label:
    system("Color 08"); 
    cout<<"\nWhich list do you want to open:\n1. Academic tasks\n2. Shopping taks\n3. Personal tasks\n4. Events\n5. Wish list\n6. Archived Tasks\n7. Exit\n";
    cin>>it;
	
    if(it>=1 && it<=7)
    {
    	return it-1;
	}
    else
    {
        cout<<"Enter a valid choice";
        goto label;
    }
}

int main() 
{
    system("Color 0A"); 
    
	    User u;
	cout<<"\n\n---------------------------------------------------------------------------------------"<<endl;
	cout<<"=--------------------------------- T A S K     P R O ---------------------------------="<<endl;
	cout<<"---------------------------------------------------------------------------------------\n\n"<<endl;
    int choice;
    system("Color 0B"); 
    option: //label if option other than 1, 2, 3 choosen
    cout<<"Choose an option:\n1. Are you Already registered?\n2.Do you want to register?\n3.exit\n";
    cin>>choice;
    if(choice==1)
    {
    	enteragain:
    	system("Color 0B"); 
    	string e,p;
    	cout<<"\nEnter email: ";
    	fflush(stdin);
    	getline(cin, e);
		cout<<"\nEnter password: ";
		char ch;
	 	while (true) 
		{
		  ch = _getwch();

			if (ch == 13) { // Enter key
				break;
			}
			else {
				cout << '*';
				p.push_back(ch);
			}
		}
    	if(!u.CheckObject("users.txt",e))
		{
			if(!u.CheckPassword("users.txt",p))
			{
			 	cout<<"\n----------------------- Login Successful ----------------------- ";
			 	
			}
			else
			{
				system("Color 0C"); 
				cout<<"\nERROR: wrong Password\nTry again\n\n";
				goto enteragain;
			}
		}
		else 
		{
			system("Color 0C"); 
			cout<<"\nERROR: wrong user name or Password\nTry again\n\n";
			goto enteragain;
		}
 		//u.readFromFile();
		u.displayffff(u);
	}
	else if(choice==2)
	{
		system("Color 0B"); 
	   	u.Input();
	}
	else if(choice==3)
	{
		exit(1);
	}
	else
	{
		goto option;
	}
	int repeats;
	//program keeps running until user chooses to exit
	while(1)
	{
		mainn:
    	system("Color 0D"); 
    	cout<<"\n\n---------------------------------------------------------------------------------------"<<endl;
	    cout<<"=--------------------------------- T A S K     P R O ---------------------------------="<<endl;
	    cout<<"---------------------------------------------------------------------------------------\n\n"<<endl;
	    int userchoice=chooselist();
	    if(userchoice==6)
	    {
	    	goto exittt;
		}
	    chooseotherfunctionalites:
		int us=inputfunction();
	    if(us== 1)//insert
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** I N S E R T I N G   A   T A S K *****************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].insert(userchoice);
		}
		else if(us==2)//update
	    {
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"***************** U P D A T I N G   A   T A S K ******************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].update();
		}
		else if(us==3)//delete
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"************** D E L E T I N G   A   T A S K *********************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].deletet();	
		}
		else if(us==4)//archive
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** A R C H I V I N G   A   T A S K *****************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.archivetasks(userchoice);
		}
		else if(us==5)//search
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	        cout<<"**************** S E A R C H I N G   A   T A S K *****************"<<endl;    	
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].search();
		}
		else if(us==6)//display
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** D I S P L A Y I N G   A   T A S K ***************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].display();
		}
		else if(us==7)//sort
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	    cout<<"************* S O R T I N G   T A S K S **************************"<<endl;
	    	    cout<<"******************************************************************\n\n"<<endl;
	    	co1:
	       	int num;
	        cout<<"\nYou have the option to sort with respect to:\n1.Details\n2.Deadline\n3.Status\n";
	        	cin>>num;
	        	switch(num){
	        		case 1:
					{
						u.l[userchoice].sortdetail();
						break;
					}
					case 2:
					{
						u.l[userchoice].sortdeadline();
						break;
					}
					case 3:
					{
						u.l[userchoice].sortstatus();
						break;
					}
					default:
					{
						int val;
						cout<<"\nEnter :\n0 to continue sorting this list\n1 to go back to main page\n";
						if(val==1)
						{
							goto co1;
						}
						else
						{
							goto mainn;
						}
						break;
					}
			}
		}
		else if(us==8)//store and exit
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** E X I T I I N G   T A S K    P R O **************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	goto exittt;
		}
		
    	system("Color 07"); 
		cout<<"\n\nTo go back the main page Press 1\nTo see more options to explore this list press 2\n\n";
		cin>>repeats;
		if(repeats==1)
		{
			goto mainn;
		}
		else if(repeats==2)
		{
			goto chooseotherfunctionalites;
		}
	    Feedback f;
	    f.FeedbackInput();
	}
	exittt:
	    Feedback f;
	    f.FeedbackInput();
	return 0;
}
