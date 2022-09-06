class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    priority_queue <int> maxHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else {
            if (num < maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);
        }
        
        int mnS = minHeap.size(),
            mxS = maxHeap.size();
        
        if (mnS - mxS > 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if (mxS - mnS > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) 
            return maxHeap.top();
        
        if (maxHeap.size() < minHeap.size())
            return minHeap.top();
        
        return (double) (maxHeap.top() + minHeap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */