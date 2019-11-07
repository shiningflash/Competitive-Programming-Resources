Some common resources for CSE419 LAB MID
========================================

# Searching

**Lower Bound:**
```
// array
int pos = lower_bound(arr, arr+n, key) - arr;

// vector
int pos = lower_bound(v.begin(), v.end(), key) - v.begin();

// a = {10, 20, 30, 30, 40, 50} // find 35? // ans = 4
```

**Upper Bound:**
```
// array
int pos = upper_bound(arr, arr+n, key) - arr;

// vector
int pos = upper_bound(v.begin(), v.end(), key) - v.begin();

// a = {10, 20, 30, 30, 40, 50} // find 50? // ans = 6
```

**Binary Search:**
```
int binary_search(int arr[], int size, int key) {
   int low = 0, high = size - 1, mid;
   while (low <= high) {
      mid = (low + high) >> 1;
      if (key = arr[mid]) return mid;
      else if (key > arr[mid]) low = mid + 1;
      else high = mid - 1;
   }
   return -1; // not found
}

// Complexity: O ( log2 ( N ) )
```
-----------------

**Array Size:**
```
int sz = sizeof(arr) / sizeof(arr[0]);
```
-----------------

# Number Theory:

**LCM (m, n):**
```
// logic: lcm(a, b) = (a*b) / gcd(a,b)
cout << lcm(10, 20) << endl; // print 20

// lcm(10, 20) = (200 / 10) = 20
```

**GCD (m, n):**
```
// 1. by writing function

int gcd(int m, int n) {
   if (m == 0) return n;
   return gcd(n%m, m);
}
```
```
// 2. using by default function

int gcd = __gcd(6, 20); // print 2
```

**Sieve (prime number generator):**
```
const int mx = 1e5;

int arr[mx+5];

// arr[x] == 0 => x is prime
// arr[x] == 1 => x is not prime / composite
void sieve() {
   a[0] = a[1] = 1;
   for (int i = 2; i*i <= mx; i++) {
       if (!arr[i]) {
           for (int j = i<<1; j <= mx; j+=i) arr[j] = 1;
       }
   }
}
```
----------------

# STL:

**vector**
* Vectors are same as dynamic arrays with the ability to resize.
```
// initialize : vector <data_type> vector_name;
vector <int> vec;

vec.push_back(12); // vec : 12
vec.push_back(3); // vec : 12, 3

vec.size();

int n = vec.front(); // n = 12
int n = vec.back(); // n = 3

sort(vec.begin(), vec.end()); // vec : 3, 12
```

**stack**
* Stack is a linear data structure
* mechanism: LIFO (Last in, First out)
```
//  initialize
stack <int> s;

s.push(4); // insert value
int n =  s.top(); // n = 4
s.pop(); // remove value 4

bool flag = s.empty(); // s = {}, flag = false;

int sizeOfStack = s.size(); // s = {}, sizeOfStack = 0

showstack(s);
```
```
void showstack(stack <int> s) { 
    while (!s.empty()){
        cout <<  s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
}
```

**queue**
* Queue is a linear data structure
* mechanism: FIFO (First in, First out)
```
queue <int> q; // initialize

q.push(4); // q = {4}
int a = q.front(); // n = 4
q.pop(); // remove value 4
   
int sizeOfQueue = q.size();

bool flag = q.empty(); // q = {}, flag = false;
```

**deque**
* The functions for deque are same as vector, with an addition of push and pop operations for both front and back.
* More efficient in case of insertion and deletion of elements than vector.
```
deque <int> d; // declaration
push_back(12); // d = {12};
push_front(3); // d = {3, 12}
int n = d.front(); // n = 3
int m = d.back(); // m = 12;
d.pop_back(); // d = {3}, 12 removed
d.pop_front(); // d ={}, 3 removed
```

**Priority_queue**
```
priority_queue <data_type> any_name; // maintain desending order
priority_queue <int, vector<int>, greater<int>> any_name; // maintain assending order
```
same as queue with operation:
`push()`, `pop()`, `size()`, `top()`, `empty()`, `front()`, `push_back()`, `pop_back()`
```
priority_queue <int> pq; 
pq.push(10); // pq = {10} 
pq.push(30); // pq = {30, 10}
pq.push(20); // pq = {30, 20, 10}
int n = pq.top(); // n = 30
pq.pop(); // 30 popped, pq = {20, 10}
```

**map:**
* Each element has a key value and a mapped value.
* No two mapped values can have same key values.
```
map<string, int> mp;
mp[1] = "Abdur Rahman";

cout << mp[1] << endl; // print "Abdur Rahman"

mp[10000] = "Amirul"

map <char, string> mc;
mc['k'] = "Kabbya Kantam"
cout << mc['k'] << endl;
```

**Set:**
* ascending input
* ignore duplicate
```
struct cmp {
   bool operator() (const int& l, const int& r) {
       return l > r;
   }
};
```
```
set <int> s; // declaration

// set <int, cmp> s; // customized decending ordered set declaration

s.insert(12); // s = {12}
s.insert(12); // s = {12}, ingonred duplicate
s.insert(3); // s = {3, 12}, remain assending order

// print set
set <int>::iterator it;
for (it = s.begin(); it != s.end(); it++) {
    cout << *it << endl;
}
```

**Struct:**
```
// name, id, addr

#define pii pair <int, int>

// v[0] = "kabbya", 530, "Mohakhali"
// v[1] = "amirul", 230, "Gulshan"
// v[2] = "samiul", 230, "Mohammadpur"

// person = custom variable type
// cmp() = custom method
```
```
struct person {
    string name, id, addr;
};
```
```
struct cmp() {
    bool operator() (const person& p1, const person& p2) {
        if (p1.id != p2.id) p1.id < p2.id;
        return p1.id < p2.id;
    }
};
```
```
// main function

person p[3];
for (int i = 0; i < 3; i++) {
   cin >> name >> id >> addr, p[i] = {name, id, addr};
}
sort(p, p+3);
for (int i = 0; i < 3; i++) {
   cout << p[i].name << " " << p[i].id << " " << p[i].addr << endl;
}
```
-------------------
### Prepared by: [Amirul Islam](linkedin.com/in/amirulislamalmamun)
