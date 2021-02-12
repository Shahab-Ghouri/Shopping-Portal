// SHOPPING PORTAL
// ADMIN PANEL

#include <iostream>
#include <conio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "Customer Panel.cpp"

using namespace std;

void gotoxy(int x, int y)                //for positioning cursor
			{
				COORD coord;
				coord.X = x;                       // X and Y coordinates
				coord.Y = y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
// classes		

void processing(){
	cout<<"Loading";
	for(int i=0;i<3;i++){
		cout<<".";
		sleep(1);
	}
}
class Admin{		// base class
	private:
		 string user="Shahab@nu.edu.pk";
		 int women_libaas_small,women_libaas_medium,women_libaas_large;
		 int women_western_small,women_western_medium,women_western_large;
		
		 int men_libaas_small,men_libaas_medium,men_libaas_large;
		 int men_western_small,men_western_medium,men_western_large;
		 
	public:
		// variables for no. of sizes 
		 
		
		int price;
		char code[6];
		string styles;	
		 // setters
		 void set_women_libaas_small(int a){
			this->women_libaas_small=a;
		 }
		 
		  void set_women_libaas_medium(int a){
			this->women_libaas_medium=a;
		 }
		 
		 
		  void set_women_libaas_large(int a){
			this->women_libaas_large=a;
		 }
		 //-----------
		  void set_women_western_small(int a){
			this->women_western_small=a;
		 }
		 
		  void set_women_western_medium(int a){
			this->women_western_medium=a;
		 }
		 
		 
		  void set_women_western_large(int a){
			this->women_western_large=a;
		 }
		 //*****************
		 // MEN
		 
		   void set_men_libaas_small(int a){
			this->men_libaas_small=a;
		 }
		 
		  void set_men_libaas_medium(int a){
			this->men_libaas_medium=a;
		 }
		 
		 
		  void set_men_libaas_large(int a){
			this->men_libaas_large=a;
		 }
		 //-----------
		  void set_men_western_small(int a){
			this->men_western_small=a;
		 }
		 
		  void set_men_western_medium(int a){
			this->men_western_medium=a;
		 }
		 
		 
		  void set_men_western_large(int a){
			this->men_western_large=a;
		 }
		 
		 
		 
		 
		// default constructor
		Admin(){
//			code[6]={"NULL"};
			styles="NULL";
		}
		
		// public variables
		int x=50,y=10,i,choice;
		string user1;
		char pass1[20],ch;
		
		
		
		
		// getters
		string getuser(){
			return user;
		}
		
		
		int get_women_libaas_small(){
			return women_libaas_small;
		 }
		 
		  int get_women_libaas_medium(){
			return women_libaas_medium;
		 }
		 
		 
		  int get_women_libaas_large(){
			return women_libaas_large;
		 }
		 //-----------
		  int get_women_western_small(){
			return women_western_small;
		 }
		 
		  int get_women_western_medium(){
			return women_western_medium;
		 }
		 
		 
		  int get_women_western_large(){
			return women_western_large;
		 }
		 //*****************
		 // MEN
		 
		  int get_men_libaas_small(){
			return men_libaas_small;
		 }
		 
		  int get_men_libaas_medium(){
			return men_libaas_medium;
		 }
		 
		 
		  int get_men_libaas_large(){
			return men_libaas_large;
		 }
		 //-----------
		  int get_men_western_small(){
			return men_western_small;
		 }
		 
		  int get_men_western_medium(){
			return men_western_medium;
		 }
		 
		 
		  int get_men_western_large(){
			return men_western_large;
		 }
		 
		
		
		// functions
		void first(){
			system("cls");
			x=50,y=10;
			gotoxy(40,11);
			cout<<"USERNAME : ";
			gotoxy(40,16);
			cout<<"PASSWORD : ";
			box1();
			box2();
			x=51;
			y=11;
			gotoxy(x,y);
			cin>>user1;
			
			if(user1==getuser()){
				x=51;
				y=16;
				gotoxy(x,y);
				
				 for( i=0;i<20;i++)
   				{
     				
 					pass1[i]=getch();
 					if(pass1[i]==8)			//AsCII Value of backspace
					{
						i-=1;
					}
					else if(pass1[i]==13)	// ASCII Value of ENTER
					break;
					else
					cout<<("*");
  				}		// end of for
   				pass1[i]='\0'; 
   				cout<<"\n\n\n";
   				if(strcmp(pass1,"admin")==0)
   				{
   					cout<<"\t\t\tLogin Successful!!\n Press Enter To Continue...."<<endl;	
					fflush(stdin);
   					cin.get();
   					processing();
				}
				else{
					x=10;
					y+=5;
					gotoxy(x,y);
					cout<<"\t\t\tLogin UnSuccessful!!\n Press Enter To Continue...."<<endl;	
   					fflush(stdin);
   					cin.get();
   					first();
				}
   				
			}		// end of user if
			else{
				x=10;
				y+=17;
				gotoxy(x,y);
				cout<<"\t\t\tLogin UnSuccessful!!\n Press Enter To Continue...."<<endl;	
   				fflush(stdin);
   				cin.get();
   				first();
			}
			
			
		}		// end of first()
		
			
			// boxes
		void box1(){
				
				gotoxy(x,y);
				cout<<"_____________________"<<endl;
				for(int i=0;i<2;i++){
					y+=1;
					gotoxy(x,y);
					cout<<"|"<<endl;
				}		// end of for
				x+=1;
				gotoxy(x,y);
				cout<<"____________________"<<endl;
				x+=20;
				y=10;
				gotoxy(x,y);
				for(int i=0;i<2;i++){
					y+=1;
					gotoxy(x,y);
					cout<<"|"<<endl;
				}		// end of for
		}		// end of box
		
		void box2(){
			x=50,y+=3;
			gotoxy(x,y);
			cout<<"_____________________"<<endl;
			for(int i=0;i<2;i++){
				y+=1;
				gotoxy(x,y);
				cout<<"|"<<endl;
			}
			x+=1;
			gotoxy(x,y);
			cout<<"____________________"<<endl;
			x+=20;
			y=15;
			gotoxy(x,y);
			for(int i=0;i<2;i++){
				y+=1;
				gotoxy(x,y);
				cout<<"|"<<endl;
			}	// end of for
		}		// end of box2
		
			void  menu();
			void collection();
			void virtual display() = 0;		// purely virtual function
			void virtual print_slow(string,int)=0;
};			// end of admin class 





class STOCK:public Admin{
	protected:
		string libaas_msg="Enter A World Of Lively Colours,Bold Prints And Embrace Joy With Latest Libaas Collection.";
		string west_msg=" This season get ready to don yourself in prints,stripy pants and with our stellar western collection.";
	public:

		void update_stock(){
		
			int ch,gender;
			system("cls");
			cout<<"\xDB\xDB\xDB\xDB\xB2 1. LIBAAS COLLECTION"<<endl;
    		cout<<"\xDB\xDB\xDB\xDB\xB2 2. WESTERNBOUND COLLECTION"<<endl;
    		cout<<"\xDB\xDB\xDB\xDB\xB2 3. EXIT"<<endl;
   			cout<<"Enter Your Choice : ";cin>>ch;
   			if(ch==3)
   			{
   				menu();
			}

    		system("cls");
        	cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 1>>> WOMEN"<<endl;
	    	cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 2>>> MEN"<<endl;
	    	cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 3>>> EXIT"<<endl;
   			cout<<"\n ENTER THE SECTION YOU WANT TO VISIT:\t";cin>>gender;
   			if(gender==3)
   			{
   				menu();
			}
   		 	processing();		// Loader
   	switch(ch)
    {
    	case 1:
    		system("cls");
    		cout<<"\n\xDB\xDB\xDB\xDB\xB2";
			print_slow(libaas_msg,40);
			cout<<"\t\xDB\xDB\xDB\xDB\xB2"<<endl;
    	    if(gender==1)
    	    { 
    	        cout<<"\n\t\t*************LIBAAS COLLECTION--WOMEN SECTION*************\n\n\n"<<endl;
    	        Women(ch);
			}
    	    else if(gender==2)
    	    {	

    	    	cout<<"\n\t\t*************LIBAAS COLLECTION--MEN SECTION*************\n\n\n"<<endl;
    	    	Men(ch);
			}
			
 		   
			break;
		case 2:
			system("cls");
			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2";
			print_slow(west_msg,40);
			cout<<"\t\xDB\xDB\xDB\xDB\xB2"<<endl;
            if(gender==1)
            {
            	cout<<"\n\t\t*************WESTERNBOUND COLLECTION--WOMEN SECTION*************\n\n\n"<<endl;
            	Women(ch);
		       
			}
			else if(gender==2)
			{
				cout<<"\n\t\t*************WESTERNBOUND COLLECTION--MEN SECTION*************\n\n\n"<<endl;
               	Men(ch);
			}
		

 	     	break;
	}		// end of switch	
			
		}		// end of update stock ----- STOCK	
		
		
		// function PROTO
		void menu();
		void collection();

		void input(int);
		void women_getdata(int);
		void Women(int);
		void Men(int);
		void men_getdata(int);
		void display();
		void print_slow(string, int);
		void delete_stock();
		
	
};					// end of STOCK class


// printing msg 
void STOCK::print_slow(string stri, int delay_time) {
	int i;
    while(i!=stri.size()){
	
        cout << stri[i];
        Sleep(delay_time);
		i+=1;
    }
}		// end of print_slow-------ADMIN,STOCK

void STOCK::menu(){
		system("cls");
		cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
		gotoxy(20,5);
		cout<<"\xDB\xDB\xDB\xDB\xB2 1. To View Stock "<<endl;	
		gotoxy(20,7);
		cout<<"\xDB\xDB\xDB\xDB\xB2 2. To Update The  Stock   "<<endl;	
		gotoxy(20,9);
		cout<<"\xDB\xDB\xDB\xDB\xB2 3. To Delete Item From The Stock"<<endl;
		gotoxy(20,11);
		cout<<"\xDB\xDB\xDB\xDB\xB2 4. Exit"<<endl;
		cin>>choice;
		input(choice);

}		// end of menu-----STOCK

void STOCK::input(int choice1){
	// start of switch case
	
	switch(choice1){
		case 1:
			collection();
		break;
		
		case 2:
			update_stock();
		break;
		
		case 3:
			delete_stock();
		break;
//		
		case 4:
			break;
		
		default:
			cout<<"\n\nInvalid Input!!"<<endl;
			cout<<"Press Any Key To Contniue..."<<endl;
			getch();			 	
		break;
		
		
	}
}			// end of input-----STOCK

void STOCK::collection(){
	int ch,gender,small,medium,large;
	system("cls");
	cout<<"\xDB\xDB\xDB\xDB\xB2 1. LIBAAS COLLECTION"<<endl;
    cout<<"\xDB\xDB\xDB\xDB\xB2 2. WESTERNBOUND COLLECTION"<<endl;
    cout<<"\xDB\xDB\xDB\xDB\xB2 3. EXIT"<<endl;
   	cout<<"\n ENTER THE SECTION YOU WANT TO VISIT:\t";cin>>ch;
    if(gender==3)
   		 menu();
//    processing();
   		 system("cls");
         cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 1>>> WOMEN"<<endl;
	     cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 2>>> MEN"<<endl;
	     cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 3>>> EXIT"<<endl;
   		 cout<<"\n ENTER THE SECTION YOU WANT TO VISIT:\t";cin>>gender;
   		 if(gender==3)
   		 menu();
   		 processing();	
   	switch(ch)
    {
    	case 1:
    		system("cls");
    		cout<<"\n\xDB\xDB\xDB\xDB\xB2\t";
			print_slow(libaas_msg,40);
			cout<<"\t\xDB\xDB\xDB\xDB\xB2"<<endl;
            
    	     if(gender==1)
    	    { 
    			
    	        cout<<"\n\t\t*************LIBAAS COLLECTION--WOMEN SECTION*************\n\n\n"<<endl;
    	        display();
				ifstream file1;		//  file1.eof()
    	        file1.open("libaaswomen.txt",ios::in);
    	        while(file1>>code>>styles>>small>>medium>>large>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<medium<<"\t\t"<<large<<"\t\t"<<price<<endl;
				}
				file1.close();
				getch();
			}
    	    else if(gender==2)
    	    {
    	    	cout<<"\n\t\t*************LIBAAS COLLECTION--MEN SECTION*************\n\n\n"<<endl;
    	    	display();
    	        ifstream file1;
    	        file1.open("libaasmen.txt",ios::in);
    	        x=50;
				y=9;
    	        while(file1>>code>>styles>>small>>medium>>large>>price){
    	        	cout<<code<<"\t\t"<<styles;
					gotoxy(x,y);cout<<small;gotoxy(x+17,y);cout<<medium;gotoxy(x+32,y);cout<<large;gotoxy(x+46,y);cout<<price<<endl;
    	        	y++;
				}
				file1.close();
				getch();			// to hold screen
			}
			menu();
			break;
		case 2:
			system("cls");
			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2";
			print_slow(west_msg,40);
			cout<<"\t\xDB\xDB\xDB\xDB\xB2\t"<<endl;
		    if(gender==1)
            {
            	cout<<"\n\t\t*************WESTERBOUND COLLECTION--WOMEN SECTION*************\n\n\n"<<endl;
            	display();
    	        ifstream file2;
    	        file2.open("westernboundwomen.txt",ios::in);
    	        while(file2>>code>>styles>>small>>medium>>large>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<medium<<"\t\t"<<large<<"\t\t"<<price<<endl;
				}
				file2.close();
				getch();
            }
			else if(gender==2)
			{
				cout<<"\n\t\t*************WESTERBOUND COLLECTION--MEN SECTION*************\n\n\n"<<endl;
				display();
    	        ifstream file2;
    	        file2.open("westernboundmen.txt",ios::in);
    	        while(file2>>code>>styles>>small>>medium>>large>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<medium<<"\t\t"<<large<<"\t\t"<<price<<endl;
				}
				file2.close();
				fflush(stdin);
				getch();
			
			} 	
 	     	menu();
 	     	break;
 	     	
 	     	default:
				cout<<"\n\nInvalid Input!!"<<endl;
				cout<<"Press Any Key To Contniue..."<<endl;
				getch();			 	
			break;
	}		// end of switch

}			// end of collection ----- STOCK			


void STOCK::display(){
	cout<<"CODE\t\tPRODUCT NAME\t\t\tSMALL\t\tMEDIUM\t\tLARGE\t\tPRICE"<<endl;
	for(int i=0;i<105;i++)
	cout<<"_";
	cout<<"\n";
}

void STOCK::women_getdata(int x){
	char temp;
	int s,m,l;
	cout<<"Enter CODE : ";cin>>code;
	cout<<"Enter PRODUCT NAME : ";cin>>styles;
	cout<<"Enter Price : ";cin>>price;
	ofstream file;							// file obj for writing record of women
	try{
		if(x==1)
		{
			cout<<"Enter SIZES : \n\tNumber Of Small : ";cin>>s;
			set_women_libaas_small(s);
			cout<<"\tNumber Of Medium : ";cin>>m;
			set_women_libaas_medium(m);
			cout<<"\tNumber Of Large : ";cin>>l;
			set_women_libaas_large(l);
			
			
			file.open("libaaswomen.txt",ios::app);		// <<
			file<<code<<" "<<styles<<" "<<get_women_libaas_small()<<" "<<get_women_libaas_medium()<<" "<<get_women_libaas_large()<<" "<<price<<"\n";
			file.close();
		}else{
			throw(x);
		}
	}	
	catch(int x_num){
//		if (x_num==2)
		cout<<"Enter Sizes : \n\tNumber Of Small : ";cin>>s;
		set_women_western_small(s);
		cout<<"\tNumber Of Medium : ";cin>>m;
		set_women_western_medium(m);
		cout<<"\tNumber Of Large : ";cin>>l;
		set_women_western_large(l);
			
			
		file.open("westernboundwomen.txt",ios::app);
		file<<code<<" "<<styles<<" "<<get_women_western_small()<<" "<<get_women_western_medium()<<" "<<get_women_western_large()<<" "<<price<<"\n";
		file.close();
	}

	cout<<"\n\nData Entered Successfully..\nWant to Add more Record?(Y/N)";cin>>temp;
	if(temp== 'Y' || 'y')
	{
		system("cls");
		update_stock();
	}
	else if(temp == 'N' || 'n')
		menu();
}		// end of women_getdata();


void STOCK::Women(int a){
		try{
				if(a==1){
									
					women_getdata(a);
					
				}else{
					throw(a);
				}
			}
			
		catch(int num){
			if(num==2){
				women_getdata(num); 
				
			}else{
				cout<<"\n\nInvalid input!!";
				menu();
			}
		}	
}		// end of women collection



// MEN
void STOCK::men_getdata(int x){
	char temp;
	int s,m,l;
	cout<<"Enter Code : ";cin>>code;
	cout<<"Enter Product Name : ";cin>>styles;
	cout<<"Enter Price : ";cin>>price;
	ofstream file;							// file obj for writing record of women
	try{
		if(x==1)
		{
			cout<<"Enter Sizes : \n\tNumber Of Small : ";cin>>s;
			set_men_libaas_small(s);
			cout<<"\tNumber Of Medium : ";cin>>m;
			set_men_libaas_medium(m);
			cout<<"\tNumber Of Large : ";cin>>l;
			set_men_libaas_large(l);
			
			
			file.open("libaasmen.txt",ios::app);
			file<<code<<" "<<styles<<" "<<get_men_libaas_small()<<" "<<get_men_libaas_medium()<<" "<<get_men_libaas_large()<<" "<<price<<"\n";
			file.close();
		}else{
			throw(x);
		}
	}
	catch(int x_num){
		cout<<"Enter Sizes : \n\tNumber Of Small : ";cin>>s;
		set_men_western_small(s);
		cout<<"\tNumber Of Medium : ";cin>>m;
		set_men_western_medium(m);
		cout<<"\tNumber Of Large : ";cin>>l;
		set_men_western_large(l);
			
			
		file.open("westernboundmen.txt",ios::app);
		file<<code<<" "<<styles<<" "<<get_men_western_small()<<" "<<get_men_western_medium()<<" "<<get_men_western_large()<<" "<<price<<"\n";
		file.close();
	}

	cout<<"\n\nData Entered Successfully..\nWant to Add more Record?(Y/N)";cin>>temp;
	if(temp== 'Y' || 'y')
	{
		system("cls");
		update_stock();
	}
	else if(temp == 'N' || 'n')
		{
			menu();
		}
}		// end of men_getdata();



void STOCK::Men(int a){
		try{
				if(a==1){
									
					men_getdata(a);
					
				}else{
					throw(a);
				}
			}
			
		catch(int num){
			if(num==2){
				men_getdata(num); 
				
			}else{
				cout<<"\n\nInvalid input!!";
				menu();
			}
		}	
}		// end of Men collection

void STOCK::delete_stock(){
	int ch,gender,small,medium,large;
	char code[6],x[6];
	string styles;
    system("cls");
	cout<<"\xDB\xDB\xDB\xDB\xB2 1. LIBAAS COLLECTION"<<endl;
    cout<<"\xDB\xDB\xDB\xDB\xB2 2. WESTERNBOUND COLLECTION"<<endl;
    cout<<"Enter Your Choice : ";cin>>ch;
//    processing();
   		 system("cls");
         cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 1>>> WOMEN"<<endl;
	     cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 2>>> MEN"<<endl;
	     cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 3>>> EXIT"<<endl;
   		 cout<<"\n ENTER THE SECTION YOU WANT TO VISIT:\t";cin>>gender;
   		 if(gender==3)
   		 menu();
   		 processing();
			
		switch(ch){
			case 1:{
				system("cls");
    			cout<<"\n\xDB\xDB\xDB\xDB\xB2\t";
				print_slow(libaas_msg,40);
				cout<<"\t\xDB\xDB\xDB\xDB\xB2"<<endl;
            
    	     	if(gender==1)
    	    	{ 
    	        	cout<<"\n\t\t*************LIBAAS COLLECTION--WOMEN SECTION*************\n\n\n"<<endl;
    	        	display();
					ifstream fptr;
    	        	fptr.open("libaaswomen.txt",ios::in);
    	        	
    	        	
    	        	
    	       		while(fptr>>code>>styles>>small>>medium>>large>>price){
    	        		cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<medium<<"\t\t"<<large<<"\t\t"<<price<<endl;
					}	
    	        	fptr.close();
    	        	cout<<"Enter The Code Of Item To Delete : ";cin>>x;
					ifstream file1;
    	        	file1.open("libaaswomen.txt",ios::in);
			
	
					ofstream file;
					file.open("temp.txt",ios::app);
						
						while(file1>>code>>styles>>small>>medium>>large>>price)
						{
							if(strcmp(code,x)==0)
							{
								continue;
							}
							else{
								file<<code<<" "<<styles<<" "<<small<<" "<<medium<<" "<<large<<" "<<price<<"\n";
							}
						}
						cout<<"\nRecord Deleted Successfully..\n Press Any Key To Continue";
						getch();
						file.close();
						file1.close();
						remove("libaaswomen.txt");
						rename("temp.txt","libaaswomen.txt");
    	        	
			
			}
    	    else if(gender==2)
    	    {
    	    	int x_axis;
    	    	cout<<"\n\t\t*************LIBAAS COLLECTION--MEN SECTION*************\n\n\n"<<endl;
    	    	display();
    	        ifstream fptr;
    	        fptr.open("libaasmen.txt",ios::in);
    	        x_axis=50;
				y=9;
    	        while(fptr>>code>>styles>>small>>medium>>large>>price){
    	        cout<<code<<"\t\t"<<styles;
					gotoxy(x_axis,y);cout<<small;gotoxy(x_axis+17,y);cout<<medium;gotoxy(x_axis+32,y);cout<<large;gotoxy(x_axis+46,y);cout<<price<<endl;
    	        	y++;
				}
				fptr.close();
				
					cout<<"Enter The Code Of Item To Delete : ";cin>>x;
					ifstream file1;
    	        	file1.open("libaasmen.txt",ios::in);
					
	
					ofstream file;
					file.open("temp.txt",ios::app);
						
						while(file1>>code>>styles>>small>>medium>>large>>price)
						{
							if(strcmp(code,x)==0)
							{
								continue;
							}
							else{
								file<<code<<" "<<styles<<" "<<small<<" "<<medium<<" "<<large<<" "<<price<<"\n";
							}
						}
						cout<<"\nRecord Deleted Successfully..\n Press Any Key To Continue";
						getch();
						file.close();
						file1.close();
						remove("libaasmen.txt");
						rename("temp.txt","libaasmen.txt");
    	        	
			
			}
			menu();
				break;
			}
			
			
			
			case 2:{
				system("cls");
    			cout<<"\n\xDB\xDB\xDB\xDB\xB2\t";
				print_slow(west_msg,40);
				cout<<"\t\xDB\xDB\xDB\xDB\xB2"<<endl;
            
    	     	if(gender==1)
    	    	{ 
    	        	cout<<"\n\t\t*************WESTERBOUND COLLECTION--WOMEN SECTION*************\n\n\n"<<endl;
    	        	display();
					ifstream fptr;
    	        	fptr.open("westernboundwomen.txt",ios::in);
    	        	
    	        	
    	        	
    	       		while(fptr>>code>>styles>>small>>medium>>large>>price){
    	        		cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<medium<<"\t\t"<<large<<"\t\t"<<price<<endl;
					}	
    	        	fptr.close();
    	        	
    	        	cout<<"Enter The Code Of Item To Delete : ";cin>>x;
					ifstream file1;
    	        	file1.open("westernboundwomen.txt",ios::in);
	
	
					ofstream file;
					file.open("temp.txt",ios::app);
						
						while(file1>>code>>styles>>small>>medium>>large>>price)
						{
							if(strcmp(code,x)==0)
							{
								continue;
							}
							else{
								file<<code<<" "<<styles<<" "<<small<<" "<<medium<<" "<<large<<" "<<price<<"\n";
							}
						}
						cout<<"\nRecord Deleted Successfully..\n Press Any Key To Continue";
						getch();
						file.close();
						file1.close();
						remove("westernboundwomen.txt");
						rename("temp.txt","westernboundwomen.txt");
    	        	
				
			}
    	    else if(gender==2)
    	    {
    	    	cout<<"\n\t\t*************WESTERBOUND COLLECTION--MEN SECTION*************\n\n\n"<<endl;
    	    	display();
    	        ifstream fptr;
    	        fptr.open("westernboundmen.txt",ios::in);
    	        while(fptr>>code>>styles>>small>>medium>>large>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<medium<<"\t\t"<<large<<"\t\t"<<price<<endl;
				}
				fptr.close();
				
					cout<<"Enter The Code Of Item To Delete : ";cin>>x;
					ifstream file1;
    	        	file1.open("westernboundmen.txt",ios::in);
	
	
					ofstream file;
					file.open("temp.txt",ios::app);
						
						while(file1>>code>>styles>>small>>medium>>large>>price)
						{
							if(strcmp(code,x)==0)
							{
								continue;
							}
							else{
								file<<code<<" "<<styles<<" "<<small<<" "<<medium<<" "<<large<<" "<<price<<"\n";
							}
						}
						cout<<"\nRecord Deleted Successfully..\n Press Any Key To Continue";
						getch();
						file.close();
						file1.close();
						remove("westernboundmen.txt");
						rename("temp.txt","westernboundmen.txt");
    	        	
			
			}
			menu();
				break;
			}		
						
		}	// end of switch---- delete_stock	
}

// main
main(){
	system("cls");
	int a;
	char ch;
	STOCK stk;
	
	time_t mytime;
		mytime = time(NULL);
		cout<<ctime(&mytime);
		cout<<"\n\n";
        cout<<"\n -----------------------------------------------------------------------------------------------------------------";
		cout<<"\n\t\t                             AHM SHOPPING PORTAL\t\t";
		cout<<"\n -----------------------------------------------------------------------------------------------------------------\n";
		cout<<" \t\t\t\t\t\t~Quality Never goes out of style.\n";
		cout<<" -NOTE-\n";
		cout<<" -Free Delivery All Over Pakistan\n";
		cout<<" -Exclusive Discount Offers\n";
		cout<<" -No exchange offer\n";
		cout<<" -Payment by cash only\n\n\n";
		
	gotoxy(30,20);
	cout<<"ENTER  <<<< 1-ADMIN PANEL"<<endl;
	gotoxy(30,21);
	cout<<"ENTER  <<<< 2-CUSTOMER PANEL"<<endl;
	cin>>a;
	
	try{
		if(a==1){
			while(1){
				
			stk.first();
			stk.menu();
			main();
			}
		}else if(a==2){
			system("cls");
			Cart c;
			c.showCollection();
			c.editCart();
			Customer c1;
			Receipt R1;
			cout<<R1;
			}else{	throw(a);	}
		
	}
	catch(int a){
			cout<<"\n ----------";
			cout<<"\n ALERT";
			cout<<"\n ----------";
			cout<<"\n Invalid panel number.";
			cout<<"\n Re-enter the panel number.";
			sleep(2);
           // system("cls");
            cout<<"\n\n\tPress any Key To Continue..";
			main();
	}
	
		
}
