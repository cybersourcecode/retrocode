
rjmp Tsykkel   
Start1:     
ldi r16, ~0x06
 rcall segment2
 rcall aeg       
ret  

Start2:     
ldi r16, ~0x5b
 rcall segment2
 rcall aeg       
ret  

start3:
ldi r16, ~0x4f
 rcall segment2
 rcall aeg
ret

start4:
ldi r16, ~0x66
 rcall segment2
 rcall aeg
ret

Tsykkel:           //KNOPKI  chtenie                                                      
 ldi r16, 0b1011_1111                        
out portd, r16         
nop
in r17, pinc                       
andi r17, 0x04                                                       
breq Start1

ldi r16, 0b1011_1111                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02 
breq Start2                                                           

ldi r16, 0b0111_1111                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02 
breq Start3 //start3   

ldi r16, 0b1110_1111                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x04
breq Start4  //start4  

ldi r16, 0b1110_1111                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02
breq Start5 // start5

ldi r16, 0b1101_1111                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02
breq start6 

ldi r16, 0b1111_1011                       
out portd, r16      
nop
in r17, pinc
andi r17, 0x04
breq start7

ldi r16, 0b1111_1011                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02
breq start8

ldi r16, 0b1111_0111                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02
breq start9 

ldi r16, 0b1111_1110                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02
breq start0 

ldi r16, 0b1111_1110                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x04
breq startE

ldi r16, 0b1111_1101                        
out portd, r16      
nop
in r17, pinc
andi r17, 0x02
breq startF
rjmp Tsykkel   

//////////////////////////////////////////////////////////
start9:
ldi r16, ~0x6f // 9
 rcall segment2
 rcall aeg
ret

startE:
ldi r16, ~0x79
 rcall segment2
 rcall aeg
ret
startF:
ldi r16, ~0x71
 rcall segment2
 rcall aeg
ret

Start0:     
ldi r16, ~0x3f
 rcall segment2
 rcall aeg       
ret

start5:
ldi r16, ~0x6d
 rcall segment2
 rcall aeg
ret
start6:
ldi r16, ~0x7d
 rcall segment2
 rcall aeg
ret
start7:
ldi r16, ~0x07
 rcall segment2
 rcall aeg
ret
start8:
ldi r16, ~0x7f
 rcall segment2
 rcall aeg
ret

segment2: 
out portd, r16 
sbi portb, 0                 ;pordi B esimene bitt pannakse ьheks
cbi portb, 0                 ;pordi B esimene bitt pannakse nulliks
ret  

