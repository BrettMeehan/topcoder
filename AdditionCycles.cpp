class AdditionCycles{
    public:
    	int cycleLength(int n);
};

int AdditionCycles::cycleLength(int n){
    int cycles = 0;
    int sum = 0;
    int start = n;
    int result;
    do{
        sum = (start%10) + (start/10);
        result = (start%10)*10 + (sum%10);
        start = result;
        cycles++;
    }while(result != n);
    
    return cycles;
}
