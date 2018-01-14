#include "uecompose.h"
#include "catch.hpp"


TEST_CASE("Vérification sur la classe ueCompose", "[uecompose]"){
    uecompose u;
    ecue *math = new ecue("math5", "algebre", 1, 10, 12, 14);
    ecue *francais = new ecue("francais5", "grammaire", 1, 10, 12, 14);
    u.ajouterEcue(math);
    u.ajouterEcue(francais);
    SECTION("test ajout"){
        REQUIRE(u.ensembleEcue().size() == 2);
    }
    SECTION("Nombre Total Heure"){
        REQUIRE(u.nombreTotalHeure() == 72);
    }
    SECTION("Trouver ECUE"){
        REQUIRE(u.trouverEcue("francais5") == 0);
    }
    SECTION("Suppresion d'une ue"){
        u.supprimerEcue(0);
        REQUIRE(u.ensembleEcue().size() == 1);
    }

}
