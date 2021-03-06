#include <wiringPi.h> 
#include <wiringPiI2C.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

//compile with gcc -lm -lwiringPi -o unmute unmute.c

//note: This really doesn't unset the mute flag
//      Rather, it just sets the radio back to normal mode
//      (i.e., reads the frequency and resends it)

int main( int argc, char *argv[]) {

  unsigned char radio[5] = {0};
  int fd;
  int dID = 0x60; // i2c Channel the device is on
  double frequency = 0;
  unsigned char frequencyH = 0;
  unsigned char frequencyL = 0;
  unsigned int frequencyB;

  //open access to the board, send error msg if fails
  if((fd=wiringPiI2CSetup(dID))<0){
     printf("error opening i2c channel\n\r");
  }
  read(fd,radio,5);

  frequency=((((radio[0]&0x3F)<<8)+radio[1])*32768/4-225000)/10000;
  frequency = round(frequency * 10.0)/1000.0;
  frequency = round(frequency * 10.0)/10.0;
  //printf ("Frequency = "); printf("%f\n",frequency);

  frequencyB=4*(frequency*1000000+225000)/32768; //calculating PLL word
  frequencyH=frequencyB>>8;
  frequencyL=frequencyB&0XFF;

  radio[0]=frequencyH; //FREQUENCY H
  radio[1]=frequencyL; //FREQUENCY L
  radio[2]=0xB0; //3 byte (0xB0): high side LO injection is on,. 
  radio[3]=0x10; //4 byte (0x10) : Xtal is 32.768 kHz 
  radio[4]=0x00; //5 byte0x00)

  write (fd, (unsigned int)radio, 5) ;

  close(fd);
  return 0;
}


