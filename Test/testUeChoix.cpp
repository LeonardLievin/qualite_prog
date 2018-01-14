#include "uechoix.h"
#include "uesimple.h"
#include "catch.hpp"

TEST_CASE("Vérification sur la classe ueChoix", "[uechoix]"){
    uechoix u;
    uesimple *math = new uesimple("math5", "algebre", 1, 3, 10, 12, 14);
    uesimple *francais = new uesimple("francais5", "grammaire", 1, 3, 10, 12, 14);
    u.ajouterUe(math);
    u.ajouterUe(francais);
    SECTION("test ajout"){
        REQUIRE(u.ueDisponible().size() == 2);
    }
    SECTION("Suppresion d'une ue"){
        u.supprimerUe(0);
        REQUIRE(u.ueDisponible().size() == 1);
    }
}
