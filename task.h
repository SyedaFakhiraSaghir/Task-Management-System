#include<iostream>
#include<string>
#define size 5
using namespace std;
class task{
     //------------------attributes-----------------------------
    private:
        string name; //task's name
        string deadline; //last day of the task
        string status; //1.partially done //2.done //3.not done
        string category; //list name //work //academic //event //personal //wishlist //archive
        string details;
        int key;
        int timet; //currect time
        bool missedtask; //done = 1 //not done=0
    public:
        task *next;
        task *prev;
        //------------------default constructor-----------------------------
        task()
        {
   
        }
         //------------------parameterized constructor-----------------------------
        task(string n,string d, string s, string c, int k, int t, bool m,string details)
        {
            name=n;
            deadline=d;
            status=s;
            category=c;
            key=k;
            timet=t;
            missedtask=m;
            next=NULL;
            prev=NULL;
            this->details = details;
        }
        //------------------copy constructor-----------------------------
        task(const task *& t)
        {
            name=t->name;
            deadline=t->deadline;;
            status=t->status;
            category=t->category;
            key=t->key;
            timet=t->timet;
            details = t->details;
            missedtask=t->missedtask;
            next=t->next;
            prev=t->prev;
        }
        //------------------setters-----------------------------
        void setname(string name)
        {
            this->name=name;
        }
        void setdeadline(string deadline)
        {
            this->deadline=deadline;
        }
        void setstatus(string status)
        {
            this->status=status;
        }
        void setcategory(string category)
        {
            this->category=category;
        }
        void setkey(int key)
        {
            this->key=key;
        }
        void settimet(int timet)
        {
            this->timet=timet;
        }
        void setmissedtask(bool missedtask)
        {
            this->missedtask=missedtask;
        }
        void setdetails(string details)
		{
			this->details = details;
		}
        //------------------getters-----------------------------
        string getname()
        {
            return name;
        }
        string getdeadline()
        {
            return deadline;
        }
        string getstatus()
        {
            return status;
        }
        string getcategory()
        {
            return category;
        }
        string getdetails()
        {
            return details;
        }
        int getkey()
        {
            return key;
        }
        int gettimet()
        {
            return timet;
        }
        bool getmissedtask()
        {
            return missedtask;
        }
};
