public class uglyNumber {
    public static int nthUglyNumber(int n) {
        int[] uglyNumber = new int[n];
        int[] index = new int[3]; // respectively for 2,3,5
        int[] factor = {2, 3, 5}; // respectively for 2,3,5
        uglyNumber[0] = 1;
        for(int i = 1; i < n; i++){
            int min = Math.min(Math.min(factor[0], factor[1]), factor[2]);
            uglyNumber[i] = min;
            if(min == factor[0]) factor[0] = 2 * uglyNumber[++index[0]];
            if(min == factor[1]) factor[1] = 3 * uglyNumber[++index[1]];
            if(min == factor[2]) factor[2] = 5 * uglyNumber[++index[2]];            
        }
        return uglyNumber[n - 1];
    }
    
    public static void main(String args[])
    {
    	System.out.println("hellso world");
    	int k = nthUglyNumber(15);
    	System.out.println(k);
    }

}

