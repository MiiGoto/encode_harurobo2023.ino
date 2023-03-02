#include <FlexCAN.h>

FlexCAN CANTransmitter(1000000);
CAN_message_t msg;

int servo = 1;
int syl1 = 0;
int syl2 = 1;
int motor = 5;
  
void setup(){
}

void loop(){
  msg.buf[0]= servo+syl1*2+syl2*4+(motor>0)*8+abs(motor)*16;
}

