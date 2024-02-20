#include <iostream>
#include<cstring>
#include<fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto


class Hotel;

class Admin{
	char name[20];
	char password[11];
	
	public:
		
		void setdata()
		{
			cout<<"Enter your username: ";
			cin>>name;
			
			cout<<endl<<"enter password: ";
			cin>>password;
			
			cout<<"Remember password: ";
			
			
			int menu_item=0, run, x=7;
			bool running = true;
			
			gotoXY(18,7); cout << "->";
			
			while(running)
			{
		            gotoXY(20,7);  cout << "1) YES";
					gotoXY(20,8);  cout << "2) NO";
				
					system("pause>nul"); // the >nul bit causes it the print no message
				
					if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
						{
							gotoXY(18,x); cout << "  ";
							x++;
							gotoXY(18,x); cout << "->";
							menu_item++;
							continue;
							
						}
						
					if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
						{
							gotoXY(18,x); cout << "  ";
							x--;
							gotoXY(18,x); cout << "->";
							menu_item--;
							continue;
						}
						
					if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
						
						switch(menu_item){
							
							case 0: {
								
								gotoXY(20,16);
								
								storeCustomer();
								
								cout<<"Info saved";
								
								system("cls");
								running=false;
								
								break;
							}
								
								
							case 1: {
								gotoXY(20,16);
								
								running=false;
								
								break;
								
							}
							
						}
							
					}		
					
		}
		
		gotoXY(20,21);
			
		}
		
		void gotoXY(int x, int y) 
		{	 
			CursorPosition.X = x; 
			CursorPosition.Y = y; 
			SetConsoleCursorPosition(console,CursorPosition); 
		}
				
		void getdata()
		{
			cout<<endl<<name<<" "<<password;
		}
	
	
	int storeCustomer()
		{				
				ofstream fout;
				fout.open("Customer.dat",ios::app|ios::binary);
				fout.write((char*)this,sizeof(*this));
				fout.close();
				return (1);
			
		}
  
  	void viewAll()
		{
			ifstream fin;
			fin.open("Customer.dat",ios::in|ios::binary);
			
			if(!fin)
			{
				cout<<"File not found ";
				
			}
			
			else
			{
				fin.read((char*)this,sizeof(*this));
				
				while(!fin.eof())
				{
					
					getdata();
					fin.read((char*)this,sizeof(*this));
					
				}
			}
			fin.close();
			
		}

		
	
};

class Customer
{
	
    char name[20];
    int destination,i;
    int days[10],rooms[10];
    string locations[10]; 
    int preference;
	char password[11];

    public:

	
	Customer()
	{
		
	}


    Customer(int a)
    {
    	
//        fflush(stdin);
//      	cout <<"Enter name: ";
//      	getline(cin,name);
//      	fflush(stdin);
//      	cout <<"Enter phone number: ";
//      	cin >> number;
		cout<<endl;
        cout <<"Number of destinations: ";
        cin >> destination;

        locations[destination];
        days[destination];
//      cout <<"Enter number of nights: ";
//      cin >> nights;

        cout << "1-Karachi" <<endl <<"2-Islamabad" <<endl <<"3-Lahore" <<endl <<"4-Naran"<<endl<<endl;

        for (i=0;i<destination;i++)
        {
            cout <<"Enter destination " <<i+1<<": " ;
            cin >> locations[i];
           	cout <<"Enter number of days: ";
        	cin >> days[i];
			cout <<"Enter number of rooms: ";
        	cin >> rooms[i];
        	cout<<endl;
        	//cout<<days[i];
        }

    }

	//getters
    // int getdestination( ) {return destination;}
    // string * getlocation() {return locations;}
    // int getpref() {return preference;}
    // int getrooms() {return rooms;}
    // void getdays() {}
    // int getnights() {return nights;}
    // int getbudget() {return budget;}

	void setdata()
		{
			cout<<"Enter your username: ";
			cin>>name;
			
			cout<<endl<<"enter password: ";
			cin>>password;
			
			cout<<"Remember password: ";
			
			
			int menu_item=0, run, x=7;
			bool running = true;
			
			gotoXY(18,7); cout << "->";
			
			while(running)
			{
		            gotoXY(20,7);  cout << "1) YES";
					gotoXY(20,8);  cout << "2) NO";
				
					system("pause>nul"); // the >nul bit causes it the print no message
				
					if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
						{
							gotoXY(18,x); cout << "  ";
							x++;
							gotoXY(18,x); cout << "->";
							menu_item++;
							continue;
							
						}
						
					if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
						{
							gotoXY(18,x); cout << "  ";
							x--;
							gotoXY(18,x); cout << "->";
							menu_item--;
							continue;
						}
						
					if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
						
						switch(menu_item){
							
							case 0: {
								
								gotoXY(20,16);
								
								storeCustomer();
								
								cout<<"Info saved";
								
								system("cls");
								running=false;
								
								break;
							}
								
								
							case 1: {
								gotoXY(20,16);
								
								running=false;
								
								break;
								
							}
							
						}
							
					}		
					
		}
		
		gotoXY(20,21);
			
		}
		
		void gotoXY(int x, int y) 
		{	 
			CursorPosition.X = x; 
			CursorPosition.Y = y; 
			SetConsoleCursorPosition(console,CursorPosition); 
		}
				
		void getdata()
		{
			cout<<endl<<name<<" "<<password;
		}
	
	
	int storeCustomer()
		{				
				ofstream fout;
				fout.open("Customer.dat",ios::app|ios::binary);
				fout.write((char*)this,sizeof(*this));
				fout.close();
				return (1);
			
		}
  
  	void viewAll()
		{
			ifstream fin;
			fin.open("Customer.dat",ios::in|ios::binary);
			
			if(!fin)
			{
				cout<<"File not found ";
				
			}
			
			else
			{
				fin.read((char*)this,sizeof(*this));
				
				while(!fin.eof())
				{
					
					getdata();
					fin.read((char*)this,sizeof(*this));
					
				}
			}
			fin.close();
			
		}
		
    friend class Hotel;
	
};




