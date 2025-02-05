#include <bits/stdc++.h>
using namespace std;
void drawboard(char *spaces);
void userinput(char *spaces,char user);
void computerinput(char *spaces,char computer);
bool winner(char *spaces,char user,char computer);
bool tie(char *spaces);
int main(){
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char user='x';
    char computer='o';
    bool running=true;
    drawboard(spaces);
    while(running){
    userinput(spaces,user);
    drawboard(spaces);
    if(winner(spaces,user,computer)){
        running=false;
        break;
    }
    else if(tie(spaces)){
        running=false;
        break;
    }
    computerinput(spaces,computer);
    drawboard(spaces);
    if(winner(spaces,user,computer)){
        running=false;
        break;
    }
    else if(tie(spaces)){
        running=false;
        break;
    }
    
    }
    return 0;
}
void drawboard(char *spaces){
   cout<<"-------------------\n";
    cout<<"|  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  |  "<<endl;
    cout<<"-------------------\n";
    cout<<"|  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  |  "<<endl;
    cout<<"-------------------\n";
    cout<<"|  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  |  "<<endl;
     cout<<"-------------------\n";
    
}
void userinput(char *spaces,char user){
    int num;
    do{
        cout<<"enter your choice (1-9) : ";
        cin>>num;
        num--;
        if(spaces[num]==' '){
            spaces[num]=user;
            break;
        }
    }while(!num>0 || !num<8);
}
void computerinput(char *spaces,char computer){
    int nu;
    srand(time(NULL));
    while(true){
        nu=rand()%9;
        if(spaces[nu]==' '){
            spaces[nu]=computer;
            break;
        }
    }
    
}
bool winner(char *spaces,char user,char computer){
    if(spaces[0]!=' '&&spaces[0]==spaces[1]&&spaces[1]==spaces[2]){
       spaces[0]==user ? cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[3]!=' '&&spaces[3]==spaces[4]&&spaces[4]==spaces[5]){
        spaces[3]==user ? cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[6]!=' '&&spaces[6]==spaces[7]&&spaces[7]==spaces[8]){
       spaces[6]==user ?cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[0]!=' '&&spaces[0]==spaces[3]&&spaces[3]==spaces[6]){
        spaces[0]==user ?cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[1]!=' '&&spaces[1]==spaces[4]&&spaces[4]==spaces[7]){
        spaces[1]==user?cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[2]!=' '&&spaces[2]==spaces[5]&&spaces[5]==spaces[8]){
        spaces[2]==user?cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[0]!=' '&&spaces[0]==spaces[4]&&spaces[4]==spaces[8]){
        spaces[0]==user ?cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else if(spaces[2]!=' '&&spaces[2]==spaces[4]&&spaces[4]==spaces[6]){
        spaces[2]==user?cout<<"\nyou won\n":cout<<"\nyou lost\n";
    }
    else{
        return false;
    }
    return true;
}
bool tie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' '){
            return false;
        }
    }
    cout<<"\nTie game\n";
    return true;
}






