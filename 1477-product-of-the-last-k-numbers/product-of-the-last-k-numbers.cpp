class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        
        int n = vec.size();

        int prod = 1;

        for(int i=0;i<k;i++){
            if(n-i-1>=0){
                prod = prod * vec[n-i-1];
            }
            else{
                break;
            }
                
        }

        return  prod;

        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */