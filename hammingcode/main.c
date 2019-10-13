//
//  main.c
//  hammingcode
//
//  Comp. Org & Architecture
//  Question 5
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isInRange(int number, int start, int end);
int invertBit(int binaryNumber);

int main() {
    int inputLength = 0;
    int inputDataBitContainingError = 0;
    
    // Gets input of length of data bits
    printf("Please input the length of data bits (8 or 16): ");
    scanf("%d", &inputLength);
    
    // Checks if length entered is not 8 or 16
    if (inputLength != 8 && inputLength != 16) {
        printf("The length of data bits can only be 8 or 16.\n");
        main(); // restart the program
    }
    
    int inputDataStream[inputLength];
    int dataStreamContainingError[inputLength];
    
    // Gets input of data stream without error
    printf("Please input the data stream without error, from the MSB to the LSB\n");
    for (int i=inputLength; i>0; i--) {
        int tempDataBit = 0;
        printf("Please enter data bit D%d: ", i);
        scanf("%d", &tempDataBit);
        
        // check if databit entered is 0 or 1
        if (tempDataBit != 0 && tempDataBit != 1) {
            printf("The data bit entered can only be 0 or 1.\n");
            i++; // do not decrement counter
        } else {
            inputDataStream[i] = tempDataBit;
        }
    }
    
    // Gets input of bit position containing error
    printf("Please input the bit position containing the error: ");
    scanf("%d", &inputDataBitContainingError);
    
    // check if user entered a number which is out of range for the datastream
    while (isInRange(inputDataBitContainingError, 1, inputLength) == FALSE) {
        printf("The index entered is out of range. Please try again: ");
        scanf("%d", &inputDataBitContainingError);
        if (isInRange(inputDataBitContainingError, 1, inputLength) == TRUE) {
            break; // exit the loop once user enters an index within the range
        }
    }
    
    // Displays data stream without error
    printf("The data stream without error is: ");
    for (int i=inputLength; i>0; i--) {
        printf("%d", inputDataStream[i]);
    }
    printf("\n");
    
    // Displays data stream with 1-bit error
    printf("The data stream with 1-bit error is: ");
    for (int i=inputLength; i>0; i--) {
        if (i == inputDataBitContainingError) {
            dataStreamContainingError[i] = invertBit(inputDataStream[i]);
        } else {
            dataStreamContainingError[i] = inputDataStream[i];
        }
        printf("%d", dataStreamContainingError[i]);
    }
    
    // TODO: display check bits of the correct data stream, in the format of C16 C8 C4 C2 C1 C0.
    
    // TODO: display check bits of the data stream with 1-bit error, in the format of C’16 C’8 C’4 C’2 C’1 C’0.
    
    // TODO: display syndrome word, in the format of C’’16 C’’8 C’’4 C’’2 C’’1 C’’0.
    
    // TODO: display which position in the table including data bits and check bits gets error
    
    printf("\nEND OF PROGRAM.\n");
}

int isInRange(number, start, end) {
    if (number < start || number > end) {
        return FALSE; // false, number is not in range
    }
    return TRUE; // true, number is in range
}

int invertBit(int binaryNumber) {
    if (binaryNumber == 0) {
        return 1;
    } else {
        return 0;
    }
}