class  Hotel 
{
    
    int price[10];
    string name[10];
    bool available; //make static or something
	string arr[10];
	int paisa[10];
	
    public:
    	  	
  

//perfection do not touch
    
    void store(const char *a)
    {
		//read and store in array
    	fstream b;
    	b.open(a, ios::in);
    	string st;
    	Customer c(1);
		paisa[10];
		for(int k=0;k<c.destination;k++)
		{    
			
     
		}

        b.close();
		display(c,a);		
		select(c);


}


void display(Customer c,const char *a)
    {
		//display 
        fstream z;
    	z.open(a, ios::in);
    	string st;

		cout<<"AVAILABLE HOTELS"<<endl;
		for(int k=0;k<c.destination;k++)
		{    
			//cout <<"what is here: "<<endl<<c.locations[k][0];
			z.seekg(0,ios::beg);
			z.seekg(0,ios::beg);
			for(int j=0;j<10;j++)  		
			{
				getline(z,st);
	            if(st[0]==c.locations[k][0] && !z.eof())
	            {
					//cout<<st<<" - "<<c.locations[k]<<" j=" <<j<<endl;
				  	cout<<j<<"-"<<st<<endl;
				  	arr[j]=st;
	        	}
				
			}
		}
        z.close();
        
        
}
    
int getNumberFromString(string s) 
{
	string numbers="";
	
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			numbers+=s[i];
		}
	}
//	cout<<numbers;
	stringstream g(numbers);
	int a;
	g>>a;
	return a;
}


void select(Customer c)
{
	int choice,result=0;
	int op[c.destination];
	char *ch;
	string ss;
	cout<<endl<<"From above options "<<endl;
	for(int i=0;i<c.destination;i++)
	{
		cout<<"Enter choice for "<<c.locations[i]<<" : ";
		cin>>choice;
		op[i]=choice;
		ss=arr[choice];
		int result=getNumberFromString(ss);
		paisa[op[i]]=result;

	}

	//totalling
	int p=0, total=0;
	cout<<endl<<"Total Cost"<<endl;
	for(int i=0;i<c.destination;i++)
	{
		
		if (p<c.destination)
		{
			//extracting name
			string t=arr[op[i]];
			t.erase(t.size()-6);

			//multiplying days
			paisa[op[i]]= paisa[op[i]] * c.days[p] * c.rooms[p];
			total=total+paisa[op[i]];
			//displaying
			cout<<t << " rooms:" << c.rooms[p]<< " days:" << c.days[p]<<" Rs"<<paisa[op[i]]<<endl;

			p++;
		}

		
	}
	cout<<"Total:Rs "<<total<<endl;

	
}
  

};


class star5 : public Hotel
{
    public:        
    string getPath()
	{
		string a="C:\\Users\\tahir\\Desktop\\5 star.txt"; //5 star
 		return a;
	}
};

class star4 : public Hotel
{
	public:		
    string getPath()
	{
		string a="C:\\Users\\tahir\\Desktop\\4 star.txt"; //4 star
 		return a;
		
	}
};

class star3 : public Hotel
{
	public:	
    string getPath()
	{
		string a="C:\\Users\\tahir\\Desktop\\3 star.txt"; //3 star
 		return a;
	}
};

class star2 : public Hotel
{
	public:
    string getPath()
	{
		string a="C:\\Users\\tahir\\Desktop\\2 star.txt"; //2 star
 		return a;
	}
};



int date()
{

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    cout << endl;
    cout << endl;


    cout << "Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    cout << "Time     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    return 0;
}

	

int main() 
{
	while(1)
	{
		date();
		break;
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO MY TRIP.COM ================|";
	getch();

	system("cls");


//	Customer c;
//	c.setdata();
//	c.getdata();
//	c.storeCustomer();
//	c.viewAll();
//
//
//	char *ch;
//	int pre;
//
//	getch();
//	system("cls");
//	
//	cout<<endl<<"preference: ";
//	cin>>pre;
//
//
//	if(pre==5)
//	{
//		string a;
//		star5 s;
//		a=s.getPath();
//		char* ch = const_cast<char*>(a.c_str());
//		s.store(ch);	 
//	}
//	
//	else if(pre==4)
//	{
//		 string a;
//		star4 s;
//		a=s.getPath();
//		char* ch = const_cast<char*>(a.c_str());
//		s.store(ch);
//	}
//	
//	else if(pre==3)
//	{
//		 string a;
//		star4 s;
//		a=s.getPath();
//		char* ch = const_cast<char*>(a.c_str());
//		s.store(ch);
//	}
//	
//	else if(pre==2)
//	{
//		 string a;
//		star2 s;
//		a=s.getPath();
//		char* ch = const_cast<char*>(a.c_str());
//		s.store(ch);
//	}
//	
//	
//	
//	
	
	
//	cout<<endl<<endl<<"View customer(s) data: ";
//	c.viewAll();
	
//	Hotel o;
//	o.store(ch);
	
	Admin A;
	A.setdata();
//	A.getdata();
//	A.storeCustomer();
	A.viewAll();			

}

