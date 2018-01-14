#include "formation.h"
#include "semestre.h"
#include "catch.hpp"


TEST_CASE("Vérification des méthodes accesseurs formation", "[formation]"){
    formation f ("domaine", "mention", "parcours", 1994);
    SECTION("Accesseur domaine"){
        REQUIRE(f.domaine() == "domaine");
    }
    SECTION("Accesseur mention"){
        REQUIRE(f.mention() == "mention");
    }
    SECTION("Accesseur parcours"){
        REQUIRE(f.parcours() == "parcours");
    }
    SECTION("Accesseur annee"){
        REQUIRE(f.annee() == 1994);
    }
}

TEST_CASE("Vérification des méthodes setter formation", "[formation]"){
    formation f ("domaineA", "mentionA", "parcoursA", 199);
    SECTION("Accesseur domaine"){
        f.setDomaine("domaine");
        REQUIRE(f.domaine() == "domaine");
    }
    SECTION("Accesseur mention"){
        f.setMention("mention");
        REQUIRE(f.mention() == "mention");
    }
    SECTION("Accesseur parcours"){
        f.setParcours("parcours");
        REQUIRE(f.parcours() == "parcours");
    }
    SECTION("Accesseur annee"){
        f.setAnnee(1994);
        REQUIRE(f.annee() == 1994);
    }
}
