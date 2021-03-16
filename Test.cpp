/**
 * Unit tests.
 * AUTHORS: <Lioz Akirav>
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Valid and equal snowman code - no spaces")
{
    /* Assert True */
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("_\n/_\\\n\\(o_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(43232124)) == nospaces("___\n(_*_)\n\\(o_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(22114411)) == nospaces("___\n.....\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(44232124)) == nospaces("___\n(_*_)\n\\(oO)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(12214411)) == nospaces("_===_\n(o..)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21314411)) == nospaces("___\n.....\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(43432124)) == nospaces("___\n(_*_)\n\\(-_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21134411)) == nospaces("___\n.....\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(43242124)) == nospaces("___\n(_*_)\n\\(o_-)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(21114211)) == nospaces("___\n.....\n(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(33232324)) == nospaces("_\n/_\\\n\\(o_O)\n(] [)\\\n(   )"));
    CHECK(nospaces(snowman(43232424)) == nospaces("___\n(_*_)\n\\(o_O)\n(] [)\n(   )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(33232134)) == nospaces("_\n/_\\\n\\(o_O)\n(> <)>\n(   )"));
    CHECK(nospaces(snowman(33232122)) == nospaces("_\n/_\\\n\\(o_O)\n(] [)>\n (\" \")"));
    CHECK(nospaces(snowman(21114413)) == nospaces("___\n.....\n(.,.)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11112211)) == nospaces("_===_\n\\(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(11113311)) == nospaces("_===_\n(.,.)\n/( : )\\\n( : )"));
}

TEST_CASE("Valid and equal snowman code - with spaces") {
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(33232124) == string("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
}

TEST_CASE("Valid but not equal snowman code - no spaces")
{
    /* Assert False */
    CHECK(nospaces(snowman(33232124)) != nospaces("_===_\n\\(o_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(11144311)) != nospaces("_===_\n(.,.)\n/( : )\\\n( : )"));
    CHECK(nospaces(snowman(12232324)) != nospaces("_\n/_\\\n\\(o_O)\n(] [)\\\n(   )"));
}

TEST_CASE("Invalid snowman code")
{
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(123412345));
    CHECK_THROWS(snowman(-12232324));
    CHECK_THROWS(snowman(9));
    CHECK_THROWS(snowman(11111119));
}