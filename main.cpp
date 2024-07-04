#include<iostream>
#include<fstream>
using namespace std;

//class to define login signup and password
class temp{
    char choices;
    string userName,email,password;
    string searchName,searchPassword,searchmail;
    fstream file;
    public:
    void Login();
    void signUp();
    void Forget();
    void again();
}obj;

//main function to enter our choices for login signup and password
int main()
{
 char choice;
cout<<"\n1- Login";
cout<<"\n2- SignUp";
cout<<"\n3- Forget Password";
cout<<"\n4- Exit";
cout<<"\nEnter Your Choice :: ";
cin>>choice;
cin.ignore();

//switch case to choose between oue choices i.e choice
switch (choice)
{
case '1':
    obj.Login();
    break;

case '2':
    obj.signUp();
    break;

case '3':
    obj.Forget();
    break;

case '4':
    exit(0);
    break;

default:
cout<<"\nInvalid Choice";
    break;
}

}

//for signing 
void temp:: signUp()
{
    cout<<"\nEnter Your User Name::";
    getline(cin,userName);
    cout<<"\nEnter Your Email::";
    getline(cin,email);
    cout<<"\nEnter Your Password::";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<< "*"<<email<< "*"<<password<<endl;  //here we have save name email and password one after another astric
    file.close();
}

//for login
void temp :: Login()
{
    bool found = false;
    cout<<"---------LOGIN--------"<<endl;
    cout<<"Enter your User Name :: "<<endl;
    getline(cin,searchName);
    cout<<"Enter your Password :: "<<endl;
    getline(cin,searchPassword);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');  //when asteic is detected after name it will stop same way goes for other
    getline(file,email,'*');
    getline(file,password,'\n');
    while( !file.eof()){
        if (userName == searchName && password == searchPassword) {
            cout << "Login Successful________!" << endl;
            found = true;
            break;
        }
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (!found) {
        cout << "Invalid Username or Password" << endl;
        again();
    }
    
    file.close();

}


//for forgot password
void temp :: Forget()
{
bool found=false;
cout<<"Enter your User Name :: "<<endl;
getline(cin,searchName);
cout<<"Enter your Email :: "<<endl;
getline(cin,searchmail);
file.open("loginData.txt",ios :: in);
getline(file,userName,'*');
getline(file,email,'*');
getline(file,password,'\n'); 
while( !file.eof()){
 if (userName == searchName && password == searchPassword) {
            cout << "Login Successful________!" << endl;
            found = true;
            break;
        }
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (!found) {
        cout << "Invalid Username or Password" << endl;
    }
}

void temp :: again()
{   
    cout<< "1.Re-enter password or email" <<endl;
    cout<< "2.forget password"<<endl;
    cout<< "3.exit"<<endl;
    cout<< "Enter your Choice :: ";
    cin>>choices;
    cin.ignore();

switch (choices)
{
case '1':
    Login();
    break;

case '2':
    Forget();
    break;

case '3':
    exit(0);
    break;


default:
    cout << "Invalid choice\n";
    break;
}
}
