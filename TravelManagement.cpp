#include <bits/stdc++.h>
#include <fstream>    // To handle file system
#include <iomanip>    // For showing floating point values
#include <windows.h>  // For system-specific functions (optional, depending on usage)
void menu();

class ManageMenu{
    protected:
        string userName;
    public:
        ManageMenu(){
            cout<<"\n\n\n\n\n\n\\tEnter your name to continue as an Admin: ";
            cin.ignore();
            getline(cin , userName);
            system("cls");
            menu();
        }

        ~ManageMenu(){}
};

using namespace std;

class Customers {
public:
    string name, gender, address, mobileNo;
    int age;
    static int custId;
    char all[999];

    // Function to get customer details and save them in a file
    void getDetails() {
        ofstream outFile("oldCustomers.txt", ios::app); // Open file in append mode
        if (!outFile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        // Get user input
        cout << "Enter Customer ID: ";
        cin >> custId;
        cout << "Enter Customer Name: ";
        cin.ignore();   // To clear newline from the input buffer
        getline(cin, name);
        cout << "Enter Customer age: ";
        cin >> age;
        cout << "Enter Customer mobile number: ";
        cin >> mobileNo;
        cout << "Enter Customer address: ";
        cin.ignore();   // To clear newline from the input buffer
        getline(cin, address);
        cout << "Enter Customer gender: ";
        cin >> gender;

        // Write customer details to file
        outFile << "\nCustomer ID: " << custId
                << "\nName: " << name
                << "\nAge: " << age
                << "\nGender: " << gender
                << "\nAddress: " << address
                << "\nMobile No: " << mobileNo
                << "\n-------------------------" << endl;

        outFile.close(); // Close file
        cout << "\nSAVED\nNOTE: We saved your details record for future purposes.\n" << endl;
    }

    void showDetails(){
        ifstream in("oldCustomers.txt");
        {
            if(!in){
                cout<<"File Error!"<<endl;
            }
            while(!(in.eof())){
                in.getline(all,999);
                cout<< all<<endl;
            }
            in.close();
        }
    }
};

class Cabs{
    public:
        int cabChoice;
        int kilometers;
        float cabCost;
        static float lastCabCost;
        void cabDetails(){
            cout<<"We collaborated with the fastest , safest , and smartest cab services around the country"<<endl;
            cout<<"--------------------------------------- ABC CABS ---------------------------------------"<<endl;
            cout<<"1. Rent a Standard Cab - Rs.15 for 1KM"<<endl;
            cout<<"2. Rent a luxury cab - Rs.25 for 1KM"<<endl;

            cout<<"\nTo calculate the cost for your journey: "<<endl;
            cout<<"Enter which kind of cab you need: "<<endl;
            cin>>cabChoice;
            cout<<"Enter kilometers you have to travel :"<<endl;
            cin>>kilometers;

            int hireCab;
            if(cabChoice==1){
                cabCost= kilometers * 15;
                cout<<"\nYour tour cost is "<<cabCost<<" rupees for a Standard Cab"<<endl;
                cout<<"Press 1 to hire this cab: or\n";
                cout<<"Press 2 to select another cab:"<<endl;
                cin>>hireCab;

                system("cls");
                if(hireCab== 1 ){
                    lastCabCost = cabCost;
                     cout<<"\nYou successfully hired a standard cab... "<<endl;
                     cout<<" Goto Menu and take the recipt"<<endl;
                }
                else if(hireCab==2){
                    cabDetails();
                }
                else{
                    cout<<"Invalid Input ! Redirecting to previous menu...\nPlease Wait !"<<endl;
                    Sleep(999);
                    system("cls");
                    cabDetails();
                }
            }
            else if(cabChoice==2){
                cabCost= kilometers * 25;
                cout<<"\nYour tour cost is "<<cabCost<<" rupees for a Luxury Cab"<<endl;
                cout<<"Press 1 to hire this cab: or";
                cout<<"Press 2 to select another cab:"<<endl;
                cin>>hireCab;

                system("cls");
                if(hireCab== 1 ){
                    lastCabCost = cabCost;
                     cout<<"\nYou successfully hired a Luxury cab... "<<endl;
                     cout<<" Goto Menu and take the receipt"<<endl;
                }
                else if(hireCab==2){
                    cabDetails();
                }
                else{
                    cout<<"Invalid Input ! Redirecting to previous menu...\nPlease Wait !"<<endl;
                    Sleep(999);
                    system("cls");
                    cabDetails();
                }

            }
            else{
                cout<<"Invalid Input ! Redirecting to Main Menu...\nPlease Wait!"<<endl;
                Sleep(1100);
                system("cls");
                menu();
                
            }
            cout<<"\nPress any key to redirect Main Menu :";
            cin>>hireCab;
            system("cls");
            if(hireCab== 1){
                menu();
            }else{
                menu(); 
            }
        }
};

class Booking{
    public:
        int choiceHotel;
        int packChoice;
        static float hotelCost;

