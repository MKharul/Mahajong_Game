int tz=1;   //tells you in which tz do we have to place the block
int blockdetect=0;
int variableb=0;   // for the goal
int goalx=0,goaly=0;
int redx=0,redy=0;

int inL = 6;
int inR = 3;
int pwmL = 5; 
int pwmR = 4;

int led = 13;

int j = 11;

int flag = 0;
int flag1 = 0;
int count = 0;

//older variables :
  int JnCount=0;
  int ir1=0,ir2=0,ir3=0,ir4=0;    //temporary variables to temporarily store the polarity of IRs 
  int dir=1;                
  int botx=1,boty=0;
  int ElementArray1[7][6]={0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,5,0,0,0,1,0,1,5,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0};

  
  int ElementArray2[7][6]={0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0}; 
  // 0-node , 1-junction , 5-block      //take input from dry run
  int block1x=0,block1y=0, block2x=0,block2y=0;      //take input from dry run




void setup() {
for(int i=3; i<=6; i++)
{
  pinMode(i, OUTPUT);
}

for(int i=22; i<=29; i++)
{

  pinMode(i,INPUT);
}
 pinMode(j, INPUT);
 
    if(botx==1 && boty==0){
        GoStraight();
      }
  
    if(botx==1 && boty==1){
      TurnLeft(); 
      GoStraight();
      GoStraight();  
      TurnLeft();
      
      //detect the arrow
      // if(signal 1 detected from image processing){ tz=1;} 
      // else if(signal 2 detected from image processing){ tz=2;} 
  
      variableb=1;
      goalx=block1x;
      goaly=block1y;
      

      blockdetect=BlockDetection();
      if(blockdetect==1){
        DoTask();
      }
      else if(block1x==4){
        TurnRight();
        GoStraight();
        TurnRight();
      }
      else if(block1x==3){
        TurnRight();
        TurnRight();
      }
      else if(block1x==2){
        TurnLeft();
        GoStraight();
        TurnLeft();
      } 
      else if(block1x==1){
        TurnLeft();
        GoStraight();
        GoStraight();
        TurnLeft();
      } 
  
    }  

}

void loop() {

    
    if((goalx==block1x && goaly==block1y) || (goalx==block2x && goaly==block2y)){
      blockdetect=BlockDetection();
      if(blockdetect!=1){
        NextPath();  
      }
    }      
        
    else{
      NextPath();  
    }
          
  
}///void loop ends





void GoStraight(){
  
  //    make the bot go forward and stop when the next juntion or node or blovk is encountered
//  if(dir==1){ boty++; }  
//  else if(dir==2){ botx++; }  
//  else if(dir==3){ boty--; }  
//  else if(dir==4){ botx--; }  
int s0 = digitalRead(22);
int s1 = digitalRead(23); 
int s2 = digitalRead(24); 
int s3 = digitalRead(25);
int s4 = digitalRead(26);
int s5 = digitalRead(27);
int s6 = digitalRead(28);
int s7 = digitalRead(29);
int jp = digitalRead(j);

if((s0 == 0) && (s1 == 0) && (s2 == 0) && ((s3 == 1) || (s4 == 1)) && (s5 == 0) && (s6 == 0) && (s7 == 0))
{
  
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 80);
  analogWrite(pwmL, 80);
}

if((s0 == 0) && (s1 == 0) && (s2 == 0) && ((s3 == 1) || (s4 == 1)) && (s5 == 1) && (s6 == 0) && (s7 == 0))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 80);
  analogWrite(pwmL, 78);
}

if((s0 == 0) && (s1 == 0) && (s2 == 0) && ((s3 == 0) || (s4 == 0)) && (s5 == 1) && (s6 == 1) && (s7 == 0))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 80);
  analogWrite(pwmL, 75);
}

if((s0 == 0) && (s1 == 0) && (s2 == 0) && ((s3 == 0) || (s4 == 0)) && (s5 == 0) && (s6 == 1) && (s7 == 1))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 80);
  analogWrite(pwmL, 72);
}

if((s0 == 0) && (s1 == 0) && (s2 == 1) && ((s3 == 1) || (s4 == 1)) && (s5 == 0) && (s6 == 0) && (s7 == 0))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 78);
  analogWrite(pwmL, 80);
}

