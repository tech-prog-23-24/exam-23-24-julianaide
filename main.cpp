#include "FilmDB.h"
#include <iostream>

int main() {
    FilmDB db;
    db.loadData();

    std::cout << "Good films of genre 'Comedy' with rating >= 7:" << std::endl;
    for (const auto& film : db.getGoodFilmsOfGenre(7, "Comedy")) {
        std::cout << film << std::endl;
    }

    std::cout << "\nFilms of genre 'Drama' with duration <= 120 minutes:" << std::endl;
    for (const auto& film : db.getFilmsOfGenreLessThan(120, "Drama")) {
        std::cout << film << std::endl;
    }

    std::cout << "\nFilms with duration <= 90 minutes:" << std::endl;
    for (const auto& film : db.getFilmsLessThan(90)) {
        std::cout << film << std::endl;
    }

    std::cout << "\nNumber of films in 'Action' genre: " << db.countGenre("Action") << std::endl;

    return 0;
}
