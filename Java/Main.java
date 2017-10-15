import java.util.*;

public class Main {
    static Random rand = new Random();
    static Date time = new Date();

    public static void main(String[] args) {
        int sortRounds = 0;
        int maxSortRounds = 10;
        long totalSortTime = 0;
        while (sortRounds < maxSortRounds)
        {
            int[] numbers = getMillionNumbers();
            long sortingTime = RunSorter(numbers);
            System.out.printf("the algorithm took %sms\n", sortingTime);
            totalSortTime += sortingTime;
            sortRounds++;
        }
        System.out.printf("total sorting time was %sms, and the average sorting time was %sms\n", totalSortTime, (totalSortTime / maxSortRounds));
    }

    public static long RunSorter(int[] numbers){
        long start = System.currentTimeMillis();
        int[] sortednums = MergeSort.Sort(numbers);
        long stop = System.currentTimeMillis();

        return stop - start;
    }

    public static int[] getMillionNumbers() {
        int[] numbers = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            numbers[i] = rand.nextInt(10000000);
        }
        return numbers;
    }

}