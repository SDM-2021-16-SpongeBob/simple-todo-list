#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

bool IsLogin = false; 
bool ISReading = false;
vector<string> task;    //vector stored unfinished tasks
vector<string> fitask;  //vector stored finished tasks
int tasks_undone = 0;   //for counting how many tasks remained 
int tasks_done = 0;     //for counting how many tasks done
string date;

static void fin(){
    vector<string>::iterator n;
    n = task.begin();
    int a = 0;
    int temp;
    cout << "Finish task( 1" << " to " << tasks_undone
    << " ): ";  
    cin >> temp;
    for(int i=0; i < temp; i++)
    {
        n++;
        a++;
    }
    fitask.push_back(task[a-1]);
    task.erase(n-1);
    tasks_undone--;
    tasks_done++;
    cout << endl;
}  

static void get_date(){
    time_t t = time(0); 
    struct tm * timeStruct = localtime(&t);
    string year = to_string(timeStruct->tm_year + 1900);
    string month = to_string(timeStruct->tm_mon + 1);
    string day = to_string(timeStruct->tm_mday);
    date = year + "-" + month + "-" + day+".txt";
}

static void save(){
    get_date();
    ofstream g(date); 
    g << "Uninished tasks: \n"; 
    for(int i = 0; i < tasks_undone; i++)
        {
            g << task[i] <<endl;
        }
    g << "Finished tasks: \n"; 
    for(int i = 0; i < tasks_done; i++)
        {
            g << fitask[i] <<endl;
        }
    g.close(); 
}

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
    g<< endl; 
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
    << " ): ";  
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
    cout << "Unfinished tasks: \n";
    for (int i = 0; i < tasks_undone; i++)
        {
            cout << i+1 << ". " << task[i] << endl << endl;
        }
    cout << "Finished tasks: \n";    
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
            display();
        else
            cout << "You haven't login!\n";
    if(temp == "fin")
        if(IsLogin)
            fin();
        else
            cout << "You haven't login!\n";
    if(temp == "save")
        if(IsLogin)
            save();
        else
            cout << "You haven't login!\n";
    if(temp == "test")
        IsLogin = true;
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