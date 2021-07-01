#define _POSIX_C_SOURCE 200809L
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "eestic.h"

#define PUHVRI_SUURUS 128

/*
 * Ameerika filmidest tuntud kihisemise-sumina töövestluse rituaal.
 */
staatiline tühimik kihisemine_sumin_näidis(täisarv korduste_arv)
{
    kuniks (täisarv i = 1; i <= korduste_arv; ++i) {
        bool kihisemine = i % 3 == 0;
        bool sumin = i % 5 == 0;

        kui (kihisemine && sumin) {
            kirjutaf("KihisemineSumin");
        } muidu kui (kihisemine) {
            kirjutaf("Kihisemine");
        } muidu kui (sumin) {
            kirjutaf("Sumin");
        } muidu {
            kirjutaf("%d", i);
        }
        kirjutaf("\n");
    }
}

/*
 * Personaliseeritud tervituste arvutiprogramm.
 */
staatiline tühimik nimetervitus_näidis(tühimik)
{
    tähemärk nimi[PUHVRI_SUURUS];

    kirjutaf("Sisesta enda nimi personaliseeritud tervituseks: ");

    kui (fsaaf(nimi, PUHVRI_SUURUS, stdin) == NULL) {
        mine tõrge;
    }

    suurus_t nime_pikkus = strnpikk(nimi, PUHVRI_SUURUS);
    kui (nime_pikkus == PUHVRI_SUURUS) {
        mine tõrge;
    }
    nimi[nime_pikkus - 1] = 0;

    kirjutaf("Tere %s!\n", nimi);

    tagasta;

tõrge:
    fkirjutaf(stderr, "Sinu nime lugemisel esines tõrkeid!\n");
}

/*
 * Punktide vahelise kauguse arvutamise programm.
 */
staatiline tühimik punktide_kaugus_näidis(tühimik)
{
    struktuur punkt
    {
        ujuk x;
        ujuk y;
    };

    tähemärk puhver[PUHVRI_SUURUS];
    struktuur punkt punktid[2];

    kirjutaf("Sisesta punktide koordinaadid \"x,y\" vormingus.\n");
    kuniks (täisarv i = 0; i < 2; ++i) {
        kirjutaf("Punkt %i: ", i);

        kui (fsaaf(puhver, PUHVRI_SUURUS, stdin) == NULL) {
            fkirjutaf(stderr, "Koordinaatide lugemisel esines tõrkeid!\n");
            tagasta;
        }

        sskänneerif(puhver, "%f,%f", &punktid[i].x, &punktid[i].y);
    }

    ujuk x = astef(punktid[0].x - punktid[1].x, 2);
    ujuk y = astef(punktid[0].y - punktid[1].y, 2);
    ujuk kaugus = ruutjuurf(x + y);

    kirjutaf("Punktide (%f,%f) ja (%f,%f) vaheline kaugus on %f ühikut\n",
             punktid[0].x, punktid[0].y,
             punktid[1].x, punktid[1].y,
             kaugus);

}

täisarv main(täisarv argc, tähemärk ** argv)
{
    kihisemine_sumin_näidis(100);
    kirjutaf("\n\n");

    nimetervitus_näidis();
    kirjutaf("\n\n");

    punktide_kaugus_näidis();
    kirjutaf("\n\n");

    tagasta 0;
}
