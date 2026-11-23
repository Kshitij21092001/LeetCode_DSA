class ProductOfNumbers {
public:

    int currProd;
    int lastZero;
    vector<int> prefix;
    ProductOfNumbers() {
        currProd=1;
        lastZero=-1;
    }
    
    void add(int num) {
        currProd*=num;
        if(currProd==0){
            currProd=1;
            lastZero=prefix.size();
            prefix.push_back(0);
        }
        else{
            prefix.push_back(currProd);
        }
    }
    
    int getProduct(int k) {
        int n=prefix.size();
        if(lastZero>=n-k)return 0;
        if(k==n)return prefix[n-1];
        if(prefix[n-k]==0)return 0;
        if(prefix[n-k-1]==0)return prefix[n-1];
        return prefix[n-1]/prefix[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */