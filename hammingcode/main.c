//
//  main.c
//  hammingcode
//
//  Comp. Org & Architecture
//  Question 5
//

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int isInRange(int number, int start, int end);
int invertBit(int binaryNumber);
int convertBinaryToDecimal(int binaryNumber[], int numberOfBits);

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
    
    // Get input of data bit containing error
    printf("Please input the data bit containing the error: ");
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
    printf("\n");
    
    // Display check bits of the correct data stream
    printf("The check bits of the correct data stream: ");
    int c16, c8, c4, c2, c1;
    if (inputLength == 8) {
        c8 = inputDataStream[5]^inputDataStream[6]^inputDataStream[7]^inputDataStream[8];
        c4 = inputDataStream[2]^inputDataStream[3]^inputDataStream[4]^inputDataStream[8];
        c2 = inputDataStream[1]^inputDataStream[3]^inputDataStream[4]^inputDataStream[6]^inputDataStream[7];
        c1 = inputDataStream[1]^inputDataStream[2]^inputDataStream[4]^inputDataStream[5]^inputDataStream[7];
        printf("%d%d%d%d", c8, c4, c2, c1);
    } else {
        c16 = inputDataStream[12]^inputDataStream[13]^inputDataStream[14]^inputDataStream[15]^inputDataStream[16];
        c8 = inputDataStream[5]^inputDataStream[6]^inputDataStream[7]^inputDataStream[8]^inputDataStream[9]^inputDataStream[10]^inputDataStream[11];
        c4 = inputDataStream[2]^inputDataStream[3]^inputDataStream[4]^inputDataStream[8]^inputDataStream[9]^inputDataStream[10]^inputDataStream[11]^inputDataStream[15]^inputDataStream[16];
        c2 = inputDataStream[1]^inputDataStream[3]^inputDataStream[4]^inputDataStream[6]^inputDataStream[7]^inputDataStream[10]^inputDataStream[11]^inputDataStream[13]^inputDataStream[14];
        c1 = inputDataStream[1]^inputDataStream[2]^inputDataStream[4]^inputDataStream[5]^inputDataStream[7]^inputDataStream[9]^inputDataStream[11]^inputDataStream[12]^inputDataStream[14]^inputDataStream[16];
        printf("%d%d%d%d%d", c16, c8, c4, c2, c1);
    }
    printf("\n");
    
    // Display check bits of the data stream with 1-bit error
    printf("The check bits of the data stream with 1-bit error: ");
    int c16Error, c8Error, c4Error, c2Error, c1Error;
    if (inputLength == 8) {
        c8Error = dataStreamContainingError[5]^dataStreamContainingError[6]^dataStreamContainingError[7]^dataStreamContainingError[8];
        c4Error = dataStreamContainingError[2]^dataStreamContainingError[3]^dataStreamContainingError[4]^dataStreamContainingError[8];
        c2Error = dataStreamContainingError[1]^dataStreamContainingError[3]^dataStreamContainingError[4]^dataStreamContainingError[6]^dataStreamContainingError[7];
        c1Error = dataStreamContainingError[1]^dataStreamContainingError[2]^dataStreamContainingError[4]^dataStreamContainingError[5]^dataStreamContainingError[7];
        printf("%d%d%d%d", c8Error, c4Error, c2Error, c1Error);
    } else {
        c16Error = dataStreamContainingError[12]^dataStreamContainingError[13]^dataStreamContainingError[14]^dataStreamContainingError[15]^dataStreamContainingError[16];
        c8Error = dataStreamContainingError[5]^dataStreamContainingError[6]^dataStreamContainingError[7]^dataStreamContainingError[8]^dataStreamContainingError[9]^dataStreamContainingError[10]^dataStreamContainingError[11];
        c4Error = dataStreamContainingError[2]^dataStreamContainingError[3]^dataStreamContainingError[4]^dataStreamContainingError[8]^dataStreamContainingError[9]^dataStreamContainingError[10]^dataStreamContainingError[11]^dataStreamContainingError[15]^dataStreamContainingError[16];
        c2Error = dataStreamContainingError[1]^dataStreamContainingError[3]^dataStreamContainingError[4]^dataStreamContainingError[6]^dataStreamContainingError[7]^dataStreamContainingError[10]^dataStreamContainingError[11]^dataStreamContainingError[13]^dataStreamContainingError[14];
        c1Error = dataStreamContainingError[1]^dataStreamContainingError[2]^dataStreamContainingError[4]^dataStreamContainingError[5]^dataStreamContainingError[7]^dataStreamContainingError[9]^dataStreamContainingError[11]^dataStreamContainingError[12]^dataStreamContainingError[14]^dataStreamContainingError[16];
        printf("%d%d%d%d%d", c16Error, c8Error, c4Error, c2Error, c1Error);
    }
    printf("\n");
    
    // Display syndrome word
    printf("The syndrome word is: ");
    int c16Syndrome, c8Syndrome, c4Syndrome, c2Syndrome, c1Syndrome, bitPositionWithError;
    c8Syndrome = c8^c8Error;
    c4Syndrome = c4^c4Error;
    c2Syndrome = c2^c2Error;
    c1Syndrome = c1^c1Error;
    if (inputLength == 8) {
        printf("%d%d%d%d\n", c8Syndrome, c4Syndrome, c2Syndrome, c1Syndrome);
        
        int syndromeWord[4];
        syndromeWord[3] = c8Syndrome;
        syndromeWord[2] = c4Syndrome;
        syndromeWord[1] = c2Syndrome;
        syndromeWord[0] = c1Syndrome;
        bitPositionWithError = convertBinaryToDecimal(syndromeWord, 3);
    } else {
        c16Syndrome = c16^c16Error;
        printf("%d%d%d%d%d\n", c16Syndrome, c8Syndrome, c4Syndrome, c2Syndrome, c1Syndrome);
        
        int syndromeWord[5];
        syndromeWord[4] = c16Syndrome;
        syndromeWord[3] = c8Syndrome;
        syndromeWord[2] = c4Syndrome;
        syndromeWord[1] = c2Syndrome;
        syndromeWord[0] = c1Syndrome;
        bitPositionWithError = convertBinaryToDecimal(syndromeWord, 4);
    }
    // Display the position number
    printf("The error occurs in position %d of the table\n", bitPositionWithError);
    
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

int convertBinaryToDecimal(int binaryNumber[], int numberOfIndexesInArray) {
    int decimal = 0;
    for (int i=numberOfIndexesInArray; i>=0; i--) {
        if (binaryNumber[i] == 1) {
            decimal += pow((double)2, (double)i);
        }
    }
    return decimal;
}
