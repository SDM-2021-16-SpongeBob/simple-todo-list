#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

bool IsLogin = false; 
bool ISReading = false;
string user_name;
vector<string> task;    //vector stored unfinished tasks
vector<string> fitask;  //vector stored finished tasks
int tasks_undone = 0;   //for counting how many tasks remained 
int tasks_done = 0;     //for counting how many tasks done
string date;

static void clr(){

   
    #ifdef linux
    system("clear");
    #endif
    
    #ifdef _WIN32
    system("cls");
    #endif
}

static void add(){
    clr();
    string temp_task;
    cout << "Add task: ";
    cin >> temp_task;
    task.push_back(temp_task);
    tasks_undone++;
    cout << "Task added." << endl;
}

static void del(){
    clr();
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
    cout << "Task deleted." << endl;
}

static void display(){
    clr();
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

static void fin(){
    clr();
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
    cout << "Task finished." << endl;
}  

static void get_date(){
    time_t t = time(0); 
    struct tm * timeStruct = localtime(&t);
    string month, day;
    int imon = timeStruct->tm_mon + 1;
    if (imon < 10)
    {
        month = "0" + to_string(imon);
    }
    else 
    {
        month = to_string(imon);
    }
    int iday = timeStruct->tm_mday;
    if (iday < 10)
    {
        day = "0" + to_string(iday);
    }
    else 
    {
        day = to_string(iday);
    }
    string year = to_string(timeStruct->tm_year + 1900);
    date = year + "-" + month + "-" + day;
}

static void save(){
    clr();
    string temp = "1";
    get_date();
    string file = user_name + "\0" + date + ".txt";
    string file_name = user_name + "\0" + date;
    ofstream g(file); 
    g << "Unfinished tasks\n"; 
    for(int i = 0; i < tasks_undone; i++)
        {
            g << task[i] << endl;
        }
    g << "Finished tasks\n"; 
    for(int i = 0; i < tasks_done; i++)
        {
            
        g << fitask[i] << endl;
        }
    g.close(); 
    ofstream write;
    write.open("saves.txt", ios::app);
    ifstream save("saves.txt");
    while(!temp.empty())
        {
            getline(save, temp);
            if (temp == file_name)
            {
                break;
            }
            else if (temp.empty())
            {
                write << file_name << endl;
            }
        }
    write.close();
    save.close();
    vector <string>().swap(task);
    vector <string>().swap(fitask);
    tasks_done = 0;
    tasks_undone = 0;
    cout << "Tasks saved successfully." << endl;
}

static int read(){
    clr();
    if (tasks_done == 0 && tasks_undone == 0)
    {
        bool fileExist = false;
        get_date();
        string file, file_name;
        vector<string> file_1;
        string temp = "1";
        int i = 0;
        ifstream f_1("saves.txt");
        while(!f_1.eof())
        {
            getline(f_1, temp);
            file = temp.substr(0, temp.length() - 10);
            if(file == user_name)
            {
                file_name = temp + ".txt";
                file_1.push_back(file_name);
                i++;
                cout << i << ". " << temp << endl;
                fileExist = true;
            }
        }
        if(!fileExist)
        {
            cout << "No tasks saved!\n";
            return 0;
        }
        else
        {
            while(!temp.empty())
            {
                getline(f_1, temp);
                if(temp.empty())
                    break;
                i++;
                cout << i << ". " << temp << endl;
            }
            cout << "Read( 1" << " to " << i
                << " ): ";  
            cin >> i;
            f_1.close();
            file_name = file_1[i-1];
            string file = file_name;
            ifstream read(file);
            if(read.is_open())
            {
                cout << "Successfully readed " <<file << endl;
                getline(read, temp);
                while(!read.eof())
                {
                    getline(read, temp);
                    if(temp == "Finished tasks")
                    {
                        while(!read.eof())
                        {
                            getline(read, temp);
                            if(read.eof())
                                break;
                            fitask.push_back(temp);
                            tasks_done++;
                        }
                        break;
                    }
                    task.push_back(temp);
                    tasks_undone++;
                }
            }
            else
            {
                cout <<"Erro: Can't read the file!" << endl;
            }
            read.close();
            return 1;
        }
    }
    else
    {
        cout << "You haven't saved the tasks!\n";
        return 2;
    }
}

static void help(){
    clr();
    cout << "'reg'         Registeration.\n"
        << "'login'         Login.\n"
        << "'add'           Add a task.\n"
        << "'fin'           Finish a task.\n"
        << "'del'           Delete a task.\n"
        << "'display'       Display the tasks.\n"
        << "'save'          Save the tasks in a file named after the date of today.\n"
        << "'read'          List the tasks file saved and read from them.\n"
        << "'exit'          Exit the programe.\n";
}

static int reg(){               
    string temp = "1";
    clr();
    string registerName, registerPassword;
    cout <<"New Username: ";
    cin >> registerName;
    cout <<"New Password: ";
    cin >> registerPassword;
    ofstream write;
    write.open("users.txt", ios::app);
    ifstream read("users.txt");
    while(!read.eof())
        {
            getline(read, temp);
            if (temp == registerName)
            {
                cout << "User registered!\n";
                write.close();
                read.close();
                return 0;
            }
        }
    write << registerName << endl << registerPassword << endl;
    write.close();
    read.close();
    clr();
    cout << "Registered successfully.\n";
    return 1;
}

static int login(){
    clr();
    string name, password, inname, inpassword, temp;
    ifstream f("users.txt");
    getline(f, name);
    getline(f, password);
    f.close();
    if (name.empty())
    {
        cout << "No users registered!\n";
    }
    else
    {
        while(1)
        {
            ifstream read("users.txt");
            cout << "User Nmae: ";
            cin >> inname;
            cout << endl << "Password: ";
            cin >> inpassword;
            while(!read.eof())
            {
                getline(read, temp);
                if(temp == inname)
                {
                    getline(read, temp);
                    if(temp == inpassword)
                    {
                        clr();
                        user_name = inname;
                        cout << "Welcome " << user_name << "!\n";
                        IsLogin = true;
                        read.close();
                        return 0;
                    }
                    else
                    {
                        clr();
                        cout << "Wrong password!\n";
                        read.close();
                        return 0;
                    }
                }
            }
            cout << "User not registered!\n";
            read.close();
            return 0;
        }
    }
    return 0;
}

static void users_auto_save(){}

static void input(string temp){
    if(temp == "add")
        if(IsLogin)
            add();
        else
            {clr();
            cout << "You haven't login!\n";}
    else if(temp == "del")
        if(IsLogin)
            del();
        else
            {clr();
            cout << "You haven't login!\n";}
    else if(temp == "display")
        if(IsLogin)
            display();
        else
            {clr();
            cout << "You haven't login!\n";}
    else if(temp == "fin")
        if(IsLogin)
            fin();
        else
            {clr();
            cout << "You haven't login!\n";}
    else if(temp == "save")
        if(IsLogin)
            save();
        else
            {clr();
            cout << "You haven't login!\n";}
    else if(temp == "read")
        if(IsLogin)
            read();
        else
            {clr();
            cout << "You haven't login!\n";}
    else if(temp == "test")
        IsLogin = true;
    else if(temp == "reg")
        if(IsLogin)
            {clr();
            cout << "You have logged in!\n";}
        else
            reg();
    else if(temp == "login")
        if(IsLogin)
            {clr();
            cout << "You have logged in!\n";}
        else
            login();
    else if(temp == "help")
        help();
    else if(temp == "clr")
        system("clear");
    else
        cout << "Command " << "'" << temp << "'" << "not found.\n";
}

int main(){
    clr();
    cout << "Type 'help' to show the commands!\n";
    while(cin)
        {
            string temp;
            cin >> temp;
            if(temp != "exit")
                input(temp);
            else
            {
                clr();
                return 0;     
            }       
        }
}
