cmake_minimum_required(VERSION 3.6)
PROJECT(tic_tac_toe CXX)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
#find_package(Boost 1.71.0 COMPONENTS program_options unit_test_framework REQUIRED HINTS "/Users/a1111/Dev/Distr/Cpp/boost/boost_1_71_0_t")

#IF (NOT Boost_FOUND)
#        message(FATAL_ERROR "Boost not found")
#ENDIF()

message(STATUS "Boost FOUND")
message("boost include dirs = ${Boost_INCLUDE_DIRS}")
message("boost dir release = ${Boost_LIBRARY_DIR_RELEASE}")
message("boost libraries =  ${Boost_LIBRARIES}")

add_subdirectory(client)
add_subdirectory(server)

# db
# stats ^
# accounts ^

# online
# ratings ^
# tournamets ^
# simuls! go wild! ^

# uttt
# cheats! like in angry birds showdown!
# multiple players on larger grid!

# --- margins project ---

# minimal:
# 1. uploading
# 2. annotation

# possible:
# 0. accounts
# 1. editing
# 2. creating pdfs
# 3. private / unlisted documents
# 4. asking questions
# 5. teams
# 6. note-taking! take annotation a step further!
# 7. introduce other file formats like word
# 8. paid subscriptions for some features
# 9. suggesting edits to pdfs instead of editing directly

# 0 is a precondition to 5 and 8
# 9 plays into 3

# Добрый день. Из-за формата семинара, так как не был полностью написан код, я не понимаю код. Кроме того, когда я пытаюсь собрать код, Ninja (билд-система, которую я использую в CLion) выдает кучу ошибок. Если можно прекрипить работающей код к семинару - было бы отлично. Даже спросила в телеграм канале - говорят ножно с Qt. Qt у меня нету, и если честно не хочу полностью переварачивать проект наголову чтобы он хоть как-то работал. Понимаю если не примете работу, но все же надеюсь что мы сможем это решить, так как итоговая аттестация скоро и у меня много других недаделанных заданий из-за того, что много время потратила на это. В error_log.txt - логи ошибок. Возможно, у меня есть проблема с компиляторам - у меня каждый второй проект совсем не компилируется, даже самые простые. Однако я похоже не одна в этой проблеме. Я так же прикреплю мой собственный план для этого проекта - и так же для одного из моих который я планирую разрабатывать для дипломного проекта на втором году обучения. Надеюсь, что это продимонстрирует мои знания материала.
# https://drive.google.com/file/d/109fXOmLeUK5LsuSkHE2bxPjUAGX0AMTf/view?usp=sharing 