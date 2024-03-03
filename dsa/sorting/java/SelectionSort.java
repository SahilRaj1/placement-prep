package sorting.java;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * SelectionSort
 */
public class SelectionSort {
    public static void main(String[] args) {
        
        List<Integer> arr = new ArrayList<Integer>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int temp = sc.nextInt();
            arr.add(temp);
        }
        System.out.println(arr);

        // selection sort
        int minIndex;
        for (int i = 0; i < n; i++) {
            minIndex = i;
            for (int j = i+1; j < n; j++) {
                if (arr.get(j) < arr.get(minIndex)) {
                    minIndex = j;
                }
            }
            Collections.swap(arr, i, minIndex);
        }

        System.out.println(arr);
        sc.close();
    }
}