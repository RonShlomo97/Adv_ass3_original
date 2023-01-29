# ass1_part2
Hi there, here some guideline for open and run this file

1. open terminal(commend line) in the folders of all the files (Vec.h Vec.cpp Main.cpp Distance.h Distance.cpp)
2. write the commend(for plannet): "g++ Main.cpp Vec.cpp Distance.cpp -std=c++11". this line will create a.out file.
3. write the commend(for plannet): "./a.out". this comment will run the program. 
4. there is NO output, you need to type numbers separately with spaces for vector. next step, press enter, and insert another vector values. for example:
    >>g++ Main.cpp Vec.cpp Distance.cpp -std=c++11
    >>./a.out
    1 2 3
    3 2 1
    ......
    You'll see the different algorithms output, and then the program will stop.
    
   
class Vec's part in the program is getting the vetors values from the user and printing the output.
class Distance's part is calculating the distances between 2 vectors according to every one of the five algorithms.
So what are the processes carried out in each department?
Vec: 
1. gets a string as an input from the user.
2. chek that the input is valid for calculating a distance (actual numbers). When getting the second vector, we'll also check that it's contains the same amount of elements as the first one.
3. casting the numbers the string contains, convert them into 'double' vars, and save them in a daynamic array.

distance: 
1. The constructor of this class must receive 2 vectors, so if we don't have 2 vectors, the program won't show us valid output. 
2. caculates the distance between them according to every one of the five algorithms.
3. We will check separately in each calculation method whether the two vectors have the same amount of elements.
4. The const p for the distance in the minkowski's algorithm is p = 2.
