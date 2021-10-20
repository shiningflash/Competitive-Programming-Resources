/*
    Take some books name and number of pages
    sort and print them by page descending order.
    If page number same, then by name ascending lexicographically.
*/

using System;
using System.Collections.Generic;

public class CustomSort {
    public struct Book {
        public string name;
        public int page;

        public Book(string name, int page) {
            this.name = name;
            this.page = page;
        }
    };

    public void manageCustomSort(string[] lines) {
        List<Book> book_list = new List<Book>();

        for (int i = 0; i < lines.Length; i++) {
            string[] words = lines[i].Split(' ');
            book_list.Add(new Book(words[0], int.Parse(words[1])));
        }

        // page descending
        // if page same, name lexicographycally ascending
        book_list.Sort(delegate(Book b1, Book b2) {
            int p = b1.page.CompareTo(b2.page);
            if (p != 0) {
                return -p;
            }
            else {
                return b1.name.CompareTo(b2.name);
            }
        });

        for (int i = 0; i < book_list.Count; i++) {
            Console.WriteLine("{0} {1}", book_list[i].name, book_list[i].page);
        }

    }
}

/*
Input
-
amy 100
david 100
heraldo 50
aakansha 75
aleksa 150

Ouput
-
aleksa 150
amy 100
david 100
aakansha 75
heraldo 50

Input
-
Amirul 12
Faria 23
Faizun 9
Samiul 9
Amirul 9

Output
-
Faria 23
Amirul 12
Amirul 9
Faizun 9
Samiul 9
*/