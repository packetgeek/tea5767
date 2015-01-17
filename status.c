#include <wiringPi.h> 
#include <wiringPiI2C.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

//compile with gcc -lm -lwiringPi -o status status.c
int main( int argc, char *argv[]) {

  unsigned char radio[5] = {0};
  int fd;
  int dID = 0x60; // i2c Channel the device is on
  double frequency = 0;

  //open access to the board, send error msg if fails
  if((fd=wiringPiI2CSetup(dID))<0){
     printf("error opening i2c channel\n\r");
  }
  read(fd,radio,5);

  frequency=((((radio[0]&0x3F)<<8)+radio[1])*32768/4-225000)/10000;
  frequency = round(frequency * 10.0)/1000.0;
  frequency = round(frequency * 10.0)/10.0;
  printf ("Frequency = "); printf("%f\n",frequency);

  close(fd);
  return 0;
}
