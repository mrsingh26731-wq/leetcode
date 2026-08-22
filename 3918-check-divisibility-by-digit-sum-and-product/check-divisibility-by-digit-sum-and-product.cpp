class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int original =n;
        long long int product =1;

        while(n>0){
            int digit =n%10;
            sum+= digit;
            product*=digit;
            n/=10;

        }
if  (original % (sum + product) == 0){
    return true;
}
else
return false;
    }
};