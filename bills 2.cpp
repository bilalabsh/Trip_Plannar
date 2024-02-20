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
	
    string name;
    int number,no_of_people,nights,destination,rooms,i;
    int days[10];
    string locations[10]; // fix this 
    float budget;
    int preference;

    public:

	
	Customer()
	{
		
	}
    Customer(int a)
    {
    	//uncomment it later
        fflush(stdin);
//        cout <<"Enter name: ";
//        getline(cin,name);
//        fflush(stdin);
//        cout <<"Enter phone number: ";
//        cin >> number;
        cout <<"Number of destinations: ";
        cin >> destination;
         locations[destination];
         days[destination];
        
//        cout <<"Enter number of nights: ";
//        cin >> nights;
        cout <<"Enter number of rooms: ";
        cin >> rooms;

       

        cout << "1-Karachi" <<endl <<"2-Islamabad" <<endl <<"3-Lahore" <<endl <<"4-Naran"<<endl;

        for (i=0;i<destination;i++)
        {
            cout <<"Enter destination " <<i+1<<": " ;
            cin >> locations[i];
           	cout <<"Enter number of days: ";
        	cin >> days[i];
        	cout<<endl;
        	cout<<days[i];
        }

    }


    int getdestination( )
    {
        return destination;
    }


    string * getlocation ()
    {
        return locations;
    }

    int getpref ()
    {
        return preference;
    }

    int getrooms()
    {
        return rooms;
    }
    void getdays()
    {
        
    }
    int getnights()
    {
        return nights;
    }
    int getbudget()
    {
        return budget;
    }

    friend class Hotel;
	
};




class  Hotel 
{
    
    int price[10];
    string name[10];
    bool available; //make static or something

	
    public:
    	  	
    
//    void setdata(string hn, float pp , int r ,int s, bool avl ) //make day night situation something
//    {
//        name = hn;
//        price[0]=pp;
//        rooms=r;
//        star=s;
//        //available=avl;
//    }

//    int getstar ()
//    {
//        return star;
//    }
//    float getprice ()
//    {
//        return price[0];
//    }
//    bool getavailable()
//    {
//        return available;
//    }
//    string getHotelName()
//    {
//        return hotel_name;
//    }
//    int getrooms ()
//    {
//        return rooms;
//    }
//    

//perfection do not touch
    
    void store(const char *a)
    {
    	fstream b;
    	b.open(a, ios::in);
    	string st;
    	Customer c(1);

		//SAB KUH  YAH HAIN 
		
		for(int k=0;k<c.destination;k++)
		{    
			b.seekg(0,ios::beg);
			for(int j=0;j<10;j++)  		
			{

				getline(b,st);
	            if(st[0]==c.locations[k][0])
	            {
	            	string t=st;
	            	t.erase(t.size()-6);
	            	name[j]=t;
	            	
	            	
	            	st.erase(0,st.size()-4);				  					  
				  	stringstream ss;  
				  	ss << st;  
				  	ss >> price[j];
				  	
				  	cout<<price[j]<<endl;
	        	}
			}
       
		}
		display(c,a);		
        b.close();
		select(c);
}

void display(Customer c,const char *a)
    {
    	   
        
        fstream z;
    	z.open(a, ios::in);
    	string st;
 
		
		for(int k=0;k<c.destination;k++)
		{    
			z.seekg(0,ios::beg);
			
	  
			for(int j=0;j<10;j++)  		
			{
				
			
				getline(z,st);
	            if(st[0]==c.locations[k][0])
	            {
				  	cout<<j<<"-"<<st<<endl;
	        	}
			}
			
       
		}
        z.close();
}
    
void select(Customer c)
{
	
	int choice;
	int ch[c.destination];
		for(int i=0;i<c.destination;i++)
	        {
	        	cout<<"Enter choice for "<<c.locations[i]<< " : ";
				cin>>choice;
				ch[i]=choice;
				cout<<endl;
				cout<< "days: "<<c.days[ch[i]]<< " price: "<<price[ch[i]]<<" rooms: "<<c.rooms<<endl;
				
			}
	
	for(int j=0;j<c.destination;j++)
	{
		//cout<< "days: "<<c.days[ch[j]]<< " price: "<<price[ch[j]]<<" rooms: "<<c.rooms<<endl;
		int total= price[ch[j]]*c.days[ch[j]]*c.rooms;
//		price[ch[j]]=total;

	cout<<name[ch[j]]<<" for "<<total<<endl;
	}
	
	
	
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
	char *ch;
	int pre;
	cout<<"preference: ";
	cin>>pre;
	if(pre==5)
	{
		string a;
		star5 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.store(ch);	 
	}
	
	else if(pre==4)
	{
		 string a;
		star4 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.store(ch);
	}
	
	else if(pre==3)
	{
		 string a;
		star4 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.store(ch);
	}
	
	else if(pre==2)
	{
		 string a;
		star2 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.store(ch);
	}
	
	
	
	
	
	
//	
//	Hotel o;
//	o.store(ch);
//	
	
			

}

