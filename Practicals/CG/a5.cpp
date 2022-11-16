#include <iostream>
#include <stdlib.h>
#include <graphics.h>
using namespace std;
//declaring matrices in global scope
int opm[3][3];
int x=320,y=240;

void axis() {  
    cleardevice();
    line(0,240,640,240);
    line(320,0,320,480);
}


void zmtoopm() {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) opm[i][j]=0;
}

void mul(int np, int com[][3], int opm[3][3]) {
    int mul_arr[np][3];
    for(int i=0; i<np; i++) {
        for(int j=0;j<3;j++) {
            mul_arr[i][j]=0;
            for(int k=0;k<3;k++) {
                mul_arr[i][j]+= com[i][k] * opm[k][j];
            }
        }
    }

    for(int i=0;i<np;i++) for(int j=0;j<3;j++) com[i][j]=mul_arr[i][j];
}

void getinput(int np,int com[][3]) {
    for(int i=0;i<np;i++) {
        cout<<"Enter co-ordinates for "<<(i+1)<<"st vertex: ";
        cin>>com[i][0]>>com[i][1];
        com[i][2]=1;
    } 
}

void trans(int tx,int ty) {
    zmtoopm();
    opm[0][0]=opm[1][1]=opm[2][2]=1;
    opm[2][0]=tx; opm[2][1]=ty;
}

void draw(int np, int com[][3]) {
    for(int i=0;i<np;i++) {
        i<(np-1)? line(com[i][0]+x,y-com[i][1],com[i+1][0]+x,y-com[i+1][1]) : line(com[i][0]+x,y-com[i][1],com[0][0]+x,y-com[0][1]);
        
    }
}

void rotate() {

}

void scale(int sx, int sy) {
    zmtoopm();
    opm[2][2]=1;
    opm[1][1]=sy;
    opm[0][0]=sx;
}

int main() {
    int gm,gd;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);
    axis();

    delay(2000);
    system("clear");
    int np, ch;
    for(int i=0;i<90;i++) cout<<"_";
    cout<<"\n\tThis program can draw polygons and can perform operations on\n\t\tthem like translation, rotation and scaling\n";
    for(int i=0;i<90;i++) cout<<"_";
    cout<<"\n\n\n";

    cout<<"Taking input for co-ordinate matrix in order to perform further operations\n\n";
    cout<<"Enter the no. of vertices of polygon: ";
    cin>>np; int com[np][3]; cout<<endl;
    getinput(np, com);
    draw(np, com);
    delay(1000);
    while(1) {
        system("clear");
        cout<<"* * * * Menu * * * *\n\n1. Translation\n2. Rotation\n3. Scaling\n4. Change co-ordinate matrix\n5. Exit";
        cout<<"\n\nEnter your choice: "; cin>>ch;

        switch (ch) {
            case 1:
                int tx,ty;
                cout<<"Enter the value of tx and ty: "; cin>>tx>>ty;
                trans(tx,ty);
                mul(np, com, opm);
                axis();
                draw(np, com);
                break;
            case 2:
                break;
            case 3:
                int sx,sy;
                cout<<"Enter the value of sx and sy: "; cin>>sx>>sy;
                scale(sx,sy);
                mul(np, com, opm);
                axis();
                draw(np, com);
                break;
            case 4:
                cout<<endl;
                getinput(np, com);
                axis();
                draw(np, com);
                break;
            case 5:
                break;


        }
    }
    delay(5000);
}