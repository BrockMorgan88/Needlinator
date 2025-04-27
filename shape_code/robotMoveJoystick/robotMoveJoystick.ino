#include <Servo.h>

Servo ml,mr;    

int i,j;

float pi= 3.1428;
float l=11.5; //l = 6 cm length of link 

float x,y,dl,dr,hl,hr;
float pl1,pl2,pr1,pr2;
int tl,tr;

float angle_left(float x, float y){
  Serial.println("Left : ");
  
  dl= sqrt((x*x)+(y*y)); //distace between origin left and (x,y) point
  
  hl=sqrt((l*l)-((dl/2)*(dl/2))); //height of the triangle
  
  pl1=atan2(hl,dl/2); // phi 1, angle between d and axis
  
  pl2=atan2(y,x); // phi 2, angle between d and l 
  
  tl= (pl1+pl2)*180/pi; // anglie between axis and l

  Serial.println(hl);
  Serial.println(pl1*180/pi);
  Serial.println(pl2*180/pi);
  Serial.println(tl);
  return tl;
  }

float angle_right(float x, float y){
  x-=6;

  Serial.println("Right : ");
  
  dr= sqrt(((x)*(x))+(y*y)); //distace between origin right and (x,y) point

  hr=sqrt((l*l)-((dr/2)*(dr/2))); //height of the triangle

  pr1=atan2(hr,dr/2); // phi 1, angle between d and axis

  pr2= atan2(y,x); // phi 2, angle between d and l 

  tr=(pr2-pr1)*180/pi;

  Serial.println(hr);
  Serial.println(pr1*180/pi);
  Serial.println(pr2*180/pi);
  Serial.println(tr);
  return tr;
  }

// Extreme Left Point
void xleft(){ 
  mr.write(110);
  ml.write(110);
  }

// Extreme Right Point
void xright(){ 
  mr.write(45);
  ml.write(45);
  }


// Extreme Top Point
void xtop(){
  mr.write(90);
  ml.write(90);
}

//Extreme Bottom Point 
void xbottom(){
  mr.write(60);
  ml.write(120);
}

void vertical_straight_line(){
  x=3;
  y=6;

  for(y=6;y<12;y+=0.5){ 
    ml.write(angle_left(x,y));
    mr.write(angle_right(x,y));
    delay(50);
  }

  for(y=11;y>5;y-=0.5){ 
    ml.write(angle_left(x,y));
    mr.write(angle_right(x,y));
    delay(50);
   }
}


void horizontal_straight_line(){
  x=0;
  y=6;
  for (x;x<7;x+=1){
    ml.write(angle_left(x,y));
    mr.write(angle_right(x,y));    
    delay(500);
   }
  
}

 
void setup() {
  ml.attach(8);  
  mr.attach(9);
  mr.write(90);
  ml.write(90);
  delay(5000);
  Serial.begin(9600);
}

void loop() {
  int a[8][2]={{1, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 2}, {3, 1}, {2, 1}}; //making 0
  //int a[12][2]={{1, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 5}, {3, 5}, {4, 4}, {5, 3}, {5, 2}, {4, 1}, {3, 0}, {2, 0}}; //making O or dimond
  //int a[12][2]={{0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5},{5,5}, {4,4}, {3,3}, {2,2}, {1,1}, {0,0}};// making / digonal line
  //int a[20][2]={{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{1,5},{2,5},{3,5},{4,5},{5,5},{5,4},{5,3},{5,2},{5,1},{5,0},{4,0},{3,0},{2,0},{1,0}}; // making [] square
 
  for (i=0;i<sizeof(a)/4;i+=1){
    x=a[i][0];
    y=a[i][1]+5;
    
    ml.write(angle_left(x,y));
    mr.write(angle_right(x,y));
    delay(300);  
  }
 
  x=1;
  y=1*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=0;
  y=2*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=1;
  y=3*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=2;
  y=3*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=3;
  y=3*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=4;
  y=2*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=3;
  y=1*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);

  x=2;
  y=1*2;
  y+=3;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  delay(500);
  
  
  x=3;
  y=11;
  ml.write(angle_left(x,y));
  mr.write(angle_right(x,y));
  
  
  xtop();
  delay(1000);
  xright();
  delay(300);
  xbottom();
  delay(1000);
  xleft();
  delay(300);
  
}
