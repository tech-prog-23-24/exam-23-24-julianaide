#include "FilmDB.h"
#include <fstream>
#include <sstream>

void FilmDB::loadData() {
    std::ifstream file(FILMDB_FILE);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string title, genreStr;
            int rating, duration;
            std::getline(ss, title, ',');
            ss >> rating >> duration;
            std::getline(ss, genreStr, ',');

            films.push_back(title);
            ratings.push_back(rating);
            durations.push_back(duration);
            std::stringstream genreStream(genreStr);
            std::string genre;
            while (std::getline(genreStream, genre, '|')) {
                genres.push_back(genre);
            }
        }
        file.close();
    }
}

std::vector<std::string> FilmDB::getFilmsByGenreAndRating(const std::string& genre, int rating) {
    std::vector<std::string> result;
    for (size_t i = 0; i < films.size(); i++) {
        if (ratings[i] >= rating && std::find(genres.begin(), genres.end(), genre) != genres.end()) {
            result.push_back(films[i]);
        }
    }
    return result;
}

std::vector<std::string> FilmDB::getFilmsByGenreAndDuration(const std::string& genre, int duration) {
    std::vector<std::string> result;
    for (size_t i = 0; i < films.size(); i++) {
        if (durations[i] <= duration && std::find(genres.begin(), genres.end(), genre) != genres.end()) {
            result.push_back(films[i]);
        }
    }
    return result;
}

std::vector<std::string> FilmDB::getFilmsByDuration(int duration) {
    std::vector<std::string> result;
    for (size_t i = 0; i < films.size(); i++) {
        if (durations[i] <= duration) {
            result.push_back(films[i]);
        }
    }
    return result;
}

int FilmDB::getGenreCount(const std::string& genre) {
    int count = 0;
    for (const auto& g : genres) {
        if (g == genre) {
            count++;
        }
    }
    return count;
}

std::vector<std::string> FilmDB::getGoodFilmsOfGenre(int rating, const std::string& genre) {
    return getFilmsByGenreAndRating(genre, rating);
}

std::vector<std::string> FilmDB::getFilmsOfGenreLessThan(int duration, const std::string& genre) {
    return getFilmsByGenreAndDuration(genre, duration);
}

std::vector<std::string> FilmDB::getFilmsLessThan(int duration) {
    return getFilmsByDuration(duration);
}

int FilmDB::countGenre(const std::string& genre) {
    return getGenreCount(genre);
}
