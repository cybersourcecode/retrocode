

rjmp Knopki            
 
Tabel:                                             
.db ~0x3F,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,0,0    
 

Knopki:
ldi r16, 0b1011_1111                        
out portd, r16         
nop
in r17, pinc                       
andi r17, 0x04                                                      
breq Algus
rjmp Knopki

 //desjatki  levii segment
Algus:                   
 
ldi r31, high(Tabel<<1)  
ldi r30, low(Tabel<<1)   
                                
Tsykkel:                   
lpm r16, z+               
cpi r16,0                                                     
breq Algus2                                            
out portd, r16            
rcall segment1            

push r31    
push r30

 //pravii segment
 Algus2:                   
 
ldi r31, high(Tabel<<1)  
ldi r30, low(Tabel<<1)   

tsikl2:
lpm r16, z+               
cpi r16,0                                       
breq memmo                
out portd, r16             
rcall segment2            
rcall aeg      
rjmp tsikl2

 Memmo:
 pop r30  
 pop r31
 rjmp Tsykkel

segment1:          //levii segm
sbi portb, 1       
cbi portb, 1
ret         

segment2:          //pravii segm
sbi portb, 0       
cbi portb, 0         
ret