if((s0 == 0) &&(s1 == 1) && (s2 == 1) && ((s3 == 0) || (s4 == 0)) && (s5 == 0) && (s6 == 0) &&(s7 == 0))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 75);
  analogWrite(pwmL, 80);
}
if((s0 == 1) &&(s1 == 1) && (s2 == 0) && ((s3 == 0) || (s4 == 0)) && (s5 == 0) && (s6 == 0) &&(s7 == 0))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 72);
  analogWrite(pwmL, 80);
}
if((s0 == 0) && (s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 0)&&(s7 == 0))
{
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 0);
  analogWrite(pwmL, 0);
}

if(jp == 1)
{
  flag = 1;
 
}

if((jp == 0) && (flag == 1))
{
   if(dir==1){ boty++; }  
  else if(dir==2){ botx++; }  
  else if(dir==3){ boty--; }  
  else if(dir==4){ botx--; } 

  flag = 0;
}
}   //closing bracket for GoStraight


void TurnLeft(){
//  dir++;
//  if(dir==5) dir=1;
  //    make the bot turn left by 90 degree
int jp = digitalRead(j);
  delay(200);
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 0); 
  analogWrite(pwmL, 0);
  delay(1000);
  

  digitalWrite(inR,HIGH);
  digitalWrite(inL,LOW);
  analogWrite(pwmR, 80);
  analogWrite(pwmL, 80);
  delay(790);
 

  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 0);
  analogWrite(pwmL, 0);
  delay(1000);

  if(jp == 1)
{
  flag = 1;
 
}

if((jp == 0) && (flag == 1))
{
  dir++;
  if(dir==5) dir=1;

  flag = 0;
}
}   //closing bracket for TurnLeft


void TurnRight(){
//  dir--;
//  if(dir==0) dir=4;
  //    make the bot turn right by 90 degree
  int jp = digitalRead(j);
   delay(200);
  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 0);
  analogWrite(pwmL, 0);
  delay(1000);
  

  digitalWrite(inR,LOW);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 80);
  analogWrite(pwmL, 80);
  delay(790);
 

  digitalWrite(inR,HIGH);
  digitalWrite(inL,HIGH);
  analogWrite(pwmR, 0);
  analogWrite(pwmL, 0);
  delay(1000);

 if(jp == 1)
{
  flag = 1;
 
}

if((jp == 0) && (flag == 1))
{
  dir--;
  if(dir==0) dir=4;

  flag = 0;
}
}   //closing bracket for TurnRight



int BlockDetection(){

  if(botx==goalx && boty+1==goaly){         // when block is in front of the bot
    if(dir==2){
      TurnRight();
    }
    else if(dir==3)
    {
      TurnRight();
      TurnRight();
    }
    else if(dir==4)
    {
      TurnLeft();
    }
    DoTask();
    return 1;
  }
  

  else if(botx+1==goalx && boty==goaly){       //when block is on ur left
    if(dir==1)
    {
        TurnLeft();
    }
    else if(dir==3)
    {
      TurnRight();
    }
    else if (dir==4)
    {
      TurnRight();
      TurnRight();
    }
    DoTask();
    return 1;
  }
  

  else if (botx-1==goalx && boty==goaly)    //when block is on ur right 
  {
    if (dir==1)
    {
      TurnRight ();
    }
    else if (dir==2)
    {
      TurnRight ();
      TurnRight();
    }
    else if (dir==3)
    {
      TurnLeft();
    }
    DoTask();
    return 1;
  }
  

  else if(botx==goalx && boty-1==goaly)      //when the block is behind u
  {
    if(dir==1)
    {
      TurnRight();
      TurnRight();
    }
    else if (dir==2)
    { 
      TurnLeft();
    }
    else if (dir==4)
    {
      TurnRight();
    }
    DoTask();
    return 1;
  }

  else{
    return 0;
  }
    
}     //closing bracket of BlockDetection





