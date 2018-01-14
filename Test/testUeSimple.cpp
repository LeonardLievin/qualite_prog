#include "uesimple.h"
#include "catch.hpp"


TEST_CASE("Vérification des méthodes accesseurs et setter ue simple", "[uesimple]"){
    uesimple math("codeMatiere", "intitule", 1, 2, 2, 2,3);
    SECTION("Accesseur ects ue simple"){
        REQUIRE(math.ects() == 3);
    }
    SECTION("setter ects ue simple"){
        math.setEcts(4);
        REQUIRE(math.ects() == 4);
	}
}
