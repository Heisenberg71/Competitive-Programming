class Solution {
private:

/*
    One Hundred = 100
    One Thoudand = 1000
    One Million = 1000,000
    One Billion = 1000,000,000
*/

    const static int ONE_HUNDRED = 100;
    const static int ONE_THOUSAND = 1000;
    const static int ONE_MILLION = 1000000;
    const static int ONE_BILLION = 1000000000;

    const vector<string> belowTen = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    string convertToWords(int num) {
        if(num < 10) {
            return belowTen[num];
        }
        if(num < 20) {
            return belowTwenty[num - 10];
        }
        if(num < ONE_HUNDRED) {
            return belowHundred[num / 10] + (num % 10 ? " " + belowTen[num%10] : "");
        }
        if(num < ONE_THOUSAND) {
            return convertToWords(num/ONE_HUNDRED) + " Hundred" + (num % ONE_HUNDRED ? " " + convertToWords(num%ONE_HUNDRED) : "");
        }
        if(num < ONE_MILLION) {
            return convertToWords(num/ONE_THOUSAND) + " Thousand" + (num % ONE_THOUSAND ? " " + convertToWords(num%ONE_THOUSAND) : "");
        }
        if(num < ONE_BILLION) {
            return convertToWords(num/ONE_MILLION) + " Million" + (num % ONE_MILLION ? " " + convertToWords(num%ONE_MILLION) : "");
        }
        return convertToWords(num/ONE_BILLION) + " Billion" + (num % ONE_BILLION ? " " + convertToWords(num%ONE_BILLION) : "");
    }

public:
    string numberToWords(int num) {
        return convertToWords(num);
    }
};
