#include"Ap_29demo.h"
//IO settings
int BUSY_Pin = D5; 
int RES_Pin = D0; 
int DC_Pin = D3; 
int CS_Pin = D1; 
int SCK_Pin = D8; 
int SDI_Pin = D10; 

#define EPD_W21_MOSI_0  digitalWrite(SDI_Pin,LOW)
#define EPD_W21_MOSI_1  digitalWrite(SDI_Pin,HIGH) 

#define EPD_W21_CLK_0 digitalWrite(SCK_Pin,LOW)
#define EPD_W21_CLK_1 digitalWrite(SCK_Pin,HIGH)

#define EPD_W21_CS_0 digitalWrite(CS_Pin,LOW)
#define EPD_W21_CS_1 digitalWrite(CS_Pin,HIGH)

#define EPD_W21_DC_0  digitalWrite(DC_Pin,LOW)
#define EPD_W21_DC_1  digitalWrite(DC_Pin,HIGH)
#define EPD_W21_RST_0 digitalWrite(RES_Pin,LOW)
#define EPD_W21_RST_1 digitalWrite(RES_Pin,HIGH)
#define isEPD_W21_BUSY digitalRead(BUSY_Pin)
////////FUNCTION//////
void driver_delay_us(unsigned int xus);
void driver_delay_xms(unsigned long xms);
void DELAY_S(unsigned int delaytime);     
void SPI_Delay(unsigned char xrate);
void SPI_Write(unsigned char value);
void EPD_W21_WriteDATA(unsigned char command);
void EPD_W21_WriteCMD(unsigned char command);
//EPD
void EPD_W21_Init(void);
void EPD_init(void);
void PIC_display(const unsigned char* picData_old,const unsigned char* picData_new);
void PIC1_display(const unsigned char* picData);
void EPD_sleep(void);
void EPD_refresh(void);
void lcd_chkstatus(void);
void PIC_display_Clean(void);
void PIC1_display_Clean(void);
unsigned char HRES,VRES_byte1,VRES_byte2;

void setup() {
   pinMode(BUSY_Pin, INPUT); 
   pinMode(RES_Pin, OUTPUT);  
   pinMode(DC_Pin, OUTPUT);    
   pinMode(CS_Pin, OUTPUT);    
   pinMode(SCK_Pin, OUTPUT);    
   pinMode(SDI_Pin, OUTPUT);    
}
//Tips//
/*When the electronic paper is refreshed in full screen, the picture flicker is a normal phenomenon, and the main function is to clear the display afterimage in the previous picture.
  When the local refresh is performed, the screen does not flash.*/
/*When you need to transplant the driver, you only need to change the corresponding IO. The BUSY pin is the input mode and the others are the output mode. */

void loop() {
  while(1)
  {
    //PICTURE1
    //EPD_init(); //EPD init
    //PIC1_display(gImage_temp); 
    //EPD_refresh();//EPD_refresh   
    //EPD_sleep();//EPD_sleep,Sleep instruction is necessary, please do not delete!!!
    //delay(5000);

    drawimage(gImage_temp, 2888);  //displays the picture in the .h file

    //PICTURE Clean
    EPD_init(); //EPD init
    PIC1_display_Clean(); //cleans the display
    EPD_refresh();//EPD_refresh   
    EPD_sleep();//EPD_sleep,Sleep instruction is necessary, please do not delete!!!
    delay(1000);

    //PICTURE1
    EPD_init(); //EPD init
    PIC_display(gImage_celcs); //displays the picture in the .h file
    EPD_refresh();//EPD_refresh   
    EPD_sleep();//EPD_sleep,Sleep instruction is necessary, please do not delete!!!
    delay(5000);

    //PICTURE Clean
    EPD_init(); //EPD init
    PIC_display_Clean(); //cleans the display
    EPD_refresh();//EPD_refresh   
    EPD_sleep();//EPD_sleep,Sleep instruction is necessary, please do not delete!!!
    delay(1000);

    while(1);

  }

}

void drawimage(const unsigned char* picName, int bufferSize)   
{    
    //PICTURE1
    EPD_init(); //EPD init
    PIC1_display(picName, bufferSize); 
    EPD_refresh();//EPD_refresh   
    EPD_sleep();//EPD_sleep,Sleep instruction is necessary, please do not delete!!!
    delay(5000);
}
/////////////////////delay//////////////////////////////////////
void driver_delay_us(unsigned int xus)  //1us
{
  for(;xus>1;xus--);
}
void driver_delay_xms(unsigned long xms) //1ms
{  
    unsigned long i = 0 , j=0;

    for(j=0;j<xms;j++)
  {
        for(i=0; i<256; i++);
    }
}
void DELAY_S(unsigned int delaytime)     
{
  int i,j,k;
  for(i=0;i<delaytime;i++)
  {
    for(j=0;j<4000;j++)           
    {
      for(k=0;k<222;k++);
                
    }
  }
}
//////////////////////SPI///////////////////////////////////
void SPI_Delay(unsigned char xrate)
{
  unsigned char i;
  while(xrate)
  {
    for(i=0;i<2;i++);
    xrate--;
  }
}


