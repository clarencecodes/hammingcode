# hammingcode
Computer Organization & Architecture - Accessed Coursework
Question 5

Hamming code algorithm is able to detect single error and correct the single error. Please design a C program for the Raspberry Pi, to implement a Hamming SEC code. The C program supports 2 different length of the data stream: 8 bits data and 16 bits data.  

The inputs to be typed by users into the C program are: 
1.	The length of the data bits. 
2.	The data stream without error.
3.	Which data bit has error occurs.

For example, the user type these input to the C program:     
1.	The length of the data bits: 16 
2.	The data stream without error: 0011001100110011
3.	Which data bit has error occurs: 8	(it means the error data stream as 0011001110110011).

The outputs from the C program (please use printf(“”) command; ) are:
1.	The data stream with 1-bit error. 
2.	The check bits of the correct data stream, in the format of C16 C8 C4 C2 C1 C0. 
3.	The check bits of the data stream with 1-bit error, in the format of C’16 C’8 C’4 C’2 C’1 C’0.
4.	The syndrome word, in the format of C’’16 C’’8 C’’4 C’’2 C’’1 C’’0.
5.	Which position in the table including data bits and check bits gets error.
