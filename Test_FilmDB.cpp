#include "FilmDB.h"
#include <gtest/gtest.h>

TEST(FilmDBTest, GetGoodFilmsOfGenre) {
    FilmDB db;
    db.loadData();

    std::vector<std::string> testCases = {
        "Comedy", "Drama", "Action", "Romance", "Sci-Fi",
        "Horror", "Documentary", "Animation", "Adventure", "Biography"
    };

    for (const auto& genre : testCases) {
        std::vector<std::string> films = db.getGoodFilmsOfGenre(7, genre);
        for (const auto& film : films) {
            ASSERT_TRUE(std::find(db.genres.begin(), db.genres.end(), genre) != db.genres.end());
            ASSERT_GE(db.ratings[std::find(db.films.begin(), db.films.end(), film) - db.films.begin()], 7);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
