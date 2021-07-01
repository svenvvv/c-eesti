#ifndef _EESTI_C_H_
#define _EESTI_C_H_

#define suurus_t    size_t
#define msuurus_t   ssize_t

#define tüübimõiste typedef
#define struktuur   struct
#define loend       enum
#define ühend       union
#define kuisuur     sizeof

#define muutumatu   const
#define märgiga     signed
#define märgita     unsigned
#define staatiline  static
#define rivistatud  inline
#define piiratud    restrict
#define hävinev     volatile
#define väline      extern
/* #define auto        auto */

#define tee         do
#define kuni        while
#define kuniks      for
#define kui         if
#define muidu       else
#define mine        goto

#define tagasta     return

#define lüliti      switch
#define valik       case
#define vaikimisi   default
#define murdu       break
#define jätka       continue

/* tüübimõiste bool    bool; */
tüübimõiste char    tähemärk;
tüübimõiste short   väike;
tüübimõiste long    suur;
tüübimõiste float   ujuk;
tüübimõiste double  topelt;
tüübimõiste void    tühimik;
tüübimõiste int     täisarv;

/* Standardteegid */

#define kirjutaf        printf
#define fkirjutaf       fprintf

#define saaf            gets
#define fsaaf           fgets

#define skänneerif      scanf
#define sskänneerif     sscanf

#define veanumber       errno

#define vabasta         free

#define ruutjuur        sqrt
#define ruutjuurf       sqrtf
#define aste            pow
#define astef           powf

#define strpikk         strlen
#define strnpikk        strnlen

#endif /* _EESTI_C_H_ */
