#include "..//catch.hpp"
#include "trim.h"

TEST_CASE("cTrim - Testing C strings with no ws on either end")
{
    char theString[100] = "Catch with Sections!";
    char theAnswer[100] = "Catch with Sections!";
    CHECK(strcmp(theString, theAnswer) == 0);

    SECTION("Front - Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    SECTION("End - Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    SECTION("Both - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("sTrim - Testing strings with no ws on either end")
{
    string theString = "Catch with Sections!";
    string theAnswer = "Catch with Sections!";
    CHECK(theString == theAnswer);

    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }

    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }

    SECTION("Both - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("cTrim - Testing C strings with whitespace on both ends")
{
    char theString[100] = "  Catch with Sections!  ";

    SECTION("Front - Just a phrase")
    {
        cTrim(theString, FRONT);
        char theAnswer[100] = "Catch with Sections!  ";
        CHECK(strcmp(theAnswer, theString) == 0);
    }


    SECTION("End - Just a phrase")
    {
        cTrim(theString, END);
        char theAnswer[100] = "  Catch with Sections!";
        CHECK(strcmp(theAnswer, theString) == 0);
    }


    SECTION("Both - Just a phrase")
    {
        cTrim(theString, BOTH);
        char theAnswer[100] = "Catch with Sections!";
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("sTrim - Testing strings with whitespace on both ends")
{
    string theString = "  Catch with Sections!  ";

    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        string theAnswer = "Catch with Sections!  ";
        CHECK(theAnswer == theString);
    }

    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        string theAnswer = "  Catch with Sections!";
        CHECK(theAnswer == theString);
    }

    SECTION("Both - Just a phrase")
    {
        sTrim(theString, BOTH);
        string theAnswer = "Catch with Sections!";
        CHECK(theAnswer == theString);
    }
}
/*
TEST_CASE("cTrim - Testing C strings with only whitespace")
{
    char theString[100] = " ";

    SECTION("Front - Just space")
    {
        cTrim(theString, FRONT);
        char theAnswer[100] = "";
        CHECK(strcmp(theAnswer, theString) == 0);
    }


    SECTION("End - Just space")
    {
        cTrim(theString, END);
        char theAnswer[100] = "";
        CHECK(strcmp(theAnswer, theString) == 0);
    }


    SECTION("Both - Just space")
    {
        cTrim(theString, BOTH);
        char theAnswer[100] = "";
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}
*/
TEST_CASE("sTrim - Testing strings with only whitespace")
{
    string theString = " ";

    SECTION("Front - Just space")
    {
        sTrim(theString, FRONT);
        string theAnswer = "";
        CHECK(theAnswer == theString);
    }

    SECTION("End - Just space")
    {
        sTrim(theString, END);
        string theAnswer = "";
        CHECK(theAnswer == theString);
    }

    SECTION("Both - Just space")
    {
        sTrim(theString, BOTH);
        string theAnswer = "";
        CHECK(theAnswer == theString);
    }
}
/*
TEST_CASE("cTrim - Testing empty C strings")
{
    char theString[100] = "";

    SECTION("Front - Nothing")
    {
        cTrim(theString, FRONT);
        char theAnswer[100] = "";
        CHECK(strcmp(theAnswer, theString) == 0);
    }


    SECTION("End - Nothing")
    {
        cTrim(theString, END);
        char theAnswer[100] = "";
        CHECK(strcmp(theAnswer, theString) == 0);
    }


    SECTION("Both - Nothing")
    {
        cTrim(theString, BOTH);
        char theAnswer[100] = "";
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}
*/
TEST_CASE("sTrim - Testing empty strings")
{
    string theString = "";

    SECTION("Front - Nothing")
    {
        sTrim(theString, FRONT);
        string theAnswer = "";
        CHECK(theAnswer == theString);
    }

    SECTION("End - Nothing")
    {
        sTrim(theString, END);
        string theAnswer = "";
        CHECK(theAnswer == theString);
    }

    SECTION("Both - Nothing")
    {
        sTrim(theString, BOTH);
        string theAnswer = "";
        CHECK(theAnswer == theString);
    }
}