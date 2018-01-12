  int JnCount=0;
 // int ir1=0,ir2=0,ir3=0,ir4=0;    //temporary variables to temporarily store the polarity of IRs 
  int dir=1;                
  int botx=1,boty=0;
  int ElementArray1[7][6]={{0}};      // 0-node , 1-junction , 5-block
  int ElementArray2[7][6]={{0}};      // 0-node , 1-junction , 5-block
  int block1x=0,block1y=0, block2x=0,block2y=0;
  int a=1;

void setup() {
}

void loop() {

  if(JnCount==0){
      GoStraight();
      botx=1,boty=1; 
      JnCount++;
  }
  
  //For detecting NODE
   /*if(digitalRead(1)==HIGH && 
      digitalRead(2)==HIGH && 
      digitalRead(3)==HIGH && 
      digitalRead(4)==LOW && 
      digitalRead(5)==LOW && 
      digitalRead(6)==HIGH && 
      digitalRead(7)==HIGH && 
      digitalRead(8)==HIGH && 
      ir1==0 && 
      ir2==0 && 
      ir3==0 && 
      ir4==0)
    {

      if(JnCount<=20){
          ElementArray1[botx][boty]=0;
        }      
      else if(JnCount>20){
          ElementArray2[botx][boty]=0;
        }      
  
    }*/   //closing bracket for node detection

  
  //For detecting JUNCTION
   else if(digitalRead(1)==HIGH && 
           digitalRead(2)==HIGH && 
           digitalRead(3)==HIGH && 
           digitalRead(4)==HIGH && 
           digitalRead(5)==HIGH && 
           digitalRead(6)==HIGH && 
           digitalRead(7)==HIGH &&            //use junction pulse pin 
           digitalRead(8)==HIGH && 
           ir1==0 && 
           ir2==0 && 
           ir3==0 && 
           ir4==0)
   {   
      if(JnCount<=20){
          ElementArray1[botx][boty]=1;
        }      
      else if(JnCount>20){
          ElementArray2[botx][boty]=1;
        }      
  
    }   //closing bracket for junction detection


  
  //For detecting BLOCKS
  /* else if(digitalRead(1)==LOW && 
           digitalRead(2)==LOW && 
           digitalRead(3)==LOW && 
           digitalRead(4)==HIGH && 
           digitalRead(5)==HIGH && 
           digitalRead(6)==LOW && 
           digitalRead(7)==LOW && 
           digitalRead(8)==LOW && 
           ir1==1 && 
           ir2==1 && 
           ir3==1 && 
           ir4==1)*/
  /* {   

      if(JnCount<=20){
          ElementArray1[botx][boty]=5;
        }      
      else if(JnCount>20){
          ElementArray2[botx][boty]=5;
        }      

      if(block1x==0 && block1y==0){
           block1x=botx;
           block1y=boty;
     
        }
      else if(block2x==0 && block2y==0){
           block2x=botx;
           block2y=boty;
     
        }
    
    }*/   //closing bracket for block detection


  switch(JnCount){    //to tell the bot in which  direction to go in

       
      case 1: 
        GoStraight();   
        break;      

      case 2:
        GoStraight();   
        break;      
      
      
      case 3:
        GoStraight();   
        break;      
      
      case 4:
      if(a==1)
      {
        TurnLeft();
        a=0;
        Serial.println("Left");
      }
      a=1;
      GoStraight();
      break;
      
      case 5:
      if(a==1)
      {
        TurnLeft();
        a=0;
        Serial.println("Left");
      }
      a=1;
      GoStraight();
      break;       
      

      case 6:
        GoStraight();   
        break;      
      
      case 7:
        GoStraight();   
        break;      
//      
//      case 8:
//      if(a==1)
//      {
//        TurnRight();
//        a=0;
//        Serial.println("Left");
//      }
//      a=1;
//        GoStraight();
//        break;      
//      
//      case 9:
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//      
//      case 10:
//        GoStraight();   
//        break;      
//      
//      case 11:
//        GoStraight();   
//        break;      
//      
//      case 12:
//        TurnLeft();
//        Serial.println("Left");
//        GoStraight();
//        break;      
//
//      case 13:
//        TurnLeft();
//        Serial.println("Left");
//        GoStraight();
//        break;      
//      
//      case 14:
//        GoStraight();   
//        break;      
//      
//      case 15: 
//        GoStraight();   
//        break;      
//      
//      case 16:
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;
//      
//      case 17:
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//      
//      case 18: 
//        GoStraight();   
//        break;      
//      
//      case 19: 
//        GoStraight();   
//        break;      
//      
//      case 20: 
//        GoStraight();   
//        botx=5;
//        boty=4;
//        break;      
//      
//      case 21: 
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//      
//      case 22: 
//        GoStraight();   
//        break;      
//      
//      case 23: 
//        GoStraight();   
//        break;      
//      
//      case 24: 
//        GoStraight();   
//        break;      
//      
//      case 25: 
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//    
//      case 26: 
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//    
//      case 27: 
//        GoStraight();   
//        break;      
//      
//      case 28:
//        TurnLeft();
//        Serial.println("Left");
//        GoStraight();
//        break;      
//
//      case 29:
//        TurnLeft();
//        Serial.println("Left");
//        GoStraight();
//        break;      
//      
//      case 30: 
//        GoStraight();   
//        break;      
//      
//      case 31: 
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//    
//      case 32: 
//        TurnRight();
//        Serial.println("Right");
//        GoStraight();
//        break;      
//    
//      case 33: 
//        GoStraight();   
//        break;      
//    
//      case 34:
//        ElementArray1[5][2]=0;
//        ElementArray1[5][3]=0;
//        ElementArray1[5][4]=0;
//
//        ElementArray2[1][0]=5;
//        ElementArray2[2][0]=5;
//        ElementArray2[3][0]=5;
//
//        DryRunDeadNodes1();
//        DryRunDeadNodes1();
//        
//        SendSignal();
//        break;
//    
//    
//    
    }   //closing bracket for switch

    JnCount++;

}   //closing bracket for void loop


void TurnLeft(){
  dir++;
  if(dir==5) dir=1;
  //    make the bot turn left by 90 degree
  
}   //closing bracket for TurnLeft




void TurnRight(){
  dir--;
  if(dir==0) dir=4;

  
  //    make the bot turn right by 90 degree
}   //closing bracket for TurnRight




void GoStraight(){
  //    make the bot go forward and stop when the next juntion or node or blovk is encountered
  if(dir==1){ boty++; }  
  else if(dir==2){ botx++; }  
  else if(dir==3){ boty--; }  
  else if(dir==4){ botx--; }  




}   //closing bracket for GoStraight

void SendSignal(){
  // send a signal and end the loop

  //stop the motors chnagung the all the dir  and in pins to high value
  
}


void DryRunDeadNodes1(){
  int i=0,j=0,k=0;

  for(i=1;i<5;i++){
    for(j=2;j<5;i++){
      k=0;

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


