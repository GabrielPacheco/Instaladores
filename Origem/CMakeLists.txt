project(Baralho)

cmake_minimum_required(VERSION 2.8)


include(CPack)

add_library(Cartas SHARED Struct.c)

add_executable(baralho main.c)

target_link_libraries(baralho Cartas)




install (
	 TARGETS Cartas #Nome do alvo que vai ser instalado (aqui é a biblioteca
	 #Onde os componentes de tempo de execução devem ser instaldos? (aqui indica uma pasta atual)
         RUNTIME DESTINATION .
         #Pode ser usado para instalar apenas parte (componentes) do software
	 COMPONENT CartasLibs
	 #Onde as bibliotecas devem ser instaladas?
         LIBRARY DESTINATION . 
         #Onde os demais arquivos devem ser instalados?
         ARCHIVE DESTINATION .
)


install (#Nome do alvo que vai ser instalado (aqui é a applicação)
	 TARGETS baralho 
	 #Onde os componentes de tempo de execução devem ser instaldos? (aqui indica uma pasta atual)
         RUNTIME DESTINATION . 
         #Pode ser usado para instalar apenas parte (componentes) do software
	 COMPONENT CartasApps
	 #Onde as bibliotecas devem ser instaladas?
         LIBRARY DESTINATION . 
         #Onde os demais arquivos devem ser instalados?
         ARCHIVE DESTINATION .
)



ENABLE_TESTING()

add_executable(Cartateste Bar_test.c)

target_link_libraries(Cartateste Cartas)

add_test(Carta-teste Carta_test)