void SPI_Write(unsigned char value)                                    
{                                                           
    unsigned char i;  
   SPI_Delay(1);
    for(i=0; i<8; i++)   
    {
        EPD_W21_CLK_0;
       SPI_Delay(1);
       if(value & 0x80)
          EPD_W21_MOSI_1;
        else
          EPD_W21_MOSI_0;   
        value = (value << 1); 
       SPI_Delay(1);
       driver_delay_us(1);
        EPD_W21_CLK_1; 
        SPI_Delay(1);
    }
}

void EPD_W21_WriteCMD(unsigned char command)
{
  SPI_Delay(1);
  EPD_W21_CS_0;                   
  EPD_W21_DC_0;   // command write
  SPI_Write(command);
  EPD_W21_CS_1;
}
void EPD_W21_WriteDATA(unsigned char command)
{
  SPI_Delay(1);
  EPD_W21_CS_0;                   
  EPD_W21_DC_1;   // command write
  SPI_Write(command);
  EPD_W21_CS_1;
}



/////////////////EPD settings Functions/////////////////////
void EPD_W21_Init(void)
{
  EPD_W21_RST_0;    // Module reset
  driver_delay_xms(1000);//At least 10ms delay 
  EPD_W21_RST_1;
  driver_delay_xms(1000);//At least 10ms delay 
  
}
void EPD_init(void)
{
    HRES=0x98;            //152
    VRES_byte1=0x00;        //152
    VRES_byte2=0x98;
    EPD_W21_Init();  //Electronic paper IC reset
    EPD_W21_WriteCMD(0x06);         //boost soft start
    EPD_W21_WriteDATA (0x17);   //A
    EPD_W21_WriteDATA (0x17);   //B
    EPD_W21_WriteDATA (0x17);   //C     
    EPD_W21_WriteCMD(0x04);  //Power on
    lcd_chkstatus();        //waiting for the electronic paper IC to release the idle signal

    EPD_W21_WriteCMD(0x00);     //panel setting
    EPD_W21_WriteDATA(0x0f);    //LUT from OTP 160x296
    EPD_W21_WriteDATA(0x0d);    //VCOM to 0V fast

    EPD_W21_WriteCMD(0x61);     //resolution setting
    EPD_W21_WriteDATA (HRES);          
    EPD_W21_WriteDATA (VRES_byte1);   
    EPD_W21_WriteDATA (VRES_byte2);

    EPD_W21_WriteCMD(0X50);     //VCOM AND DATA INTERVAL SETTING      
    EPD_W21_WriteDATA(0x77);    //WBmode:VBDF 17|D7 VBDW 97 VBDB 57   WBRmode:VBDF F7 VBDW 77 VBDB 37  VBDR B7
  }
void EPD_refresh(void)
{
    EPD_W21_WriteCMD(0x12);     //DISPLAY REFRESH   
    driver_delay_xms(100);          //!!!The delay here is necessary, 200uS at least!!!     
    lcd_chkstatus();
} 
void EPD_sleep(void)
{
    EPD_W21_WriteCMD(0X50);  //VCOM AND DATA INTERVAL SETTING     
    EPD_W21_WriteDATA(0xf7); //WBmode:VBDF 17|D7 VBDW 97 VBDB 57    WBRmode:VBDF F7 VBDW 77 VBDB 37  VBDR B7   
    
    EPD_W21_WriteCMD(0X02);   //power off
    lcd_chkstatus();    //need to add

  
}


void PIC_display(const unsigned char* picData_old)
{
    unsigned int i;
    EPD_W21_WriteCMD(0x10);       //Transfer old data
    for(i=0;i<2888;i++)      
  {
    EPD_W21_WriteDATA(pgm_read_byte(&picData_old[i]));
  }
  
}
void PIC1_display(const unsigned char* picData, int size)
{
    unsigned int i;
    EPD_W21_WriteCMD(0x10);       //Transfer old data
    for(i=0;i<size;i++)      
  {
    EPD_W21_WriteDATA(pgm_read_byte(&picData[i]));
  }
  
}
void PIC1_display_Clean(void) //function to clear the display
{
    unsigned int i;
    EPD_W21_WriteCMD(0x10);       //Transfer old data
    for(i=0;i<2888;i++)      
  {
    EPD_W21_WriteDATA(0xff);
  }
  
}
void PIC_display_Clean(void) //function to clear the display
{
    unsigned int i;
    EPD_W21_WriteCMD(0x10);       //Transfer old data
    for(i=0;i<2888;i++)      
  {
    EPD_W21_WriteDATA(0xff);
  }
  
   EPD_W21_WriteCMD(0x13);        //Transfer new data
    for(i=0;i<2869;i++)      
  {
    EPD_W21_WriteDATA(0xff);
  }
}
void lcd_chkstatus(void)
{
  unsigned char busy;
  do
  {
    EPD_W21_WriteCMD(0x71);
    busy = isEPD_W21_BUSY;
    busy =!(busy & 0x01);        
  }
  while(busy);   
  driver_delay_xms(200);                       
}
//////////////////////////////////END/////////////////////////////////////////
