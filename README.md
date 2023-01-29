# Adv_Prog_Ass_3

How to compile and execute:
first step, open two terminals ot two tabs in the mobaxtreme system. in both frames insert the command "make". afterwars, choose a terminal to use as a server and insert a command according to the format: "./server.out file port", when file is an absolute path or a relative path of the file (relative path can be used only if the file is in the same directory or a subfolder inside the directory, and port is the port number of the server.
Afterwards, in the second terminal,  insert a command according to the format: "./client.out ip port", when ip is the ip and port are the ip of the system where the server runs and port is the server's prot number. The values must be matching.

Explanation about the code:
Most of the code hasn't changed. The main changes are setting 2 main functions to run a server and a client separately. Once the server is opened, a client can connect to it. the client will send values of vectors, distance algorithms and integers and will get a category from the server as we did in the previous assignment. the server will find the most common category in the knn and send it to the client, which will print it to the screen. Once the client sent "-1" to the server, the connection will be stopped, but the server will keep running, even though we won't be able to connect to it anymore, unless we shut the server down and start the whole process from the start.
Another significant change is adding the "KnnSysRun" class, which connects between the client and the server and gets a char[]including the vector, the algorithm and the k value, separates them so we can find the most common category in the knn. 
