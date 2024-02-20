#include <iostream>
#include<cstring>
#include<fstream>

#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

class Hotel;


class Customer
{
    string name;
    int number,no_of_people,days,nights,destination,rooms,i;
    string locations[10]; // fix this 
    float budget;
    char pref;
    int preference;

    public:



    Customer()
    {
        fflush(stdin);
        cout <<"Enter name: ";
        getline(cin,name);
        fflush(stdin);
        cout <<"Enter phone number: ";
        cin >> number;
        cout <<"Enter number of days: ";
        cin >> days;
        cout <<"Enter number of nights: ";
        cin >> nights;
        cout <<"Enter budget : ";
        cin >> budget; //fix this
        cout <<"Enter number of rooms: ";
        cin >> rooms;

        // cout << "Do You have a preference(y/n): ";
        // cin >> pref;
        // if (pref=='y')
        // {
            cout << "Enter preference: ";
            cin >> preference;
        // }

        cout <<"Number of destinations: ";
        cin >> destination;

        cout << "1-Karachi" <<endl <<"2-Islamabad" <<endl <<"3-Lahore" <<endl <<"4-Naran"<<endl;

        for (i=0;i<destination;i++)
        {
            cout <<"Enter destination " <<i+1<<": " ;
            cin >> locations[i];
            // cout << "Enter this destinations budget: ";
            // cinn >> buddget[i];
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

    int getstar ()
    {
        return preference;
    }

    int getrooms()
    {
        return rooms;
    }
    int getdays()
    {
        return days;
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
    
    float price;
    bool available; //make static or something
    int star;
    string hotel_name;
    int rooms;
    string city;

    public:
    	
    	Hotel()
    	{
    		
		}

    void setdata(string hn, float pp , int r ,int s, bool avl ) //make day night situation something
    {
        hotel_name = hn;
        price=pp;
        rooms=r;
        star=s;
        //available=avl;
    }

//    void display()
//    {
//        printf("| %-40s | %-10s | %-10s | %-25s |\n", hotel_name, rooms, star, available);
//    	cout<< "Hotel Name: " << hotel_name <<endl;
//    	cout<< "Rooms: " << rooms <<endl;
//    	cout<< "Star: " << star <<endl;
//    	cout<< "Availability: " << available <<endl;    
//	}

    int getstar ()
    {
        return star;
    }
    float getprice ()
    {
        return price;
    }
    bool getavailable()
    {
        return available;
    }
    string getHotelName()
    {
        return hotel_name;
    }
    int getrooms ()
    {
        return rooms;
    }
    
    bool checker (string search)
	{
		int offset;
		string line;
	
		ifstream i;
		i.open("C:\\Users\\tahir\\Desktop\\oop project\\project.txt");
//	cout<<"Enter the name you want to search: "<<endl;
//	cin>>search;
	
		while(!i.eof())
		{
			getline(i,line);
			if((offset=line.find(search,0))!=string::npos)
			{
				cout<<"Arha";
				return true;
				
			}
		}
	i.close();
}

    
    void name()
    {
    	Customer c;
    	string st;
    	string l;
        int i=0,j=0,size=0,k=0;
        ifstream z;
        z.open("C:\\Users\\tahir\\Desktop\\Project.txt");
        
        //name
		string t;
            //cout<<c.destination;
            //cout<<c.locations[0];
            cout<<endl;
            
            z>>t;
//            cout<<"Arha hai?";
//	        cout<<t;
		
	
//				cout<<c.locations[k];
		//for(i=0;i<2;i++)
		//{
		for(k=0;k<c.destination;k++)
		{        		
			
            if(checker(c.locations[k]))
            {
//            	cout<<"Arha hai?(2)"<<endl;
//            	cout<<st;
				cout<<"For city "<<c.locations[k]<<" We have the following options: ";
            	getline(z,st);
            	cout<<st;
            	
            	
            	cout<<endl;
//            	getline(z,st);
//            	cout<<st;
            	
//            	size++;
//                //cout <<t[j];
//                hotel_name[j]=t[j];
                
            
			}
            else
            {
            	//char *t=new char[size];
               // cout << " tf ";
                break;
            }
        }
            
            
 		
        
	
        
//        for(i=0;i<size;i++)
//        {
//        	cout<<hotel_name[i];
//		}
        
       

        z.close();
    
    
	}
    void setcity()
    {
        int i=0,j=0,size=0;
        ifstream z("C:\\Users\\tahir\\Desktop\\Project.txt");
        //ifstream z(path);

        //name
        char *t=new char[size];
        while(!z.eof())
        {
            z.get(t[j]);
            if (!(t[j]=='c'))
            {
            	size++;
                //cout <<t[j];
                city[j]=t[j];
                
            }
            else if(!(t[j]==','))
            {
                break;
            }
            j++;
            
        }
        for(i=0;i<size;i++)
        {
        	cout<<city[i];
		}
        
       

        z.close();
    }

    

};


class star5 : public Hotel
{
    
    public:
    
    star5()
    {
        
       
    }

};

class City : public Customer
{

    Hotel *Karachi=new Hotel[60]; 
    public:

    City()
    {

    }


    void searching(  )
    {

        Karachi[0].setdata("Marriot",5000,2,4,true);
	    Karachi[1].setdata("Marriot",10000,3,4,true);      
        Karachi[2].setdata("PC",2000,1,4,true);
        Karachi[3].setdata("PC",4000,2,4,true);
        Karachi[4].setdata("Awari",1500,1,3,true);
        Karachi[5].setdata("Marriot",3500,2,3,true);
        
        int i,j;

        int destination =getdestination();
//        int *location = getlocation();
        int star=getstar();
        int room= getrooms();



//        for (i=0;i<destination;i++)
//        {
//            if (*(location+i)==1) //karachi
//            {
//    
//                for (j=0;j<6;j++) //chnage according array size
//                {
//
//
//                    if (star == Karachi[j].getstar() && room == Karachi[j].getrooms() )
//                    {
//                      printf("-----------------------------------------------------------------------------------------------------------------\n");
//                        printf("| %-40s | %-10s | %-10s | %-25s |\n", "Hotle", "Room", "Star", "Availability");
//                        cout <<endl <<endl;
//                        //Karachi[j].display();
//                    }
//
//
//                }
//
//            }
//            else if (*(location+i)==2) //islamabad
//            {
//
//            }
//            else if(*(location+i)==3)//lahore
//            {
//
//            }
//            else if (*(location+i)==4)//naran
//            {
//                
//            }
//        }
    }

};





int main() 
{

    // City ob1;
    // ob1.searching();
    //star5 d;
//    Hotel o;
//    o.name();
//    cout<<endl;
//    o.setcity();
    //City c;
    //c.searching();
	
//	Customer c;

	Hotel o;
	o.name();	

}