void DoTask(){
  
  if(variableb==1){

    //Detect colour of block using ImageProcessing
    
    //if(colour is blue){
    //  pick the block
        
        ElementArray1[block1x][block1y]=1;
    
        DeadNodes1();
        blockdetect=0;

    //  if(tz==1){
    //    goalx=5;
    //    goaly=1;
    //  }  
    //  else if(tz==2){
    //    goalx=2;
    //    goaly=1;
    //  }  
    //  redx=block2x;
    //  redy=block2y;
    //  variableb=3;
    //}

    //else if(colour is red){
    //  redx=block1x;
    //  redy=block1y;
    //  goalx=block2x;
    //  goaly=block2y;
    //  variableb=2;
    //}

    
  }


  else if(variableb==2){
    
    //if(confirm if colour is blue){
    //  pick the block
        ElementArray1[block2x][block2y]=1;
        DeadNodes1();
        blockdetect=0;
    //  if(tz==1){
    //    goalx=5;
    //    goaly=1;
    //  
    //  }  
    //  else if(tz==2){
    //    goalx=2;
    //    goaly=1;
    //  }  
    //  variableb=3;
    //}
  }
  
  
  
  else if(variableb==3){

    if(dir==1){
      TurnRight();
      TurnRight();
    }
    else if(dir==2){
      TurnLeft();  
    }
    else if(dir==4){
      TurnRight();
    }
    //put block in tz
    blockdetect=0;
    variableb=4;
    goalx=redx;
    goaly=redy;    
  }


  else if(variableb==4){

    //pick red
    variableb=5;
    if(ElementArray1[5][1]==1){
      goalx=5;
      goaly=1;  
    }
    else if(ElementArray1[4][2]==1){
      goalx=4;
      goaly=2;  
    }
    ElementArray1[redx][redy]=1;
  
    DeadNodes1();

  }


  else if(variableb==5){

    if(botx==5 && boty==1){
      if(dir==2){
        TurnRight();  
      }
      else if(dir==3){
        TurnRight();  
        TurnRight();  
      }
      else if(dir==4){
        TurnLeft();  
      }
    //put block in  pit1
    GoStraight();

    }

    else if(botx==4 && boty==2){
      if(dir==1){
        TurnLeft();  
      }
      else if(dir==3){
        TurnRight();  
      }
      else if(dir==4){
        TurnRight();  
        TurnRight();  
      }
    //put block in  pit1
    GoStraight();
    TurnRight();
    
    }
    
    ElementArray1[5][2]=1;
    ElementArray1[5][3]=1;
    ElementArray1[5][4]=1;
    GoStraight();    

    botx=3;
    boty=3;
            
      int i=0,j=0;
      for(i=0;i<7;i++){
        for(j=0;j<6;j++){
          ElementArray1[i][j]=ElementArray2[i][j];  
        }  
      }  
    
    
    variableb=6;    
    goalx=2;
    goaly=1;
  
  }    


  else if(variableb==6){
    
    if(dir==1){
      TurnRight();  
      TurnRight();  
    }
    else if(dir==2){
      TurnLeft();  
    }
    else if(dir==4){
      TurnRight();  
    }

//      pick block
      goalx=3;
      goaly=3;
      variableb==7;
  }



  else if(variableb==7){

    if(dir==1){
      TurnLeft();  
    }
    else if(dir==3){
      TurnRight();  
    }
    else if(dir==4){
      TurnRight();  
      TurnRight();  
    }
    GoStraight();
    TurnRight();
    GoStraight();
    TurnLeft();
    
    //put the block in tz3
  }


}     //closing bracket of DoTask




void DeadNodes1(){
  int i=0,j=0,k=0;

  for(i=1;i<5;i++){
    for(j=2;j<5;i++){
      k=0;

      if(botx!=i && boty!=j){
        if(ElementArray1[i][j]!=5){
          if(ElementArray1[i][j+1]==0){   k++;  }      
          if(ElementArray1[i][j-1]==0){   k++;  }      
          if(ElementArray1[i+1][j]==0){   k++;  }      
          if(ElementArray1[i-1][j]==0){   k++;  }      
    
          if(k>=3){
            ElementArray1[i][j]=0;
          }
        }        
      }

    }  
  }
}





