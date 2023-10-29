class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int chance=minutesToTest/minutesToDie;
        int i=0;
        while(pow((chance+1), i)<buckets){
            i++;
        }
        return i;
    }
};
