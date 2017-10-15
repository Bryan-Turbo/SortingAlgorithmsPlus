public class MergeSort{
    private static int[] MergeLists(int[] firstHalf, int[] secondHalf) {
        int[] list = new int[firstHalf.length + secondHalf.length];

        int firstHalfIndex = 0;
        int secondHalfIndex = 0;

        for (int i = 0; i < firstHalf.length + secondHalf.length; i++) {
            if (firstHalfIndex < firstHalf.length && secondHalfIndex < secondHalf.length) {
                if (firstHalf[firstHalfIndex] < secondHalf[secondHalfIndex]) {
                    list[i] = firstHalf[firstHalfIndex];
                    firstHalfIndex++;
                } else {
                    list[i] = secondHalf[secondHalfIndex];
                    secondHalfIndex++;
                }
            } else {
                if (firstHalfIndex >= firstHalf.length) {
                    list[i] = secondHalf[secondHalfIndex];
                    secondHalfIndex++;
                } else if (secondHalfIndex >= secondHalf.length) {
                    list[i] = firstHalf[firstHalfIndex];
                    firstHalfIndex++;
                }
            }
        }
        return list;
    }

    public static int[] Sort(int[] elementList) {
        if (elementList.length <= 1)
            return elementList;

        int length = elementList.length;
        int middle = length / 2;

        int[] firstarray = GetElementsFrom(elementList, 0, middle);
        int[] secondArray = GetElementsFrom(elementList, middle, length);

        return MergeLists(Sort(firstarray), Sort(secondArray));
    }

    private static int[] GetElementsFrom(int[] elementList, int lower, int upper) {
        int[] list = new int[upper - lower];

        for (int i = lower; i < upper; i++)
            list[i - lower] = elementList[i];

        return list;
    }
}