        void hotels(){
            string hotelNo[]={"Pacific" , "Avendra" , "ElephantBay"};
            for(int a =0 ; a<3 ; a++){
                cout<<a+1<<". Hotel "<<hotelNo[a]<<endl;
            }
            cout<<"\nCurrently we collaborated with above hotels!"<<endl;
            cout<< "Press any key to back or\nEnter number of hotel you want to book:";
            cin>>choiceHotel;
            system("cls");

            if(choiceHotel == 1){
                cout<<"------- WELCOME TO HOTEL PACIFIC -------\n"<<endl;
                cout<<"The Garden , food and beverage . Enjoy all you can drink , Stay cool and get chilled in summer sun. "<<endl;
                cout<<"Packages offered by Pacific:\n"<<endl;
                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facilities you need just for : Rs. 5000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium : Rs. 10000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive a Luxury at Pacific : Rs. 15000.00"<<endl;

                cout<<"\nPress another key to back or\n Enter Package Number you want to book: "<<endl;
                cin>>packChoice;

                if(packChoice==1){
                    hotelCost=5000.00;
                    cout<<"You have successfully booked Standard Pack at Pacific."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else if(packChoice==2){
                    hotelCost=10000.00;
                    cout<<"You have successfully booked Premium Pack at Pacific."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else if(packChoice==3){
                    hotelCost=15000.00;
                    cout<<"You have successfully booked Luxury Pack at Pacific."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid input! Redirecting to previous menu \nPlease Wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    hotels();
                }
                int gotoMenu;
                cout<<"\nPress any key to redirect to main menu:"<<endl;
                cin>>gotoMenu;
                if(gotoMenu== 1){
                    menu();
                }else{
                    menu();
                }
            }
            else if(choiceHotel == 2){
                cout<<"------- WELCOME TO HOTEL AVENDRA -------\n"<<endl;
                cout<<"The Garden , food and beverage . Enjoy all you can drink , Stay cool and get chilled in summer sun. "<<endl;
                cout<<"Packages offered by Avendra:\n"<<endl;
                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facilities you need just for : Rs. 5000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium : Rs. 10000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive a Luxury at Avendra : Rs. 15000.00"<<endl;

                cout<<"\nPress another key to back or\n Enter Package Number you want to book: "<<endl;
                cin>>packChoice;

                if(packChoice==1){
                    hotelCost=5000.00;
                    cout<<"You have successfully booked Standard Pack at Avendra."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else if(packChoice==2){
                    hotelCost=10000.00;
                    cout<<"You have successfully booked Premium Pack at Avendra."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else if(packChoice==3){
                    hotelCost=15000.00;
                    cout<<"You have successfully booked Luxury Pack at Avendra."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid input! Redirecting to previous menu \nPlease Wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    hotels();
                }
                int gotoMenu;
                cout<<"\nPress any key to redirect to main menu:"<<endl;
                cin>>gotoMenu;
                if(gotoMenu== 1){
                    menu();
                }else{
                    menu();
                }
            }
            
            else if(choiceHotel == 3){
                cout<<"------- WELCOME TO HOTEL ELEPHANTBAY -------\n"<<endl;
                cout<<"The Garden , food and beverage . Enjoy all you can drink , Stay cool and get chilled in summer sun. "<<endl;
                cout<<"Packages offered by ElephantBay:\n"<<endl;
                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facilities you need just for : Rs. 5000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium : Rs. 10000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive a Luxury at ElephantBay : Rs. 15000.00"<<endl;

                cout<<"\nPress another key to back or\n Enter Package Number you want to book: "<<endl;
                cin>>packChoice;

                if(packChoice==1){
                    hotelCost=5000.00;
                    cout<<"You have successfully booked Standard Pack at ElephantBay."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else if(packChoice==2){
                    hotelCost=10000.00;
                    cout<<"You have successfully booked Premium Pack at ElephantBay."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else if(packChoice==3){
                    hotelCost=15000.00;
                    cout<<"You have successfully booked Luxury Pack at ElephantBay."<<endl;
                    cout<<"Goto Menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid input! Redirecting to previous menu \nPlease Wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    hotels();
                }
                int gotoMenu;
                cout<<"\nPress any key to redirect to main menu:"<<endl;
                cin>>gotoMenu;
                if(gotoMenu == 1){
                    menu();
                }else{
                    menu();
                }
            }

        }
};
float Booking :: hotelCost;
float Cabs:: lastCabCost;
int Customers:: custId;
class Charges : public Booking , public Cabs , public Customers{
    public:
        void printBill(){
            ofstream outf("receipt.txt");
            {
                outf<<"---- ABC Travel Agency -----"<<endl;
                outf<<"---------- Receipt --------- "<<endl;
                outf<< "Customer Id: "<<Customers :: custId<<endl<<endl;
                outf<<"Description\t\t Total "<<endl;
                outf<<"Hotel cost: "<< fixed << setprecision(2)<<Booking:: hotelCost<<endl;
                outf<<"Tavel (Cab) cost: "<< fixed << setprecision(2)<<Cabs:: lastCabCost<<endl;
                outf<<"_____________________________"<<endl;
                outf<< "Total charge :\t\t"<< fixed << setprecision(2)<<Booking::hotelCost + Cabs:: lastCabCost<<endl;
                outf<<"_____________________________"<<endl;
                outf<<"-------- THANK YOU ----------"<<endl;
            }
            outf.close();
        }

        void showBill(){
            ifstream inf("receipt.txt");
            {
                if(!inf){
                    cout<<"There is no file called receipt!!!"<<endl;
                }
                while(!(inf.eof())){
                    inf.getline(all,999);
                    cout<<all<<endl;
                }
            }
            inf.close();
        }

};

 void menu(){
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout<<"\t\t      *ABC Travels * \n"<<endl;
    cout<<"------------------ Main Menu ------------------"<<endl;
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    cout<<"\t|\t\t\t\t\t|"<<endl;
    cout<<"\t|\tCustomer Management -> 1\t|"<<endl;
    cout<<"\t|\tCabs Management     -> 2\t|"<<endl;
    cout<<"\t|\tBookings Management -> 3\t|"<<endl;
    cout<<"\t|\tCharges & Bills     -> 4\t|"<<endl;
    cout<<"\t|\tExit                -> 5\t|"<<endl;
    cout<<"\t|\t\t\t\t\t|"<<endl;
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;

    cout<<"\nEnter you choice:";
    cin>>mainChoice;
    system("cls");
    Customers c1;
    Cabs c2;
    Booking c3;
    Charges c4;

    if(mainChoice==1){
        cout<<"-------Customers-------\n"<<endl;
        cout<<"1. Enter New Customer"<<endl;
        cout<<"2. See Old Customers"<<endl;
        cout<<"\nEnter Choice: ";
        cin>>inChoice;
        system("cls");
        if(inChoice==1){
            c1.getDetails();
        }
        else if(inChoice==2){
            c1.showDetails();
        }
        else{
            cout<<"Invalid input! Redirecting to previous menu \nPlease Wait!"<<endl;
            Sleep(1100);
            system("cls");
            menu();
        }
        cout <<"\nPress any key to redirect to main menu"<<endl;
        cin>>gotoMenu;
        system("cls");
        if(gotoMenu==1){
            menu();
        }
        else {
            menu();
        }
    }

    else if(mainChoice==2){
        c2.cabDetails();
    }
    else if(mainChoice==3){
        cout<<"--> Book a Luxury Hotel Using the System <--"<<endl;
        c3.hotels();
    }
    else if(mainChoice==4){
        cout<<"--> Get Your Receipt <--"<<endl;
        c4.printBill();

        cout<<"Your Receipt is already printed ,  You can get it from file path\n"<<endl;
        cout<<"To display your receipt on the screen  enter 1:\nOr Enter another key to go back in main menu"<<endl;
        cin>>gotoMenu;
        if(gotoMenu==1){
            system("cls");
            c4.showBill();
            cout<<"\nPress any key to redirect to main menu"<<endl;
            cin>>gotoMenu;
            system("cls");
            if(gotoMenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("cls");
            menu();
        }
    }

    else if(mainChoice==5){
        cout<<"--GOOD-BYE---"<<endl;
        Sleep(999);
        system("cls");
        menu();
    }
    else{
        cout<<"Invalid input! Redirecting to previous menu \nPlease Wait!"<<endl;
        Sleep(1100);
        system("cls");
        menu();
    }

}

int main(){
    ManageMenu start;
    return 0;
}
