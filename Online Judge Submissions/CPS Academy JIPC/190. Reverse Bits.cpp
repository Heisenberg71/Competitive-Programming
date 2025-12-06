class Solution {
private:
    static const int MAX_BIT_SIZE = 32;
public:
    int reverseBits(int n) {

        vector<int> binary_representation;
        for(int i = 0; i < MAX_BIT_SIZE; i++) {
            int reminder = n%2;
            binary_representation.push_back(reminder);
            n /= 2;
        }

        int reversedValue = 0;
        long long powerOfTwo = 1;
        for(int i = MAX_BIT_SIZE - 1; i >= 0; i--) {
            int currentBit = binary_representation[i];
            reversedValue += currentBit*powerOfTwo;
            powerOfTwo *= 2;
        }

        return reversedValue;
    }
};


class Solution {
private:
    static const int MAX_BIT_SIZE = 32;
public:
    int reverseBits(int n) {
        int reversedNumber = 0;
        for(int i = MAX_BIT_SIZE - 1; i >= 0; i--) {
            int currentBit = n%2;
            reversedNumber += currentBit*(1 << i);
            n /= 2;
        }
        return reversedNumber;
    }
};


class Solution {
private:
    static const int MAX_BIT_SIZE = 32;
public:
    int reverseBits(int n) {
        int reversedNumber = 0;
        for(int i = MAX_BIT_SIZE - 1; i >= 0; i--) {
            int currentBit = n&1;
            reversedNumber += currentBit*(1 << i);
            n >>= 1;
        }
        return reversedNumber;
    }
};
