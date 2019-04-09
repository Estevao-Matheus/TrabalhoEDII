#include <iostream>
#include "Objeto.h"

using namespace std;

Objeto::Objeto()
{

}

Objeto::Objeto(int userID, int movieID, float rating, long long int timestamp)
{
    UserID = userID;
    MovieID = movieID;
    Rating = rating;
    Timestamp = timestamp;
}

Objeto::~Objeto()
{
}

void Objeto::Imprimi()
{
    cout << "\n" << UserID << " // " << MovieID << " // " << Rating << " // " << Timestamp << "\n";
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

long long int Objeto::getTimestamp() const {
    return Timestamp;
}

void Objeto::setTimestamp(long long int Timestamp) {
    Objeto::Timestamp = Timestamp;
}
