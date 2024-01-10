*----so do noi chan----------NHOM NXHN--------------
P1.4->D4
P1.5->D5
P1.6->D6
P1.7->D7
P1.1->RS
P1.2->E
P1.3->COI
P2.3->GAS
P2.4->LUA
GND->RW
------------------------HE THONG BAO CHAY------------------
*/
#include"msp430g2553.h"
#include "LCD_16x2.h"
#define COI BIT3
#define GAS BIT3
#define LUA BIT4
void main( void )
{
  WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer 
  P1DIR |= COI;      // 1.3 OUTPUT       
  P2DIR &= ~GAS;   // 2.3  INPUT     
  P2REN |= GAS;     // kich hoat resistor P2.3 keo len    
  P1OUT &= ~COI;   //1.3 INPUT
  P2DIR &= ~LUA;  //2.4 INPUT        
  P2REN |= LUA;   // kich hoat resistor P2.4 keo len    
   LCD_Init();    // khoi tao LCD
   LCD_Clear();   // xoa sach da hien thi tren LCD
   LCD_Goto(3,1); // vi tri hien thi
   LCD_PrintString("HE THONG"); //In ra man hinh 
   LCD_Goto(3,2); // vi tri hien thi
   LCD_PrintString("BAO CHAY"); //In ra man hinh 
  __delay_cycles(2000000); 
   LCD_Clear(); // xoa sach da hien thi tren LCD
    LCD_Goto(5,1); // vi tri hien thi
   LCD_PrintString("GVHD"); //In ra man hinh 
   LCD_Goto(0,2); // vi tri hien thi
   LCD_PrintString("Th.s:H-V-VIET");//In ra man hinh 
  __delay_cycles(2000000);
   LCD_Clear();// xoa sach da hien thi tren LCD
 while (1){
    if (!(P2IN & GAS)) {    
       P1OUT |= COI; // coi hoat dong
       LCD_Goto(3,1); // vi tri hien thi
       LCD_PrintString("CANH BAO"); //In ra man hinh 
       LCD_Goto(1,2); // vi tri hien thi
       LCD_PrintString("RO KHI GAS"); //In ra man hinh        
       __delay_cycles(2000000);
       LCD_Clear(); // xoa sach da hien thi tren LCD
    } 
    else{
           if(P2IN & LUA) {    
             P1OUT |= COI; // coi hoat dong
             LCD_Goto(3,1); // vi tri hien thi
             LCD_PrintString("CANH BAO"); //In ra man hinh 
             LCD_Goto(4,2); // vi tri hien thi
             LCD_PrintString("CO LUA"); //In ra man hinh 
             __delay_cycles(2000000);
             LCD_Clear(); // xoa sach da hien thi tren LCD
           }
          else if (!(P2IN & LUA)){
            P1OUT &=~COI; // coi tat
            LCD_Goto(5,1); // vi tri hien thi
            LCD_PrintString("IHOME"); //In ra man hinh 
            LCD_Goto(4,2); // vi tri hien thi
            LCD_PrintString("XIN CHAO"); //In ra man hinh 
             __delay_cycles(1000000);
             LCD_Clear();// xoa sach da hien thi tren LCD
             }
        }
    }             
}
