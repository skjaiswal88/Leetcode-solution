class MedianFinder {
public:

    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    int m;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.size()==0 && minh.size()==0){
            maxh.push(num);
            m=-1;
            return;
        }

        if(maxh.size() == minh.size()){
            if(num>findMedian()){
                minh.push(num);
                m=1;
            }
            else{
                maxh.push(num);
                m=-1;
            }
        }
        else if(maxh.size() > minh.size()){
            if(num>=findMedian()){
                minh.push(num);
                m=0;
            }
            else{
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(num);
                m=0;
            }
        }
        else{
            if(num<=findMedian()){
                maxh.push(num);
                m=0;
            }
            else{
                maxh.push(minh.top());
                minh.pop();
                minh.push(num);
                m=0;
            }
        }
        
    }
    
    double findMedian() {
        if(m==0){
            return ((maxh.top()+minh.top())/2.0);
        }
        else if(m==-1){
            return double(maxh.top());
        }
        else{
            return double(minh.top());
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */