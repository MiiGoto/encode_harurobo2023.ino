#include <FlexCAN.h>

FlexCAN CANTransmitter(1000000);
CAN_message_t msg;

int servo = 1;
int syl1 = 0;
int syl2 = 1;
int motor = 5;
  
void setup(void)
{
  CANTransmitter.begin();
  Serial.begin(115200);
  delay(1000);

  msg.len = 8;
  msg.id = 0x200;
  for ( int idx = 0; idx < msg.len; ++idx ) {
    msg.buf[idx] = 0;
  }
}

void loop(void){
  msg.buf[0]= servo+syl1*2+syl2*4+(motor>0)*8+abs(motor)*16;
}

