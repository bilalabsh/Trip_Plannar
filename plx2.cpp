#include <iostream>
#include<cstring>
#include<fstream>
#include <sstream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

class Hotel;


class Customer
{
	
    char name[20];
    int destination,i;
    int days[10],rooms[10];
    string locations[10];
	char number[11]; 
    int preference;

    public:

	
	Customer()
	{
		strcpy(name,"no title");
		strcpy(number,"no numb");
	}

    Customer(int a)
    {
    	
        fflush(stdin);
//      cout <<"Enter name: ";
//      getline(cin,name);
//      fflush(stdin);
//      cout <<"Enter phone number: ";
//      cin >> number;
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
		fflush(stdin);
      
	  	cout <<"Enter name: ";
      	cin>>name;
	  
	  	fflush(stdin);
      
//	  	cout <<"Enter phone number: ";
//		cin>>number;

	}
	
	void getdata()
	{
		cout<<name;
	}
	
	
	int storeinfile()
	{
		if(name=="no name")
		{
			cout<<"not initialised";
			return(0);
		}
		
		else
		{
			
		ofstream fout;
		fout.open("Customers.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		return (1);		
		
		}
				
			
	}
	
	
	void viewAllz()
		{
			ifstream fin;
			
			fin.open("Customers.dat",ios::in|ios::binary);
			
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




int main() 
{
//	char *ch;
//	int pre;
//	cout<<"preference: ";
//	cin>>pre;
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
	
	
	Customer c;
	c.setdata();
	cout<<endl<<"Get data: ";
	c.getdata();
	cout<<endl;
	c.storeinfile();
	c.viewAllz();
	
	
	
//	
//	Hotel o;
//	o.store(ch);
//	
	
			

}

