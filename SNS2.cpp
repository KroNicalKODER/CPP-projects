#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int wherex(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int wherey(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

void gotoxy(int x, int y){
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class person{
protected:
    char name[30];
    int age;
    char email[50];
    char birthday[16];
public:
    // virtual void getData() = 0;
    //virtual void calcAge() = 0;
};
class user;
user findUserById(const char * id);

class post{
public:
    char postid[50];
    char body[900000];
    float coins;
    post(){
        coins = 0;
    }
    void showPost(){
        cout<<"post-id : "<<postid<<endl;
        cout<<"post : "<<body<<endl;
        cout<<"coins : "<<coins<<endl;
    }
    void getPostFromConsole(char *postids){
        strcpy(postid,postids);
        cout<<"What's on your mind : ";
        fflush(stdin);
        gets(body);
    }
    void getCoins(float c,char* id){
        coins+=c;

    }
};
class user : public person{                 //user(user-id)/post/ and user(user-id)/friends list
    int usernum;
    char password[50];
    char bio[100000];
    int numFriends;
    //int complaints;
    int numPost;
    float coins;
public:
    user(){
        numPost = 0;
        numFriends = 0;
        coins = 0;
    }
    void deletePost(char* postId){
        ifstream ifs;
        ofstream ofs;
        post p;
        char str[100];
        strcpy(str,userid);
        strcat(str,".dat");
        ifs.open(str,ios::binary|ios::in);
        while(ifs.read((char*)&p,sizeof(p))){
            if(strcmp(postId,p.postid)==0)
                continue;
            ofs.open("temp.dat",ios::out|ios::binary|ios::app);
            ofs.write((char*)&p,sizeof(p));
            ofs.close();
        }
        ifs.close();
        remove(str);
        rename("temp.dat",str);
    }
    void addCoins(char* posstid){
        post p;
        long t;
        float cns;
        char str[100];
        fstream ifs;
        strcpy(str,userid);
        strcat(str,".dat");
        ifs.open(str,ios::binary|ios::out|ios::in);
        while(!ifs.eof()){
            t = ifs.tellg();
            ifs.read((char*)&p,sizeof(p));
            if(strcmp(p.postid,posstid)==0){
                cout<<"Enter the amount you want to support : ";
                cin>>cns;
                coins+=cns;
                p.coins+=cns;
                ifs.seekg(t);
                ifs.write((char*)&p,sizeof(p));
                ifs.close();
                fstream fs;user u;
                fs.open("userDetails.dat",ios::in|ios::out|ios::binary);
                while(fs.read((char*)&u,sizeof(u))){
                    t = fs.tellg();
                    if(strcmp(u.userid,userid)==0){
                        u.numPost++;
                        fs.seekg(t);
                        fs.write((char*)&u,sizeof(u));
                        fs.close();
                    }
                }
                p.showPost();
                return;
            }
        }
        ifs.close();
    }
    char userid[100];
    void addFollower(user U){
        char fileName[100];user u;
        strcpy(fileName,userid);
        strcat(fileName,"friends");
        strcat(fileName,".dat");
        ofstream ofs;
        ofs.open(fileName,ios::binary|ios::app);
        ofs.write((char*)&U,sizeof(U));
        ofs.close();
        fstream fs;long t;
        fs.open("userDetails.dat",ios::in|ios::out|ios::binary);
        while(fs.read((char*)&u,sizeof(u))){
            t = fs.tellg();
            if(strcmp(u.userid,userid)==0){
                u.numFriends++;
                fs.seekg(t);
                fs.write((char*)&u,sizeof(u));
                fs.close();
            }
        }
    }
    void delFollower(user U){
        ifstream ifs;
        ofstream ofs;
        user Uread;
        char fileName[100];
        strcpy(fileName,userid);
        strcat(fileName,"friends");
        strcat(fileName,".dat");
        ifs.open(fileName,ios::binary|ios::in);
        while(ifs.read((char*)&Uread,sizeof(Uread))){
            if(strcmp(U.userid,Uread.userid)==0)
            continue;
            ofs.open("temp.dat",ios::binary|ios::out|ios::app);
            ofs.write((char*)&Uread,sizeof(Uread));
            ofs.close();
        }
        ifs.close();user u;
        remove(fileName);
        rename("temp.dat",fileName);
        fstream fs;long t;
        fs.open("userDetails.dat",ios::in|ios::out|ios::binary);
        while(fs.read((char*)&u,sizeof(u))){
            t = fs.tellg();
            if(strcmp(u.userid,userid)==0){
                u.numFriends--;
                fs.seekg(t);
                fs.write((char*)&u,sizeof(u));
                fs.close();
            }
        }
    }
    void showFollower(){
        char fileName[100];
        user U;
        int choice;
        strcpy(fileName,userid);
        strcat(fileName,"friends");
        strcat(fileName,".dat");
        ifstream ifs;
        ifs.open(fileName,ios::binary|ios::in);
        while(ifs.read((char*)&U,sizeof(U))){
            U.displayUserDataOnConsole();
            cout<<"Enter 1 to continue : ";
            cin>>choice;

        }
        ifs.close();
    }
    void getDataFromConsole(){
        cout<<"User Id : ";
        cin>>userid;
        cout<<"Name : ";
        cin>>name;
        cout<<"Age : ";
        cin>>age;
        cout<<"Birthday : ";
        cin>>birthday;
        cout<<"Email : ";
        cin>>email;
        cout<<"Bio : ";
        cin>>bio ;
        cout<<endl ;
    }
    void displayUserDataOnConsole(){
        cout<<"name : "<<name<<endl;
        cout<<"Email : "<<email<<endl;
        cout<<"userid : "<<userid<<endl;
        cout<<"coins : "<<coins<<endl;
        cout<<"numPost : "<<numPost<<endl;
        cout<<"numFriends : "<<numFriends<<endl;
    }
    void addPost(){
        post p;user u;           // creating user and post instances
        char id[50];
        strcpy(id,userid);
        char num[5];
        sprintf(num,"%d",numPost);       //inputting string num
        numPost++;
        fstream fs;long t;
        fs.open("userDetails.dat",ios::in|ios::out|ios::binary);
        while(fs.read((char*)&u,sizeof(u))){
            t = fs.tellg();
            if(strcmp(u.userid,userid)==0){
                u.numPost++;
                fs.seekg(t);
                fs.write((char*)&u,sizeof(u));
                fs.close();
            }
        }
        strcat(id,num);
        p.getPostFromConsole(id);
        char str[100];
        strcpy(str,userid);
        strcat(str,".dat");
        fs.open(str,ios::binary|ios::out|ios::app);
        fs.write((char*)&p,sizeof(p));
        fs.close();
    }
    void showPost(){
        post p;
        fstream fs;
        char str[100];
        strcpy(str,userid);
        strcat(str,".dat");
        fs.open(str,ios::binary|ios::in);
        while(!fs.eof()){
            fs.read((char*)&p,sizeof(p));
            p.showPost();
        }
        fs.close();
    }
};

class admin{
    char username[] = "adminhere";
    char password[] = "meranaam";
public:
    void deleteUser(user U){
        user u;
        ifstream ifs;
        ofstream ofs;
        ifs.open("userDetails.dat",ios::binary|ios::in);
        while(ifs.read((char*)&u),sizeof(u)){
            if(strcmp(U.userid,u.userid)==0)
                continue;
            ofs.open("temp.dat",ios::out|ios::app);
            ofs.write((char*)u,sizeof(u));
            ofs.close();
        }
        ifs.close();
        remove("userDetails.dat");
        rename("temp.dat","userDetails.dat");
    }
};

user findUserById(const char * id){
    user u;
    ifstream ifs;
    ifs.open("userDetails.dat",ios::binary|ios::app);
    while(ifs.read(((char*)&u),sizeof(u))){
        if(strcmp(u.userid,id)==0){
            ifs.close();
            return u;
        }
    }
    return u;
}

bool findUser(user& U){
    ifstream ifs;
    user Uread;
    ifs.open("userDetails.dat",ios::in|ios::binary);
    while(ifs.read((char*)&Uread,sizeof(Uread))){
        if(strcmp(U.userid,Uread.userid) == 0){
            ifs.close();
            return true;
        }
    }
    ifs.close();
    return false;
}

user addUser(){
    user u;
    u.getDataFromConsole();
    ofstream ofs;
    ofs.open("userDetails.dat",ios::app|ios::binary);
    ofs.write((char*)&u,sizeof(u));
    ofs.close();
    return u;
}

void displayAllUsers(){
     fstream fs;int ch;
     user U2;
    fs.open("userDetails.dat",ios::in|ios::binary);
    while(fs.read((char*)&U2,sizeof(U2))){
        U2.displayUserDataOnConsole();
        cout<<"\nEnter 1 to continue : ";
        cin>>ch;
    }
    fs.close();
}



int main(){
    char postid[50];
    user U = addUser();
    int ch;
    fstream fs;
    cout<<"Enter 1 for post : ";
    cin>>ch;
    if(ch == 1){
      U.addPost();
       cout<<"Continue";
       cin>>ch;

    }
    displayAllUsers();
    user fuser = findUserById("mrdvny");
    user fuser2 = findUserById("aryan");
    fuser.addFollower(fuser2);
    fuser.showFollower();
    fuser.displayUserDataOnConsole();
    fuser.addPost();
    cout<<"Enter postid : ";
    cin>>postid;
    fuser.addCoins(postid);

}
