/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

import java.util.Arrays;
import java.util.Hashtable;

class Frog {

	public static void printArray(int [] arr, int len)
	{
		
		//System.out.print("hello");
		for(int i=0; i<len; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
    public static void main(String []args)
    {
        int []arr={5, 4, 1, 2};
        System.out.print(frogJump(arr, 7
        		, 3));
    }
    public static int frogJump (int [] arr, int X, int D) {
        if (arr == null || arr.length == 0 || X <= D)
            return 0;
        int []result = new int [X + 1];
        Hashtable<Integer, Integer> legalLeafPosition = new Hashtable<>();
        legalLeafPosition.put (0, 0);
        Arrays.fill(result, Integer.MAX_VALUE);
        result [0] = 0;
        for (int index = 0; index <arr.length; index ++) {
            if (!legalLeafPosition.containsKey (arr[index]))
                legalLeafPosition.put (arr[index], index);
        }
        legalLeafPosition.put (X, 0);
        for (int actualposition = 1; actualposition <= X; actualposition ++) {
            if (legalLeafPosition.containsKey(actualposition)) {
                if (actualposition <= D) {
                    result[actualposition] = legalLeafPosition.get(actualposition);
                } else {
                    for (int previousposition = 1; previousposition <= D; previousposition++)
                        if (legalLeafPosition.get (actualposition) >result [actualposition - previousposition]) {
                            result [actualposition] = Math.min (result [actualposition], legalLeafPosition.get (actualposition));
                        } else {
                            result [actualposition] = Math.min (result[actualposition], result [actualposition - previousposition]);
                        }
                    }
                }
            }
        
        printArray(result, X+1);
        return result [X] == Integer.MAX_VALUE? -1: result [X];
    }
}