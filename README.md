# Test_CADEX

## Compiling

```shell
g++ main.cpp -ldl -o curves -L. -lcurve -Wl,-rpath=.
```

## Running
```shell
./curve
```
or 

```shell
./curve [count]
```
where count <= size of the first container. By default, the size of the first container does not exceed 10