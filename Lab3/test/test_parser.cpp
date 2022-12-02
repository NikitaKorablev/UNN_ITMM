//
// Created by nikita on 12/1/22.
//
#include "gtest.h"
#include "Calculate.h"

TEST(Lexema, arithmetic_analysis_check) {
    string str = "123 - \n5 * (10+5)";
    queue<Lexema> l = lex(str);
    ASSERT_EQ("123-5*(10+5)", lexToString(l));
}

TEST(Lexema, definition_of_value_type_position) {
    string str = "123 - \n5 * 10 + 3 / 1";

    queue<Lexema> l1;
    l1.push(Lexema("123", Value, 0));
    l1.push(Lexema("-", Operation, 1));
    l1.push(Lexema("5", Value, 2));
    l1.push(Lexema("*", Operation, 3));
    l1.push(Lexema("10", Value, 4));
    l1.push(Lexema("+", Operation, 5));
    l1.push(Lexema("3", Value, 6));
    l1.push(Lexema("/", Operation, 7));
    l1.push(Lexema("1", Value, 8));

    queue<Lexema> l2 = lex(str);
    ASSERT_EQ(l1.size(), l2.size());
    while (!l1.empty() && !l2.empty()) {
        ASSERT_EQ(l1.front().getStr(), l2.front().getStr());
        ASSERT_EQ(l1.front().getType(), l2.front().getType());
        ASSERT_EQ(l1.front().getPosition(), l2.front().getPosition());
        l1.pop(); l2.pop();
    }
}

TEST(Lexema, lexical_error) {
    string str = "123 - \n5 * (10+5)";
    queue<Lexema> l1 = lex(str);
    ASSERT_NO_THROW(lexCheckErr(l1));
}

//-------------------------------------------------------------------

TEST(Syntax, check_parser) {
    string str = "15 * 3 + 5 - 15 / 3";

    queue<Lexema> l1;
    l1.push(Lexema("15", Value, 0));
    l1.push(Lexema("3", Value, 2));
    l1.push(Lexema("*", Operation, 1));
    l1.push(Lexema("5", Value, 4));
    l1.push(Lexema("+", Operation, 3));
    l1.push(Lexema("15", Value, 6));
    l1.push(Lexema("3", Value, 8));
    l1.push(Lexema("/", Operation, 7));
    l1.push(Lexema("-", Operation, 5));
    queue<Lexema> l2 = sunt(lex(str));

    ASSERT_EQ(l1.size(), l2.size());
    while (!l1.empty() && !l2.empty()) {
        ASSERT_EQ(l1.front().getStr(), l2.front().getStr());
        ASSERT_EQ(l1.front().getType(), l2.front().getType());
        ASSERT_EQ(l1.front().getPosition(), l2.front().getPosition());
        l1.pop(); l2.pop();
    }

}
