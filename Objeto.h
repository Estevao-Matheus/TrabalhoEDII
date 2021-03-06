//
// Created by Johannes Victor on 28/03/2019.
//

#ifndef TRABALHOEDII_OBJETO_H
#define TRABALHOEDII_OBJETO_H


class Objeto {
public:
    Objeto();
    Objeto(int userID, int movieID, float rating, long long int timestamp);
    ~Objeto();
    void Imprimi();

private:
    int UserID;
public:
    int getUserID() const;

    void setUserID(int UserID);

    int getMovieID() const;

    void setMovieID(int MovieID);

    float getRating() const;

    void setRating(float Rating);

    long long int getTimestamp() const;

    void setTimestamp(long long int Timestamp);

private:
    int MovieID;
    float Rating;
    long long int Timestamp;
};


#endif //TRABALHOEDII_DADO_H
