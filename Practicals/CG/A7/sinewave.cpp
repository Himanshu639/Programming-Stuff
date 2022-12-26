#include <graphics.h>
#include <cmath>
using namespace std;

int main() {
    int x=320,y=240;
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    
    for(float i=0;i<640;i+=0.2) {
        line(0,270,640,270);
        line(0,210,640,210);
        setcolor(9);
        circle(i*10,y-(10*sin(i)),20);
        delay(20);
        cleardevice();
    }
}