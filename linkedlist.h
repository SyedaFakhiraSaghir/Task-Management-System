#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "task.h"
#define size 5
using namespace std;

class linkedlist{
    public:
    task *head;
    linkedlist()
    {
        head=NULL;
    }
    void inserttask(task *t)
    {
    	task *newnode= new task(*t);
    	if (head == NULL) {
            head = newnode;
        }
        else {
            task* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
	}
    void insert(int choiceoflist) 
	{
    	system("Color 07"); 
    	string n;
		string d;
		string s;
		int k;
		int t;
		int m;
		string details;
		string c;
		int inp;
		//n:\n1.Academic tasks\n2.Shopping taks\n3.Personal tasks\n4.Events\n5.Wish list\n6.Archived Tasks";
    	if(choiceoflist==0)
    	{
    		c="Academic tasks";
		}
		else if(choiceoflist==1)
    	{
    		c="Shopping tasks";
		}
		else if(choiceoflist==2)
    	{
    		c="Personal tasks";
		}
		else if(choiceoflist==3)
    	{
    		c="Events";
		}
		else if(choiceoflist==4)
    	{
    		c="Wish list";
		}
		else if(choiceoflist==5)
    	{
    		c="Archived Tasks";
		}
    	cout << "Enter Task Name: ";
		fflush(stdin);
		getline(cin,n);
    	cout << "Enter Task Deadline (dd/mm/yy) : ";
		fflush(stdin);
		getline(cin,d);
    	cout << "Enter Task Status\n1. Done\n2. Not done\n3.partially done\n ";
		fflush(stdin); 
		cin>>inp;
		if(inp==1)
		{
			s="done";
		}
		else if(inp==2)
		{
			s="not done";
		}
		else if(inp==3)
		{
			s="partially done";
		}
    	cout << "Enter Key: "; 
		cin >> k;
    	cout << "Enter Time: "; 
		cin >> t;
		labelagain:
    	cout << "Enter 1 if you missed the task, and 0 if you didn't: ";
		cin >> m;
		if(m==0 || m==1)
		{
			goto cont;
		}
		else
		{
			goto labelagain;
		}
		cont:
    	cout << "\nEnter Details Of Task: ";
		fflush(stdin);
		getline(cin, details);
        task* newnode = new task(n, d, s, c, k, t, m, details);
        if (head == NULL) {
            head = newnode;
        }
        else {
            task* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

   	void search()
	{
		int number;
		tryagain:
    	system("Color 01"); 
		string tname;
		cout << "\nEnter Task Name You Want To Search: ";
		fflush(stdin);
		getline(cin,tname);
	    task* t = head;
		while(t != NULL){
			if(t->getname() == tname){
				cout << endl << "------------ Task found -----------" << endl;
				displaytask(t);
				return;
			}
			t=t->next;
		}
		gain:
		cout<<"The task name entered does'nt exist\nEnter 1 to try again\n2 to go back to main\n";
		cin>>number;
		if(number==1)
		{
			goto tryagain;
		}
		else if(number==2)
		{
			return;
		}
		else
		{
			cout<<"Error wrong choice!!\n";
			goto gain;
		}
    }

   void display()
    {
    	system("Color 09"); 
        task* t=head;
        cout<<"\n************TASK DETAILS************\n";
        while(t!=NULL)
		{
           cout<<"\n-----------------------------------------"<<endl;
           cout<<"\n\nTask name: "<<t->getname();
           cout<<"\nDeadline: "<<t->getdeadline();
           cout<<"\nCategory: "<<t->getcategory();
           cout<<"\nStatus: "<<t->getstatus();
           cout << "\nDetails: " << t->getdetails();
           cout<<"\nMissed tasks: "<<t->getmissedtask();
           cout<<"\nTime: "<<t->gettimet()<<endl;
           cout<<"-----------------------------------------\n"<<endl;
           t=t->next;
		}
    }
   void displaytask(task *t)
    {
    	if(t!=NULL){
    	system("Color 01");
        cout<<"\n************TASK DETAILS************\n";
        cout<<"\n-----------------------------------------"<<endl;
       cout<<"\nTask name: "<<t->getname();
       cout<<"\tDeadline: "<<t->getdeadline();
       cout<<"\nCategory: "<<t->getcategory();
       cout<<"\tStatus: "<<t->getstatus();
       cout << "\nDetails: " << t->getdetails();
       cout<<"\nMissed tasks: "<<t->getmissedtask();
       cout<<"\tTime: "<<t->gettimet();
       cout<<"-----------------------------------------\n"<<endl;
   		}
   		else{
   			cout<<"Task doesn't exist";
		   }
    }
    
void sortdeadline() {
	system("Color 01");
    if (head == NULL || head->next == NULL) {
        return; // Return if the list is empty or has only one element
    }

    task* current;
    task* nextNode;
    task* temp = new task(); 
    bool swapped;

    do {
        swapped = false;
        current = head;

        while (current->next != NULL) {
            nextNode = current->next;
            string str=current->getdeadline();
            int num1=str[0]-'0';
            num1*=10;
            int temp1=str[1]-'0';
            num1+=temp1;
            
            int num2=str[3]-'0';
            num2*=10;
            temp1=str[4]-'0';
            num2+=temp1;

          	int num3=str[6]-'0';
            num3*=10;
            temp1=str[7]-'0';
            num3+=temp1;
            
            str=nextNode->getdeadline();
            
            int num4=str[0]-'0';
            num4*=10;
            temp1=str[1]-'0';
            num4+=temp1;
            
            int num22=str[3]-'0';
            num22*=10;
            temp1=str[4]-'0';
            num22+=temp1;

          	int num33=str[6]-'0';
            num33*=10;
            temp1=str[7]-'0';
            num33+=temp1;
            
            if (num33 < num3) {
                // Swap values
                temp->setname(current->getname());
                temp->setdeadline(current->getdeadline());
                temp->setstatus(current->getstatus());
                temp->setcategory(current->getcategory());
                temp->setkey(current->getkey());
                temp->settimet(current->gettimet());
                temp->setdetails(current->getdetails());
						

                current->setname(nextNode->getname());
                current->setdeadline(nextNode->getdeadline());
                current->setstatus(nextNode->getstatus());
                current->setcategory(nextNode->getcategory());
                current->setkey(nextNode->getkey());
                current->settimet(nextNode->gettimet());
				current->setdetails(nextNode->getdetails());
				
                nextNode->setname(temp->getname());
                nextNode->setdeadline(temp->getdeadline());
                nextNode->setstatus(temp->getstatus());
                nextNode->setcategory(temp->getcategory());
                nextNode->setkey(temp->getkey());
                nextNode->settimet(temp->gettimet());
				nextNode->setdetails(temp->getdetails());
				
                swapped = true;
            }
            if (num22 < num2 && num33==num3) {
                // Swap values
                temp->setname(current->getname());
                temp->setdeadline(current->getdeadline());
                temp->setstatus(current->getstatus());
                temp->setcategory(current->getcategory());
                temp->setkey(current->getkey());
                temp->settimet(current->gettimet());
                temp->setdetails(current->getdetails());
						

                current->setname(nextNode->getname());
                current->setdeadline(nextNode->getdeadline());
                current->setstatus(nextNode->getstatus());
                current->setcategory(nextNode->getcategory());
                current->setkey(nextNode->getkey());
                current->settimet(nextNode->gettimet());
				current->setdetails(nextNode->getdetails());
				
                nextNode->setname(temp->getname());
                nextNode->setdeadline(temp->getdeadline());
                nextNode->setstatus(temp->getstatus());
                nextNode->setcategory(temp->getcategory());
                nextNode->setkey(temp->getkey());
                nextNode->settimet(temp->gettimet());
				nextNode->setdetails(temp->getdetails());
				
                swapped = true;
            }
            if (num4 < num1 && num22 ==num2) {
                // Swap values
                temp->setname(current->getname());
                temp->setdeadline(current->getdeadline());
                temp->setstatus(current->getstatus());
                temp->setcategory(current->getcategory());
                temp->setkey(current->getkey());
                temp->settimet(current->gettimet());
                temp->setdetails(current->getdetails());
						

                current->setname(nextNode->getname());
                current->setdeadline(nextNode->getdeadline());
                current->setstatus(nextNode->getstatus());
                current->setcategory(nextNode->getcategory());
                current->setkey(nextNode->getkey());
                current->settimet(nextNode->gettimet());
				current->setdetails(nextNode->getdetails());
				
                nextNode->setname(temp->getname());
                nextNode->setdeadline(temp->getdeadline());
                nextNode->setstatus(temp->getstatus());
                nextNode->setcategory(temp->getcategory());
                nextNode->setkey(temp->getkey());
                nextNode->settimet(temp->gettimet());
				nextNode->setdetails(temp->getdetails());
				
                swapped = true;
            }

            current = current->next;
        }

    } while (swapped);

    delete temp; 
}
    void sortstatus()
    {
    	int num;
        cout<<"Press:\n";
		cout<<"1 if you want to sort acoording to sequence (not done, partially done, done)\n";
		cout<<"2 if you want to sort acoording to sequence (partially done, not done, done)\n";
		cout<<"3 if you want to sort acoording to sequence (done, partially done, not done)\n";
		cout<<"4 if you want to go back\n";
		cin >> num;
		if(num == 4 || head == NULL)
		{
			return;
		}
		bool swapped;
		task *curr = head;
		while(curr->next != NULL)
		{
			swapped = false;
			task *temp = curr->next;		
			while(temp != NULL)
			{
				string de = temp->getdetails();
				string n = temp->getname();
				string d = temp->getdeadline();
				string s = temp->getstatus();
				string c = temp->getcategory();
				int k = temp->getkey();
				int t = temp->gettimet();
				
				if(num == 1)
				{
					if(temp->getstatus() == "not done" && curr->getstatus() != "not done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					else if(temp->getstatus() == "partially done" && curr->getstatus() != "not done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
				}
				else if(num==2)
				{
					if(temp->getstatus() == "partially done" && curr->getstatus() != "partially done")
					{	
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					else if(temp->getstatus() == "not done" && curr->getstatus() != "patially done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					
				}
				else if(num == 3)
				{
					if(temp->getstatus() == "done" && curr->getstatus() != "done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					else if(temp->getstatus() == "partially done" && curr->getstatus() != "done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
				}
				temp = temp->next;
			}
			if(swapped == false)
			{
				break;
			}
			curr = curr->next;
		}
    }
    void sortdetail() //sorting according to the length of details
    {
    	system("Color 07"); 
    	int num;
    	cout<<"Press:\n";
		cout<<"1 if you want tasks with more details on the top\n";
		cout<<"2 if you want tasks with less details on the top\n";
		cout<<"3 if you want to go back\n";
		cin >> num;
		if(num == 3 || head == NULL)
		{
			return;
		}
		
		int count = 0;
		int count2 = 0;
		bool swapped;
		task *curr = head;
		while(curr->next != NULL)
		{
			swapped = false;
			count = 0;
			string str = curr->getdetails();
			for(int i = 0; i < str.length();i++)
			{
				if(str[i] == ' ' || str[i] == str.length()-1)
				{
					count++;
				}
			}
			task *temp = curr->next;		
			while(temp != NULL)
			{
				string de = temp->getdetails();
				string n = temp->getname();
				string d = temp->getdeadline();
				string s = temp->getstatus();
				string c = temp->getcategory();
				int k = temp->getkey();
				int t = temp->gettimet();
				count2 = 0;
				str = temp->getdetails();
				for(int i = 0; i < str.length();i++)
				{
					if(str[i] == ' ' || str[i] == str.length()-1)
					{
						count2++;
					}
				}
			
				//if num==2 put the tasks with less details at top else if num==1 put the tasks with more deatils on top
        		//ascending
       	 		//descending
				if(num==1)
				{
					if(count < count2)
					{
						temp->setdetails(curr->getdetails());
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						count = count2;
						swapped = true;
					}
				}
				else if(num==2)
				{
					if(count > count2)
					{	
						task *swap = temp;
						 	
						temp->setdetails(curr->getdetails());
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						count = count2;
						swapped = true;
					}
				}
				temp = temp->next;
			}
			if(swapped == false)
			{
				break;
			}
			curr = curr->next;
		}
    }
    void update()
    {
    	system("Color 0A"); 
    	continue2:
    	int number;
    	string n;
    	cout<< endl <<"Enter Task Name which you want to Update: ";
		fflush(stdin);
    	getline(cin,n);
        task *t = head;
        while(t->getname() != n)
        {
        	t = t->next;
		}
		continue1:
    	int choice;
        cout<<"\nWhat do you want to update:\n1. Task Name\n2.Task deadline\n3.Task Status\n4.Task time\n5.Task details\n6.Missed or not\n"<<endl;
        cin>>choice;
        switch(choice)
        {
        	case 1:
			{
				string name;
				cout<< "\nEnter Name : ";
				fflush(stdin);
				getline(cin,name);
        		t->setname(name);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 2:
			{
				string deadline;
				cout<<"\nEnter Deadline: ";
				fflush(stdin);
				getline(cin,deadline);
				t->setdeadline(deadline);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 3:
			{
				string status;
				cout<<"\nEnter Status : ";
				fflush(stdin);
				getline(cin,status);
				t->setstatus(status);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 4:
			{
				int timet;
				cout<<"\nEnter Time : ";
				cin >> timet;
				t->settimet(timet);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 5:
			{
				string de;
				cout<<"\nEnter Details: ";
				fflush(stdin);
				getline(cin,de);
				
				t->setdetails(de);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 6:
			{
				int mm;
				cout<<"\nEnter if task missed or not: ";
				cin >> mm;
				t->setmissedtask(mm);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			default:
				{
					int val;
					system("Color 0C"); 
					cout<<"\nEnter a valid choice :\n0 to continue updation in this task\n1 to update a new task\n2 to go back to main page\n";
					if(val==1)
					{
						goto continue2;
					}
					else if(val==0)
					{
						goto continue1;
					}
					else
					{
						return;
					}
				}
		}
    }
    void deletet()
    {
    	tryagain:
    		int number,flag=0;
    	string n;
    	cout<<"\nEnter Task Name to be Deleted : ";
		fflush(stdin);
    	getline(cin,n);
        task *t=head;
        if(head != NULL && head->getname() == n)
		{
			head = head->next;
		}
		else 
		{
			task *t = head;
        	while(t->next != NULL)
        	{
        		if(t->next->getname() == n)
				{
					flag=1;
					break;
				}
        		t = t->next;
			}
			if(flag==1)
			{
				t->next = t->next->next;
			}
			if(flag==1)
			{
				cout<<"\nTask not found\n";
				return;
			}
		}
		gain:
		cout<<"\nEnter 1 to keep deleting tasks\n2 to go back to main\n";
		cin>>number;
		if(number==1)
		{
			goto tryagain;
		}
		else if(number==2)
		{
			return;
		}
		else
		{
			cout<<"Error wrong choice!!\n";
			goto gain;
		}
    }
    task* archive()
    {
        string n;
    	cout<<"\nEnter Task Name to be Archived : ";fflush(stdin);
    	getline(cin,n);
        
        if(head != NULL && head->getname() == n)
		{
			task *temp = head;
			head = head->next;
			return temp;
		}
		task *t = head;
        while(t->next != NULL)
        {
        	if(t->next->getname() == n)
			{
				break;
			}
        	t = t->next;
		}
		task *temp = t->next;
		t->next = t->next->next;
		return temp; 
	}
};