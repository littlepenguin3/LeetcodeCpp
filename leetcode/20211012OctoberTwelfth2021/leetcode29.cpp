#include<iostream>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
         if (dividend == INT_MIN) {
            if (divisor == 1) {
                return INT_MIN;
            }
            if (divisor == -1) {
                return INT_MAX;
            }
            if (divisor == INT_MIN) {
                return  1 ;
            }
            int sign = ((dividend<0&&divisor<0)||(dividend>0&&divisor>0)) ? 1:-1;
            divisor = (divisor<0) ? -divisor : divisor;
            int ans = 0;
            int a = dividend;
            int b = divisor;
            int dividendBit = 31;
            int divisorBit = 0;
            while(b>0) {
                b = b>>1;
                divisorBit++;
            }
            int shiftBit = dividendBit - divisorBit;
            divisor = divisor<<shiftBit;
            for(int i=0;i<=shiftBit;i++) {
                if(dividend+divisor<=0) {
                    ans+=1;
                    dividend+=divisor;
                    if(dividend+divisor<=0) {
                        ans+=1;
                        dividend+=divisor;
                    }
                }else {
                    ans+=0;
                }
                if(i!=shiftBit) {
                    ans = ans<<1;
                }
                divisor = divisor>>1;
            }
            return sign*ans;
        }
        // 考虑除数为最小值的情况
        if (divisor == INT_MIN) {
            return 0;
        }
        int sign = ((dividend<0&&divisor<0)||(dividend>0&&divisor>0)) ? 1:-1;
        dividend = (dividend<0) ? -dividend : dividend;
        divisor = (divisor<0) ? -divisor : divisor;
        if(dividend<divisor) {
            return sign*0;
        }else {
            int ans = 0;
            int a = dividend;
            int b = divisor;
            int dividendBit = 0;
            int divisorBit = 0;
            while(a>0) {
                a = a>>1;
                dividendBit++;
            }
            while(b>0) {
                b = b>>1;
                divisorBit++;
            }
            int shiftBit = dividendBit - divisorBit;
            divisor = divisor<<shiftBit;
            for(int i=0;i<=shiftBit;i++) {
                if(dividend-divisor>=0) {
                    ans+=1;
                    dividend-=divisor;
                }else {
                    ans+=0;
                }
                if(i!=shiftBit) {
                    ans = ans<<1;
                }
                divisor = divisor>>1;
            }
            return sign*ans;
        }
    }
};

int main() {
    Solution test;
    cout<<test.divide(INT_MIN,-3)<<endl<<1852423/241;
}
//without solution
//Program 00:46:0 Debug 9:00:01
//noexpection 