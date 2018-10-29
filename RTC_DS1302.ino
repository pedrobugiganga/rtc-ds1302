#include <LiquidCrystal.h>
#include  <virtuabotixRTC.h> 
#define CLK 9
#define DAT 10
#define RST 8
virtuabotixRTC myRTC(CLK, DAT, RST);
LiquidCrystal lcd ( 7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  myRTC.setDS1302Time(00, 41, 12, 3, 23, 10, 2018);                                               
}

void loop() {
  myRTC.updateTime();

  lcd.setCursor(0,0); lcd.print(myRTC.dayofmonth);
  lcd.setCursor(2,0); lcd.print("/");
  lcd.setCursor(3,0); lcd.print(myRTC.month);
  lcd.setCursor(5,0); lcd.print("/");
  lcd.setCursor(6,0); lcd.print(myRTC.year);
  lcd.setCursor(0,1); lcd.print(myRTC.hours);
  lcd.setCursor(2,1); lcd.print(":");
  lcd.setCursor(3,1); lcd.print(myRTC.minutes);
  lcd.setCursor(5,1); lcd.print(":");
  lcd.setCursor(6,1); lcd.print(myRTC.seconds);
  if(myRTC.seconds == 0){
    lcd.setCursor(7,1); lcd.print(" ");
  }
  

  switch (myRTC.dayofweek){
    case 1 : lcd.setCursor(11,0); lcd.print("SEG"); break;
    case 2 : lcd.setCursor(11,0); lcd.print("TER"); break; 
    case 3 : lcd.setCursor(11,0); lcd.print("QUA"); break;
    case 4 : lcd.setCursor(11,0); lcd.print("QUI"); break;
    case 5 : lcd.setCursor(11,0); lcd.print("SEX"); break;
    case 6 : lcd.setCursor(11,0); lcd.print("SAB"); break;
    case 8 : lcd.setCursor(11,0); lcd.print("DOM"); break;
  }

  delay(1000);
}
