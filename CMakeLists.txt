cmake_minimum_required(VERSION 3.24)
project(Adv_Prog_Ass_3)

set(CMAKE_CXX_STANDARD 14)

include_directories("../../OneDrive/שולחן העבודה/הצילו/Adv_Prog_Ass_3-6c99dc3d052d58da65404170bfa1386674e7de11")

add_executable(Adv_Prog_Ass_3
        CategoryVec.cpp
        CategoryVec.h
        DataSimilarityItem.cpp
        DataSimilarityItem.h
        Distance.cpp
        Distance.h
        KNN_System.cpp
        KNN_System.h
        Main.cpp
        Vec.cpp
        Stream.cpp
        Stream.h
        Vec.h)
