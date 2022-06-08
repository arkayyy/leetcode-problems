
class MedianFinder {
public:
    //INTUITION: We take two opposite fashion priority queues, one in ascending and one in descending. And we will push elements in queue based on their range of elements inside. 
    //Our aim is to divide all the elements into two adjacent ranges.
    //So this way at last, the top of the priority queues would always contain the central element(s).
    
    
    //ALGO:
    //So the whole sequence of number given is divided into two separate ranges, one stored in max heap and the other stored in min heap.
    // e.g.[1,2,3,4,5,6] is divided into:
    //top->[3,2,1] for pq1 (maxheap)     AND        top->[4,5,6] for pq2(minheap). So the top of both pq's give us the central elements.

    //e.g. [1,2,3,4,5] is divided into:
    //top->[3,2,1] for pq1 (maxheap)     AND     top->[4,5] for pq2(minheap). Here the top of bigger pq will give us the central element.
	
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<int> pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty() || pq1.top()>num) pq1.push(num); //initially inserting in pq1, or if the element falls in range of the elements already present in pq1
        else pq2.push(num); //otherwise inserting in pq2
        
        //the rule is that any priority queue having more than 1 elements more than the other priority queue,
        //we will transfer the extra element to the other priority queue 
        //as we will only transfer the topmost element of each pq, so for max heap it'll be the max element shifted, and for min head min. element shifted
		//So, the two ranges will always stay adjacent to each other and never get disrupted.

        if(pq1.size()> pq2.size()+1) 
        {pq2.push(pq1.top()); pq1.pop();}
        else if(pq2.size()>pq1.size()+1)
        {pq1.push(pq2.top()); pq2.pop();}
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()) return pq1.empty()?0:((pq1.top()+pq2.top())/2.0);
        else return pq1.size()>pq2.size()?pq1.top():pq2.top();
    }
};
