class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1;
        int i=1;
        int n=ratings.size();
        int peak,down;

        while(i<n){

            if(ratings[i]==ratings[i-1]){
                sum++; i++; continue;
            }
            peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum=sum+peak;
                i++;
            }

            down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum=sum+down;
                i++;
            }
            down++;

            if(down>peak) sum=sum+(down-peak);
        }

        return sum;
    }
};