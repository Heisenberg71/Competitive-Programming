/**
https://leetcode.com/problems/find-median-from-data-stream/description/
*/

class MedianFinder {
private:
    multiset<int> firstHalf, secondHalf;
public:
    MedianFinder() {
        firstHalf.clear();
        secondHalf.clear();
    }
    
    void addNum(int num) {
        if(secondHalf.empty() || *secondHalf.begin() <= num) secondHalf.insert(num);
        else firstHalf.insert(num);
        
        int diff = firstHalf.size() - secondHalf.size();
        while(diff > 0){
            auto middleValue = --firstHalf.end();
            secondHalf.insert(*middleValue);
            firstHalf.erase(middleValue);
            diff -= 2;
        }
        
        diff = secondHalf.size() - firstHalf.size();
        while(diff > 1){
            auto middleValue = secondHalf.begin();
            firstHalf.insert(*middleValue);
            secondHalf.erase(middleValue);
            diff -= 2;
        }
    }
    
    double findMedian() {
        int fullSize = firstHalf.size() + secondHalf.size();
        return (fullSize&1) ? *secondHalf.begin() : (*(--firstHalf.end()) + *secondHalf.begin())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
