#include "catch.hpp"
#include "ecue.h"

TEST_CASE("Vérification des méthodes accesseurs ecue", "[ecue]"){
    ecue e("codeMatiere", "intitule", 1, 2, 2, 2);
    SECTION("Accesseur Heure Cours"){
        REQUIRE(e.nombreHeureCours() == 2);
    }
    SECTION("Accesseur Heure TP"){
        REQUIRE(e.nombreHeureTp() == 2);
    }
    SECTION("Accesseur Heure TD"){
        REQUIRE(e.nombreHeureTd() == 2);
	}
}

TEST_CASE("Vérification des méthodes setter ecue", "[ecue]"){
    ecue e("codeMatiere", "intitule", 1, 2, 2, 2);
    SECTION("setter Heure Cours"){
        e.setNbHeureCours(3);
        REQUIRE(e.nombreHeureCours() == 3);
    }
    SECTION("Accesseur Heure TP"){
        e.setNbHeureTp(4);
        REQUIRE(e.nombreHeureTp() == 4);
    }
    SECTION("Accesseur Heure TD"){
        e.setNbHeureTd(5);
        REQUIRE(e.nombreHeureTd() == 5);
	}
}

/*TEST_CASE("Afficher une ecue", "[ecue]"){
    ecue e("codeMatiere", "intitule", 1, 2, 2, 2);
    std::string s = "";
    SECTION("afficheur ecue"){
        e.afficher(s);
        REQUIRE(s == "Code matiere : codeMatiere | Intitule : intitule | Coef : 1\nNombre heures : COURS : 2 | TD : 2 | TP : 2\n");
    }
    SECTION("affiche avec << ecue"){
        s << e;
        REQUIRE(s == "Code matiere : codeMatiere | Intitule : intitule | Coef : 1\nNombre heures : COURS : 2 | TD : 2 | TP : 2\n");
    }
}*/


TEST_CASE("Nombre total heure ecue", "[ecue]"){
    ecue e("codeMatiere", "intitule", 1, 2, 2, 2);
    std::string s = "";
    SECTION("nombre heure total ecue"){
        REQUIRE(e.nombreTotalHeure() == 6);
    }
}
