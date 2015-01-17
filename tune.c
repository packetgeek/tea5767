#include <wiringPi.h> 
#include <wiringPiI2C.h> 
#include <stdio.h> 
#include <stdlib.h> 

//compile with gcc -lwiringPi -o tune tune.c

int main( int argc, char *argv[]) {

  //printf ("RPi - tea5767 Philips FM Tuner v0.3 \n") ;

  unsigned char radio[5] = {0};
  int fd;
  int dID = 0x60; // i2c Channel the device is on
  unsigned char frequencyH = 0;
  unsigned char frequencyL = 0;
  unsigned int frequencyB;

  double frequency = strtod(argv[1],NULL);

  frequencyB=4*(frequency*1000000+225000)/32768; //calculating PLL word
  frequencyH=frequencyB>>8;
  frequencyL=frequencyB&0XFF;

  //printf ("Frequency = "); printf("%f",frequency);
  //printf("\n"); // data to be sent

  radio[0]=frequencyH; //FREQUENCY H
  radio[1]=frequencyL; //FREQUENCY L
  radio[2]=0xB0; //3 byte (0xB0): high side LO injection is on,. 
  radio[3]=0x10; //4 byte (0x10) : Xtal is 32.768 kHz 
  radio[4]=0x00; //5 byte0x00)

  if((fd=wiringPiI2CSetup(dID))<0){
    printf("error opening i2c channel\n\r");
  }

  write (fd, (unsigned int)radio, 5) ;
  close (fd);
  return 0;
}
