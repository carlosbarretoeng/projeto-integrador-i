cmake_minimum_required(VERSION 3.16)
project(Projeto_R)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projeto_R main.cpp FichaDoPersonagem.cpp FichaDoPersonagem.h Util.cpp Util.h Game.cpp Game.h Tutorial.cpp Tutorial.h RaciocinioLogicoMatematico.cpp RaciocinioLogicoMatematico.h Cenario.cpp Cenario.h GeradorDeTelas.cpp GeradorDeTelas.h)