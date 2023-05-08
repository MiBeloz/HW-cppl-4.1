#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

#include "List.cpp"


TEST_CASE("test List functions", "[List]") {
    setlocale(LC_ALL, "ru");

    List test_list;

    INFO("Проверка, пустой ли объект после создания");
    CHECK(test_list.Empty());
        
    INFO("Проверка, пустой ли объект после добавления элемента");
    test_list.PushBack(5);
    CHECK_FALSE(test_list.Empty());

    INFO("Проверка размера объекта - Size()");
    test_list.PushBack(7);
    CHECK(test_list.Size() == 2);

    INFO("Проверка размера объекта, после извлечения последнего элемента");
    test_list.PopBack();
    CHECK(test_list.Size() == 1);

    INFO("Проверка, пустой ли объект и равен ли размер нулю после очистки объекта");
    test_list.Clear();
    CHECK(test_list.Empty());
    CHECK_FALSE(test_list.Size());
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}
