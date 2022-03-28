class Solution {
public:
    bool canReorderDoubled(vector<int>& arr){
        //INTUITION: keep pairing every even number with its half. If nos. are left which can't be paired return false!
      
        //ALGO: store frequencies in a map and keep decreasing as nos. are paired
        
        map<int,int> pos, neg; //ordered map taken to later traverse them in ordered fashion
        
        int p = 0, n = 0; //couting positive and negative nos.
        for(auto a: arr)
        {
            if(a>=0)
               {p++; pos[a]++;}
            else
               {n++; neg[a]++;}
        }
        if((p&1) || (n&1)) //since we need to pair both -ve and +ve elements so none of them can be present in an odd no.
            return false;
    
        for(auto m = pos.rbegin(); m!=pos.rend(); m++) //moving in +ve nos. in descending order because, we check for pairing a number with its half (which is smaller than the no. itself)
            //by doing this a lot of iterations will be saved!
        {
            int num = (*m).first;
            int freq = (*m).second;
           
            if(num==0 && (freq&1)) //since 0 can only be paired with itself, so even freq must be present
                return false;
            else if(freq>0)
            {
                if(num&1) return false; //any odd number encountered must be the half of a bigger even no. processed earlier, 
                //and it must have been paired with that even no. already
                //SO the frequency of the half must have already been reduced to 0 earlier, so we can't encounter any odd no. with freq>0
                if(pos[num/2]==0 || pos[num/2]<freq)
                    return false;
                (*m).second = 0 ;
                pos[num/2] -= freq;
				if(pos[num/2]==0) pos.erase(num/2);
            }
        }
        
        for(auto m = neg.begin(); m!=neg.end();m++)//moving in -ve nos. in ascending order because, we check for pairing a -ve number with its half (which is bigger than the no. itself)
        {
            int num = (*m).first;
            int freq = (*m).second;
            
            if(freq>0)
            {
                if((abs(num))&1) return false; //same logic as for +ve nos.
                
                if(neg[num/2]==0 || neg[num/2]<freq)
                    return false;
                
                (*m).second = 0 ;
                neg[num/2] -= freq;
				if(neg[num/2]==0) neg.erase(num/2);
            }
        }

        return true;
    }
};