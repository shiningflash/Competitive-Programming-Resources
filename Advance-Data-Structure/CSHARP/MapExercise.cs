/*
    Take two integer followed by two string lines.
    Check if all words of second string present in first string.
*/

using System;
using System.Collections.Generic;

public class MapExercise {
    public void run(string[] lines) {
        string[] line1 = lines[0].Split(' ');
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);

        var map = new Dictionary<string, int>();

        string[] input1 = lines[1].Split(' ');
        for (int i = 0; i < n; i++) {
            int x = map.ContainsKey(input1[i]) ? map[input1[i]] : 0;
            map[input1[i]] = x + 1;
        }

        bool ans = true;

        string[] input2 = lines[2].Split(' ');
        for (int i = 0; i < m; i++) {
            int x = map.ContainsKey(input2[i]) ? map[input2[i]] : 0;
            if (x > 0) map[input2[i]] = x - 1;
            else {
                ans = false;
                break;
            }
        }

        Console.WriteLine(ans ? "Yes" : "No");
    }
}

/*
Input
-
6 4
give me one grand today night
give one grand today
Output
-
Yes
Input
-
6 5
two times three is not four
two times two is four
Output
-
No
*/