void NextPath(){
  

  if((botx==goalx) && (boty==goaly)){       //case1
  
      DoTask();
  
  }


  
  else if((botx==goalx) && (boty<goaly)){       //case 2

    if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
          TurnRight();
          TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }
    
    else if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
          TurnRight();
        }
      else if(dir==4){
          TurnRight();
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx+1][boty]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx-1][boty]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end of case 2  
  
  


  else if((botx==goalx) && (boty>goaly)){       //case 3

    if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
        TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
          TurnRight();
          TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
          TurnRight();
        }
      else if(dir==4){
          TurnRight();
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }
    
    else if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx+1][boty]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx-1][boty]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end of case 3  
  
  

  else if((botx<goalx) && (boty==goaly)){       //case 4

    if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
        TurnRight();
        }
      else if(dir==4){
          TurnRight();
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }
    
    else if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
          TurnRight();
          TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx][boty+1]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx][boty-1]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx-1][boty]==1){
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end  of case 4  
  
  


  else if((botx>goalx) && (boty==goaly)){       //case 5

    if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
        TurnRight();
        TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }
    
    else if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
          TurnRight();
        }
      else if(dir==4){
          TurnRight();
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx][boty+1]==1){
        TurnRight();
        GoStraight();  
      }
      else if(ElementArray1[botx][boty-1]==1){
        TurnLeft();
        GoStraight();  
      }
      else if(ElementArray1[botx+1][boty]==1){
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end of case 5  
  




  else if((botx>goalx) && (boty>goaly)){        //case 6

    if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
        TurnRight();
        TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }
    
    else if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
          TurnRight();
        }
      else if(dir==4){
          TurnRight();
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx][boty-1]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx][boty+1]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx+1][boty]==1){
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end of case 6  
  


  else if((botx>goalx) && (boty<goaly)){        //case 7

    if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
        TurnRight();
        TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
          TurnRight();
          TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
          TurnRight();
        }
      else if(dir==4){
          TurnRight();
          TurnRight();
        }
      GoStraight();
       if(variableb>4){
        DeadNodes1();
      }
   
      if(ElementArray1[botx][boty+1]==1){
        TurnRight();
        GoStraight();
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
    
    else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx-1][boty]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx+1][boty]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx][boty-1]==1){
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //case 7  
  


  else if((botx<goalx) && (boty>goaly)){        //case 8

    if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
        TurnRight();
        }
      else if(dir==4){
        TurnRight();
        TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }
    
    else if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
          TurnRight();
          TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx][boty-1]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx][boty+1]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx-1][boty]==1){
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end of case 8  
  


  else if((botx<goalx) && (boty<goaly)){        //case 9

     if(ElementArray1[botx][boty+1]==1){
      if(dir==2){
          TurnRight();
        }
      else if(dir==3){
          TurnRight();
          TurnRight();
        }
      else if(dir==4){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

    else if(ElementArray1[botx+1][boty]==1){
      if(dir==1){
          TurnLeft();
        }
      else if(dir==3){
        TurnRight();
        }
      else if(dir==4){
        TurnRight();
        TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }
    }

   else if(ElementArray1[botx][boty-1]==1){
      if(dir==1){
          TurnRight();
          TurnRight();
        }
      else if(dir==2){
          TurnLeft();
        }
      else if(dir==4){
          TurnRight();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx+1][boty]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx-1][boty]==1){
        TurnLeft();
        GoStraight();  
         if(variableb>4){
          DeadNodes1();
        }
     }
    }
    
    else if(ElementArray1[botx-1][boty]==1){
      if(dir==1){
          TurnRight();
        }
      else if(dir==2){
          TurnRight();
          TurnRight();
        }
      else if(dir==3){
          TurnLeft();
        }
      GoStraight();
      if(variableb>4){
        DeadNodes1();
      }

      if(ElementArray1[botx][boty+1]==1){
        TurnLeft();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx][boty-1]==1){
        TurnRight();
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
      else if(ElementArray1[botx-1][boty]==1){
        GoStraight();  
        if(variableb>4){
          DeadNodes1();
        }
      }
    }
  }     //end of case 9  
  
  
}     //closing bracket of nextpath














