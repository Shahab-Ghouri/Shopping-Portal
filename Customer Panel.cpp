#include<iostream>
#include<string.h>
#include<fstream>
#include<unistd.h>
#include<cstring>
#include<iomanip> 
#include<stdlib.h>
#include<ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
bool isChar(char c) 
{ 
    return((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
} 
bool isDigit(const char c) 
{ 
    return(c>='0'&&c<='9'); 
}  
bool is_valid(string email) 
{ 
    if(!(email[0]))
	{ 
        return 0;
    } 
    int At=-1,Dot=-1; 
    for (int i=0;i<email.length();i++) 
	{ 
	    if(email[i]=='@') 
		{ 
	        At=i; 
	    } 
	    else if(email[i]=='.') 
		{ 
	        Dot=i; 
	    } 
    } 
	if(At==-1||Dot==-1) 
	{
	   return 0; 
	}
	if(At>Dot) 
	{
	   return 0; 
	}
	   return !(Dot>=(email.length()-1)); 
	} 


	

class Customer  
{
	protected:
		string c_id;
		string c_add;
		string c_name;
		string c_fname;
		string c_lname;
		string c_phone;
		string c1_phone;
		string c_country;
		string c_province;
		int c_zip[5];
		string c_email;
		string c_street;
	public: 
		int x,y;
		void inputCustomerDetailsBilling();
		void inputCustomerDetailsShipping();
		void displayDetails(string c_name,string c_add,string c_phone,string c_email) //FUNCTION OVERLOADING
		{  
		    fstream Billingfile;
		    Billingfile.open("BillingDetails.txt",ios::app);
		    cout<<"\n________________________";
		    cout<<" \n BILL TO:";
		    cout<<"\n________________________";
		    cout<<"\n CONTACT NAME:"<<c_name;
		    Billingfile<<c_name;
		    Billingfile<<"\n";
		    cout<<"\n ADDRESS:"<<c_add;
		    Billingfile<<c_add;
		    Billingfile<<"\n";
		    cout<<"\n PHONE_NO:"<<c_phone;
		    Billingfile<<c_phone;
		    Billingfile<<"\n";
		    cout<<"\n EMAIL-ADDRESS:"<<c_email;
		    Billingfile<<c_email;
		    Billingfile<<"\n\n";
		} 
		void displayDetails(string c_fname,string c_lname,string c_country,string c_province,string c_street,int c_zip[],string c_phone,string c1_phone)
		{  
		    fstream shipfile;
		    shipfile.open("ShippingDetails.txt",ios::app);
		    system("cls");
		    cout<<"\n________________________";
		    cout<<" \n SHIP TO:";
		    cout<<"\n________________________";
		    cout<<"\n FIRST NAME:"<<c_fname;
		    shipfile<<c_fname;
		    shipfile<<"\n";
		    cout<<"\n LAST NAME:"<<c_lname;
		    shipfile<<c_lname;
		    shipfile<<"\n";
		    cout<<"\n ADDRESS:";
		    cout<<c_country<<" "<<c_province<<" "<<c_street<<" ";
		    shipfile<<"\n";
		    shipfile<<c_country<<" "<<c_province<<" "<<c_street;
		    for(int i=0;i<=4;i++)
		    {
			   cout<<c_zip[i];
		    }
		    shipfile<<"\n";
		    cout<<"\n CONTACT NUMBER 1:"<<c_phone;
		    shipfile<<c_phone;
		    shipfile<<"\n";
		    cout<<"\n CONTACT NUMBER 2:"<<c1_phone;
		    shipfile<<c_phone;
		    shipfile<<"\n\n";
		    sleep(2);
        } 
};
void Customer::inputCustomerDetailsBilling()
{
	    
		    cout<<"\n\t \t_______________BILLING INFORMATION_______________ \n";
		    cout<<"\n ENTER YOUR CONTACT NAME:";
			cin>>c_name;
		    cout<<"\n ENTER RESIDENTIAL/DEPT ADDRESS:";
		    cin>>c_add;
			cout<<"\n ENTER YOUR CONTACTNO:";
			reEnter:
			cin>>c_phone;		    
			if(c_phone.length()!=11)
			{ 
					cout<<"\n ----------";
					cout<<"\n ALERT";
					cout<<"\n ----------";
					cout<<"\n Invalid phone number entered.";
					cout<<"\n Re-enter the phone number.";
					sleep(2);
				    goto reEnter;
			}
			 p_number:
			cout<<"\n ENTER YOUR EMAILADDRESS:";
			cin>>c_email;
			bool ans=is_valid(c_email);
			if(ans==0)
			{
				cout<<"\n ----------";
				cout<<"\n ALERT";
				cout<<"\n ----------";
				cout<<"\n Invalid email_address entered.";
				cout<<"\n Re-enter the email_address.";
				sleep(2);
				goto p_number;
			}
			inputCustomerDetailsShipping();
		   displayDetails(c_name,c_add,c_phone,c_email);
}
void Customer::inputCustomerDetailsShipping()
{
	        cout<<"\n\t \t_______________SHIPPING INFORMATION_______________ \n";
		    cout<<"\n ENTER YOUR FIRST NAME:";
			cin>>c_fname;
			cout<<"\n ENTER YOUR LAST NAME:";
			cin>>c_lname;
			cout<<"\n ENTER COUNTRY:";
			cin>>c_country;
			cout<<"\n ENTER CITY: ";
			cin>>c_province;
			cout<<"\n ENTER STREET ADDRESS:";
			cin>>c_street;
			reenterzip:
			cout<<"\n ENTER ZIP /POSTAL CODE: ";
			for(int i=0;i<=4;i++)
			{
				cin>>c_zip[i];
			}
		    ReEnter2:
			cout<<"\n CONTACT NUMBER 1:";
		    cin>>c_phone;
			if(c_phone.length()!=11)
			{
				cout<<"\n ----------";
				cout<<"\n ALERT";
				cout<<"\n ----------";
				cout<<"\n Invalid phone number entered.";
				cout<<"\n Re-enter the phone number.";
				sleep(2);
				goto ReEnter2;
			}		
			ReEnter1:
			cout<<"\n CONTACT NUMBER 2:"; 
			cin>>c1_phone;       
		    if(c1_phone.length()!=11)
			{
				cout<<"\n ----------";
				cout<<"\n ALERT";
				cout<<"\n ----------";
				cout<<"\n Invalid phone number entered.";
				cout<<"\n Re-enter the phone number.";
				sleep(2);
				goto ReEnter1;
			}
			displayDetails(c_fname,c_lname,c_country,c_province,c_street,c_zip,c_phone,c1_phone);		
}
class Store //ABSTRACT CLASS
{
   protected:
        char code[6];
        char styles[50];
        int small;
        int med;
        int lar;
        int price;
    public:
    virtual void showCollection()=0;  //PURE VIRTUAL FUNCTION
//    void printHeader()
//	{
//	   // system("color 70");
//		time_t mytime;
//		mytime = time(NULL);
//		cout<<ctime(&mytime);
//		cout<<"\n\n";
//		char pannel;
//		char *p;
//		p=&pannel;
//	    cout<<"\n -----------------------------------------------------------------------------------------------------------------";
//		cout<<"\n\t\t                             AHM SHOPPING PORTAL\t\t";
//		cout<<"\n -----------------------------------------------------------------------------------------------------------------\n";
//		cout<<" \t\t\t\t\t\t\t\t\t~Quality Never goes out of style.\n";
//		cout<<" -NOTE-\n";
//		cout<<" -Free Delivery All Over Pakistan\n";
//		cout<<" -Exclusive Discount Offers\n";
//		cout<<" -No exchange offer\n";
//		cout<<" -Payment by cash only\n\n\n";	
//	}
    void Header()
    {
    	cout<<"__________________________________________________________";
    	cout<<"CODE\t\tPRODUCT NAME\t\t\tSMALL\t\tMEDIUM\t\tLARGE\t\tPRICE"<<endl;
		for(int i=0;i<105;i++)
		cout<<"_";
		cout<<"\n";
//        cout<<"\n\n  CODE    STYLES               S     M     L    PRICE";
//        cout<<"\n________________________________________________________";
	}
    
};
class WomenCategory:virtual public Store
{
    public:
    void showEasternWomenCollection(); //IMPLEMENTATION OF PURE VIRTUAL FUNCTION-showEasternCollection()
	void showWesternWomenCollection();
   	void showCollection()
    {
    	showEasternWomenCollection() ;//IMPLEMENTATION OF PURE VIRTUAL FUNCTION-showEasternCollection()
		showWesternWomenCollection();
	}
};
class MenCategory:virtual public Store
{
    public:
    void showEasternMenCollection(); //IMPLEMENTATION OF PURE VIRTUAL FUNCTION-showEasternCollection()
	void showWesternMenCollection(); 
    void showCollection()
    {
    	showEasternMenCollection();  //IMPLEMENTATION OF PURE VIRTUAL FUNCTION-showEasternCollection()
		showWesternMenCollection(); 
	}
};
void WomenCategory:: showEasternWomenCollection() //IMPLEMENTATION OF PURE VIRTUAL FUNCTION-showEasternCollection()
    {
    	ifstream infile;
    	infile.open("libaaswomen.txt",ios::in);
    	Header();
          while(infile>>code>>styles>>small>>med>>lar>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<med<<"\t\t"<<lar<<"\t\t"<<price<<endl;
				}
		infile.close();
	}
void WomenCategory::showWesternWomenCollection() 
	{
    	ifstream infile;
    	 
		infile.open("westernboundwomen.txt",ios::in);
        Header();
    	        while(infile>>code>>styles>>small>>med>>lar>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<med<<"\t\t"<<lar<<"\t\t"<<price<<endl;
				}
		infile.close();
	} 
void MenCategory::showEasternMenCollection()
    {
    	ifstream infile;
    	infile.open("libaasmen.txt",ios::in);
        Header();
		 while(infile>>code>>styles>>small>>med>>lar>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<med<<"\t\t"<<lar<<"\t\t"<<price<<endl;
				}
	    infile.close();
	}
void MenCategory::showWesternMenCollection()
	{
    	ifstream infile;
    	infile.open("westernboundmen.txt",ios::in);
       	Header();
		  while(infile>>code>>styles>>small>>med>>lar>>price){
    	        	cout<<code<<"\t\t"<<styles<<"\t\t\t"<<small<<"\t\t"<<med<<"\t\t"<<lar<<"\t\t"<<price<<endl;
				}
		infile.close();
	}		
	
class Cart:public MenCategory,public WomenCategory
{
	protected:
	char id[6];
	char size;
	int req;
	char reshop;
    public:
    Cart()
    {
    //	printHeader();
	}
	void showCollection();
	void displayUser(int choice,int gender);
	void updateStock(int choice,int gender);
    void displayCart();
    void editCart();
    void removeItem();
    void finalCart(int req,int removequantity,char remid[]);
};
void Cart::showCollection()
{        	system("cls");
            int choice;
            int gender;
            label:
            cout<<"\n PICK OUR BEST COLLECTION!"<<endl;
            cout<<"\xDB\xDB\xDB\xDB\xB2 1. LIBAAS COLLECTION"<<endl;
    		cout<<"\xDB\xDB\xDB\xDB\xB2 2. WESTERNBOUND COLLECTION"<<endl;
            cout<<"\n";    		    
            cout<<"\n ENTER YOUR CHOICE : ";
            cin>>choice;
            
   		    gender:
            try //EXCEPTION HANDLING FOR INCORRECT COLLECTION NUMBER
            {
                if(choice==1||choice==2)
            	{
            		    system("cls");
            		  	cout<<"\n";
			            cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 1>>> WOMEN"<<endl;
	     				cout<<"\n\xDB\xDB\xDB\xDB\xB2  ENTER 2>>> MEN"<<endl;
			   		    cout<<"\n ENTER THE SECTION YOU WANT TO VISIT:\t";
			   		    cin>>gender;
				}
				else
				{
					
					cin.clear();
					cin.ignore();
					throw choice;
				}
			}
            catch(...)  
			{
				cout<<"\n ----------";
				cout<<"\n ALERT";
				cout<<"\n ----------";
                cout<<"\n Invalid collection number entered.";
                cout<<"\n Re-enter the collection number.";
                sleep(2);
                system("cls");
				goto label;
            }
   		    try
   		    {
   		    	if(gender==1||gender==2)
   		    	{
   		    		switch(choice)
                    {
		                case 1:
		                {
		                	system("cls");
		                	cout<<"\nEnter A World Of Lively Colours,Bold Prints And Embrace Joy With Latest Libaas Collection.";
		                    cout<<"\n\n\n";
		                    if(gender==1)
		                    {
		                        cout<<"\n\t\t*************  LIBAAS COLLECTION--WOMEN SECTION  *************\n\n\n"<<endl; 
		                        WomenCategory::showEasternWomenCollection();
		                    }
		                    else if(gender==2)
		    	            { 
		                        cout<<"\n\t\t*************  LIBAAS COLLECTION--MEN SECTION  *************\n\n\n"<<endl;;	
		                        MenCategory::showEasternMenCollection();
					        }
					        break;
		                }
		                case 2:
		                {
		                	system("cls");
		                	cout<<"\nThis season get ready to don yourself in prints,stripy pants and with our stellar western collection.";
		                    cout<<"\n\n\n";
		                    if(gender==1)
		                    {
		                        cout<<"\n\t\t*************  WESTERNBOUND COLLECTION--WOMEN SECTION  *************\n\n\n"<<endl;
		                        WomenCategory::showWesternWomenCollection();
		                    }
		                    else if(gender==2)
		    	            { 
		                        cout<<"\n\t\t*************  WESTERNBOUND COLLECTION--MEN SECTION  *************\n\n\n"<<endl;
								MenCategory::showWesternMenCollection();	
					        }
					        break;
					    }
                    }
				}
				else 
   		    	{
   		    		throw gender;
				}
			}
		    catch (...)  //EXCEPTION HANDLING FOR INCORRECT SECTION NUMBER
			{
				Beep(900,500);								// 900 Hertz for 500 milliseconds
				Beep(900,500);
				Beep(900,500);
				cout<<"\n ----------";
				cout<<"\n ALERT";
				cout<<"\n ----------";
				cout<<"\n Invalid section number entered.";
				cout<<"\n Re-enter the section number.";
				sleep(2);
                system("cls");
                cin.clear();
                cin.ignore();
				goto gender;
			}
			displayUser(choice,gender);
    }
    
void Cart:: displayUser(int choice,int gender)
{
		char reshop;
		productid:
		ifstream infile;
		if(choice==1&&gender==1)
		{
				infile.open("libaaswomen.txt",ios::in);
		}
		else if(choice==1&&gender==2)
		{
				infile.open("libaasmen.txt",ios::in);
		}
		else if(choice==2&&gender==1)
		{
				infile.open("westernboundwomen.txt",ios::in);
		}
		else if(choice==2&&gender==2)
		{
				infile.open("westernboundmen.txt",ios::in);
		}
	        bool flag=true;
	        ofstream cartfile;
	        cartfile.open("Cart.txt",ios::app);
            cout<<"\n\n";
        	cout<<"\n ENTER THE PRODUCT ID:";
        	fflush(stdin);
			cin>>id;
			while(infile>>code>>styles>>small>>med>>lar>>price)
			{
				if(strcmp(code,id)==0)
			    {
			    	flag=true;
			    	break;
	        	}
	        	else
				{
					flag=false;
				}
			}
			char a;
			if(flag==true)
			{
				cout<<"\n ENTER S>>>SMALL";
		        cout<<"\n ENTER M>>>MEDIUM";
		        cout<<"\n ENTER L>>>LARGE\n\n";
		        cout<<"\n NOTE: If the entered item is not in the list, the required item will not be added in the cart.";
		        sizel:
		        cout<<"\n\n ENTER THE REQUIRED SIZE(S/M/L):";
		        cin>>size;
		        if((size=='S'||size=='s')||(size=='M'||size=='m')||(size=='L'||size=='l'))
		        {
		        	quantitylabel:
			        cout<<" ENTER THE REQUIRED QUANTITY:\t";
			        cin>>req;
			        try
			        {
			        	if (isdigit(req)==true)
			        	{
			        		throw req;
						}
					}
					catch(...)
					{
						cout<<"\n ----------";
						cout<<"\n ALERT";
						cout<<"\n ----------";
						cout<<"\n Invalid quantity entered.";
						cout<<"\n Re-enter the quantity.";
						sleep(2);
		               // system("cls");
		                cin.clear();
		                cin.ignore();
						goto quantitylabel;
					}
			        cout<<"\n";
			        system("cls");
			        cout<"---------------------------------------------------------------------------------";
			        cout<<"\n\t\t\tPRODUCT DETAILS\t\t";
			        cout<"---------------------------------------------------------------------------------";
					cout<<"\n\n";	
                    try
	                 {
	                	if((size=='s'||size=='S')&&(req<=small)||(size=='M'||size=='m')&&(req<=med)||(size=='L'||size=='l')&&(req<=lar))
	                	{
						    cout<<"\n";
							cout<<"  "<<code<<"    "<<styles<<"       "<<req<<"    "<<price;
							cartfile <<code<<"    "<<styles<<"       "<<req<<"    "<<price;	
							cartfile<<"\n";
					    }
					    else
					    {
					    	throw a;
						}
					}
					catch(...)
					{
						cout<<"\n We are short of "<<styles<<".Sorry for the inconvenience.";
						cout<<"\n Do you want to shop again?";
                		cin>>reshop;
                		try
						{
                			if(reshop=='Y'||reshop=='y')
                    	    {
	                    		system("cls");
	                    		showCollection();
	                    	}
	                    	else
	                    	{
	                    		throw 101;
							}
						}
						catch(...)
						{
							exit(0);
							cartfile.close();
						}
					}
				}
				else 
				{
				    cout<<"\n ----------";
					cout<<"\n ALERT";
					cout<<"\n ----------";
					cout<<"\n Invalid size entered.";
					cout<<"\n Re-enter the size.";
					sleep(2);
		            goto sizel;
				}
			}
	        else
	        {
	        	infile.close();
	        	cout<<"\n ----------";
				cout<<"\n ALERT";
				cout<<"\n ----------";
				cout<<"\n Invalid productid entered.";
				cout<<"\n Re-enter the productid.";
				sleep(2);
	        	goto productid;
	        	
			}
			
			infile.close();
			cartfile.close();
			updateStock(choice,gender);
			
}
void Cart:: updateStock(int choice,int gender)
    {
		        char filename[20];
	            ifstream infile;
			    ofstream updatedfile;
		        updatedfile.open("Updatedfile.txt",ios::out);
				if(choice==1&&gender==1)
				{
						infile.open("libaaswomen.txt",ios::in);
						strcpy(filename,"libaaswomen.txt");
				}
				else if(choice==1&&gender==2)
				{
						infile.open("libaasmen.txt",ios::in);
						strcpy(filename,"libaasmen.txt");
				}
				else if(choice==2&&gender==1)
				{
						infile.open("westernboundwomen.txt",ios::in);
						strcpy(filename,"westernboundwomen.txt");
				}
				else if(choice==2&&gender==2)
				{
						infile.open("westernboundmen.txt",ios::in);
						strcpy(filename,"westernboundmen.txt");
				}
		    while(infile>>code>>styles>>small>>med>>lar>>price)
		    {
		    	if(strcmp(code,id)==0)
		    	{
		    		if(size=='s'||size=='s')
		    		{
		    		      small=small-req;	
					}
		    		else if(size=='m'||size=='M')
		    		{
		    		    med=med-req;
					}
					else if(size=='l'||size=='L')
					{
						lar=lar-req;
					}
		    		updatedfile<<code<<"    "<<styles<<"       "<<small<<"    "<<med<<"    "<<lar<<"    "<<price;
				}
				if(strcmp(code,id)!=0)
				{
					updatedfile<<code<<"    "<<styles<<"       "<<small<<"    "<<med<<"    "<<lar<<"    "<<price;
				}
		    	updatedfile<<"\n";
			}
			infile.close();
			updatedfile.close();
			remove(filename);
			rename("Updatedfile.txt",filename);
			char reshop;
			cout<<"\n\n";
		    cout<<"\n DO YOU WANT TO RESHOP?";
		    cin>>reshop;
		    if(reshop=='y'||reshop=='Y')
		    {
		    	system("cls");
		    	showCollection();
			}
			else
			{
			   displayCart();	
			}
    }
    void Cart:: displayCart()
    {
	    ifstream cartfile;
	    cartfile.open("Cart.txt",ios::in);
	    system("cls");
	    cout<<"\n---------------------------------------";
	    cout<<"\n Your items in cart are:";
	    cout<<"\n---------------------------------------";
	    while(cartfile>>code>>styles>>req>>price)
		{
			cout<<"\n";
			cout<<"  "<<code<<"    "<<styles<<"       "<<req<<"    "<<price;
		}
		cartfile.close();
    }
void Cart::editCart()
   {
    int quantity;
	removelabel:
	int num;
	cout<<"\n\n Enter '1'>>> To remove any item from the cart";
    cout<<"\n Enter '2'>>> To proceed for the bill";
    cout<<"\n\n Enter number: ";
    cin>>num ;
	try
    {
		if(num==1)
		{
			removeItem();
		}
		else if(num==2)
		{
	  		Customer c1;
	  		system("cls");
	  		c1.inputCustomerDetailsBilling();
	  	//	c1.displayDetails();
		}
		else
		{
			cin.clear();
			cin.ignore();
			throw 101;
	    }
    }
    catch(...)
    {
		cout<<"\n ----------";
		cout<<"\n ALERT";
		cout<<"\n ----------";
		cout<<"\n Invalid selection number entered.";
		cout<<"\n Re-enter the number.";
		sleep(5);
		goto removelabel;
    }
}
void Cart ::removeItem()
{
	    ifstream cartfile;
		cartfile.open("Cart.txt",ios::in);
		ofstream billfile;
		billfile.open("Bill.txt",ios::out);	
	    int del;
		char remcode[6];
		cout<<"\n ENTER THE CODE OF THE PRODUCT TO REMOVE:";
		fflush(stdin);
		cin>>remcode;
		printf("\n ENTER THE QUANTITY TO REMOVE:");
		cin>>del;
	   while(cartfile>>code>>styles>>req>>price)
	{
			if(strcmp(code,remcode)==0)
			{
				req=req-del;
				if(req>0)
					billfile<<"  "<<code<<"    "<<styles<<"       "<<req<<"    "<<price;
			}
			else
			{
			    	billfile<<"  "<<code<<"    "<<styles<<"       "<<req <<"    "<<price;
			}  
			billfile<<"\n";
		} 		
		
			
			cout<<"\n\n DO YOU STILL WANT TO REMOVE PRODUCT?";
			char option;
			cin>>option;
			if(option=='Y'||option=='y')
			{ 
		    	billfile.close();
		    	cartfile.close();
		    	remove("Cart.txt");
		    	rename("Bill.txt","Cart.txt");	 
		    	billfile.open("Bill.txt",ios::out);
				cartfile.open("cart.txt",ios::in);
		    	removeItem();
				Customer c;
		    	c.inputCustomerDetailsBilling();
		}
		else
		{
			billfile.close();
		    cartfile.close();
		    remove("Cart.txt");
		    rename("Bill.txt","Cart.txt");	 
		    
		}		
			
			
//			billfile.close();
//		    cartfile.close();
//		    remove("Cart.txt");
//		    rename("Bill.txt","Cart.txt");	 
//		    Customer c1;
//		    getch();
//		    system("cls");
//	  		c1.inputCustomerDetailsBilling();
				
}
void  userRate(int num)
{
        fstream filerating;
		
        char ast='*';
		 if(num==1)
		 {
	 	filerating.open("UserRating.txt",ios::app);
		 cout<<"\t\t\t\t\t\t\t\t  "<<ast;
		 filerating<<"\t\t\t\t\t\t\t\t  "<<ast;
		 filerating<<"\n";
		 cout<<"\n";
		 filerating.close();
		 
		 }
		 else if(num==2)
		 {
		filerating.open("UserRating.txt",ios::app);
		cout<<"\t\t\t\t\t\t\t\t\t\t"<<ast;
		 filerating<<"\t\t\t\t\t\t\t\t\t\t"<<ast;
		 filerating<<"\n";
		 cout<<"\n";
		 filerating.close();
		 }
		 else if(num==3)
		 {
		 	filerating.open("UserRating.txt",ios::app);
		 	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "<<ast;
		 	filerating<<"\t\t\t\t\t\t\t\t\t\t\t\t  "<<ast;
		 	filerating<<"\n";
		     cout<<"\n";
		 	filerating.close();
		 }
		 
	     
}
void userRating()
{
	int num,i,j;
	fstream filerating;	
	//filerating.open("UserRating.txt",ios::app);
	system("cls");
	cout<<"\n\n-------------------------------------------- Service Quality Review -------------------------------------------------";
	cout<<"\n\n Please indicate your level of agreement,with the following statements:\n";
	cout<<"\n ENTER 1>>> AGREE";
	cout<<"\n ENTER 2>>> NEUTRAL";
	cout<<"\n ENTER 3>>> DISAGREE";
	"\n_______________________________________\n";

	//printf("\n\n\t\t\t\t\t\t\t\t%s%15s%14s\n", "AGREE", "NEUTRAL","DISAGREE");
	
	cout<<"\n\n\t\t\t\t\t\t\t\tAGREE"<<"\t\t   NEUTRAL"<<"\t    DISAGREE";
	//filerating<<"\n\n\t\t\t\t\t\t\t\tAGREE"<<"\t\t   NEUTRAL"<<"\t      DISAGREE";
	cout<<"\n____________________________________________________________________________________________________\n\n";
    filerating.open("UserRating.txt",ios::app);
	cout<<"It was easier for me to navigate the products.";
	filerating<<"It was easier for me to navigate the products.\n";
	cin>>num;
	userRate(num);
	filerating.close();
	
	filerating.open("UserRating.txt",ios::app);
	cout<<"I am satisfied with the pricing of the product.";
	filerating<<"I am satisfied with the pricing of the product.\n";
	cin>>num;
	userRate(num);
	filerating.close();
	
	filerating.open("UserRating.txt",ios::app);
	cout<<"I will recommend the services/products.";
	filerating<<"I will recommend the services/products.\n";
	cin>>num;
	userRate(num);
	filerating.close();

	filerating.open("UserRating.txt",ios::app);
	cout<<"I will visit this site again.";
	filerating<<"I will visit this site again.\n";
	cin>>num;
	userRate(num);
	filerating.close();
	
	filerating.open("UserRating.txt",ios::app);
	cout<<"The checkout process was simple.";
	filerating<<"The checkout process was simple.\n";
	cin>>num;
	userRate(num);
	filerating.close();
	
}
class Receipt:public Customer
{
	private:
		float total;
		int billno ;
	    int req;
	    char code[6];
	    string styles;
	    int price;
	public:
        void printingTime()
		{
			time_t t;
		    time(&t);
		    cout<<"\t\t\t"<<ctime(&t);
		}

		friend ostream&operator<<(ostream &out,Receipt &r);
};
ostream&operator<<(ostream &out,Receipt &r)
		{
			fstream BillfileNo,BillfileNo1;
			BillfileNo.open("Bill Number Records.txt",ios::in);
			BillfileNo1.open("Bill Number Records1.txt",ios::app);
			while(BillfileNo>>r.billno)
			{ 
			    cout<<"\n Receipt No:";
				cout<<setw(4)<<setfill('0')<<r.billno;
			}
			    BillfileNo1<<"\n\n"<<r.billno;
			    BillfileNo.close();
			    r.billno++;
			    BillfileNo.open("Bill Number Records.txt",ios::out);
			    BillfileNo<<r.billno;
			    BillfileNo<<"\n";
			    out<<"\n\t\t---------------------------------------------------------------------------------------\n";
				out<<"\t\t\t\t\t\tOriginal Receipt";
			    out<<"\n\t\t---------------------------------------------------------------------------------------\n";
		            ifstream cartfile;
					cartfile.open("Cart.txt",ios::in);
			        out<<"\t\t---------------------------------------------------------------------------------------";
			        out<<"\n";
			        while(cartfile>>r.code>>r.styles>>r.req>>r.price) 
			        {
			        	out<<"\n";
			            out<<"\t\t\t\t"<<r.code<<"     "<<r.styles<<"      "<<r.price<<"      "<<r.req;
			            r.total=r.total+(r.price*r.req);
			        }
			    cartfile.close();
			    float dis=0;
			    if(r.total>=5000)
		    	dis=r.total*0.1;
			    else if(r.total>=10000)
			    dis=r.total*0.2;
			    else if(r.total>=20000)
			    dis=r.total*0.3;
			    float receipt;
			    receipt=r.total-dis;
			    
			out<<"\n\t\t---------------------------------------------------------------------------------------\n";
		    out<<"\t\tTotal Amount:          "<<r.total;
		    out<<"\n\t\tDiscounted Amount:     "<<dis;
		    out<<"\n\t\tInvoice Amount:        "<<receipt;
		    out<<"\n\t\t---------------------------------------------------------------------------------------\n";
			r.printingTime();
			checkout:
			out<<"\n";
		    out<<"\n\t\t\t******************** Thanks for your valuable time ********************\n\n\n";
		    sleep(10);
		    system("cls");
		    cout<<"\n";
		    char checkout;
			out<<"\n";
		    out<<"\n -->Thanks for your valuable time.\n\n--> Please Enter 'F' to fill feedback form\n--> Please Enter 'E' to exit:";
		    //char checkout;
		    cin>>checkout;
		    if(checkout=='F'||checkout=='f')
		    {
		    	userRating();
			}
			else if(checkout=='E'||checkout=='e')
			{
				remove("Cart.txt");
				exit (1);
			}
		    out<<"\n\t\t\tPlease Enter 'E' to exit:";
            cin>>checkout;
		    if(checkout=='E'||checkout=='e')
			{
				remove("Cart.txt");
				exit (1);
			}
	}
