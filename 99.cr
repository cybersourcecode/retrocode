

rjmp Button          
 
Tabel:                                             
.db ~0x3F,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,0,0    
 

Button:
ldi r16, 0b1011_1111                        
out portd, r16         
nop
in r17, pinc                       
andi r17, 0x04                                                      
breq Start
rjmp Button

 //left segment
Start:                   
 
ldi r31, high(Tabel<<1)  
ldi r30, low(Tabel<<1)   
 
Cikl:                   
lpm r16, z+               
cpi r16,0                                                     
breq Button                                           
out portd, r16            
rcall segment1            

push r31    
push r30

 //right segment
Start2:                   
 
ldi r31, high(Tabel<<1)  
ldi r30, low(Tabel<<1)   

Cikl2:
lpm r16, z+               
cpi r16,0                                       
breq memmo                
out portd, r16             
rcall segment2            
rcall time     
rjmp Cikl2

 Memmo:
 pop r30  
 pop r31
 rjmp Cikl

segment1:          //left segm
sbi portb, 1       
cbi portb, 1
ret         

segment2:          //right segm
sbi portb, 0       
cbi portb, 0         
ret
