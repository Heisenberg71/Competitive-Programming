string mult(string s1,string s2){  // big value = s1 , small value = s2
    string ss;
    int c = 0;
    for(int i=s2.length()-1;i>=0;i--){
        int carry=0;
        string s;
        for(int j=s1.length()-1;j>=0;j--){
            int n=((s1[j]-48)*(s2[i]-48))+carry;
            s.push_back((n % 10)+48);
            carry=n/10;
        }
        while(carry){
            s.push_back((carry % 10)+48);
            carry /= 10;
        }
        c++;
        if (c > 1)
        {
            for (int m = 0;m < c - 1;m++)s.insert(s.begin(), '0');
            carry = 0;
            for (int i = 0,j=0;i<s.length();i++,j++) {
                if (j <ss.length())
                {
                    int n = (ss[j] - 48) + (s[i] - 48) + carry;
                    ss[j] = (n % 10) + 48;
                    carry = n / 10;
                }
                else
                {
                    int n = (s[i] - 48) + carry;
                    ss.push_back((n % 10) + 48);
                    carry = n / 10;
                }
            }
            while (carry) {
                ss.push_back((carry % 10) + 48);
                carry /= 10;
            }
        }
        if (c == 1) {
            ss = s;
        }
    }
    reverse(ss.begin(), ss.end());
    return ss;
}
