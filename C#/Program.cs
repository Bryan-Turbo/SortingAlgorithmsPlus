using System;
using System.Collections.Generic;
using System.Linq;

namespace csharp
{
    class Program
    {
        static Random rand = new Random();
        static void Main(string[] args)
        {
            int sortRounds = 0;
            int maxSortRounds = 10;
            long totalSortTime = 0;
            while (sortRounds < maxSortRounds)
            {
                int[] numbers = Numbers().Take(10000000).ToArray();
                long sortingTime = RunSorter(numbers);
                Console.WriteLine($"the algorithm took {sortingTime}ms");
                totalSortTime += sortingTime;
                sortRounds++;
            }
            Console.WriteLine($"total sorting time was {totalSortTime}ms, and the average sorting time was {totalSortTime / maxSortRounds}ms");
        }

        static long RunSorter(int[] numbers)
        {
            long start = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
            int[] sortednums = numbers.Sort();
            long stop = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
            return stop - start;
        }

        static IEnumerable<int> Numbers()
        {
            while (true)
            {
                yield return rand.Next(0, 10000000);
            }
        }
    }
}
