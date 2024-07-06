
# Регистрирует статическую библиотеку
function(custom_add_library_from_dir TARGET)
    # Собираем файлы с текущего каталога
    file(GLOB TARGET_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
    list(FILTER TARGET_SRC EXCLUDE REGEX ".*_test\\.cpp$")
    add_library(${TARGET} ${TARGET_SRC})
endfunction()

# Регистрирует исполняемую цель сборки
function(custom_add_executable_from_dir TARGET)
    # Собираем файлы с текущего каталога
    file(GLOB TARGET_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
    add_executable(${TARGET} ${TARGET_SRC})
endfunction()

# Регистрирует тесты, использующие Catch2 для запуска
function(custom_add_library_test_from_dir TEST_TARGET LIBRARY_UNDER_TEST)
    # Собираем файлы тестов с текущего каталога
    file(GLOB TARGET_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*_test.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
    add_executable(${TEST_TARGET} ${TARGET_SRC})
    # Добавляем компоновку с проверяемой библиотекой и Catch2
    target_link_libraries(${TEST_TARGET} PRIVATE ${LIBRARY_UNDER_TEST} Catch2::Catch2WithMain)
    # Регистрируем исполняемый файл в CMake как набор тестов.
    add_test(${TEST_TARGET} ${TEST_TARGET})
endfunction()

# Регистрирует тесты, использующие Catch2 для запуска
function(custom_add_test_from_dir TEST_TARGET)
    # Собираем файлы тестов с текущего каталога
    file(GLOB TARGET_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
    add_executable(${TEST_TARGET} ${TARGET_SRC})
    # Добавляем компоновку с Catch2
    target_link_libraries(${TEST_TARGET} PRIVATE Catch2::Catch2WithMain)
    # Регистрируем исполняемый файл в CMake как набор тестов.
    add_test(${TEST_TARGET} ${TEST_TARGET})
endfunction()

function(custom_enable_sanitizers TARGET)
    if(CMAKE_BUILD_TYPE MATCHES "Debug")
        set(
            CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -fsanitize=undefined -fsanitize=address"
        )
        target_link_options(${TARGET} BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address)
    endif()
endfunction()
