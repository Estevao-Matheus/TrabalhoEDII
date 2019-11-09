#include <iostream>
#include "Objeto.h"

using namespace std;

Objeto::Objeto()
{

}

Objeto::Objeto(int userID, int movieID, float rating)
{
    UserID = userID;
    MovieID = movieID;
    Rating = rating;
}

Objeto::~Objeto()
{
}

void Objeto::Imprimi()
{
    cout << "\n" << UserID << " // " << MovieID << " // " << Rating << "\n";
}

int Objeto::getUserID() const {
    return UserID;
}

void Objeto::setUserID(int UserID) {
    Objeto::UserID = UserID;
}

int Objeto::getMovieID() const {
    return MovieID;
}

void Objeto::setMovieID(int MovieID) {
    Objeto::MovieID = MovieID;
}

float Objeto::getRating() const {
    return Rating;
}

void Objeto::setRating(float Rating) {
    Objeto::Rating = Rating;
}


