make:
	g++ -std=c++11 -o server.out Vec.cpp Distance.cpp CategoryVec.cpp DataSimilarityItem.cpp KNN_System.cpp Stream.cpp Server.cpp KnnSysRun.cpp

	g++ -std=c++11 -o client.out Client.cpp
clean:
	rm *.o server.out client.out