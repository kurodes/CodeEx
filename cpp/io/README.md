
# `<iosteam>`
## To std. input / output / error stream:
`cout, cerr, clog`

## IO redirection: < >
`./a <cin.txt >cout.txt 2>cerr_clog.txt`

## `cout.put() cout.write()`

## Flush
`cout << "..." << flush`

## Displayed number base
```cpp
// set to decimal, hexadecimal, octal mode
cout << x; / cout << dec << x;
cout << hex << x;
cout << oct << x;
```

## Adjust field widths & fill char
`cout.fill('*');`

`cout.width(5);` only effect the next item displayed.

## 
