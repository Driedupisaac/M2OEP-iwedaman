cmake_minimum_required(VERSION 3.29)
project(M2OEP_iwedaman)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP_iwedaman
    main.cpp
        Game.cpp
        Player.h
        Game.h
        Player.cpp
        Asset.cpp
        utility.cpp
        Piece.h
        Piece.cpp
        Property.h
        ElecWater.h
        Railroad.h
        Railroad.cpp
        Board.h
        Street.h
        Square.h)


