class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        vec.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
        vec.clear();
        vec.push_back(1);
        }
        else{
            vec.push_back(vec.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n = vec.size();
        if(n<=k){
            return 0;
        }

        return vec.back()/vec[n-k-1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */