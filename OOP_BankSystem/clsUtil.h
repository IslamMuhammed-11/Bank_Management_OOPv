#pragma once
#include<iostream>
#include<ctime>
#include"clsDate.h"
using namespace std;

class clsUtil
{
public:

    enum enCharType { SmallLetters = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChar = 5 };

    static void Srand() {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To) {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomChar(enCharType CharType) {

        switch (CharType)
        {
        case enCharType::SmallLetters:
        {
            // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
            return char(RandomNumber(97, 122));
            break; // break is not necessary after return.
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            // Generate a random special character (ASCII: 33 '!' to 47 '/').
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII: 48 '0' to 57 '9').
            return char(RandomNumber(48, 57));
            break;
        }

        case enCharType::MixChar:
            return char(RandomNumber(33, 122));
        }
        // If no valid type is provided, return a null character.
        return '\0';

    }

    static string GenerateWord(enCharType CharType, int Length) {
        string word;

        for (int i = 0; i < Length; i++)
        {
            word += GetRandomChar(CharType);
        }
        return word;
    }

    static string GenerateKey() {
        string Key;

        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key += GenerateWord(enCharType::CapitalLetter, 4);

        return Key;
    }

    static void GenerateKeys(int numberOfKeys) {

        for (int i = 0; i < numberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }

    }

    static void Swap(int& Num1, int& Num2) {
        int Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2) {

        double Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;

    }

    static void Swap(string& s1, string& s2) {
        string Temp;
        Temp = s1;
        s1 = s2;
        s2 = Temp;
    }

    static void Swap(clsDate& date1, clsDate& date2) {
        clsDate Temp;
        Temp = date1;
        date1 = date2;
        date2 = Temp;
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength)
    {
        // Fill the array with random numbers between 1 and 100.
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }

    static void PrintArray(int arr[100], int arrLength)
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";

        cout << "\n";  // Print a newline after printing all elements.
    }

    static void PrintArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";
        // Loop through the array and print each element with its index.
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n"; // Extra newline for formatting.
    }

    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;  // Initialize sum to zero.

        // Loop through each element of the array and add it to Sum.
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }

        return Sum;  // Return the calculated sum.
    }

    static float ArrayAverage(int arr[100], int arrLength)
    {
        // Compute the average by casting the sum to float to ensure floating-point division.
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        // Loop through each element up to arrLength and copy from source to destination.
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;

            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }

    static void FillArrayWithKeys(string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();
    }

    static void FillArrayWithWords(string arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(enCharType::SmallLetters, RandomNumber(2, 7));
    }

    static string taps(int count) {
        string tap;
        for (int i = 0; i < count; i++)
        {
            tap += "\t";
        }
        return tap;
    }

    static string EncryptText(string Text, int EncryptionKey = 12)
    {
        // Loop through each character of the text.
        // Note: Using "<= Text.length()" iterates one extra time (accessing the null terminator), 
        // which may be unintended. Ideally, use "< Text.length()".
        for (int i = 0; i <= Text.length(); i++)
        {
            // Convert the current character to its integer ASCII value,
            // add the encryption key, cast it back to char, and assign it back.
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text; // Return the encrypted text.
    }

    static string DecryptText(string Text, int EncryptionKey = 12)
    {
        // Loop through each character of the text.
        // Note: Using "<= Text.length()" will process one extra character (the null terminator).
        for (int i = 0; i <= Text.length(); i++)
        {
            // Convert the current character to its ASCII integer value,
            // subtract the encryption key, cast back to char, and assign it back.
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text; // Return the decrypted text.
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

};

