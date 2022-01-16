# FDF 
An introduction project to the graphics branch @ 42.</br>

Reads in a height map to generate a 3D model that the user can interact with!

## Compiling and running
This project will only work on 42school Macs!

Run `make`. An executable will compile.

Run it with `./fdf [map]`
##Usage
After running `make` to generate the fdf executable you can run the program with `./fdf [valid_fdf_file]`.
A valid fdf file will consist of a matrix of number delimited by spaces. Each number's position represents an (x , y) coordinate with the value of the number itself representing a height (z).

Valid fdf files will always have the same number of elements per row.

Example:
```
$> cat -e 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0$
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0$
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0$
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0$
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0$
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0$
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
$>
```
## Maps

You can find differents maps on the `maps` folder or create yours using the following example.

`Map of the top picture :`
![pyra.fdf](/image/pyramap.png)
![42.fdf](/image/42map.png)
##Output

The program 
