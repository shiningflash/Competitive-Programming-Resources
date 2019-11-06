Swapping of 2 numbers using XOR
-------------------------------

This method is fast and doesn’t require the use of 3rd variable.
```
  // A quick way to swap a and b 
  a ^= b; 
  b ^= a; 
  a ^= b;
  
  // or you can use
  a ^= b ^= a ^= b
```
