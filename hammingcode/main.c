//
//  main.c
//  hammingcode
//
//  Comp. Org & Architecture
//  Question 5
//

#include <stdio.h>

int isInRange(int number, int start, int end);

int main() {
    int inputLength = 0;
    int inputIndexOfDataBitContainingError = 0;
    
    // Gets input of length of data bits
    printf("Please input the length of data bits (8 or 16): ");
    scanf("%d", &inputLength);
    
    // Checks if length entered is not 8 or 16
    if (inputLength != 8 && inputLength != 16) {
        printf("The length of data bits can only be 8 or 16.\n");
        main(); // restart the program
    }
    
    int inputDataStream[inputLength-1];
    
    // Gets input of data stream without error
    printf("Please input the data stream without error, bit by bit\n");
    for (int i=0; i<=(inputLength-1); i++) {
        int tempDataBit = 0;
        printf("Please enter data bit D%d: ", i);
        scanf("%d", &tempDataBit);
        
        // check if databit entered is 0 or 1
        if (tempDataBit != 0 && tempDataBit != 1) {
            printf("The data bit entered can only be 0 or 1.\n");
            i--; // do not increment counter
        } else {
            inputDataStream[i] = tempDataBit;
        }
    }
    
    // Gets input of zero-based index of data bit containing error
    printf("Please input the zero-based index of the data bit containing the error: ");
    scanf("%d", &inputIndexOfDataBitContainingError);
    
    // check if user entered a number which is out of range for the datastream
    while (isInRange(inputIndexOfDataBitContainingError, 0, (int)sizeof(inputDataStream)) == 0) {
        printf("The index entered is out of range. Please try again: ");
        scanf("%d", &inputIndexOfDataBitContainingError);
        if (isInRange(inputIndexOfDataBitContainingError, 0, (int)sizeof(inputDataStream)) == 1) {
            break; // exit the loop once user enters an index within the range
        }
    }
    
    // Displays data stream without error
    // TODO: remove this once done with assignment
    printf("Your data stream without error is: ");
    for (int i=0; i<=(inputLength-1); i++) {
        printf("%d", inputDataStream[i]);
    }
    
    // TODO: display the data bit with 1-bit error
    
    // TODO: display check bits of the correct data stream, in the format of C16 C8 C4 C2 C1 C0.
    
    // TODO: display check bits of the data stream with 1-bit error, in the format of C’16 C’8 C’4 C’2 C’1 C’0.
    
    // TODO: display syndrome word, in the format of C’’16 C’’8 C’’4 C’’2 C’’1 C’’0.
    
    // TODO: display which position in the table including data bits and check bits gets error
    
    printf("\nEND OF PROGRAM.\n");
}

int isInRange(number, start, end) {
    if (number < start || number > end) {
        return 0; // false, number is not in range
    }
    return 1; // true, number is in range
}

