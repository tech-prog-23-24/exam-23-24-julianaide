#ifndef FILMDB_H
#define FILMDB_H

#include <string>
#include <vector>

#define FILMDB_FILE "films.txt"

class FilmDB {
private:
    std::vector<std::string> films;
    std::vector<int> ratings;
    std::vector<int> durations;
    std::vector<std::string> genres;

    void loadData();
    std::vector<std::string> getFilmsByGenreAndRating(const std::string& genre, int rating);
    std::vector<std::string> getFilmsByGenreAndDuration(const std::string& genre, int duration);
    std::vector<std::string> getFilmsByDuration(int duration);
    int getGenreCount(const std::string& genre);

public:
    std::vector<std::string> getGoodFilmsOfGenre(int rating, const std::string& genre);
    std::vector<std::string> getFilmsOfGenreLessThan(int duration, const std::string& genre);
    std::vector<std::string> getFilmsLessThan(int duration);
    int countGenre(const std::string& genre);
};

#endif // FILMDB_H
