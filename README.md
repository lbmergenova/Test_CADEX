# Test_CADEX

## Compiling

```shell
g++ main.cpp -ldl -o curves -L. -lcurve -Wl,-rpath=.
```

## Running
```shell
./curves
```
or 

```shell
./curves [count]
```
where count <= size of the first container. By default, the size of the first container does not exceed 10.

### 
rewrite libcurve.so  
c++ -fPIC -shared Point.cpp Helix.cpp Ellipse.cpp Circle.cpp -o libcurve.so

check for leaks  
valgrind --leak-check=full ./curve