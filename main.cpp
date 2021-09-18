#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

bool IsLogin = false; 
vector<string> task;    //vector stored unfinished tasks
vector<string> fitask;  //vector stored finished tasks
int tasks_undone = 0;   
int tasks_done = 0;

static void fin(){}

static void save(){}

static void read(){}

static void help(){}

static void reg(){               
    string registerName, registerPassword;
    ofstream g("users.txt"); 
    cout <<endl <<"New Username: ";
    cin >> registerName;
    cout <<"New Password: ";
    cin >> registerPassword;
    g<<registerName; 
    g<<'\n'; 
    g<<registerPassword;
    g.close(); 
}

static void login(){
    string name, password, inname, inpassword;
    ifstream f("users.txt");
    getline(f, name);
    getline(f, password);
    if (name.empty())
    {
        cout << "No users registered!\n";
    }
    else
    {
        while(1)
        {
            cout << endl << "User Nmae: ";
            cin >> inname;
            cout << endl << "Password: ";
            cin >> inpassword;
            if (inname == name && inpassword == password)
            {
                IsLogin = true;
                system("clear");
                cout << "Welcome, " << name << "!\n";
                break;
            }
            else if (inname == "exit")
                break;
            else
                cout << "Wrong user name or password!\n";
        }
    }
}

static void users_auto_save(){}

//static string get_date(){}

static void add(){
    string temp_task;
    cout << "Add task: ";
    cin >> temp_task;
    task.push_back(temp_task);
    tasks_undone++;
    cout << endl;

}

static void del(){
    vector<string>::iterator n;
    n = task.begin();
    int temp;
    cout << "Delete task( 1" << " to " << tasks_undone
    << " )";  
    cin >> temp;
    for(int i=0; i < temp; i++)
    {
            n++;
        }
    task.erase(n-1);
    tasks_undone--;
    cout << endl;
}

static void display(){
    cout << "Tasks(unfinished): \n";
    for (int i = 0; i < tasks_undone; i++)
        {
            cout << i+1 << ". " << task[i] << endl << endl;
        }
    cout << "Tasks(finished): \n";    
    for (int i = 0; i < tasks_done; i++)
        {
            cout << i+1 << ". " << fitask[i] << endl << endl;
        }
}

static void input(string temp){
    if(temp == "add")
        if(IsLogin)
            add();
        else
            cout << "You haven't login!\n";
    if(temp == "del")
        if(IsLogin)
            del();
        else
            cout << "You haven't login!\n";
    if(temp == "display")
        if(IsLogin)
            add();
        else
            cout << "You haven't login!\n";
    if(temp == "reg")
        if(IsLogin)
            cout << "You have logged in!\n";
        else
            reg();
    if(temp == "login")
        if(IsLogin)
            cout << "You have logged in!\n";
        else
            login();
    if(temp == "clr")
        system("clear");
}

int main(){
    cout << "Type 'help' to show the commands!\n";
    while(cin)
        {
            string temp;
            cin >> temp;
            if(temp != "exit")
                input(temp);
            else
                return 0;            
        }
}